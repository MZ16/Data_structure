#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct _node {
	int data;
	struct _node* next;
	struct _node* prev;
}Node;

typedef struct _deque {
	Node* head;
	Node* tail;
}Deque;

void DequeInit(Deque* pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Deque* pdeq)
{
	if (pdeq->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Deque* pdeq, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = pdeq->head;

	if (DQIsEmpty(pdeq))
		pdeq->tail = newNode;
	else
		pdeq->head->prev = newNode;

	newNode->prev = NULL;
	pdeq->head = newNode;
}

void DQAddLast(Deque* pdeq, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = pdeq->tail;

	if (DQIsEmpty(pdeq))
		pdeq->head = newNode;
	else
		pdeq->tail->next = newNode;

	newNode->next = NULL;
	pdeq->tail = newNode;
}

int DQRemoveFirst(Deque* pdeq)
{
	Node* rnode = pdeq->head;
	int rdata = pdeq->head->data;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	pdeq->head = pdeq->head->next;
	free(rnode);

	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;

	return rdata;
}

int DQRemoveLast(Deque* pdeq)
{
	Node* rnode = pdeq->tail;
	int rdata = pdeq->tail->data;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	pdeq->tail = pdeq->tail->prev;
	free(rnode);

	if (pdeq->tail == NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;

	return rdata;
}

int DQGetFirst(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	return pdeq->head->data;
}

int DQGetLast(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	return pdeq->tail->data;
}

int main() {
	Deque deq;
	DequeInit(&deq);

	DQAddFirst(&deq, 1); DQAddFirst(&deq, 2);
	DQAddLast(&deq, 3); DQAddLast(&deq, 4);

	printf("%d\n", DQGetFirst(&deq));
	printf("%d\n", DQGetLast(&deq));

	DQRemoveFirst(&deq);
	DQRemoveFirst(&deq);
	printf("%d\n", DQGetFirst(&deq));

	DQRemoveLast(&deq);
	
	printf("%d\n", DQGetLast(&deq));
	DQRemoveLast(&deq);
	if (DQIsEmpty(&deq))printf("Deque Empty!\n");

}