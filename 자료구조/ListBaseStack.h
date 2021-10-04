#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE	1
#define FALSE	0
#define STACK_LEN	100


/*연결리스트 기반 스택*/
typedef struct _node {
	int data;
	struct _node* prev;
}Node;
typedef struct _head {
	Node* head;
}LinkedList;
typedef LinkedList Stk;

void StackInit(Stk* pstack);
int SIsEmpty(Stk* pstack);

void SPush(Stk* pstack, int data);
int SPop(Stk* pstack);
int SPeek(Stk* pstack);

#endif