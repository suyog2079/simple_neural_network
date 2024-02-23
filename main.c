#include <stdio.h>
#include "include.c"

void train()
{

}

void run()
{
	int index;
	printf("enter the index you wanna test \n");
	scanf("%d",&index);
}

int main()
{
	int ans;
	int i,j;
	printf("0 to train, 1 to test");
	scanf("%d",&ans);
	if(ans==0)
	{
		train();
	}
	else if(ans == 1)
	{
		run();
	}

}
