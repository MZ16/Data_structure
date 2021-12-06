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

// 왼쪽 자식 노드 제거, 제거된 노드의 주소 값이 반환된다.
BTreeNode* RemoveLeftSubTree(BTreeNode* bt) {
	BTreeNode* delNode;
	
	delNode = bt->left;
	bt->left = NULL;
	return delNode;
}

// 오른쪽 자식 노드 제거, 제거된 노드의 주소 값이 반환된다.
BTreeNode* RemoveRightSubTree(BTreeNode* bt) {
	BTreeNode* delNode;
	
	delNode = bt->right;
	bt->right = NULL;
	return delNode;
}

// 메모리 소멸을 수반하지 않고 main의 왼쪽 자식 노드를 변경한다. 
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
	main->left = sub;
}

// 메모리 소멸을 수반하지 않고 main의 오른쪽 자식 노드를 변경한다. 
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub) {
	main->right = sub;
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

// 트리에서 노드를 제거하고 제거된 노드의 주소 값을 반환한다. 
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target) {
	// 삭제 대상이 루트 노드인 경우를 별도로 고려해야 한다.
	BTreeNode* pVRoot = MakeBTreeNode(); // 가상 루트 노드

	BTreeNode* pNode = pVRoot; // parent node
	BTreeNode* cNode = *pRoot; // current node
	BTreeNode* dNode; // delete node;

	//루트 노드를 pVRoot가 가르키는 노드의 오른쪽 서브 노드가 되게 한다.
	ChangeRightSubTree(pVRoot, *pRoot);

	//삭제 대상을 지정한 노드 탐색
	while (cNode != NULL && GetData(cNode) != target) {
		pNode = cNode;
		//target이 부모노드보다 작다면 왼쪽 서브트리의 주소를 저장
		if (target < GetData(cNode)) cNode = GetLeftSubTree(cNode);
		else cNode = GetRightSubTree(cNode);
	}
	if (cNode == NULL) return NULL; // 삭제 대상이 존재하지 않을 경우
	
	dNode = cNode; // 삭제대상을 가르킴
	// 첫 번째 경우 - 삭제할 노드가 단말 노드인 경우
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) {
		if (GetLeftSubTree(pNode) == dNode) RemoveLeftSubTree(pNode);
		else RemoveRightSubTree(pNode);
	}
	// 두 번째 경우 - 하나의 자식 노드를 갖는 경우
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) {
		BTreeNode* dcNode; //delete node의 자식 노드
		//삭제 대상의 자식 노드를 찾는다.
		if (GetLeftSubTree(dNode) != NULL) dcNode = GetLeftSubTree(dNode);
		else dcNode = GetRightSubTree(dNode);
		// 삭제 대상의 부모 노드와 자식 노드를 연결한다.
		if (GetLeftSubTree(pNode) == dNode) // 삭제 대상이 왼쪽 자식 노드
			ChangeLeftSubTree(pNode, dcNode);
		else ChangeRightSubTree(pNode, dcNode); // 삭제 대상이 오른쪽 자식 노드
	}
	// 세 번째 경우 - 두 개의 자식 노드를 모두 갖는 경우
	else {
		BTreeNode* mNode = GetRightSubTree(dNode); // min node, 대체노드를 가르킴
		BTreeNode* mpNode = dNode; // min node의 부모 노드, 대체노드의 부모노드
		int delData;
		// step1. 삭제 노드를 대체할 노드를 찾음
		while (GetLeftSubTree(mNode) != NULL) {
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}
		// step2. 대체할 노드에 저장된 값을 삭제할 노드에 대입
		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));
		// step3. 대체할 노드의 부모 노드와 자식 노드를 연결
		if (GetLeftSubTree(mpNode) == mNode) ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

		dNode = mNode;
		SetData(dNode, delData); // 백업 데이터 복원
	}
	// 삭제된 노드가 루트 노드인 경우를 처리
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


// 이진 탐색 트리에 저장된 모든 노드의 데이터를 출력한다.
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
		if (sNode == NULL)printf("탐색 실패\n");
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