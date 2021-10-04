#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100
#define TRUE 1
#define FALSE 0

typedef struct CQueue {
	int front;
	int rear;
	int queArr[MAX];
}Queue;

int NextPosIdx(int pos) { // helper function
	if (pos + 1 == MAX)return 0;
	else return pos + 1;
}

void QInit(Queue* pq) {
	pq->front = 0;
	pq->rear = 0;
}

int QEmpty(Queue* pq) {
	if (pq->front == pq->rear)return TRUE;
	else return FALSE;
}

void EnQ(Queue* pq,int data) {
	if (NextPosIdx(pq->rear) == pq->front) { // Queue�� full�ϰ��
		printf("Queue Memory Error!!\n");
		exit(1);
	}
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;	
}

int DeQ(Queue* pq) {
	if (QEmpty(pq)) { // Queue�� Empty�� ���
		printf("Queue Memory Error!!\n");
		exit(1);
	}
	pq->front = NextPosIdx(pq->front); 
	return pq->queArr[pq->front];
	/*
	* data�� ������� ���� ��ȯ�ϴ� ������ front�� �̵��Ͽ� ���̻� �������� �������� 
	* Peek�Լ� ȣ�� �� ���������ʰ� EnQ�Լ� ȣ�� �� ���� �����
	*/
}

int QPeek(Queue *pq) {
	if (!QEmpty(pq)) return pq->queArr[NextPosIdx(pq->front)];
	else {
		printf("���� ����");
		exit(1);
	}
}

int main() {
	Queue pq;
	QInit(&pq);
	EnQ(&pq, 1); EnQ(&pq, 2);
	EnQ(&pq, 3); EnQ(&pq, 4);
	printf("QPeek : %d\n", QPeek(&pq));
	
	for (int i = 1; i <= 4; i++) {
		printf("%d��° DeQ data : %d\n", i,DeQ(&pq));
	}
	
	if (QEmpty(&pq))printf("Q�� ������ϴ�.\n");
	

}