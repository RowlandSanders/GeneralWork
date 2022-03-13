CECS 326 Project 1 ReadMe - Rowland Sanders and Quan Do 

How to run the program!

Steps:
1. Download our lab1 main and our Makefile, place it in your linux directory of choice

2. Run the program using the terminal using gcc compiler one at a time or run them using the Makefile provided:
'''
make: main.c
	gcc main.c -o p1main -lpthread
	./p1main 4
	./p1main 5

	gcc main.c -o p2main -D PTHREAD_SYNC -lpthread 
	./p2main 4
	./p2main 5
'''

3. To begin, type 'ls' in terminal within the correct directory, this should display the files you placed in the directory, then type 'make' in the terminal. This will compile both the unSync and Sync versions.

4. They can also be run through the terminal directly using the gcc compiler by typing 'gcc main.c -o p1main -lpthread', hitting enter, then typing './p1main (NUMBER OF CORES)' for unsynced testing 
or 'gcc main.c -o p2main -D PTHREAD_SYNC -lpthread', hitting enter, then typing './p1main (NUMBER OF CORES)' for synced testing. The number of cores must be a postive number.


