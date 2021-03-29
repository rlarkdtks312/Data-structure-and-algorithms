#define _CRT_SECURE_NO_WARNINGS //scanf 에러 해결법
#include<stdio.h>
#include<stdlib.h>
#include <string.h>	//strlen() 사용하기 위해 추가

#define MAX_STACK_SIZE 100					//배열의 크기
typedef char element;						//char -> element
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

element peek(StackType* s)	//peek 함수 추가
{
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		return -1;
		//exit(1);
	}
	else return s->data[(s->top)];
}

int prec(char op)	//연산자의 우선순위를 매기는 함수
{
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

// 중위 표기 수식 -> 후위 표기 수식
void infix_to_postfix(char exp[])
{
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	StackType s;
	init_stack(&s); // 스택 초기화
	for (i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/': // 연산자
		// 스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s));
			push(&s, ch);
			break;
		case '(': // 왼쪽 괄호
			push(&s, ch);
			break;
		case ')': // 오른쪽 괄호
			top_op = pop(&s);
			// 왼쪽 괄호를 만날때까지 출력
			while (top_op != '(') {	//오른쪽 괄호가 나왔다는 것은 괄호 사이의 연산이 최우선이니까 표시해도 된다는 의미구나!!
				printf("%c", top_op);
				top_op = pop(&s); //연산자들을 제거해줌
			}
			break;
		default: // 피연산자
			printf("%c", ch);
			break;
		}
	}
	while (!is_empty(&s)) // 스택에 저장된 연산자들 출력 마지막 남은 연산자 출력
		printf("%c", pop(&s));
}

int main(void)
 {
	char* s = "(2+3)*4+9+1+2-3-5";
	printf("중위표시수식 %s \n", s);
	printf("후위표시수식 ");
	infix_to_postfix(s);
	printf("\n");
	return 0;
}
/*
* stack에 피연산자를 넣고 연산자에 맞게 계산을 수행하는 프로그램
*/