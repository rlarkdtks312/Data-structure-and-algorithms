#include <stdio.h>
#include <stdlib.h>

struct Example {
	int num;
	struct Example* link;
};

void main()
{
	struct Example n1, n2, n3;


	n1.num = 10;
	n1.link = &n2;
	
	n2.num = 20;
	n2.link = &n1;
	
	n3.num = 30;
	n3.link = &n3;
	
	printf("%d \n", n1.link->link->num);

	return 0;
}

/*
* 자신참조형 구조체로 링크드 리스트라고도 한다고 합니다.
* 구조체를 선언 할 때 주소를 담을 수 있는 변수를 선언해서 그 변수(포인터)에 다음 구조체의 주소 값을 넣어서 만듭니다.
* 배열과는 다르게 중간에 값들을 추가하고 제거하는데 유연합니다.
*/