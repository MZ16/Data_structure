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
	if (NextPosIdx(pq->rear) == pq->front) { // Queue가 full일경우
		printf("Queue Memory Error!!\n");
		exit(1);
	}
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;	
}

int DeQ(Queue* pq) {
	if (QEmpty(pq)) { // Queue가 Empty인 경우
		printf("Queue Memory Error!!\n");
		exit(1);
	}
	pq->front = NextPosIdx(pq->front); 
	return pq->queArr[pq->front];
	/*
	* data의 변경없이 값을 반환하는 이유는 front가 이동하여 더이상 참조하지 않음으로 
	* Peek함수 호출 시 참조하지않고 EnQ함수 호출 시 값을 덮어씌움
	*/
}

int QPeek(Queue *pq) {
	if (!QEmpty(pq)) return pq->queArr[NextPosIdx(pq->front)];
	else {
		printf("참조 실패");
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
		printf("%d번째 DeQ data : %d\n", i,DeQ(&pq));
	}
	
	if (QEmpty(&pq))printf("Q가 비었습니다.\n");
	

}