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
		pstack->stackArr[pstack->topIndex] = NULL; //굳이 NULL로 저장하지 않아도 topIndex에 의해 값이 덮어씌워지고 
		// 참조할 인덱스가 정해져있기 때문에 상관없음
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