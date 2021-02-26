#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int main(int argc, char* argv[]) {
	int i;
	fprintf(stderr, "Entradas da main\n");
	fprintf(stderr, "argv[0] = \"%s\"\n", argv[0]);
	for (i = 1; i < argc; i++) {
		fprintf(stderr, "%s\n", argv[i]);
	}
	fprintf(stderr, "\n");
	
	FILE* cfPtr;
	char carct;
	int caract_num = 0;
	static char* a_string_ptr;

	// Abre um arquivo texto para leitura, 
	// cujo nome está em argv[1].
	// Copia o texto do arquivo para a string a_string_ptr, 
	// criada dinamicamente.
	// Fecha o arquivo.
	
	if ((cfPtr = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "File could not be opened\n");

	}
	else {
		fseek(cfPtr, 0, SEEK_END);
		int len_of_file = ftell(cfPtr);
		rewind(cfPtr);

		a_string_ptr = (char*)malloc(len_of_file);

		do {
			carct = fgetc(cfPtr);
			a_string_ptr[caract_num] = carct;
			fprintf(stderr, "%c", a_string_ptr[caract_num]);
			caract_num++;
		} while (!feof(cfPtr));
		a_string_ptr[caract_num] = '\0';
		fprintf(stderr, "\n");
	}

	fclose(cfPtr);

	// Não modifique o código acima

	// --- Instruções do Programa ---
	// O ponteiro a_string_prt aponta para a string que foi impressa na tela.
	// Neste exercício você deve fazer um programa para determinar:
	// a) A quantidade de caracteres há na string, excluindo o fim de string ('\0').
	// b) O tamanho da string em bytes
	// c) A quantidade de dígitos representados na string (0..9)
	// d) A quantidade de letras representados na string
	// e) A quantidade de letras maiúsculas na string
	// f) A quantidade de letras minúsculas na string
	// g) A quantidade de espaços em branco na string
	// h) A quantidade de caracteres de controle
	// i) A quantidade de caracteres que representam pontuação
	// j) A quantidade de caracteres que são imprimíveis na tela (aqueles visíveis na tela),
	//	  incluindo espaço em branco
	// Você pode usar, entre outras, as funções ilustradas no livro texto 
	// (Deitel, C How to Program, 8th ed., Cap.8 - Fig.8.1), definidas em ctype.h
	// A documentação das funções pode ser encontrada em:
	// https://docs.microsoft.com/pt-br/cpp/c-runtime-library/character-classification?view=msvc-160

	// Faça seu código aqui

	int k, val_carct;
	unsigned int output[10] = { 0 };
	
	output[0] = strlen(a_string_ptr);
	output[1] = output[0] + 1;

	for (k = 0; a_string_ptr[k] != '\0'; k++) {
		if (a_string_ptr[k] != EOF) {
			val_carct = (unsigned char)a_string_ptr[k];
		}
		else {
			val_carct = a_string_ptr[k];
		}
		if (isdigit(val_carct)) output[2]++;
		if (isalpha(val_carct)) output[3]++;
		if (isupper(val_carct)) output[4]++;
		if (islower(val_carct)) output[5]++;
		if (val_carct  ==  ' ') output[6]++;
		if (iscntrl(val_carct)) output[7]++;
		if (ispunct(val_carct)) output[8]++;
		if (isprint(val_carct)) output[9]++;
	}

	// --- Saída dos resultados ---
	// Os valores dos itens de (a) até (j) devem ser impressos em decimal, cada qual
	// separado por UM espaço em branco.
	// Após o último valor (item j) deve ser impresso um pula linha ('\n'),
	// ou seja, não tem espaço.

	// Faça seu código para a saída dos resultados aqui

	for (k = 0; k < 10; k++) {
		printf((k < 9 ? "%d " : "%d\n"), output[k]);
	}

	// Não modifique o código abaixo

	return 0;
}
