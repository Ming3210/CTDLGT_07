#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct Queue{
	int arr[MAX];
	int front;
	int rear;
} Queue;

//khoi tao hang doi
void initialQueue(Queue* queue){
	queue->front = -1;
	queue->rear = -1;
}

int isEmpty(Queue* queue){
	if(queue->front == -1){
		return 1;
	}
	return 0;
}

int isFull(Queue* queue){
	if(queue->rear == MAX-1){
		return 1;
	}
	return 0;
}

// Them phan tu vao cuoi hang doi
void enqueue(Queue* queue, int value){
	if(isFull(queue)){
		printf("Hang doi da day\n");
		return;
	}
	if(isEmpty(queue)){
		queue->front = 0;
	}
	queue->rear++;
	queue->arr[queue->rear] = value;
}

void dequeue(Queue* queue){
	if(isEmpty(queue)){
		printf("Hang doi rong");
		return;
	}
	queue->front++;
	if(queue->front> queue->rear){
		queue->front = -1;
		queue->rear = -1;
	}	
}

void printQueue(Queue* queue){
	if(isEmpty(queue)){
		printf("Hang doi rong\n");
		return;
	}
	for (int i = queue->front; i<= queue->rear;i++ ){
		printf("%d\t", queue->arr[i]);
	}
}

void peek(Queue* queue){
		if(isEmpty(queue)){
		printf("Hang doi rong");
		return;
	}
	printf("\nGia tri dau: %d", queue->arr[queue->front]);
}

int main(){
	Queue queue;
	initialQueue(&queue);
	int n;
	int value;
	printf("Nhap n: ");
	scanf("%d",&n);
	for(int i = 0; i<n;i++){
	
		printf("Nhap gia tri: ");
		scanf("%d",&value);
		enqueue(&queue,value);
	}
	
	printQueue(&queue);
	peek(&queue);
	
	return 0;
}
