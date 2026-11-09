CC = gcc
CFLAGS = -Wall

TARGET = student
SRCS = stud_main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c stud_sort.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c student.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
