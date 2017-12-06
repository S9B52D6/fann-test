#include <stdio.h>
#include <stdlib.h>
#include "fann.h"

int main() {
	const unsigned int num_input = 2;
	const unsigned int num_output = 1;
	const unsigned int num_layers = 4;
	const unsigned int num_neurons = 12;
	const float desired_error = (const float) 0.0001;
	const unsigned int max_epochs = 50000;
	const unsigned int epochs_between_reports = 1000;

	struct fann *ann = fann_create_standard(num_layers, num_input, num_neurons, num_neurons, num_output);
	fann_set_activation_function_hidden(ann, FANN_GAUSSIAN);
	fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);
	
	fann_train_on_file(ann, "training_data.fann", max_epochs, epochs_between_reports, desired_error);
	fann_save(ann, "test.net");
	
	fann_destroy(ann);
	return 0;
}
