#ifndef __AB_STACK_H__
#define __AB_STACK_H__

#define TRUE	1
#define FALSE	0
#define STACK_LEN	100




/*배열기반 스택*/
typedef struct _arrayStack
{
	int stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, int data);
int SPop(Stack* pstack);
int SPeek(Stack* pstack);

#endif