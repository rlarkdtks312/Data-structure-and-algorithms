#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode { // 노드 타입을 구조체로 정의한다. 정수형태의 데이터와 구조체의 주소값을 저장하는 link 포인터로 구성되어 있다.
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, int value) //linked list의 제일 앞에서 부터 추가하는 함수 malloc을 사용한 동적할당으로 list 구조체를 만들고 link포인터를 head를 가르키게 하고 자신의 주소값을 새로운 head값으로 저장
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

// pre가 가리키는 노드의 다음 노드를 삭제한다. malloc으로 동적할당 해주었기 때문에 메모리할당 해제를 해주어야함
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link; // (1)
	pre->link = removed->link; // (2)
	free(removed); // (3)
	return head; // (4)
}

void print_list(ListNode* head) //주소값 옮기면서 p = null 이 될떄 까지 돌리는 함수
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

// 테스트 프로그램
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