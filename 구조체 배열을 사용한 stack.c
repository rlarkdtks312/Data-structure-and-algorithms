#define _CRT_SECURE_NO_WARNINGS //scanf 에러 해결법
#include<stdio.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 100					//배열의 크기
typedef int element;						//int -> element
typedef struct {							//구조체 선언
	element data[MAX_STACK_SIZE];
	int top;							
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}
// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		printf("스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		return -1;
		//exit(1);
	}
	else return s->data[(s->top)--];
}

int main(void)
{
	StackType s;
	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));

	printf("%d\n", pop(&s));						//공백 에러 발생을 기대
	
	init_stack(&s);

	for (int i = 1; i < MAX_STACK_SIZE + 1; i++) {	//포화 상태로 만들기	
		push(&s, i);
		if (i % 10 == 0) {
			printf("%d\n", i);
		}
	}

	printf("추가완료\n");							//포화 에러 발생을 기대
	push(&s, 5);


}

/*
* 구조체 배열을 사용하여 stack을 구현하였다.
*/