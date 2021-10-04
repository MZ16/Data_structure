#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // isdigit(숫자 판별)함수를 사용하기 위함
#define TRUE 1
#define FALSE 0
typedef struct _node {
	struct _node* prev;
	int data;
}Node;

typedef struct _stk {
	Node* head;
}LStk;

void LInit(LStk* stk) {
	stk->head = NULL;
}



void LPush(LStk* stk, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = stk->head;
	stk->head = newNode;
}

int LEmpty(LStk * stk) {
	if (stk->head != NULL)return FALSE;
	else if (stk->head == NULL)return TRUE;
}

int LPop(LStk* stk) {
	int rdata;
	Node *rNode;
	if (LEmpty(stk)) {
		printf("Stack empty!\n");
		exit(1);
	}
	else {
		rdata = stk->head->data;
		rNode = stk->head;
		stk->head = stk->head->prev;
		free(rNode);
	}
	return rdata;
}

int LTop(LStk* stk) {
	return stk->head->data;
}

int GetOpPrec(char op) { // 연산자를 전달해서 반환되는 값을 가지고 
	//대소비교를 하여 연산자 우선순위를 측정해야함으로 함수를 하나 더 만들듬
	switch (op) {
	case '(':
		return 1;
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;

	}
	return -1;
}

int WhoPrecOp(char op1, char op2) { // GetOpPrec은 WhoPrecOp함수의 Helper Fucntion이다.
	int op1prec = GetOpPrec(op1);
	int op2prec = GetOpPrec(op2);

	if (op1prec > op2prec) return 1;
	else if (op1prec < op2prec) return -1;
	else return 0;
}

void ConvToRPNExp(char exp[]) {
	LStk stk;
	int len = strlen(exp);
	char* ConvExp = (char*)malloc(len+1); // 피연산자와 연산자를 담을 수식
	LInit(&stk);	
	memset(ConvExp, 0, sizeof(char)*len+1);

	int idx = 0;
	char Pop,tok;
	
	for (int i = 0; i < len; i++) {
		tok = exp[i];
		if (isdigit(tok)) { // 피연산자 걸러내기
			ConvExp[idx++] = tok;
		}
		else { // 연산자 처리
			switch (tok)
			{
			case '(': 
				LPush(&stk, tok); break;
			case ')':
				while (1) {
					Pop = LPop(&stk);
					if (Pop == '(')break; //여는괄호는 우선순위가 제일 낮음
					ConvExp[idx++] = Pop;
				}break;
			case '+': case '-':
			case '*': case '/':
				while (!LEmpty(&stk) && WhoPrecOp(LTop(&stk), tok) >= 0) // 스택의 우선순위가 높으면 pop
					ConvExp[idx++] = LPop(&stk);
				LPush(&stk, tok);
				break;
			}
		}
		
	}
	while (!LEmpty(&stk)) {
		ConvExp[idx++] = LPop(&stk);
	}
	strcpy(exp, ConvExp); // exp에 변환된 수식 반환
	free(ConvExp);
}

//+,- = 1 , *,/ = 2 , () = 0
int main() {
	char solve[100];
	scanf("%s", solve);
	

	ConvToRPNExp(solve);
	

	printf("%s \n", solve);
	
	return 0;

}