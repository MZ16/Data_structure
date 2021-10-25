#include <stdio.h>
#include <stdlib.h>

typedef int BTData;
typedef struct _bTree {
	BTData data;
	struct _bTree *left;
	struct _bTree* right;
}BTreeNode;

BTreeNode* MakeBTreeNode() {
	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->data = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

BTData GetData(BTreeNode* bt) {
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
	if (main->left != NULL)free(main->left);
	main->left = sub;
}
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	if (main->right != NULL)free(main->right);
	main->right = sub;
}

void RemoveLeftSubTree(BTreeNode* bt) {
	bt->left = NULL;
}

void RemoveRightSubTree(BTreeNode* bt) {
	bt->right = NULL;
}

typedef void VisitFuncPtr(BTData data);

typedef BTData	BSTData;

// BST�� ���� �� �ʱ�ȭ
void BSTMakeAndInit(BTreeNode** pRoot) {
	*pRoot = NULL;
}

// ��忡 ����� ������ ��ȯ
BSTData BSTGetNodeData(BTreeNode* bst) {
	return GetData(bst);
}

// BST�� ������� ������ ����(����� �������� ����)
void BSTInsert(BTreeNode** pRoot, BSTData data) {
	BTreeNode* pNode = NULL; // parent node
	BTreeNode* cNode = *pRoot; // current node
	BTreeNode* nNode = NULL; // new node

	//���ο� ��尡 �߰��� ��ġ�� ã��
	while (cNode != NULL) {
		if (GetData(cNode) == data) return; // ������ �ߺ� ����
		pNode = cNode;
		if (GetData(cNode) > data) cNode = GetLeftSubTree(cNode);
		else cNode = GetRightSubTree(cNode);
	} // ��ġ�� ã������ Ž��

	// pNode�� ���� ��忡 �߰��� �� ����� ����
	nNode = MakeBTreeNode(); // �� ��� ����
	SetData(nNode, data); // �� ��忡 ������ ����

	//pNode�� ���� ��忡 �� ��带 �߰�
	if (pNode != NULL) // �� ��尡 ��Ʈ ��尡 �ƴ϶��
	{
		if (GetData(pNode) > data) MakeLeftSubTree(pNode, nNode);
		else MakeRightSubTree(pNode, nNode);
	}
	else *pRoot = nNode; // �� ��尡 ��Ʈ �����
}

// BST�� ������� ������ Ž��
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target) {
	BTreeNode* cNode = bst; // current node
	BSTData cd; // current data

	while (cNode != NULL) {
		cd = GetData(cNode);
		if (target == cd) return cNode;
		else if (target < cd) cNode = GetLeftSubTree(cNode);
		else cNode = GetRightSubTree(cNode);
	}
	return NULL;
}

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if (bt == NULL)return;
	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if (bt == NULL)return;	
	PreorderTraverse(bt->left, action);
	action(bt->data);
	PreorderTraverse(bt->right, action);
}
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if (bt == NULL)return;
	PreorderTraverse(bt->left, action);	
	PreorderTraverse(bt->right, action);
	action(bt->data);
}


int main() {
	BTreeNode* bstRoot;
	BTreeNode* sNode; // search
	BSTMakeAndInit(&bstRoot);
	int N;
	scanf("%d", &N);
	for (int val, i = 0; i < N; i++) {
		scanf("%d", &val);
		BSTInsert(&bstRoot, val);
	}
	int M;
	scanf("%d", &M);
	for (int val, i = 0; i < M; i++) {
		scanf("%d", &val);
		sNode = BSTSearch(bstRoot, val);
		if (sNode == NULL)printf("Ž�� ����\n");
		else printf("key : %d\n", BSTGetNodeData(sNode));
	}
	return 0;
}