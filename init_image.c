#include "mnist.h"

int init_input_layer_for_train(float *inp, int index)
{
    // call to store mnist in array
    load_mnist();

	// print pixels of first data in test dataset
	int i;
	for (i=0; i<784; i++) {
		*((inp+0)+i) = train_image[index][i];
	}
	return train_label[index];
}

int init_input_layer_for_test(float *inp, int index)
{
	load_mnist();

	int i;
	for (i=0; i<784; i++) {
		*((inp+0)+i) = test_image[index][i];	
	}
	return test_label[index];
}
