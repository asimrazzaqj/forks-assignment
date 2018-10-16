#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
//#include<sys/types.h>
int main()
{
	int s2[10];
	int	Arr[1000];
	int arr1[2];
	for(int i=0;i<1000;i++)
	{
		Arr[i]=i;		
	}
	for(int i=0;i<10;i++){
		if(pipe(arr1)==-1)
		{
			printf("no pipe\n");
		}
		int cpid=fork();
		if(cpid==0)
		{
			close(arr1[0]);		
			int sum=0;
			for(int j=i*100;j<i*100+100;j++)
			{
				sum=sum+Arr[j];	
			}
			write(arr1[1],&sum,sizeof(sum));
			close(arr1[1]);	
			exit(0);
		}
		else
		{
			wait(NULL);
			close(arr1[1]);
			s2[i]=0;
			read(arr1[0],&s2[i],sizeof(s2[i]));
		}
	}
	int total=0;
	for(int i=0;i<10;i++)
	{
		total+=s2[i];
	}
	printf("%d\n",total);		
	return 0;
}#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
//#include<sys/types.h>
int main()
{
	int s2[10];
	int	Arr[1000];
	int arr1[2];
	for(int i=0;i<1000;i++)
	{
		Arr[i]=i;		
	}
	for(int i=0;i<10;i++){
		if(pipe(arr1)==-1)
		{
			printf("no pipe\n");
		}
		int cpid=fork();
		if(cpid==0)
		{
			close(arr1[0]);		
			int sum=0;
			for(int j=i*100;j<i*100+100;j++)
			{
				sum=sum+Arr[j];	
			}
			write(arr1[1],&sum,sizeof(sum));
			close(arr1[1]);	
			exit(0);
		}
		else
		{
			wait(NULL);
			close(arr1[1]);
			s2[i]=0;
			read(arr1[0],&s2[i],sizeof(s2[i]));
		}
	}
	int total=0;
	for(int i=0;i<10;i++)
	{
		total+=s2[i];
	}
	printf("%d\n",total);		
	return 0;
}