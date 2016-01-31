#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
void fork9(){
	int child_status;
	if(fork() == 0){
		printf("HC: hello from child\n");
	}
	else{
		printf("HP: hello from parent\n");
		wait (&child_status);
		printf("ct: child has terminated\n");
	}
	printf("bye\n");
	exit(0);
}

int main(){
	fork9();
}
