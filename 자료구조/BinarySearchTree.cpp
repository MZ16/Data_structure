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

// ���� �ڽ� ��� ����, ���ŵ� ����� �ּ� ���� ��ȯ�ȴ�.
BTreeNode* RemoveLeftSubTree(BTreeNode* bt) {
	BTreeNode* delNode;
	
	delNode = bt->left;
	bt->left = NULL;
	return delNode;
}

// ������ �ڽ� ��� ����, ���ŵ� ����� �ּ� ���� ��ȯ�ȴ�.
BTreeNode* RemoveRightSubTree(BTreeNode* bt) {
	BTreeNode* delNode;
	
	delNode = bt->right;
	bt->right = NULL;
	return delNode;
}

// �޸� �Ҹ��� �������� �ʰ� main�� ���� �ڽ� ��带 �����Ѵ�. 
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
	main->left = sub;
}

// �޸� �Ҹ��� �������� �ʰ� main�� ������ �ڽ� ��带 �����Ѵ�. 
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	main->right = sub;
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

// Ʈ������ ��带 �����ϰ� ���ŵ� ����� �ּ� ���� ��ȯ�Ѵ�. 
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target) {
	// ���� ����� ��Ʈ ����� ��츦 ������ ����ؾ� �Ѵ�.
	BTreeNode* pVRoot = MakeBTreeNode(); // ���� ��Ʈ ���

	BTreeNode* pNode = pVRoot; // parent node
	BTreeNode* cNode = *pRoot; // current node
	BTreeNode* dNode; // delete node;

	//��Ʈ ��带 pVRoot�� ����Ű�� ����� ������ ���� ��尡 �ǰ� �Ѵ�.
	ChangeRightSubTree(pVRoot, *pRoot);

	//���� ����� ������ ��� Ž��
	while (cNode != NULL && GetData(cNode) != target) {
		pNode = cNode;
		//target�� �θ��庸�� �۴ٸ� ���� ����Ʈ���� �ּҸ� ����
		if (target < GetData(cNode)) cNode = GetLeftSubTree(cNode);
		else cNode = GetRightSubTree(cNode);
	}
	if (cNode == NULL) return NULL; // ���� ����� �������� ���� ���
	
	dNode = cNode; // ��������� ����Ŵ
	// ù ��° ��� - ������ ��尡 �ܸ� ����� ���
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
		if (GetLeftSubTree(pNode) == dNode) RemoveLeftSubTree(pNode);
		else RemoveRightSubTree(pNode);
	}
	// �� ��° ��� - �ϳ��� �ڽ� ��带 ���� ���
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {
		BTreeNode* dcNode; //delete node�� �ڽ� ���
		//���� ����� �ڽ� ��带 ã�´�.
		if (GetLeftSubTree(dNode) != NULL) dcNode = GetLeftSubTree(dNode);
		else dcNode = GetRightSubTree(dNode);
		// ���� ����� �θ� ���� �ڽ� ��带 �����Ѵ�.
		if (GetLeftSubTree(pNode) == dNode) // ���� ����� ���� �ڽ� ���
			ChangeLeftSubTree(pNode, dcNode);
		else ChangeRightSubTree(pNode, dcNode); // ���� ����� ������ �ڽ� ���
	}
	// �� ��° ��� - �� ���� �ڽ� ��带 ��� ���� ���
	else {
		BTreeNode* mNode = GetRightSubTree(dNode); // min node, ��ü��带 ����Ŵ
		BTreeNode* mpNode = dNode; // min node�� �θ� ���, ��ü����� �θ���
		int delData;
		// step1. ���� ��带 ��ü�� ��带 ã��
		while (GetLeftSubTree(mNode) != NULL) {
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}
		// step2. ��ü�� ��忡 ����� ���� ������ ��忡 ����
		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));
		// step3. ��ü�� ����� �θ� ���� �ڽ� ��带 ����
		if (GetLeftSubTree(mpNode) == mNode) ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData); // ��� ������ ����
	}
	// ������ ��尡 ��Ʈ ����� ��츦 ó��
	if (GetRightSubTree(pVRoot) != *pRoot) *pRoot = GetRightSubTree(pVRoot);
	free(pVRoot);
	return dNode;
}

void ShowData(int data) {
	printf("%d ", data);
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action) {
	if (bt == NULL)return;	
	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}


// ���� Ž�� Ʈ���� ����� ��� ����� �����͸� ����Ѵ�.
void BSTShowAll(BTreeNode* bst) {
	InorderTraverse(bst, ShowData);
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
	BSTShowAll(bstRoot); printf("\n"); printf("\n");
	int M;
	scanf("%d", &M);
	/*for (int val, i = 0; i < M; i++) {
		scanf("%d", &val);
		sNode = BSTSearch(bstRoot, val);
		if (sNode == NULL)printf("Ž�� ����\n");
		else printf("key : %d\n", BSTGetNodeData(sNode));
	}*/
	for (int val,i = 0; val,i < M; val,i++)
	{
		scanf("%d", &val);
		sNode = BSTRemove(&bstRoot, val);
		free(sNode);
		BSTShowAll(bstRoot); printf("\n");
	}
	return 0;
}
/*
9
5 8 1 6 4 9 3 2 7
3
7 1 4
*/