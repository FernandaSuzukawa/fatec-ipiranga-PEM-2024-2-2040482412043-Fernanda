/******************************************************************************

Nome: Fernanda Yui Bam Suzukawa
RA: 2040482412043

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int compare(const void *a, const void *b) {
    double diff = (*(double*)a - *(double*)b);
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}

int main() {
    const char *materias[] = {
        "Raciocínio lógico",
        "Conceitos de gerenciamento de projetos",
        "Língua inglesa",
        "Conceitos de metodologia ágil",
        "Linguagem javascript",
    };

    int N = sizeof(materias) / sizeof(materias[0]);
    double notas[10], results[N], resultf = 0;

    for (int i = 0; i < N; i++) {
        results[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        int qtd = 0;
        printf("Matéria: %s\n\n", materias[i]);

        printf("Insira a quantidade de notas (entre 3 e 10): \n");
        while (scanf("%i", &qtd) != 1 || qtd <= 2 || qtd > 10) {
            printf("Número inválido. Insira um valor entre 3 e 10:\n");
            clearInputBuffer();
        }
        
        clearInputBuffer();
        
        printf("Insira as notas (entre 0 e 10):\n");
        for (int j = 0; j < qtd; j++) {
            while (scanf("%lf", &notas[j]) != 1 || notas[j] < 0 || notas[j] > 10) {
                printf("Número inválido. Insira um valor entre 0 e 10:\n");
                clearInputBuffer();
            }
        }

        clearInputBuffer();

        qsort(notas, qtd, sizeof(double), compare);

        for (int j = 1; j < qtd - 1; j++) {
            results[i] += notas[j];
        }

        resultf += results[i];

        printf("\n=================\n\n");
    }

    for (int i = 0; i < N; i++) {
        printf("%s = %.1lf\n", materias[i], results[i]);
    }

    printf("\nNota final do candidato = %.1lf\n", resultf);

    return 0;
}
