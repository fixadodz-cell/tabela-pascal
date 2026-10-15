#include <stdio.h>

#define MAX_LINHAS 20

int main(void) {
    int triangulo[MAX_LINHAS][MAX_LINHAS] = {0};
    int linhas;

    printf("Quantas linhas deseja exibir? ");
    scanf("%d", &linhas);

    if (linhas < 1 || linhas > MAX_LINHAS) {
        printf("Digite um número entre 1 e %d.\n", MAX_LINHAS);
        return 1;
    }

    for (int i = 0; i < linhas; i++) {
        triangulo[i][0] = 1;
        triangulo[i][i] = 1;

        for (int j = 1; j < i; j++) {
            triangulo[i][j] = triangulo[i - 1][j - 1]
                            + triangulo[i - 1][j];
        }
    }

    for (int i = 0; i < linhas; i++) {
        for (int espacos = 0; espacos < linhas - i - 1; espacos++) {
            printf("   ");
        }

        for (int j = 0; j <= i; j++) {
            printf("%6d", triangulo[i][j]);
        }

        printf("\n");
    }

    return 0;
}