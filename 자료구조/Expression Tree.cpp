#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0

typedef int BTData;

typedef struct _bTreeNode {
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;



BTreeNode* MakeTreeNode(void) {
	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
int GetData(BTreeNode* bt) {
	return bt->data;
}
void SetData(BTreeNode* bt, BTData data) {
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt) {
	return bt->left;
}
BTreeNode* GetRightSubTree(BTreeNode* bt) {
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->left != NULL) free(main->left);
	main->left = sub;
}
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->right != NULL) free(main->right);
	main->right = sub;
}

typedef void VisitFuncPtr(BTData data);

void InordefTraverse(BTreeNode* bt, VisitFuncPtr action) { //중위 순회 ∧ 
	if (bt == NULL) return;

	InordefTraverse(bt->left, action);
	action(bt->data);
	InordefTraverse(bt->right,action);
}

void PreordefTraverse(BTreeNode* bt, VisitFuncPtr action) { // 전위 순회 ＜
	if (bt == NULL) return;


	action(bt->data);
	PreordefTraverse(bt->left, action);
	PreordefTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action) { // 후위 순회 ＞
	if (bt == NULL) return;

	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}


typedef BTreeNode* Data;

typedef struct _node {
	Data data;
	struct _node* prev;
}Node;
typedef struct _head {
	Node* head;
}LinkedList;
typedef LinkedList Stk;



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

void SPush(Stk* pstack, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->prev = pstack->head;
	pstack->head = newNode;


}

Data SPop(Stk* pstack) {
	Data rdata = pstack->head->data;
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
Data SPeek(Stk* pstack) {
	if (SIsEmpty(pstack)) {
		printf("stack empty!!\n");
		exit(1);
	}
	return pstack->head->data;

}


BTreeNode* MakeExpTree(char exp[]) { // 후위순회를 입력받아 트리로 만듬
	Stk stk;
	BTreeNode* pnode;
	int len = strlen(exp);
	for (int i = 0; i < len; i++) {
		pnode = MakeTreeNode();
		if (isdigit(exp[i])) { // 피연산자일 경우
			SetData(pnode, exp[i]-'0');
		}
		else { // 연산자인 경우 
			
			MakeRightSubTree(pnode, SPop(&stk));
			MakeLeftSubTree(pnode, SPop(&stk));
			SetData(pnode, exp[i]);
		}
		SPush(&stk, pnode);
	}
	return SPop(&stk);
}

void ShowNodeData(int data) {
	if (0 <= data && data <= 9) printf("%d ", data); //피연산자
	else printf("%c ", data);//연산자
}

void ShowPrefixTypeExp(BTreeNode* bt) {
	PreordefTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode* bt) {
	InordefTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode* bt) {
	PostorderTraverse(bt, ShowNodeData);
}

int EvaluateExpTree(BTreeNode* bt)
{
	int op1, op2;

	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);

	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt))
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}


int main() {
	char exp[] = "15+7*";
	BTreeNode* bt = MakeExpTree(exp);

	printf("전위 표기법 : "); ShowPrefixTypeExp(bt);
	printf("\n");

	printf("중위 표기법 : "); ShowInfixTypeExp(bt);
	printf("\n");

	printf("전위 표기법 : "); ShowPostfixTypeExp(bt);
	printf("\n");

	printf("연산의 결과: %d \n", EvaluateExpTree(bt));
}
