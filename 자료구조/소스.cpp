#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
}Node;

int main() {
	/*기본 틀*/
	Node* head=NULL;
	Node* tail=NULL;
	Node* cur=NULL;
	Node* newNode=NULL;
	int readData;

	/*노드 생성 및 연결*/
	while (1) {
		printf("추가할 데이터 입력 : ");
		scanf("%d", &readData);
		if (readData < 1)break;

		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL) {
			head = newNode;
		}
		else {
			tail->next = newNode;
		}
		tail = newNode;
	}
	/*전체 출력*/
	if (head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else {
		cur = head;
		printf("%d ", cur->data);
		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}printf("\n");

	/*전체 노드 삭제*/
	if (head == NULL) {
		printf("데이터가 없습니다.");
	}
	else {
		Node* delNode = head;
		Node* delNextNode = head->next;
		printf("삭제한 데이터 %d\n", delNode->data);
		free(delNode);
		while (delNextNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			printf("삭제한 데이터 %d\n", delNode->data);
			free(delNode);
		}
		head = NULL;
	}

	/*지정된 데이터 삭제
	* 1. 처음부터 끝까지 돌면서 data값 비교,
	* 2. 값이 없는경우 예외처리
	* 3. 삭제할 노드의 앞과 뒤 노드를 연결해준 후 삭제
	* 4. 근데 앞과 뒤 노드를 알려면 양방향 노드여야되지 않나?
	int delData;

	printf("삭제할 데이터 입력 ");
	scanf("%d", &delData);
	cur = head;
	Node* delNode = cur;
	while (cur->next != NULL) {
		if (cur->data == delData)
			free(delNode);
		else
			cur = cur->next;
	}cur = NULL;
		*/
	

	/*전체 출력*/
	if (head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}
	else {
		cur = head;
		printf("%d ", cur->data);
		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	

	return 0;
}