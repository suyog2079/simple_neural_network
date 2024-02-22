#include <stdio.h>

FILE *w1p;
FILE *w2p;
FILE *w3p;

void write_weights(int n, float *w1,float *w2, float *w3) //to store the final weights after training
{
	w1p = fopen("weights/w1.txt","w");
	w2p = fopen("weights/w2.txt","w");
	w3p = fopen("weights/w3.txt","w");
	int i,j;

	if(w1 == NULL || w2 == NULL || w3 == NULL || w1p == NULL || w2p == NULL || w3p == NULL) return;

	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			fwrite(((w1+i)+j), sizeof(1.00f), 1, w1p);
			fwrite(((w2+i)+j), sizeof(1.00f), 1, w2p);
			fwrite(((w3+i)+j), sizeof(1.00f), 1, w3p);
		}
	}
	fclose(w1p);
	fclose(w2p);
	fclose(w3p);
}

void write(int n, float *w1, float *w2, float *w3) //to initialize the weights at first iteration
{
	int i,j;
	//	printf("in write ");
	if(w1 == NULL || w2 == NULL || w3 == NULL)
	{
		printf("null");
		return;
	}

	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			*((w1+i)+j) = 5.0f;
			*((w2+i)+j) = 2.0f;
			*((w3+i)+j) = 3.0f;
		}
	}
	write_weights(n,w1,w2,w3);
}

void init_weights(int n, float *w1,float *w2, float *w3) //to read the value of weights from the file and store them in weights array
{
	int i,j;

	w1p = fopen("weights/w1.txt","r");
	w2p = fopen("weights/w2.txt","r");
	w3p = fopen("weights/w3.txt","r");

	if(w1p == NULL || w2p == NULL || w3p == NULL)
	{
		write(n,w1,w2,w3);
		printf("nulllllllllllllllllllllllllllllllllllllll \n ");
		return;
	}
		
	for(i=0; i<n ; i++) {
		for (j=0; j<n ; j++) {
			fread(((w1+i)+j), sizeof(1.00f), 1, w1p);
			fread(((w1+i)+j), sizeof(1.00f), 1, w1p);
			fread(((w1+i)+j), sizeof(1.00f), 1, w1p);
		}	
		printf("\n");
	}

	fclose(w1p);
	fclose(w2p);
	fclose(w3p);
}

void print_matrix(int n, float *w1,float *w2, float *w3)
{
	if(w1 == NULL || w2 == NULL || w3 == NULL) return;

	int i,j;
	printf("here is w1: \n");
	
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			printf("%f \t ", *((w1+i)+j));
		}
		printf("\n");
	}

	printf("here is w2: \n");
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			printf("%f \t ", *((w2+i)+j));
		}
		printf("\n");
	}	

	printf("here is w3: \n");
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			printf("%f \t ", *((w3+i)+j));
		}
		printf("\n");
	}
}
