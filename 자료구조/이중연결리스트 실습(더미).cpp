#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* ���ϴ� ������ ����, ����, ��� */

typedef struct node {
	int data;
	struct node* next;
	struct node* prev;
}Node;

int main() {
	Node* head = (Node*)malloc(sizeof(Node)); // head�� ���̿� ����
	head->prev = NULL;
	head->next = NULL;
	Node* cur = head;
	
	
	int data;
	while (1) { // ���⼭���� ���Ḯ��Ʈ ����
		scanf("%d", &data);
		if (data < 0)break;
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = data;
		cur->next = newNode;
		newNode->prev = cur;			
		newNode->next = NULL;
		cur = newNode;
	}
	//����� �غ���.
	/*
	while (cur!=head) {
		
		printf("%d ", cur->data);
		cur = cur->prev;
	}*/



	int remove;
	printf("���� ������ :");
	scanf("%d", &remove);
	while (1) {//������ ������带 ����� cur�� ��ĭ ������ ����� ���Ŀ� ������� ��,�ڿ��ִ� ��带 �����Ų �Ŀ� ���� 		
		Node* del = (Node*)malloc(sizeof(Node));
		del = cur;
		cur = cur->prev;
		if (del->data == remove&&del->next!=NULL) { // 5�� ����� �ȵ�. del�� 5�ΰ�� del->next�� NULL�ε� del->next->prev���� ����
			del->next->prev = cur;		// ���� ���̰� �־ �������� �ڴ� ���̰� ��� �̷�
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