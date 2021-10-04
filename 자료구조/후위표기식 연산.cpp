#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


typedef struct _node {
	struct _node* prev;
	int data;
}Node;

typedef struct _stk {
	Node* head;
}Lstk;

void Linit(Lstk* stk) {
	stk->head = NULL;
}

int Lempty(Lstk* stk) {
	if (stk->head == NULL)return 1;
	return 0;
}

void Lpush(Lstk* stk, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = stk->head;
	stk->head = newNode;
}

int Lpop(Lstk* stk) {
	int rdata;
	Node* rNode;
	if (Lempty(stk)) {
		printf("Stack empty!\n");
		exit(1);
	}
	rdata = stk->head->data;
	rNode = stk->head;
	stk->head = stk->head->prev;
	free(rNode);
	return rdata;
}


void ConvExp(char exp[]) {
	int len = strlen(exp);
	Lstk stk;
	Linit(&stk);
	int tok;
	int pop1, pop2;

	for (int i = 0; i < len; i++) {
		tok = exp[i];
		if (isdigit(tok)) { // 피연산자라면 push
			Lpush(&stk, tok - '0'); // 스택에 int형으로 넣기위함
		}
		else { // 연산자라면 pop2번, 연산, push
			pop2 = Lpop(&stk);
			pop1 = Lpop(&stk);
			switch (tok)
			{
			case '*':
				Lpush(&stk, pop1 * pop2);
				break;
			case '/':
				Lpush(&stk, pop1 / pop2);
				break;
			case '+':
				Lpush(&stk, pop1 + pop2);
				break;
			case '-':
				Lpush(&stk, pop1 - pop2);
				break;
			}
		}
	}
	printf("%d\n", Lpop(&stk));

}


int main() {
	char exp[100];

	scanf("%s", exp);

	ConvExp(exp);
}