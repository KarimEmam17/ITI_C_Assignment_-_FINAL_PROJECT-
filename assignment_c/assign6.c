 #include <stdio.h>
void main (){
	int arr[10] , max =0 , min =99;
	for (int i =0; i<10; i++)
	{
		printf("enter number %d ",i+1);
		scanf("%d",&arr[i]);
		if (max<arr[i])
			max = arr[i];
	    if (arr[i]<min)
			min = arr[i];
	}
	printf("the maximum = %d \n", max);
	printf("the minimum = %d  \n", min);
	
}