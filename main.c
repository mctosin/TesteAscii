#include "stdio.h"
#include "stdlib.h"

int main(int argc, char* argv[]) {
	int i;
	fprintf(stderr, "Entradas da main\n");
	fprintf(stderr, "argv[0] = \"%s\"\n", argv[0]);
	for (i = 1; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
	char mystring[] = "O \"Ze galinha\" tem 25 anos\n";
	fprintf(stderr, "%s", mystring);
	return 0;
}
