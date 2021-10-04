#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct _node {
	int data;
	struct _node* next;
}Node;

typedef struct _Queue {
	Node* front;
	Node* rear;
}Queue;

void QInit(Queue* pq) {
	pq->front = NULL;
	pq->rear = NULL;
}

int QEmpty(Queue* pq) {
	if (pq->front == NULL)return TRUE;
	else return FALSE;
}

void EnQueue(Queue* pq, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (QEmpty(pq)) { // Empty인 경우 front와 rear가 첫 노드를 가르키는것을 처리
		pq->front = newNode;
		pq->rear = newNode;
	}
	else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
	
}

int DeQueue(Queue* pq) {
	int rdata;
	Node* rNode;
	if (QEmpty(pq)) {
		printf("Queue Memory Error!\n");
		exit(1);
	}
	rdata = pq->front->data;
	rNode = pq->front;
	pq->front = pq->front->next;
	free(rNode);
	return rdata;
}

int QPeek(Queue* pq) {
	if(!QEmpty(pq)) return pq->front->data;
	else {
		printf("Queue Memoey Error!\n");
		exit(1);
	}
}


int main() {
	Queue pq;
	QInit(&pq);
	EnQueue(&pq, 1); EnQueue(&pq, 2);
	EnQueue(&pq, 3); EnQueue(&pq, 4);
	printf("QPeek : %d\n", QPeek(&pq));
	int cnt = 0;
	for (int i = 1; i <= 4; i++) {
		if (i % 2 == 0) {
			printf("\nQPeek : %d\n", QPeek(&pq));
		}

		printf("%d번째 DeQ data : %d\n", i, DeQueue(&pq));
	}

	if (QEmpty(&pq))printf("Q가 비었습니다.\n");
}