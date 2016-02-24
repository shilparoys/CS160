#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int a[10][10];
int b[10][10];
int c[20][20];
int d[20][20];
int mult1[10][10];
int mult2[20][20];

FILE *fp;
char buff[1200];

void printMatrixA(){
	for(int r = 0; r < 10; r++){
		for(int c = 0; c < 10; c++)
		{
			printf("%d ", a[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}
void printMatrixB(){
	for(int r = 0; r < 10; r++){
		for(int c = 0; c < 10; c++)
		{
			printf("%d ", b[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}
void printMatrixC(){
	for(int r = 0; r < 20; r++){
		for(int c1 = 0; c1 < 20; c1++)
		{
			printf("%d ", c[r][c1]);
		}
		printf("\n");
	}
	printf("\n");
}
void printMatrixD(){
	for(int r = 0; r < 20; r++){
		for(int c = 0; c < 20; c++)
		{
			printf("%d ", d[r][c]);
		}
		printf("\n");
	}
	printf("\n");
}
void fillA(){
	fgets(buff, 120, fp);
	int x = 0;
	int y = 0;

	while(fgets(buff, 120, fp) != NULL){
		if(strcmp(buff, "---\n") == 0){
			break;
		}
		int i = 0;
		for(i = 0; i < strlen(buff); i++){
			if(buff[i] == ' '){
				continue;
			}
			if(buff[i] == '\n'){
				++y;
				x = 0;
			}
			else{
				a[y][x] = atoi(&buff[i]);
				++x;
			}
		}
	}

}
void fillB(){
	fgets(buff, 120, fp);
	int x = 0;
	int y = 0;

	while(fgets(buff, 120, fp) != NULL){
		if(strcmp(buff, "---\n") == 0){
			break;
		}
		int i = 0;
		for(i = 0; i < strlen(buff); i++){
			if(buff[i] == ' '){
				continue;
			}
			if(buff[i] == '\n'){
				++y;
				x = 0;
			}
			else{
				b[y][x] = atoi(&buff[i]);
				++x;
			}
		}
	}

}
void fillC(){
	fgets(buff, 410, fp);
	int x = 0;
	int y = 0;

	while(fgets(buff, 410, fp) != NULL){
		if(strcmp(buff, "---\n") == 0){
			break;
		}
		int i = 0;
		for(i = 0; i < strlen(buff); i++){
			if(buff[i] == ' '){
				continue;
			}
			if(buff[i] == '\n'){
				++y;
				x = 0;
			}
			else{
				c[y][x] = atoi(&buff[i]);
				++x;
			}
		}
	}

}
void fillD(){
	fgets(buff, 410, fp);
	int x = 0;
	int y = 0;

	while(fgets(buff, 410, fp) != NULL){
		if(strcmp(buff, "---\n") == 0){
			break;
		}
		int i = 0;
		for(i = 0; i < strlen(buff); i++){
			if(buff[i] == ' '){
				continue;
			}
			if(buff[i] == '\n'){
				++y;
				x = 0;
			}
			else{
				d[y][x] = atoi(&buff[i]);
				++x;
			}
		}
	}

}
int main(int argc, char *argv[]){
	fp = fopen("matrices.txt", "r");
	fillA();
	fillB();
	fillC();
	fillD();
	fclose(fp);
	printMatrixA();
	printMatrixB();
	printMatrixC();
	printMatrixD();
	return 0;
}






