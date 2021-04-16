//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>


typedef int element;
typedef struct DListNode { // 이중연결 노드 타입
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;
// 이중 연결 리스트를 초기화 자기 자신을 가르키도록 함
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

// 이중 연결 리스트의 노드를 출력 원형 연결이기때문에 p = phead 가 되면 모든 노드를 출력한것 
void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}
// 새로운 데이터를 노드 before의 오른쪽에 삽입한다.
void dinsert(DListNode* before, element data)
{
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode; // 새로운 노드와 오른쪽 노드부터 연결해주는 이유는 before의 왼쪽부터 연결하게 되면 오른쪽 노드로 이동 할 수 없기 때문이다.
	before->rlink = newnode;
}

// 노드 removed를 삭제한다. 좌우 노드를 서로 연결해주고 동적할당 해제
void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

// 이중 연결 리스트 테스트 프로그램 
int main(void)
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("추가 단계\n");
	for (int i = 0; i < 5; i++) {
		// 헤드 노드의 오른쪽에 삽입
		dinsert(head, i);
		print_dlist(head);
	}
	printf("\n삭제 단계\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);
	return 0;
}