#include <stdio.h>
#include <stdlib.h>
//#include "ArrayBaseStack.h" // �迭���
#include "ListBaseStack.h"

int main() {
	//Stack stk; // �迭���
	Stk stk;
	StackInit(&stk);
	SPush(&stk, 1); SPush(&stk, 2);
	SPush(&stk, 3); SPush(&stk, 4);
	
	while(!SIsEmpty(&stk)){
		printf("%d ", SPop(&stk));
	}


	

}