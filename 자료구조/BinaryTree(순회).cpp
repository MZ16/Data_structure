#include <stdio.h>
#include <stdlib.h>

typedef struct _bTreeNode {
	int data;
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
void SetData(BTreeNode* bt, int data) {
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


void InordefTraverse(BTreeNode* bt) { //���� ��ȸ �� 
	if (bt == NULL) return;

	InordefTraverse(bt->left);
	printf("%d\n", bt->data);
	InordefTraverse(bt->right);
}

void PreordefTraverse(BTreeNode* bt) { // ���� ��ȸ ��
	if (bt == NULL) return;

	
	printf("%d\n", bt->data);
	PreordefTraverse(bt->left);
	PreordefTraverse(bt->right);
}

void PostorderTraverse(BTreeNode* bt) { // ���� ��ȸ ��
	if (bt == NULL) return;

	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	printf("%d\n", bt->data);
}

int main() {
	BTreeNode* bt1 = MakeTreeNode();
	BTreeNode* bt2 = MakeTreeNode();
	BTreeNode* bt3 = MakeTreeNode();
	BTreeNode* bt4 = MakeTreeNode();
	BTreeNode* bt5 = MakeTreeNode();

	SetData(bt1, 1); SetData(bt2, 2);
	SetData(bt3, 3); SetData(bt4, 4);
	SetData(bt5, 5);

	MakeLeftSubTree(bt1, bt2); MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4); MakeRightSubTree(bt2, bt5);

	printf("���� ��ȸ\n");
	InordefTraverse(bt1); // ����

	printf("���� ��ȸ\n");
	PreordefTraverse(bt1); // ����

	printf("���� ��ȸ\n");
	PostorderTraverse(bt1); // ����
}
