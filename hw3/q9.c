#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

int a[10][10];
int b[10][10];
int c[20][20];
int d[20][20];
int mult1[10][10];
int mult2[20][20];
double time1, time2, time3, time4 = 0;
struct timeval tv1, tv2;

void printMult1();
void printMult2();
struct v{
	int r;
	int c;
};
void *pmult(void *vargp){
	struct v *dt = vargp;
	int sum = 0;
	for(int k = 0; k < 10; k++){
		sum += a[dt->r][k] * b[k][dt->c];
	}
	mult1[dt->r][dt->c] = sum;
	free(vargp);
	pthread_exit(0);
}

void pMultiply1(){
	gettimeofday(&tv1, NULL);
	pthread_t tid[10][10];
	int count = 0;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			struct v *dt = (struct v *) malloc(sizeof(struct v));
			dt->r = i;
			dt->c = j;
			pthread_create(&tid[i][j], NULL, pmult, dt);
			count++;
		}
	}
	for(int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			pthread_join(tid[i][j], NULL);
		}
	}
	gettimeofday(&tv2, NULL);
	time4 = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec);
}
void *pmult2(void *vargp){
	struct v *dt = vargp;
	int sum = 0;
	for(int k = 0; k < 20; k++){
		sum += a[dt->r][k] * b[k][dt->c];
	}
	mult2[dt->r][dt->c] = sum;
	free(vargp);
	pthread_exit(0);
}

void pMultiply2(){
	gettimeofday(&tv1, NULL);
	pthread_t tid[20][20];
	int count = 0;
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			struct v *dt = (struct v *) malloc(sizeof(struct v));
			dt->r = i;
			dt->c = j;
			pthread_create(&tid[i][j], NULL, pmult, dt);
			count++;
		}
	}
	for(int i = 0; i < 20; i++){
		for (int j = 0; j < 20; j++){
			pthread_join(tid[i][j], NULL);
		}
	}
	gettimeofday(&tv2, NULL);
	time3 =(double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec);
}
void seqMultiply1(){
	gettimeofday(&tv1, NULL);
	int sum = 0;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			sum = 0;
			for(int k = 0; k < 10; k++){
				sum = sum + a[i][k] * b[k][j];
			}
			mult1[i][j] = sum;
		}
	}
	gettimeofday(&tv2, NULL);
	time1 = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec);
}
void seqMultiply2(){
	gettimeofday(&tv1, NULL);
	int sum = 0;
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			sum = 0;
			for(int k = 0; k < 20; k++){
				sum = sum + c[i][k] * d[k][j];
			}
			mult2[i][j] = sum;
		}
	}
	gettimeofday(&tv2, NULL);
	time2 = (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec);
}
void printA(){
	printf("A\n");
	for(int i =0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			printf("%d ", a[i][j]);
		}
	printf("\n");
	}
}
void printB(){
	printf("B\n");
	for(int i =0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			printf("%d ", b[i][j]);
		}
	printf("\n");
	}
}
void printMult1(){
	for(int i =0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			printf("%d ", mult1[i][j]);
		}
	printf("\n");
	}
}
void printC(){
	printf("C\n");
	for(int i =0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			printf("%d ", c[i][j]);
		}
	printf("\n");
	}
}
void printD(){
	printf("D\n");
	for(int i =0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			printf("%d ", d[i][j]);
		}
	printf("\n");
	}
}
void printMult2(){
	for(int i =0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			printf("%d ", mult2[i][j]);
		}
	printf("\n");
	}
}
void fillA(){
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			a[i][j] = ((rand() % 9) + 1);
		}
	}
}
void fillB(){
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			b[i][j] = ((rand() % 9) + 1);
		}
	}
}
void fillC(){
	
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			c[i][j] = ((rand() % 9) + 1);
		}
	}
}
void fillD(){
	
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 20; j++){
			d[i][j] = ((rand() % 9) + 1);
		}
	}
}
int main(int argc, char *argv[]){
	srand(time(NULL));
	fillA();
	fillB();
	fillC();
	fillD();
	printA();
	printB();
	printC();
	printD();
	seqMultiply1();
	seqMultiply2();
	printf("Seq Mult1\n");
	printMult1();
	printf("Seq Mult2\n");
	printMult2();
	pMultiply1();
	pMultiply2();
	printf("Parallel Mult1\n");
	printMult1();
	printf("Parallel Mult2\n");
	printMult2();
	printf ("Total time = %f seconds for seq mult1\n",time1);	
	printf ("Total time = %f seconds for seq mult2\n",time2);	
	printf ("Total time = %f seconds for parallel mult1\n",time3);	
	printf ("Total time = %f seconds for parallel mul2\n",time4);	
	return 0;
}






