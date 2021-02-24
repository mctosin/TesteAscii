#include "stdio.h"
#include "stdlib.h"

int main(int argc, char** argv) {
	int i;
	fprintf(stderr, "Entradas da main\n");
	for (i = 1; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
	return 0;
}