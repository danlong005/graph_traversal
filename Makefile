CC=gcc

a.out:
	$(CC) -o graph_traversal index.c

run:
	./graph_traversal < inputs/input01.txt

clean:
	rm -rf graph_traversal
