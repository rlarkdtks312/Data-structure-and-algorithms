#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char element[100];

typedef struct DListNode { // ���߿��� ��� Ÿ��
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

DListNode* current; //���� ����Ǵ� �뷡�� ��� ��ġ�� �����ϱ� ���� ������

// ���� ���� ����Ʈ�� �ʱ�ȭ
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

// ���� ���� ����Ʈ�� ��带 ���
void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		if (p == current) //���� ����Ǵ� �뷡���� �ƴ���
			printf(" <-| # %s # |->", p->data);
		else
			printf("<-| %s |->", p->data);
	}
	printf("\n");
}

// ���ο� �����͸� ��� before�� �����ʿ� �����Ѵ�.
void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	strcpy(newnode->data, data);
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}

// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void)
{
	char ch;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	dinsert(head, "Mamamia");
	dinsert(head, "Dancing Queen");
	dinsert(head, "Fernando");

	current = head->rlink;
	print_dlist(head);

	do { //q�� �Է��Ҷ�����
		printf("\n��ɾ �Է��Ͻÿ�(<, >, q): ");
		ch = getchar();
		getchar(); // ��Ȯ���� �𸣰����� getchar()��  ����� �� ������ ó�����ֱ� ���ؼ��ε�?
		if (ch == '<') {
			current = current->llink;
			if (current == head)
				current = current->llink;
		}
		else if (ch == '>') {
			current = current->rlink;
			if (current == head)
				current = current->rlink;
		}
		print_dlist(head);

	} while (ch != 'q');

	return 0;
}