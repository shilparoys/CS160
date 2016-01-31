#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
void cleanup(void){
	printf("cleaning up\n");
}

void fork6(){
	atexit(cleanup);
	fork();
	exit(0);
}

int main(){
	fork6();
}
