#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void fork2(){
	printf("LO\n");
	fork();
	printf("Ll1\n");
	fork();
	printf("Bye\n");
}

int main(){
	fork2();
}
