#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"


void StackInit(Stk* pstack) {
	pstack->head = NULL;
}

int SIsEmpty(Stk* pstack) {
	if (pstack->head == NULL) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void SPush(Stk* pstack, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;		
	newNode->prev = pstack->head;
	pstack->head = newNode;
	
	
}

int SPop(Stk* pstack) {
	int rdata = pstack->head->data;
	Node* rNode = pstack->head;
	if (SIsEmpty(pstack)) {
		printf("stack empty!!\n");
		exit(1);
	}
	else {
		pstack->head = pstack->head->prev;
		free(rNode);

	}
	return rdata;
}
int SPeek(Stk* pstack) {
	if (SIsEmpty(pstack)) {
		printf("stack empty!!\n");
		exit(1);
	}
	return pstack->head->data;

}