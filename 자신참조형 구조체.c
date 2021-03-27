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