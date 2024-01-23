#include <stdio.h>
#define MaxLenght 100

typedef int ElementType;

typedef struct{
	ElementType Elements[MaxLenght];
	int front, rear;	
}Queue;

void Maknull_Queue(Queue *q){
	q->front = -1;
	q->rear = -1;
}

int Empty_Queue(Queue q){
	return q.front == -1;
}

int Full_Queue(Queue q){
	return (q.rear-q.front) == MaxLenght-1;
}

void EndQueue(ElementType x, Queue *q){
	if(!Full_Queue(*q)){
		if(Empty_Queue(*q))
			q->front = 0;
		if(q->rear ==  MaxLenght-1){
			for(int i=q->front; i<= q->rear; ++i){
				q->Elements[i - q->front] = q->Elements[i];
			}
			q->rear = MaxLenght - q->front - 1;
			q->front = 0;
		}
		q->rear = q->rear + 1;
		q->Elements[q->rear] = x;
	}else {
		printf("Hang day !!!");
	}
}

void Delete_Queue(Queue *q){
	if(!Empty_Queue(*q)){
		q->front = q->front + 1;
		if(q->front > q->rear){
			Maknull_Queue(q);
		}
	}else{
		printf("Hang rong !!!");
	}
}

ElementType Front(Queue q){
	return q.Elements[q.front];
}

void Read_Queue(Queue *q){
	Maknull_Queue(q);
	ElementType x;
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		scanf("%d", &x);
		EndQueue(x, q);
	}
}

void Print_Queue(Queue *q){
	while(!Empty_Queue(*q)){
		printf("%d", Front(*q));
		Delete_Queue(q);
	}
	printf("\n");
}


