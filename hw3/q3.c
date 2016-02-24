#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 8

void *printHello(void *threadid)
{
	long taskid = (long)threadid;
	sleep(1);
	printf("Hello from thread %ld\n", taskid);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;
	
	for(t = 0; t<NUM_THREADS;t++){
		printf("Creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, printHello, (void *) &t);
		if(rc){
			printf("Error: return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}
	for(t = 0; t < NUM_THREADS; t++){
		pthread_join(threads[t], NULL);
	}
}
