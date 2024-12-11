#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct Item{
	char* data;
	int priority;
}Item;

typedef struct Queue{
	Item arr[MAX];
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
void enqueue(Queue* queue, char* value,int priority){
	if(isFull(queue)){
		printf("Hang doi da day\n");
		return;
	}
	if(isEmpty(queue)){
		queue->front = 0;
	}
 	queue->rear++;
    queue->arr[queue->rear].data = value;
    queue->arr[queue->rear].priority = priority; 
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

void printQueue(Queue* queue) {
    if(isEmpty(queue)) {
        printf("Hang doi rong\n");
        return;
    }
    Item max = queue->arr[queue->front];
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%s\t", queue->arr[i].data); 
    }
  	for (int i = queue->front; i <= queue->rear; i++) {
     if(queue->arr[i].priority < max.priority){ 
            max = queue->arr[i];
        }
    }
    printf("\nPhan tu uu tien cao nhat %s (Uu tien %d)",max.data,max.priority);
}

int main(){
	Queue queue;
	initialQueue(&queue);
	char value;
	enqueue(&queue,"TASK A", 2);
	enqueue(&queue,"TASK B", 4);
	enqueue(&queue,"TASK C", 3);
	dequeue(&queue);
	printQueue(&queue);
	return 0;
}
