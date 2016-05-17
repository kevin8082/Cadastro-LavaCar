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
char limpa_n(char a[], int b);
char limpa_char(char a[], int b);

int main() {

    setlocale(LC_ALL, "");
    struct cadastro lavacar[50];
    bool posicao[50] = { false };
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
                rewind(stdin);
                printf("Digite o número do cadastro: ");
                scanf_s("%i", &num);

                if (posicao[num - 1]) {
                    printf("Esta posição já esta ocupada.\n");
                } else if (num > 0 && num <= 50) {

                    posicao[num - 1] = true;
                    rewind(stdin);
                    printf("Digite o nome do cliente: ");
                    fgets(lavacar[num - 1].nome, 20, stdin);
                    limpa_n(lavacar[num - 1].nome, 20);
                    rewind(stdin);
                    printf("Digite o telefone do cliente: ");
                    fgets(lavacar[num - 1].telefone, 13, stdin);
                    limpa_n(lavacar[num - 1].telefone, 13);
                    rewind(stdin);
                    printf("Digite o cpf do cliente: ");
                    fgets(lavacar[num - 1].cpf, 15, stdin);
                    limpa_n(lavacar[num - 1].cpf, 15);
                    for (int i = 0; i < 15; i++) {
                        if (lavacar[num - 1].cpf[i] == ',') {
                            lavacar[num - 1].cpf[i] = '.';
                        }
                    }
                    rewind(stdin);
                    printf("Digite a placa do carro do cliente: ");
                    fgets(lavacar[num - 1].placa, 9, stdin);
                    limpa_n(lavacar[num - 1].placa, 9);
                    rewind(stdin);
                    printf("Digite o serviço prestado: ");
                    fgets(lavacar[num - 1].servico, 20, stdin);
                    limpa_n(lavacar[num - 1].servico, 20);
                    rewind(stdin);
                    printf("Digite o valor total: ");
                    scanf_s("%f", &lavacar[num - 1].valor);
                    printf("Cadastro Criado.\n");

                } else if (num > 50) {
                    printf("O número máximo de cadastros é 50.\n");
                } else {
                    printf("Número inválido, digite um número entre 1 e 50.\n");
                }

                do {
                    printf("Para criar outro cadastro aperte 1 e para sair aperte 2.\n");
                    rewind(stdin);
                    opcao = _getch();
                } while (opcao != '1', opcao != '2');
            } while (opcao != '2');

            break;
            case '2':

            do {
                system("cls");
                printf("Digite o número do cadastro: ");
                scanf_s("%i", &num);

                if ((num > 0 && num <= 50) && posicao[num - 1]) {
                    printf("Nº - Nome - Telefone - CPF - Placa do Carro - Serviço Prestado - Valor Total\n");
                    busca(lavacar[num - 1], num);
                } else if (num > 50) {
                    printf("O número máximo de cadastros é 50.\n");
                } else {
                    printf("Registro Vazio.\n");
                }

                do {
                    printf("Para realizar outra busca aperte 1 e para sair aperte 2.\n");
                    rewind(stdin);
                    opcao = _getch();
                } while (opcao != '1', opcao != '2');
            } while (opcao != '2');

            break;
            case '3':

            do {
                system("cls");
                printf("Nº - Nome - Telefone - CPF - Placa do Carro - Serviço Prestado - Valor Total\n");
                for (int i = 0; i < 50; i++) {
                    if (posicao[i]) {
                        busca(lavacar[i], (i + 1));
                    }
                }

                printf("Aperte qualquer tecla para sair.\n");
                _getch();
                break;
            } while (true);

            break;
            case '4':

            do {
                system("cls");
                printf("Digite o número do cadastro que você deseja deletar: ");
                scanf_s("%i", &num);
                if ((num > 0 && num <= 50) && posicao[num - 1]) {

                    limpa_char(lavacar[num - 1].nome, 20);
                    limpa_char(lavacar[num - 1].telefone, 13);
                    limpa_char(lavacar[num - 1].cpf, 15);
                    limpa_char(lavacar[num - 1].placa, 9);
                    limpa_char(lavacar[num - 1].servico, 20);
                    lavacar[num - 1].valor = 0;
                    posicao[num - 1] = false;
                    printf("Cadastro Deletado.\n");

                } else if (num > 50) {
                    printf("O número máximo de cadastros é 50.\n");
                } else {
                    printf("Cadastro Inválido ou Vazio.\n");
                }

                do {
                    printf("Para deletar outro cadastro aperte 1 e para sair aperte 2.\n");
                    rewind(stdin);
                    opcao = _getch();
                } while (opcao != '1', opcao != '2');
            } while (opcao != '2');

            break;
            case '5':
            return 0;
            break;
        }

    } while (true);
}

void busca(struct cadastro a, int b) {
    printf("%i - %-2s - %-2s - %-2s - %-2s - %-2s - %.2f\n", b, a.nome, a.telefone, a.cpf, a.placa, a.servico, a.valor);
}

char limpa_n(char a[], int b) {
    for (int i = 0; i < b; i++) {
        if (a[i] == '\n') {
            a[i] = '\0';
        }
    }
    return a[b];
}

char limpa_char(char a[], int b) {
    for (int i = 0; i < b; i++) {
        a[i] = '\0';
    }
    return a[b];
}