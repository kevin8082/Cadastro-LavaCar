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
	int num = 0;

	do {

		system("cls");
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

			system("cls");

			do {

				printf("Digite a posição do cadastro: ");
				scanf_s("%i", &num);

				if (posicao[num - 1] == true) {

					printf("Esta posição já esta ocupada.\n");

				} else {

					posicao[num - 1] = true;
					rewind(stdin);
					printf("Digite o nome do cliente: ");
					fgets(lavacar[num - 1].nome, 50, stdin);
					rewind(stdin);
					printf("Digite o telefone do cliente: ");
					fgets(lavacar[num - 1].telefone, 13, stdin);
					rewind(stdin);
					printf("Digite o cpf do cliente: ");
					fgets(lavacar[num - 1].cpf, 14, stdin);
					rewind(stdin);
					printf("Digite a placa do carro do cliente: ");
					fgets(lavacar[num - 1].placa, 8, stdin);
					rewind(stdin);
					printf("Digite o serviço prestado: ");
					fgets(lavacar[num - 1].servico, 50, stdin);
					rewind(stdin);
					printf("Digite o valor total: ");
					scanf_s("%i", &lavacar[num - 1].valor);
					printf("Cadastro Criado.\n");

					printf("Para criar outro cadastro aperte 1 e para sair digite 2.\n");
					rewind(stdin);
					opcao = _getch();

					if (opcao == '2') {

						break;

					}
				
				}

			} while (true);

			break;
		case '2':
			system("cls");



			break;
		case '3':
			system("cls");



			break;
		case '4':
			system("cls");



			break;		
		}
		
		if (opcao == '5') {

			break;

		}

	} while (true);

	system("pause");
	return 0;

}
