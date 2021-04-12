#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int element; // intŸ���� element�� �θ��ڴ�.

// �����Ϳ� ���� ����� �ּ� ���� �����ϴ� link�� ����� ������ ����ü
typedef struct ListNode { // ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;

// ����Ʈ�� �׸� ��� 
void print_list(ListNode* head)
{
	ListNode* p; // ����� ���ϴ� �ּҸ� �޾��ֱ� ���� ��� ������
	if (head == NULL) return; // ��忡 �ƹ��͵� ������ �Լ� ��
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link; // ���� ���� �̵�
	} while (p != head);
	printf("%d->", p->data); // ������ ��� ���
}

// ����Ʈ�� �տ� ��带 �߰��ϱ� ���� �Լ�
ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1) ��尡 �������� ����Ű�� ����� �ּҸ� �߰��� ��尡 ����Ű������
		head->link = node; // (2) ��尡 �߰��� ��带 ����Ű���� ��
	}
	return head; // ����� ��� �����͸� ��ȯ�Ѵ�.
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1)
		head->link = node; // (2)
		head = node; // (3) insert_first �Լ��� �� ������ ������ head�� ���� �߰��� ���� ���� �����μ� �߰��� ��带 ���� ���� �������� �����ϰ� ��
	}
	return head; // ����� ��� �����͸� ��ȯ�Ѵ�.
}


int main(void)
{
	ListNode* head = NULL;
	// list = 10->20->30->40
	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
	return 0;
}