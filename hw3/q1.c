#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *printHello(void * vargp){
	printf("Hello World\n");
	return NULL;
}

int main(int argc, char * argv[]){
	int n = atoi(argv[1]);
	pthread_t tid[n];
	for(int i = 0; i < n; i++){
		if(pthread_create(&tid[i], NULL, printHello, NULL) < 0){
			printf("Error\n");
			exit(1);
		}
	}
	for(int i = 0; i < n; i++){
		pthread_join(tid[i], NULL);
	}
}
