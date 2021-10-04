#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int data;
	struct _node* next;
}Node;

int main() {
	/*�⺻ Ʋ*/
	Node* head=NULL;
	Node* tail=NULL;
	Node* cur=NULL;
	Node* newNode=NULL;
	int readData;

	/*��� ���� �� ����*/
	while (1) {
		printf("�߰��� ������ �Է� : ");
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
	/*��ü ���*/
	if (head == NULL)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else {
		cur = head;
		printf("%d ", cur->data);
		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}printf("\n");

	/*��ü ��� ����*/
	if (head == NULL) {
		printf("�����Ͱ� �����ϴ�.");
	}
	else {
		Node* delNode = head;
		Node* delNextNode = head->next;
		printf("������ ������ %d\n", delNode->data);
		free(delNode);
		while (delNextNode != NULL) {
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			printf("������ ������ %d\n", delNode->data);
			free(delNode);
		}
		head = NULL;
	}

	/*������ ������ ����
	* 1. ó������ ������ ���鼭 data�� ��,
	* 2. ���� ���°�� ����ó��
	* 3. ������ ����� �հ� �� ��带 �������� �� ����
	* 4. �ٵ� �հ� �� ��带 �˷��� ����� ��忩�ߵ��� �ʳ�?
	int delData;

	printf("������ ������ �Է� ");
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
	

	/*��ü ���*/
	if (head == NULL)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
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