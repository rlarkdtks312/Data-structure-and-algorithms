#define _CRT_SECURE_NO_WARNINGS //scanf ���� �ذ��
#include<stdio.h>
#include<stdlib.h>

#define MAX_STACK_SIZE 100					//�迭�� ũ��
typedef int element;						//int -> element
typedef struct {							//����ü ����
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s)
{
	s->top = -1;
}
// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

// �����Լ�
void push(StackType* s, element item)
{
	if (is_full(s)) {
		printf("���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		printf("���� ���� ����\n");
		return -1;
		//exit(1);
	}
	else return s->data[(s->top)--];
}

int check_matching(const char* in)	//���ڿ��� �ּҰ��� �޾Ƽ� �˻翡 ���
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in); // n= ���ڿ��� ����
	init_stack(&s); // ������ �ʱ�ȭ
	for (i = 0; i < n; i++) {
		ch = in[i]; // ch = ���� ����
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
					return 0;	//��ȣ���� �����µ� �� �ݾ����� ����!!
				}
				break;
			}
		}
	}
	if (!is_empty(&s)) return 0; // ���ÿ� ���������� ����
	return 1;	//����!
}

int main(void)
{
	char* p = "{ A[(i+1)]=0; }";
	if (check_matching(p) == 1)
		printf("%s ��ȣ�˻缺��\n", p);
	else
		printf("%s ��ȣ�˻����\n", p);

	char* p2 = "{ A[(i+1)]=0; }}";
	if (check_matching(p2) == 1)
		printf("%s ��ȣ�˻缺��\n", p2);
	else
		printf("%s ��ȣ�˻����\n", p2);

	return 0;
}

/*
* ����ü �迭�� ����Ͽ� stack�� �����Ͽ���.
*/