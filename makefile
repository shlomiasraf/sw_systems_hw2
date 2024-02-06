CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_MY_math=my_mat.o
FLAGS= -Wall 
# Create main with static library by recursive
mains: $(OBJECTS_MAIN) libclassmymath.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) ./libclassmymath.a
# Compile main.c	
main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c
# Make the static library with OBJECTS_LIB_Recursive
libclassmymath.a: $(OBJECTS_MY_math)
	$(AR) rcs $@ $^
# Add NumClass.h to the implicit rules
%.o: %.c my_mat.h
	$(CC) $(CFLAGS) -c $<
#Clear everything we create
clean:
	rm -f *.o *.a *.so mains 
