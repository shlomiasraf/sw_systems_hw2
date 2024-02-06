CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_MY_mat=my_mat.o
FLAGS= -Wall 
all: connections
# Create main with the my_mat library.
connections: $(OBJECTS_MAIN) libmy_mat.a
	$(CC) $(FLAGS) -o connections $(OBJECTS_MAIN) ./libmy_mat.a
# Compile main.c	
main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c
# Make the library with OBJECTS_MY_mat
libmy_mat.a: $(OBJECTS_MY_mat)
	$(AR) rcs $@ $^
# Add my_mata.h to the implicit rules
%.o: %.c my_mat.h
	$(CC) $(CFLAGS) -c $<
#Clear everything we create
clean:
	rm -f *.o *.a *.so con 
