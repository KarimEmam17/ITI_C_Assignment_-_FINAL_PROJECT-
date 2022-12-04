#include<stdio.h>
void max_min(int *ptr,int* arr);
int main()
{
/*	
// sorting  algorithm
int arr[10],max=0 ;
int size =sizeof(arr)/sizeof(int);
for (int i=0;i<10;i++)
{
printf("enter  elment  %d\n",i+1);
scanf("%d",&arr[i]);
}
for(int i =0; i<size;i++)
{
	for (int j=i+1;j<size;j++)
	if (arr[i]<arr[j])
	{
		int temp =arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
	}
}


for (int i=0;i<10;i++)
{
printf("enter  elment  %d ,is =%d\n",i,arr[i]);

}
	*/
//char arr_3[]="notfound";
/*
int arr[10],arr_2[11],searching,count=0,index=1;
for(int i=0;i<10;i++) 
{
	printf("enter the elemnt %d\n",i+1);
	scanf("%d",&arr[i]);
}
printf("enter the searching num \n");
scanf("%d",&searching);
for(int i=0;i<10;i++) 
{
	if(arr[i]==searching)
	{
		//arr_3[0]=' ';
		//arr_3[1]=' ';
		//arr_3[2]=' ';
		
		arr_2[0]=count;
		count++;
		arr_2[index]= i+1;
		index++;
	}
}
for (int i=0;i<index;i++)
{
	if(i==0)
	{
	printf("it appers %d  times \n",count);
	}
	else
	printf("the index %d\n",arr_2[i]);
	
	
}
	
*/
/*
int arr[10],first=0,last=sizeof(arr)/sizeof(int),mid=((first+last)/2),req;
for(int i=0;i<10;i++)
{
printf("enter element\n");
scanf("%d",&arr[i]);
}
for(int i=0;i<10;i++)
{
	for(int j=i+1;j<10;j++)
	{
		if(arr[i]>arr[j])
		{
		int temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		}
	}
}
printf("enter searching num \n");
scanf("%d",&req);
printf("mid %d\n",mid);

while(arr[mid]!=req && mid!=first && (mid!=last-1))
{
	if (arr[mid]<req)
	{
		first=mid;
		mid=((first+last)/2);
		
	}
	else if (arr[mid]>req);
	{
		last=mid;
		mid=((first+last)/2);
	}
	
}
//printf("the e =%d",arr[mid]);
printf("the index =%d",mid);
*/
int arr[10],ptr[2];
for (int i=0 ;  i<10; i++)
{
	printf("enter element  \n");
	scanf("%d",&arr[i]);
}

 max_min(arr,ptr);
	printf("the max %d the min %d \n",ptr[0],ptr[1]);
return 0;
}



void  max_min(int *ptr,int *arr)
{
	for (int i=0; i<10;i++)
	{
		for (int j=i+1; i<10;i++)
			{
				if(ptr[i]<ptr[j])
				{
					int temp=ptr[i];
					ptr[i]=ptr[j];
					ptr[j]=temp;
				}
			}
	}
	int  themax, themin=themax,mid;
	themax =-ptr[0]+ptr[10];
	themin=themax;
	for (int i=0;i<10;i++)
	{
		if((ptr[i]-ptr[i+1])<themin)
		{
			themin=(ptr[i]-ptr[i+1]);
		}
	}
	
	arr[0]=themax;
	arr[1]=themin;
	
	
	
	
}