CC = gcc
TARGET = myclock1
SOURCE = $(TARGET).c


.PHONY: all
all: $(TARGET)

$(TARGET) : $(SOURCE)
	$(CC) $(SOURCE) -o $(TARGET) -Wall -g -O0 `pkg-config clutter-1.0 --cflags --libs`

.PHONY: clean 
clean :
	rm $(TARGET)
