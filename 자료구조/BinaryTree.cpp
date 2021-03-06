#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct _bTreeNode{
	int data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;

BTreeNode* MakeTreeNode() {
	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

int GetData(BTreeNode* bt) {
	return bt->data;
}

void SetData(BTreeNode* bt,int data) { 
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt) { // 좌측 subtree주소값 반환
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt) { 
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub) { // 부모노드와 좌측 자식노드 연결
	if (main->left != NULL) free(main->left);  // 기존 연결된 노드는 삭제
	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->right != NULL) free(main->right);
	main->right = sub;
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

	printf("%d\n", GetData(bt1));
	printf("%d\n", GetData(GetLeftSubTree(bt1)));
	
	printf("%d\n", GetData(GetRightSubTree(bt1)));
	printf("%d\n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));
	printf("%d\n", GetData(GetLeftSubTree(bt2)));	
	printf("%d\n", GetData(GetRightSubTree(bt2)));
	

	return 0;
}