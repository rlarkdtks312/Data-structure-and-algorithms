#define _CRT_SECURE_NO_WARNINGS //scanf ���� �ذ��
#include<stdio.h>
#include<stdlib.h>
#include <string.h>	//strlen() ����ϱ� ���� �߰�

#define MAX_STACK_SIZE 100					//�迭�� ũ��
typedef char element;						//char -> element
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

element peek(StackType* s)	//peek �Լ� �߰�
{
	if (is_empty(s)) {
		printf("���� ���� ����\n");
		return -1;
		//exit(1);
	}
	else return s->data[(s->top)];
}

int prec(char op)	//�������� �켱������ �ű�� �Լ�
{
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

// ���� ǥ�� ���� -> ���� ǥ�� ����
void infix_to_postfix(char exp[])
{
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	StackType s;
	init_stack(&s); // ���� �ʱ�ȭ
	for (i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/': // ������
		// ���ÿ� �ִ� �������� �켱������ �� ũ�ų� ������ ���
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s));
			push(&s, ch);
			break;
		case '(': // ���� ��ȣ
			push(&s, ch);
			break;
		case ')': // ������ ��ȣ
			top_op = pop(&s);
			// ���� ��ȣ�� ���������� ���
			while (top_op != '(') {	//������ ��ȣ�� ���Դٴ� ���� ��ȣ ������ ������ �ֿ켱�̴ϱ� ǥ���ص� �ȴٴ� �ṉ̀���!!
				printf("%c", top_op);
				top_op = pop(&s); //�����ڵ��� ��������
			}
			break;
		default: // �ǿ�����
			printf("%c", ch);
			break;
		}
	}
	while (!is_empty(&s)) // ���ÿ� ����� �����ڵ� ��� ������ ���� ������ ���
		printf("%c", pop(&s));
}

int main(void)
 {
	char* s = "(2+3)*4+9+1+2-3-5";
	printf("����ǥ�ü��� %s \n", s);
	printf("����ǥ�ü��� ");
	infix_to_postfix(s);
	printf("\n");
	return 0;
}
/*
* stack�� �ǿ����ڸ� �ְ� �����ڿ� �°� ����� �����ϴ� ���α׷�
*/