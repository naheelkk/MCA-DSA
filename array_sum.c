#include <stdio.h>
int main(){
	int range, sum = 0, arr[range];
	printf("Enter the range of numbers you want to get sum of\n");
	scanf("%d",&range);
	for(int i = 0; i < range; i++){
		printf("Enter Element No. %d ",i + 1);
		scanf("%d",&arr[i]);
	}	
	for(int i = 0; i < range; i++)
		sum = arr[i] + sum;
		
	printf("Sum of %d numbers  is %d\n",range, sum);
	return 0;
}
