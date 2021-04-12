#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int element; // int타입을 element로 부르겠다.

// 데이터와 다음 노드의 주소 값을 저장하는 link를 멤버로 가지는 구조체
typedef struct ListNode { // 노드 타입
	element data;
	struct ListNode* link;
} ListNode;

// 리스트의 항목 출력 
void print_list(ListNode* head)
{
	ListNode* p; // 노드의 변하는 주소를 받아주기 위한 노드 포인터
	if (head == NULL) return; // 노드에 아무것도 없으면 함수 끝
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link; // 다음 노드로 이동
	} while (p != head);
	printf("%d->", p->data); // 마지막 노드 출력
}

// 리스트의 앞에 노드를 추가하기 위한 함수
ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1) 헤드가 다음으로 가르키던 노드의 주소를 추가한 노드가 가르키도록함
		head->link = node; // (2) 헤드가 추가한 노드를 가르키도록 함
	}
	return head; // 변경된 헤드 포인터를 반환한다.
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
		head = node; // (3) insert_first 함수와 위 내용은 같지만 head를 현재 추가한 노드와 같게 함으로서 추가한 노드를 헤드로 만들어서 마지막에 삽입하게 함
	}
	return head; // 변경된 헤드 포인터를 반환한다.
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