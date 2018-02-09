/* myclock1.c */

/*****************************************************************************/

#include <glib-object.h>

#define MY_TYPE_CLOCK (my_clock_get_type ())
#define MY_CLOCK(obj) 
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), MY_TYPE_CLOCK, MyClock))
#define MY_CLOCK_CLASS(klass) 
  (G_TYPE_CHECK_CLASS_CAST ((klass), MY_TYPE_CLOCK, MyClockClass))
#define MY_IS_CLOCK(obj) 
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MY_TYPE_CLOCK))
#define MY_IS_CLOCK_CLASS(klass) 
  (G_TYPE_CHECK_CLASS_TYPE ((klass), MY_TYPE_CLOCK))
#define MY_CLOCK_GET_CLASS(obj) 
  (G_TYPE_INSTANCE_GET_CLASS ((obj), MY_TYPE_CLOCK, MyClockClass))

typedef struct _MyClock        MyClock;
typedef struct _MyClockClass   MyClockClass;
typedef struct _MyClockPrivate MyClockPrivate;

struct _MyClock
{
  GObject         parent;
  MyClockPrivate *priv;
};

struct _MyClockClass
{
  GObjectClass parent_class;
};

enum
{
  PROP_0,
  PROP_DATE_TIME,
  PROP_LAST
};

struct _MyClockPrivate
{
  GDateTime *datetime;
  guint      timeout;
};

G_DEFINE_TYPE (MyClock, my_clock, G_TYPE_OBJECT);

static GParamSpec *props[PROP_LAST];

GDateTime *
my_clock_get_date_time (MyClock *clock_)
{
  g_return_val_if_fail (MY_IS_CLOCK (clock_), NULL);

  return g_date_time_ref (clock_->priv->datetime);
}

static void
my_clock_set_date_time (MyClock   *clock_,
                        GDateTime *datetime)
{
  g_date_time_unref (clock_->priv->datetime);
  clock_->priv->datetime = g_date_time_ref (datetime);
  g_object_notify_by_pspec (G_OBJECT (clock_), props[PROP_DATE_TIME]);
}

static gboolean
my_clock_update (gpointer data)
{
  MyClock   *clock_ = data;
  GTimeVal   now;
  GDateTime *datetime;
  guint      interval;

  g_get_current_time (&now);

  datetime = g_date_time_new_from_timeval_local (&now);
  my_clock_set_date_time (clock_, datetime);
  g_date_time_unref (datetime);

  interval = (1000000L - now.tv_usec) / 1000L;
  clock_->priv->timeout =
    g_timeout_add_full (G_PRIORITY_HIGH_IDLE,
                        interval,
                        my_clock_update,
                        g_object_ref (clock_),
                        g_object_unref);

  return FALSE;
}

static void
my_clock_set_property (GObject      *object,
                       guint         param_id,
                       const GValue *value,
                       GParamSpec   *pspec)
{
  switch (param_id)
    {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, param_id, pspec);
      break;
    }
}

static void
my_clock_get_property (GObject   *object,
                       guint      param_id,
                       GValue     *value,
                       GParamSpec *pspec)
{
  MyClock *clock_ = MY_CLOCK (object);

  switch (param_id)
    {
    case PROP_DATE_TIME:
      g_value_set_boxed (value, clock_->priv->datetime);
      break;
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, param_id, pspec);
      break;
    }
}

static void
my_clock_finalize (GObject *gobject)
{
  MyClockPrivate *priv = MY_CLOCK (gobject)->priv;

  g_date_time_unref (priv->datetime);
  g_source_remove (priv->timeout);

  G_OBJECT_CLASS (my_clock_parent_class)->finalize (gobject);
}

static void
my_clock_class_init (MyClockClass *klass)
{
  GObjectClass *obj_class = G_OBJECT_CLASS (klass);
  GParamSpec   *pspec;

  obj_class->set_property = my_clock_set_property;
  obj_class->get_property = my_clock_get_property;
  obj_class->finalize     = my_clock_finalize;

  g_type_class_add_private (klass, sizeof (MyClockPrivate));

  pspec = g_param_spec_boxed ("datetime",
                              "Date and Time",
                              "The date and time to show in the clock",
                              G_TYPE_DATE_TIME,
                              G_PARAM_READABLE | G_PARAM_STATIC_STRINGS);
  props[PROP_DATE_TIME] = pspec;
  g_object_class_install_property (obj_class, PROP_DATE_TIME, pspec);
}

static void
my_clock_init (MyClock *clock_)
{
  MyClockPrivate *priv;

  priv = clock_->priv =
    G_TYPE_INSTANCE_GET_PRIVATE (clock_,
                                 MY_TYPE_CLOCK,
                                 MyClockPrivate);

  priv->datetime = g_date_time_new_now_local ();
  priv->timeout = 0;

  my_clock_update (clock_);
}

MyClock *
my_clock_new (void)
{
  return g_object_new (MY_TYPE_CLOCK, NULL);
}

/*****************************************************************************/

#include <clutter/clutter.h>

static void
clock_datetime_changed (GObject    *object,
                        GParamSpec *pspec,
                        gpointer    data)
{
  MyClock      *clock_ = MY_CLOCK (object);
  ClutterActor *text   = data;
  GDateTime    *datetime;
  gchar        *str;

  datetime = my_clock_get_date_time (clock_);
  str = g_date_time_format (datetime, "%xn%H:%M:%S");

  clutter_text_set_text (CLUTTER_TEXT (text), str);

  g_free (str);
  g_date_time_unref (datetime);
}

int
main (int    argc,
      char **argv)
{
  ClutterActor      *stage;
  ClutterActor      *text;
  ClutterConstraint *constraint;
  MyClock           *clock_;

  if (clutter_init (&argc, &argv) != CLUTTER_INIT_SUCCESS)
    return -1;

  /* stage */
  stage = clutter_stage_get_default ();
  clutter_actor_set_size (stage, 320, 240);
  clutter_stage_set_color (CLUTTER_STAGE (stage), CLUTTER_COLOR_Black);
  clutter_stage_set_user_resizable (CLUTTER_STAGE (stage), TRUE);

  /* text */
  text = clutter_text_new_full ("Sans Bold 20",
                                "NOW",
                                CLUTTER_COLOR_LightButter);
  clutter_container_add_actor (CLUTTER_CONTAINER (stage), text);
  clutter_text_set_line_alignment (CLUTTER_TEXT (text), PANGO_ALIGN_CENTER);

  /* align text in center of stage */
  constraint =
    clutter_align_constraint_new (stage, CLUTTER_ALIGN_X_AXIS, 0.5);
  clutter_actor_add_constraint (text, constraint);

  constraint =
    clutter_align_constraint_new (stage, CLUTTER_ALIGN_Y_AXIS, 0.5);
  clutter_actor_add_constraint (text, constraint);

  /* clock */
  clock_ = my_clock_new ();
  g_signal_connect (clock_,
                    "notify::datetime",
                    G_CALLBACK (clock_datetime_changed),
                    text);

  clutter_actor_show (stage);

  clutter_main ();

  return 0;
}
