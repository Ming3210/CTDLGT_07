#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct Deque {
    int arr[MAX];
    int front;
    int rear;
} Deque;

void initializeDeque(Deque *deque) {
    deque->front = -1;
    deque->rear = -1;
}

int isEmpty(Deque* deque){
	if(deque->front == -1){
		return 1;
	}
	return 0;
}

int isFull(Deque* deque){
	if(deque->rear == MAX-1){
		return 1;
	}
	return 0;
}

void addFront(Deque *deque, int data) {
    if (isFull(deque)) {
        printf("Hangg doi day\n");
        return;
    }
    
    if (isEmpty(deque)) {
        deque->front = 0;
         deque->rear=0;
    } 
    else {
        for(int i = deque->rear + 1; i > 0; i--) {
            deque->arr[i] = deque->arr[i-1];
        }
        deque->rear++; 
    }
    
    deque->arr[0] = data;  
}
void addRear(Deque *deque, int data) {
    if (isFull(deque)) {
        printf("Hang doi day\n");
        return;
    }
    if (isEmpty(deque)) {
        deque->front = 0;
        
    } 
    
    deque->rear++;
    
    deque->arr[deque->rear] = data;
}

void removeFront(Deque *deque) {
  	if(isEmpty(deque)){
		printf("Hang doi rong");
		return;
	}
	deque->front++;
	if(deque->front> deque->rear){
		deque->front = -1;
		deque->rear = -1;
	}	
}

void removeRear(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Hang doi rong\n");
        return;
    }
   	deque->rear--;
	if(deque->front> deque->rear){
		deque->front = -1;
		deque->rear = -1;
	}	
}

void printDeque(Deque *deque) {
    if (isEmpty(deque)) {
        printf("Hang doi rong\n");
        return;
    }
    printf("Hang doi: ");
    int i = deque->front;
    while (1) {
        printf("%d\t", deque->arr[i]);
        if (i == deque->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque deque;
    initializeDeque(&deque);

    addFront(&deque, 10);
    printDeque(&deque);

    addRear(&deque, 20);
    printDeque(&deque);
    
    addFront(&deque,5);
    printDeque(&deque);
    
    removeFront(&deque);
    printDeque(&deque);
    
    removeRear(&deque);
    printDeque(&deque);

   

    return 0;
}
