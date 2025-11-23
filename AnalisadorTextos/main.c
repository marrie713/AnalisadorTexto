#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define MAX 100

int contarVogais(char frase[]) {
    int contador = 0;

    for (int i = 0; frase[i] != '\0'; i++) {
        char c = tolower(frase[i]);
        if (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u') {
            contador++;
        }
    }

    return contador;
}

int contarConsoantes(char frase[]) {
    int contador = 0;

    for (int i = 0; frase[i] != '\0'; i++) {
        if (isalpha(frase[i])) {
            char c = tolower(frase[i]);
            if (c != 'a' && c != 'e' && c != 'i' &&
                c != 'o' && c != 'u') {
                contador++;
            }
        }
    }

    return contador;
}

void paraMaiusculas(char frase[]) {
    for (int i = 0; frase[i] != '\0'; i++) {
        frase[i] = toupper(frase[i]);
    }
}

void paraMinusculas(char frase[]) {
    for (int i = 0; frase[i] != '\0'; i++) {
        frase[i] = tolower(frase[i]);
    }
}

int main() {

    setlocale(LC_ALL, "Portuguese_Brazil");

    char frase[MAX];
    int opcao;
    int continuar = 1;

    while (continuar) {

        printf("\nDigite uma frase de até 100 caracteres: ");
        fgets(frase, MAX, stdin);

        frase[strcspn(frase, "\n")] = '\0';

        do {
            printf("=====<3 MENU <3=====\n");
            printf("1 - Contar vogais\n");
            printf("2 - Contar consoantes\n");
            printf("3 - Converter para MAIUSCULAS\n");
            printf("4 - Converter para minusculas\n");
            printf("5 - Digitar outra frase\n");
            printf("6 - Encerrar\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

            getchar();

            switch (opcao) {
                case 1:
                    printf("\nNumero de vogais: %d\n", contarVogais(frase));
                    break;

                case 2:
                    printf("\nNumero de consoantes: %d\n", contarConsoantes(frase));
                    break;

                case 3:
                    paraMaiusculas(frase);
                    printf("\nFrase em MAIUSCULAS: %s\n", frase);
                    break;

                case 4:
                    paraMinusculas(frase);
                    printf("\nFrase em minusculas: %s\n", frase);
                    break;

                case 5:
                    break;

                case 6:
                    printf("\nEncerrando o programa...\n");
                    continuar = 0;
                    break;

                default:
                    printf("\nOpcao invalida!\n");
            }

        } while (opcao != 5 && opcao != 6);
    }

    return 0;
}

// '\0' caractere nulo e ele marca o final da string na memória.
// ctype.h verifica se a letra está no alfabeto
