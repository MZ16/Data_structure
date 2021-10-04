#ifndef __list
#define __list

typedef struct _node {
	struct _node* next;
	int numofdata;
};
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