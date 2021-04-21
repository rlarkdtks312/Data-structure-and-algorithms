#include<stdio.h>
#include<stdlib.h>



//int SUM(int n){
//	int sum =0;
//	while(n >= 0){
//		sum += n;
//		n = n - 1;				
//	}
//	return sum;
//}

int main(){
	int n = 0;
	scanf("%d", &n);

	int result = 0;
	
	while(n >= 0){
		result += n;
		n = n - 1;				
	}	
	//result = SUM(n);

	printf("Result = %d", result);
	
	return 0;	
}
