make: main.c
	gcc main.c -o p1main -lpthread
	./p1main 4
	./p1main 5

	gcc main.c -o p2main -D PTHREAD_SYNC -lpthread 
	./p2main 4
	./p2main 5