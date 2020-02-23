#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int mutex = 1, full = 0 , empty = MAX ; 
int buffer[MAX] , p= 0 , c =0 ; 

void wait(int * s){
	//decrements the semaphore
	*s = *s-1 ; 
}

void signal(int * s){
	//increments the semaphore
	*s = *s +1 ; 
}

void producer(int data){
	if(mutex==0 || empty==0){ 
		printf("-- Buffer Full -- \n") ; 
		return ;
	} 
	wait(&mutex) ; 
	wait(&empty) ; 
		
	p = (p+1)%MAX ; 
	buffer[p] = data ; 
	printf("Produced : %d" , data) ; 

	signal(&mutex) ; 
	signal(&full) ; 
}

void consumer(){
	if(mutex==0 || full==0) { 
		printf("-- Empty Buffer -- \n"); 
		return ; 
	}
	wait(&mutex) ; 
	wait(&full) ; 

	c= (c+1)%MAX ; 
	int data = buffer[c] ; 
	printf("\nConsumed : %d" , data) ; 
	
	signal(&mutex) ; 
	signal(&empty) ; 
}

int main(void){
	int ch , data ; 
	while(1){
		printf("\n\n1.Producer\n2.Consumer\n3.Exit\n") ;
		printf("Enter your choice:"); 
		scanf("%d" , &ch) ; 
		switch(ch){
			case 1 :
				printf("Enter data : " ) ; 
				scanf("%d", &data) ; 
				producer(data)  ; 
				break ; 
			case 2 : 
				consumer() ; 
				break ; 
			case 3:
			return 0; 
		}
	}
	return 0;
}