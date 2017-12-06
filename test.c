#include <stdio.h>
#include <math.h>
#include "floatfann.h"

int main() {
	fann_type *calc_out;
	fann_type input[2];

	struct fann *ann = fann_create_from_file("test.net");

	fann_type input_a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	fann_type input_b[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	const int INPUT_A_LENGTH = 11;
	const int INPUT_B_LENGTH = 11;

	for(int i = 0; i < INPUT_A_LENGTH; i++) {
		for(int j = 0; j < INPUT_B_LENGTH; j++) {
			input[0] = input_a[i];
			input[1] = input_b[j];
			calc_out = fann_run(ann, input);
			printf("[%f, %f] => %f\n", input[0], input[1], calc_out[0]);
		}
	}

	fann_destroy(ann);
	return 0;
}
