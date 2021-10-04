#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // isdigit(���� �Ǻ�)�Լ��� ����ϱ� ����
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

int GetOpPrec(char op) { // �����ڸ� �����ؼ� ��ȯ�Ǵ� ���� ������ 
	//��Һ񱳸� �Ͽ� ������ �켱������ �����ؾ������� �Լ��� �ϳ� �� �����
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

int WhoPrecOp(char op1, char op2) { // GetOpPrec�� WhoPrecOp�Լ��� Helper Fucntion�̴�.
	int op1prec = GetOpPrec(op1);
	int op2prec = GetOpPrec(op2);

	if (op1prec > op2prec) return 1;
	else if (op1prec < op2prec) return -1;
	else return 0;
}

void ConvToRPNExp(char exp[]) {
	LStk stk;
	int len = strlen(exp);
	char* ConvExp = (char*)malloc(len+1); // �ǿ����ڿ� �����ڸ� ���� ����
	LInit(&stk);	
	memset(ConvExp, 0, sizeof(char)*len+1);

	int idx = 0;
	char Pop,tok;
	
	for (int i = 0; i < len; i++) {
		tok = exp[i];
		if (isdigit(tok)) { // �ǿ����� �ɷ�����
			ConvExp[idx++] = tok;
		}
		else { // ������ ó��
			switch (tok)
			{
			case '(': 
				LPush(&stk, tok); break;
			case ')':
				while (1) {
					Pop = LPop(&stk);
					if (Pop == '(')break; //���°�ȣ�� �켱������ ���� ����
					ConvExp[idx++] = Pop;
				}break;
			case '+': case '-':
			case '*': case '/':
				while (!LEmpty(&stk) && WhoPrecOp(LTop(&stk), tok) >= 0) // ������ �켱������ ������ pop
					ConvExp[idx++] = LPop(&stk);
				LPush(&stk, tok);
				break;
			}
		}
		
	}
	while (!LEmpty(&stk)) {
		ConvExp[idx++] = LPop(&stk);
	}
	strcpy(exp, ConvExp); // exp�� ��ȯ�� ���� ��ȯ
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