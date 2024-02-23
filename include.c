#include <stdio.h>
#include "init_image.c"

FILE *i_l1;
FILE *l1_l2;
FILE *l2_l3;
FILE *l3_o;

float w_inp_l1[784][1000];
float w_l1_l2[1000][1000];
float w_l2_l3[1000][1000];
float w_l3_out[1000][9];

float inp[1][784];
float l1[1][1000];
float l2[1][1000];
float l3[1][1000];
float out[1][10];

void write_weights() //to store the final weights after training
{
	int i,j;

	i_l1  = fopen("weights/w_inp_l1.txt","wb");
	l1_l2 = fopen("weights/w_l1_l2.txt","wb");
	l2_l3 = fopen("weights/w_l2_l3.txt","wb");
	l3_o  = fopen("weights/w_l3_out.txt","wb");

	for(i=0;i<1000;i++)
	{
		for(j=0;j<1000;j++)
		{
			fprintf(l1_l2,"%f",w_l1_l2[i][j]);
			fprintf(l2_l3,"%f",w_l2_l3[i][j]);
		}
	}

	for(i=0;i<784;i++)
	{
		for(j=0;j<1000;j++)
		{
			fprintf(i_l1,"%f",w_inp_l1[i][j]);
		}
	}

	for(i=0;i<1000;i++)
	{
		for(j=0;j<10;j++)
		{
			fprintf(l3_o,"%f",w_l3_out[i][j]);
		}
	}

	fclose(i_l1);
	fclose(l1_l2);
	fclose(l2_l3);
	fclose(l3_o);
}

void write_first() //to initialize the weights at first iteration
{
	int i,j;

	for(i=0;i<1000;i++)
	{
		for(j=0;j<1000;j++)
		{
			w_l1_l2[i][j] = 0.00f;
			w_l2_l3[i][j] = 0.00f;
		}
	}

	for(i=0;i<784;i++)
	{
		for(j=0;j<1000;j++)
		{
			w_inp_l1[i][j] = 0.00f;
		}
	}

	for(i=0;i<1000;i++)
	{
		for(j=0;j<10;j++)
		{
			w_l3_out[i][j] = 0.00f;
		}
	}

	write_weights();
}

void read_weights() //to read the value of weights from the file and store them in weights array
{
	int i,j;

	i_l1  = fopen("weights/w_inp_l1.txt","rb");
	l1_l2 = fopen("weights/w_l1_l2.txt","rb");
	l2_l3 = fopen("weights/w_l2_l3.txt","rb");
	l3_o  = fopen("weights/w_l3_out.txt","rb");

	if(i_l1 == NULL || l1_l2 == NULL || l2_l3 == NULL || l3_o == NULL)
	{
		write_first();
		return;
	}
		
	for(i=0;i<1000;i++)
	{
		for(j=0;j<1000;j++)
		{
			fscanf(l1_l2,"%f",&w_l1_l2[i][j]);
			fscanf(l2_l3,"%f",&w_l2_l3[i][j]);
		}
	}

	for(i=0;i<784;i++)
	{
		for(j=0;j<1000;j++)
		{
			fscanf(i_l1,"%f",&w_inp_l1[i][j]);
		}
	}

	for(i=0;i<1000;i++)
	{
		for(j=0;j<10;j++)
		{
			fscanf(l3_o,"%f",&w_l3_out[i][j]);
		}
	}

	fclose(i_l1);
	fclose(l1_l2);
	fclose(l2_l3);
	fclose(l3_o);
} 

float relu(float x)
{
	if(x<=0)
	{
		return 0;
	}

	else return x;
}

void start_training()
{
	int i;
	for (i=0; i < 60000; i++)
	{
		init_input_layer_for_train(*inp,i);

	}
}

void backprop()
{
}

void error()
{
}


