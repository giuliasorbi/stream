CC = gcc
CFLAGS = -c -Wall
SOURCES = stream.c read_file.c minimum.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = stream

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@echo $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# ‘$<’ is the automatic variable that holds the name of the prerequisite 
# ‘$@’ is the automatic variable that holds the name of the targetmake