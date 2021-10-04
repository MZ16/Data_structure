#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* 원하는 데이터 삽입, 삭제, 출력 */

typedef struct node {
	int data;
	struct node* next;
	struct node* prev;
}Node;

int main() {
	Node* head = (Node*)malloc(sizeof(Node)); // head를 더미에 연결
	head->prev = NULL;
	head->next = NULL;
	Node* cur = head;
	
	
	int data;
	while (1) { // 여기서부터 연결리스트 삽입
		scanf("%d", &data);
		if (data < 0)break;
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		cur->next = newNode;
		newNode->prev = cur;			
		newNode->next = NULL;
		cur = newNode;
	}
	//출력을 해보자.
	/*
	while (cur!=head) {
		
		printf("%d ", cur->data);
		cur = cur->prev;
	}*/



	int remove;
	printf("삭제 데이터 :");
	scanf("%d", &remove);
	while (1) {//삭제는 삭제노드를 만들고 cur를 한칸 앞으로 당겨줌 그후에 삭제노드 앞,뒤에있는 노드를 연결시킨 후에 삭제 		
		Node* del = (Node*)malloc(sizeof(Node));
		del = cur;
		cur = cur->prev;
		if (del->data == remove&&del->next!=NULL) { // 5가 출력이 안됨. del이 5인경우 del->next는 NULL인데 del->next->prev에서 에러
			del->next->prev = cur;		// 앞은 더미가 있어서 괜찮지만 뒤는 더미가 없어서 이럼
			cur->next = del->next;	
			del->prev = NULL;
			free(del);
			break;
		}
		else if (del->data == remove && del->next == NULL) {
			cur->next = NULL;
			del->prev = NULL;
			free(del);
			break;
		}
	
	}
	cur = head;
	while (cur) {
		cur = cur->next;
		printf("%d ", cur->data);
	}
}