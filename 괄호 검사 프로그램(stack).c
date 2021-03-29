#define _CRT_SECURE_NO_WARNINGS //scanf 에러 해결법
#include<stdio.h>
#include<stdlib.h>

int check_matching(const char* in)
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
					return 0;
				}
				break;
			}
		}
	}
	if (!is_empty(&s)) return 0; // 스택에 남아있으면 오류
	return 1;
}

int main(void)
{
	char* p = "{ A[(i+1)]=0; }";
	if (check_matching(p) == 1)
		printf("%s 괄호검사성공\n", p);
	else
		printf("%s 괄호검사실패\n", p);
	return 0;
}

/*
* 구조체 배열을 사용하여 stack을 구현하였다.
*/