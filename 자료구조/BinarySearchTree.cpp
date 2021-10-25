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

// BST의 생성 및 초기화
void BSTMakeAndInit(BTreeNode** pRoot) {
	*pRoot = NULL;
}

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode* bst) {
	return GetData(bst);
}

// BST를 대상으로 데이터 저장(노드의 생성과정 포함)
void BSTInsert(BTreeNode** pRoot, BSTData data) {
	BTreeNode* pNode = NULL; // parent node
	BTreeNode* cNode = *pRoot; // current node
	BTreeNode* nNode = NULL; // new node

	//새로운 노드가 추가될 위치를 찾음
	while (cNode != NULL) {
		if (GetData(cNode) == data) return; // 데이터 중복 방지
		pNode = cNode;
		if (GetData(cNode) > data) cNode = GetLeftSubTree(cNode);
		else cNode = GetRightSubTree(cNode);
	} // 위치를 찾기위한 탐색

	// pNode의 서브 노드에 추가할 새 노드의 생성
	nNode = MakeBTreeNode(); // 새 노드 생성
	SetData(nNode, data); // 새 노드에 데이터 저장

	//pNode의 서브 노드에 새 노드를 추가
	if (pNode != NULL) // 새 노드가 루트 노드가 아니라면
	{
		if (GetData(pNode) > data) MakeLeftSubTree(pNode, nNode);
		else MakeRightSubTree(pNode, nNode);
	}
	else *pRoot = nNode; // 새 노드가 루트 노드라면
}

// BST를 대상으로 데이터 탐색
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
		if (sNode == NULL)printf("탐색 실패\n");
		else printf("key : %d\n", BSTGetNodeData(sNode));
	}
	return 0;
}