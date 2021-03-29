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

int check_matching(const char* in)	//문자열의 주소값을 받아서 검사에 사용
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in); // n= 문자열의 길이
	init_stack(&s); // 스택의 초기화
	for (i = 0; i < n; i++) {
		ch = in[i]; // ch = 다음 문자
		switch (ch) {
		case '(': case '[': case '{':
			push(&s, ch);
			break;
		case ')': case ']': case '}':
			if (is_empty(&s)) return 0;
			else {
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '[' && ch != ']') ||
					(open_ch == '{' && ch != '}')) {
					return 0;	//괄호들을 열었는데 안 닫았으면 에러!!
				}
				break;
			}
		}
	}
	if (!is_empty(&s)) return 0; // 스택에 남아있으면 오류
	return 1;	//성공!
}

int main(void)
{
	char* p = "{ A[(i+1)]=0; }";
	if (check_matching(p) == 1)
		printf("%s 괄호검사성공\n", p);
	else
		printf("%s 괄호검사실패\n", p);

	char* p2 = "{ A[(i+1)]=0; }}";
	if (check_matching(p2) == 1)
		printf("%s 괄호검사성공\n", p2);
	else
		printf("%s 괄호검사실패\n", p2);

	return 0;
}

/*
* 구조체 배열을 사용하여 stack을 구현하였다.
*/