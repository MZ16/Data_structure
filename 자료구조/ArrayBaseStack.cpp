#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"


void StackInit(Stack* pstack) {
	pstack->topIndex = -1;
}

int SIsEmpty(Stack* pstack) {
	if (pstack->topIndex == -1) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

void SPush(Stack* pstack, int data) {
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

int SPop(Stack* pstack) {
	int rdata;
	if (SIsEmpty(pstack)) {
		printf("stack empty!!\n");
		exit(1);
	}
	else {
		rdata = pstack->stackArr[pstack->topIndex];
		pstack->stackArr[pstack->topIndex] = NULL; //���� NULL�� �������� �ʾƵ� topIndex�� ���� ���� ��������� 
		// ������ �ε����� �������ֱ� ������ �������
		pstack->topIndex -= 1;
		return rdata;
	}

}
int SPeek(Stack* pstack) {
	
	if (SIsEmpty(pstack)) {
		printf("stack empty!!\n");
		exit(1);
	}
	else {
		return pstack->stackArr[pstack->topIndex];
	}
}