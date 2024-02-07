CC= gcc
CFLAGS= -Wall -g 
OBJ= my_mat.o

all: my_graph my_Knapsack
# Make the shared library with OBJ
libmy_mat.so: $(OBJ) my_mat.h
	$(CC) -shared -fpic -o $@ $^
# Create my_graph with the my_mat library.
my_graph: my_graph.o libmy_mat.so
	$(CC) $(CFLAGS) my_graph.o ./libmy_mat.so -o my_graph
# Compile my_graph.c
my_graph.o: my_graph.c my_mat.h 
	$(CC) $(CFLAGS) -c my_graph.c 
# Create my_Knapsack
my_Knapsack: my_Knapsack.o 
	$(CC) $(CFLAGS) my_Knapsack.o -o my_Knapsack
# Compile my_Knapsack.c
my_knapsack.o: my_knapsack.c
	$(CC) $(CFLAGS) -o my_Knapsack.c

clean:
	rm -f *.o *.so my_graph my_Knapsack