#define _CRT_SECURE_NO_WARNINGS //scanf 에러 해결법
#include<stdio.h>
#include<stdlib.h>
#include <string.h>	//strlen() 사용하기 위해 추가
#define MAX_STACK_SIZE 100					//배열의 크기
#define MAZE_SIZE 6							//미로의 크기

typedef struct { //행렬을 위한 구조체 선언
	short r;
	short c;
} element; 

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
		return;
		//exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s)	//peek 함수 추가
{
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		return;
		//exit(1);
	}
	else return s->data[(s->top)];
}

element here = { 1,0 }, entry = { 1,0 };
char maze[MAZE_SIZE][MAZE_SIZE] = {
{ '1', '1', '1', '1', '1', '1' },
{ 'e', '0', '1', '0', '0', '1' },
{ '1', '0', '0', '0', '1', '1' },
{ '1', '0', '1', '0', '1', '1' },
{ '1', '0', '1', '0', '0', 'x' },	//x -> 1 이면 실패
{ '1', '1', '1', '1', '1', '1' },
};

void push_loc(StackType* s, int r, int c)	//벽이 아니고 지나온 길이 아닌 경우에 stack에 push하는 함수
{
	if (r < 0 || c < 0) return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}
// 미로를 화면에 출력한다. 
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])
{
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}

int main(void)
{
	printf("value = %c\n", maze[1][0]);	//확인용
	int r, c;
	StackType s;
	init_stack(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		maze_print(maze);
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);
		if (is_empty(&s)) {	//모든 방향이 막히거나 다 가본경우
			printf("실패\n");
			return;
		}
		else
			here = pop(&s);
	}
	printf("성공\n");

	return 0;
}
/*
* 미로를 2차원 배열로 구현하고 탈출하는 프로그램
*/