CC = gcc
TARGET1 = actor-model
SOURCE1 = $(TARGET1).c

TARGET2 = basic-actor
SOURCE2 = $(TARGET2).c

TARGET3 = bin-layout
SOURCE3 = $(TARGET3).c

TARGET4 = box-layout
SOURCE4 = $(TARGET4).c

TARGET5 = canvas
SOURCE5 = $(TARGET5).c

TARGET6 = constraints
SOURCE6 = $(TARGET6).c

TARGET7 = drag-action
SOURCE7 = $(TARGET7).c

TARGET8 = drop-action
SOURCE8 = $(TARGET8).c

TARGET9 = easing-modes
SOURCE9 = $(TARGET9).c

TARGET10 = flow-layout 
SOURCE10 = $(TARGET10).c

TARGET11 = grid-layout
SOURCE11 = $(TARGET11).c

TARGET12 = image-content
SOURCE12 = $(TARGET12).c

TARGET13 = layout-manager
SOURCE13 = $(TARGET13).c

TARGET14 = pan-action
SOURCE14 = $(TARGET14).c

TARGET15 = rounded-rectangle
SOURCE15 = $(TARGET15).c

TARGET16 = scroll-actor
SOURCE16 = $(TARGET16).c

TARGET17 = threads 
SOURCE17 = $(TARGET17).c

.PHONY: all
all: $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) $(TARGET7) \
$(TARGET8) $(TARGET9) $(TARGET11) $(TARGET12) $(TARGET13) $(TARGET14) \
$(TARGET15) $(TARGET16)

$(TARGET1) : $(SOURCE1)
	$(CC) $(SOURCE1) -o $(TARGET1) -Wall -g -O0 `pkg-config clutter-1.0 --cflags --libs`

$(TARGET2) : $(SOURCE2)
	$(CC) $(SOURCE2) -o $(TARGET2) -Wall -g -O0 `pkg-config clutter-1.0 --cflags --libs`

$(TARGET3) : $(SOURCE3)
	$(CC) $(SOURCE3) -o $(TARGET3) -Wall -g -O0 `pkg-config clutter-1.0 --cflags --libs`

$(TARGET4) : $(SOURCE4)
	$(CC) $(SOURCE4) -o $(TARGET4) -Wall -g -O0 `pkg-config clutter-1.0 --cflags --libs`

$(TARGET5) : $(SOURCE5)
	$(CC) $(SOURCE5) -o $(TARGET5) -Wall -g -O0 -lm `pkg-config clutter-1.0 cairo --cflags --libs`

$(TARGET6) : $(SOURCE6)
	$(CC) $(SOURCE6) -o $(TARGET6) -Wall -g -O0 `pkg-config clutter-1.0 --cflags --libs`

$(TARGET7) : $(SOURCE7)
	$(CC) $(SOURCE7) -o $(TARGET7) -Wall -g -O0 `pkg-config clutter-1.0 --cflags --libs`

$(TARGET8) : $(SOURCE8)
	$(CC) $(SOURCE8) -o $(TARGET8) -Wall -g -O0 `pkg-config clutter-1.0 --cflags --libs`

$(TARGET9) : $(SOURCE9)
	$(CC) $(SOURCE9) -o $(TARGET9) -Wall -g -O0 `pkg-config clutter-1.0 --cflags --libs`

$(TARGET10) : $(SOURCE10)
	$(CC) $(SOURCE10) -o $(TARGET10) -Wall -g -O0 `pkg-config clutter-1.0 --cflags --libs`

$(TARGET11) : $(SOURCE11)
	$(CC) $(SOURCE11) -o $(TARGET11) -Wall -g -O0 `pkg-config clutter-1.0 --cflags --libs`

$(TARGET12) : $(SOURCE12)
	$(CC) $(SOURCE12) -o $(TARGET12) -Wall -g -O0 `pkg-config clutter-1.0 --cflags --libs`

$(TARGET13) : $(SOURCE13)
	$(CC) $(SOURCE13) -o $(TARGET13) -Wall -g -O0 -lm `pkg-config clutter-1.0 --cflags --libs`

$(TARGET14) : $(SOURCE14)
	$(CC) $(SOURCE14) -o $(TARGET14) -Wall -g -O0 `pkg-config clutter-1.0 --cflags --libs`

$(TARGET15) : $(SOURCE15)
	$(CC) $(SOURCE15) -o $(TARGET15) -Wall -g -O0 `pkg-config clutter-1.0 --cflags --libs`

$(TARGET16) : $(SOURCE16)
	$(CC) $(SOURCE16) -o $(TARGET16) -Wall -g -O0 `pkg-config clutter-1.0 --cflags --libs`

$(TARGET17) : $(SOURCE17)
	$(CC) $(SOURCE17) -o $(TARGET17) -Wall -g -O0 `pkg-config clutter-1.0 --cflags --libs`


.PHONY: clean 
clean :
	rm $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4) $(TARGET5) $(TARGET6) $(TARGET7) \
$(TARGET8) $(TARGET9) $(TARGET10) $(TARGET11) $(TARGET12) $(TARGET13) $(TARGET14) \
$(TARGET15) $(TARGET16) $(TARGET17)
