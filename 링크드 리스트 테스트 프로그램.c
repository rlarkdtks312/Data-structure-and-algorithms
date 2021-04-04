#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode { // ��� Ÿ���� ����ü�� �����Ѵ�. ���������� �����Ϳ� ����ü�� �ּҰ��� �����ϴ� link �����ͷ� �����Ǿ� �ִ�.
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, int value) //linked list�� ���� �տ��� ���� �߰��ϴ� �Լ� malloc�� ����� �����Ҵ����� list ����ü�� ����� link�����͸� head�� ����Ű�� �ϰ� �ڽ��� �ּҰ��� ���ο� head������ ����
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); // (1)
	p->data = value; // (2)
	p->link = head; // (3)
	head = p; // (4)
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value) 
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1)
	p->data = value; //(2)
	p->link = pre->link; //(3)
	pre->link = p; //(4)
	return head; //(5)
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head; // (1)
	head = removed->link; // (2)
	free(removed); // (3)
	return head; // (4)
}

// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. malloc���� �����Ҵ� ���־��� ������ �޸��Ҵ� ������ ���־����
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link; // (1)
	pre->link = removed->link; // (2)
	free(removed); // (3)
	return head; // (4)
}

void print_list(ListNode* head) //�ּҰ� �ű�鼭 p = null �� �ɋ� ���� ������ �Լ�
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

// �׽�Ʈ ���α׷�
int main(void)
{
	ListNode* head = NULL;
	for (int i = 0; i < 11; i=i+2) {
		head = insert_first(head, i);
		print_list(head);
	}
	for (int i = 0; i < 11; i = i + 2) {
		head = delete_first(head);
		print_list(head);
	}
	return 0;
}