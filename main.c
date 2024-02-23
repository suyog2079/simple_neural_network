#include <stdio.h>
#include "include.c"

#define n 10

float w1[n][n];
float w2[n][n];
float w3[n][n];
int neuron[n];

void train()
{
	init_weights(n,*w1,*w2,*w3);
	print_matrix(n,*w1,*w2,*w3);	
//	write_weights(n,*w1,*w2,*w3);
}

void run()
{
	int index;
	printf("enter the index you wanna test \n");
	scanf("%d",&index);
	init_weights(n,*w1,*w2,*w3);
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
