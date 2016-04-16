#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

struct cadastro {

	char nome[20];
	char telefone[13];
	char cpf[15];
	char placa[9];
	char servico[20];
	float valor;

};

void busca(struct cadastro a, int b);

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

			do {

				system("cls");
				printf("Digite o número do cadastro: ");
				scanf_s("%i", &num);

				if (posicao[num - 1] == true) {

					printf("Esta posição já esta ocupada.\n");

				}
				else {

					posicao[num - 1] = true;
					rewind(stdin);
					printf("Digite o nome do cliente: ");
					fgets(lavacar[num - 1].nome, 20, stdin);

					for (int i = 0; i < 20; i++)
					{
						if (lavacar[num - 1].nome[i] == '\n')
							lavacar[num - 1].nome[i] = '\0';
					}

					rewind(stdin);
					printf("Digite o telefone do cliente: ");
					fgets(lavacar[num - 1].telefone, 13, stdin);

					for (int i = 0; i < 13; i++)
					{
						if (lavacar[num - 1].telefone[i] == '\n')
							lavacar[num - 1].telefone[i] = '\0';
					}

					rewind(stdin);
					printf("Digite o cpf do cliente: ");
					fgets(lavacar[num - 1].cpf, 15, stdin);

					for (int i = 0; i < 15; i++)
					{

						if (lavacar[num - 1].cpf[i] == ',') {
							lavacar[num - 1].cpf[i] = '.';
						}

						if (lavacar[num - 1].cpf[i] == '\n') {
							lavacar[num - 1].cpf[i] = '\0';
						}
					}

					rewind(stdin);
					printf("Digite a placa do carro do cliente: ");
					fgets(lavacar[num - 1].placa, 9, stdin);

					for (int i = 0; i < 9; i++)
					{
						if (lavacar[num - 1].placa[i] == '\n')
							lavacar[num - 1].placa[i] = '\0';
					}

					rewind(stdin);
					printf("Digite o serviço prestado: ");
					fgets(lavacar[num - 1].servico, 20, stdin);

					for (int i = 0; i < 20; i++)
					{
						if (lavacar[num - 1].servico[i] == '\n')
							lavacar[num - 1].servico[i] = '\0';
					}

					rewind(stdin);
					printf("Digite o valor total: ");
					scanf_s("%f", &lavacar[num - 1].valor);

					printf("Cadastro Criado.\n");

					printf("Para criar outro cadastro aperte 1 e para sair aperte 2.\n");
					rewind(stdin);
					opcao = _getch();

					if (opcao == '2') {

						break;

					}

				}

			} while (true);

			break;
		case '2':

			do {

				system("cls");
				printf("Digite o número do cadastro: ");
				scanf_s("%i", &num);

				if (posicao[num - 1] == true) {

					printf("Nº - Nome - Telefone - CPF - Placa do Carro - Serviço Prestado - Valor Total\n");
					busca(lavacar[num - 1], num);

				} else {

					printf("Registro Vazio.\n");

				}

				printf("Para realizar outra busca aperte 1 e para sair aperte 2.\n");
				rewind(stdin);
				opcao = _getch();

				if (opcao == '2') {

					break;

				}

			} while (true);

			break;
		case '3':		

			do {

				system("cls");
				printf("Nº - Nome - Telefone - CPF - Placa do Carro - Serviço Prestado - Valor Total\n");
				for (int i = 0; i < 50; i++) {

					if (posicao[i] == true) {

						busca(lavacar[i], (i + 1));

					}

				}

				printf("Aperte qualquer tecla para sair.\n");
				rewind(stdin);
				opcao = _getch();

				if (opcao != '\n') {

					break;

				}

			} while (true);

			break;
		case '4':
			system("cls");


			break;
		}

		if (opcao == '5') {

			break;

		}

	} while (true);

	return 0;

}

void busca(struct cadastro a, int b) {

	printf("%i - %-2s - %-2s - %-2s - %-2s - %-2s - %.2f\n", b, a.nome, a.telefone, a.cpf, a.placa, a.servico, a.valor);

}