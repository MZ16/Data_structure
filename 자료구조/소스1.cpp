#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(suppress:4996)
#pragma warning(disable:4996)

typedef struct _node {
	char data;
	struct _node* prev;
	struct _node* next;
}Node;


int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	Node* cur = head;

	int N;
	char ch, op;

	while (ch = getchar() != '\n') {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = ch;
		newNode->next = NULL;
		newNode->prev = cur;
		cur->next = newNode;
		cur = cur->next;
	}

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%c", &op);

		switch (op) {
		case 'L': // 커서를 왼쪽으로 이동
		{
			if (cur->prev == NULL)continue;
			cur = cur->prev;
			break;
		}

		case 'D': // 커서를 오른쪽으로 이동
		{
			if (cur->next == NULL)continue;
			cur = cur->next;
			break;
		}

		case 'B': {
			Node* del = (Node*)malloc(sizeof(Node));
			del = cur->prev;
			if (del->prev == NULL)continue;
			else {
				del->prev->next = cur;
				cur->prev = del->prev;
				del = NULL;
			}
			free(del);
			break;
		}


		case 'P':
		{
			char c;
			scanf("%c", &c);
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->data = c;
			cur->prev = newNode;
			newNode->next = cur;
			newNode->prev = cur->prev->prev;
			newNode->prev->next = newNode;
			break;
		}

		}

	}
	cur = head->next;
	while (cur) {
		printf("%c", cur->data);
		cur->next;
	}
	return 0;
}
