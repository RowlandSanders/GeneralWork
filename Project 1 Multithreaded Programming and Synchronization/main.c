//Quan Do & Rowland Sanders
//CECS 326 Sec 4
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int SharedVariable = 0;
//declare mutex lock
pthread_mutex_t mutex;
//declare barrier
pthread_barrier_t barr;

void* SimpleThread(void *which){ //changed argument due to input error
	int num, val;
  int currThread = (int)(size_t)which; //cast argument to int
	
	for(num = 0; num < 20; num++){
    //Synchronization code here 
    #ifdef PTHREAD_SYNC
    pthread_mutex_lock(&mutex); //Locks current thread
    #endif

	 if (random() > RAND_MAX/2)
	 	usleep(500);
			
		val = SharedVariable;
		printf("*** thread %d sees value %d\n", currThread,val);
		SharedVariable = val + 1; //increment global variable

    #ifdef PTHREAD_SYNC
    pthread_mutex_unlock(&mutex); //unlocks current thread and alows another thread to be accessed
    #endif
	}
	#ifdef PTHREAD_SYNC
  	pthread_barrier_wait(&barr); //Allows threads to "meet up" before displaying final value
  	#endif
	val = SharedVariable;
	printf("Thread %d sees final value %d\n", currThread,val);
  return 0;
}

int main(int argc, char *argv[]){
	if(argc != 2){
	printf("Invalid number of inputs"); //one input checker
	return 0;
	}
	
	int numofThr;
	numofThr = atoi(argv[1]); //change string to integer

	  #ifdef PTHREAD_SYNC
  	pthread_mutex_init(&mutex, NULL); //initialize mutex

  	pthread_barrier_init(&barr, NULL, numofThr); //initialize barrier
  	#endif

	if(numofThr < 1){ //check if input is positive 
	printf("Invalid thread value");
	return 0;
	}
	
	pthread_t thr[numofThr];
  int index[numofThr];
  printf("Size:%ld \nNumberofThreads:%d\n", (sizeof(thr)/sizeof(thr[0])),numofThr);
	
	for(int i = 0; i < numofThr; i++){
  index[i] = i; //giving threads an ID
	pthread_create(&(thr[i]),NULL, SimpleThread, (void *)(size_t) i); //create thread
	}
	
	for(int i = 0; i < numofThr; i++){ 
	pthread_join(thr[i], NULL); //Blocks calling thread untill current thread ends, the first parameter is ID of the target thread and the second parameter is the is the address of the function / the point it will return too.
	}
}
