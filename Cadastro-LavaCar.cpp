#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

struct cadastro {

	char nome[50];
	char telefone[13];
	char cpf[14];
	char placa[8];
	char servico[50];
	float valor;

};

int main() {

	setlocale(LC_ALL, "");

	struct cadastro lavacar[50];
	bool posicao[50];
	char opcao;

	do {

		printf("Escolha sua opção:\n");
		printf("1 para novo cadastro\n");
		printf("2 para busca de cadastro\n");
		printf("3 para a listagem de cadastros\n");
		printf("4 para remover um cadastro\n");
		printf("5 para sair\n");
		rewind(stdin);
		opcao = _getch();

		switch (opcao) {
		case '1':



			break;
		case '2':



			break;
		case '3':



			break;
		case '4':



			break;
		}

		if (opcao == '5') {

			break;

		}

	} while (true);

	system("pause");
	return 0;
}
