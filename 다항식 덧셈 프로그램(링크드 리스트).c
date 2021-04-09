#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���׽��� ����� �����, ���� �׸��� ���� ���� ������ link�� �ɹ��� ������ ����ü�̴�.
typedef struct ListNode { // ��� Ÿ��
	int coef;
	int expon;
	struct ListNode* link;
} ListNode;


// ���� ����Ʈ ���: ��ũ�� ����Ʈ�� haed, tail, size�� �ɹ��� ������ ����ü�̴�.
typedef struct ListType { // ����Ʈ ��� Ÿ��
	int size;
	ListNode* head;
	ListNode* tail;
} ListType;


// ���� �Լ�: ���� �޽��� ���
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}


// ����Ʈ ��� ���� �Լ� size, head, tail�� �ɹ��� ������ ListType ����ü�� �����ϴ� �Լ��� �ʱⰪ�� 0�� null�� �ʱ�ȭ�Ѵ�.
ListType* create()
{
	ListType * plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

 //����Ʈ, ���, ������ ���ڷ� �޾Ƽ� ����Ʈ�� �������� ���ο� ��� ����ü�� �����Ͽ� ����� �������� �����ϰ� ���� ��尡 �ִٸ� ���� �ƴϸ� ����Ʈ�� head, tail�Ѵ� �ڽ��� ����Ű���� �ϴ� �Լ�
void insert_last(ListType* plist, int coef, int expon)
{
	ListNode* temp =
		(ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("�޸� �Ҵ� ����");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

// list3 = list1 + list2
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* a = plist1->head; // ù ��° ����Ʈ�� ����� �ּҸ� �Ѱ���
	ListNode* b = plist2->head; // �� ��° ����Ʈ�� ����� �ּҸ� �Ѱ���
	int sum;
	while (a && b) { // �� �� �ϳ��� null�� ����ų �� ����
		if (a->expon == b->expon) { // a�� ���� > b�� ����
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link; // �ѹ� �� ����������� ���� ���� �̵�
		}
		else if (a->expon > b->expon) { // a�� ���� == b�� ����
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else { // a�� ���� < b�� ����
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}
	// a�� b���� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵��� ���
		// ��� ���׽����� ����
	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

//����Ʈ ����ü�� ���ڷ� �޾Ƽ� haed�� ����� ����� �ּҸ� �̿��Ͽ� ����� ������ ����Ʈ��
void poly_print(ListType* plist)
{
	ListNode* p = plist->head;
	printf("polynomial = ");
	for (; p; p = p->link) {
		printf("%dx^%d + ", p->coef, p->expon); // ������ �����ְ� ��ó�� ���� �־ x�� �߰��Ͽ� ������
	}
	printf("\n");
}

int main(void)
{
	ListType* list1, * list2, * list3;
	// ���� ����Ʈ ��� ����
	list1 = create();
	list2 = create();
	list3 = create();
	// ���׽� 1�� ����
	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);
	// ���׽� 2�� ����
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);
	poly_print(list1);
	poly_print(list2);
	// ���׽� 3 = ���׽� 1 + ���׽� 2
	poly_add(list1, list2, list3);
	poly_print(list3);
	free(list1); free(list2); free(list3);
}