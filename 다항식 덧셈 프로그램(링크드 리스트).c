#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 다항식의 요소인 계수와, 지수 그리고 다음 노드와 연결할 link를 맴버로 가지는 구조체이다.
typedef struct ListNode { // 노드 타입
	int coef;
	int expon;
	struct ListNode* link;
} ListNode;


// 연결 리스트 헤더: 링크드 리스트의 haed, tail, size를 맴버로 가지는 구조체이다.
typedef struct ListType { // 리스트 헤더 타입
	int size;
	ListNode* head;
	ListNode* tail;
} ListType;


// 오류 함수: 에러 메시지 출력
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}


// 리스트 헤더 생성 함수 size, head, tail을 맴버로 가지는 ListType 구조체를 생성하는 함수로 초기값은 0과 null로 초기화한다.
ListType* create()
{
	ListType * plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

 //리스트, 계수, 지수를 인자로 받아서 리스트의 마지막에 새로운 노드 구조체를 생성하여 계수와 지수값을 저장하고 이전 노드가 있다면 연결 아니면 리스트의 head, tail둘다 자신을 가르키도록 하는 함수
void insert_last(ListType* plist, int coef, int expon)
{
	ListNode* temp =
		(ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
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
	ListNode* a = plist1->head; // 첫 번째 리스트의 헤드노드 주소를 넘겨줌
	ListNode* b = plist2->head; // 두 번째 리스트의 헤드노드 주소를 넘겨줌
	int sum;
	while (a && b) { // 둘 중 하나가 null을 가르킬 떄 까지
		if (a->expon == b->expon) { // a의 차수 > b의 차수
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link; // 한번 씩 사용했음으로 다음 노드로 이동
		}
		else if (a->expon > b->expon) { // a의 차수 == b의 차수
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else { // a의 차수 < b의 차수
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}
	// a나 b중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두
		// 결과 다항식으로 복사
	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

//리스트 구조체를 인자로 받아서 haed에 저장된 노드의 주소를 이용하여 계수와 지수를 프린트함
void poly_print(ListType* plist)
{
	ListNode* p = plist->head;
	printf("polynomial = ");
	for (; p; p = p->link) {
		printf("%dx^%d + ", p->coef, p->expon); // 계수라고 적혀있고 밑처럼 쓰고 있어서 x를 추가하여 수정함
	}
	printf("\n");
}

int main(void)
{
	ListType* list1, * list2, * list3;
	// 연결 리스트 헤더 생성
	list1 = create();
	list2 = create();
	list3 = create();
	// 다항식 1을 생성
	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);
	// 다항식 2를 생성
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);
	poly_print(list1);
	poly_print(list2);
	// 다항식 3 = 다항식 1 + 다항식 2
	poly_add(list1, list2, list3);
	poly_print(list3);
	free(list1); free(list2); free(list3);
}