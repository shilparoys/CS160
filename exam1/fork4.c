#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void fork4(){
	printf("LO\n");
	if( fork() != 0){
		printf("L1\n");
		if(fork() != 0){
			printf("L2\n");
			fork();
		}
	}
	printf("Bye\n");
}

int main(){
	fork4();
}
