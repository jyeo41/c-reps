CC = gcc
CFLAGS = -g -Wall -Werror -pedantic-errors
TARGET = snowflakes

all = $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c -lm

clean:
	rm $(TARGET)
