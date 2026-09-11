#include <stdio.h>

int main() {
    printf("Considere um cojunto de 4 numeros dos quais nenhum deles e zero, dois sao positivos e dois sao negativos. Sorteamos ao acaso, com reposicao, 2 numeros desse conjunto. Determine a probabilidade de: a.) Um deles ser negativo. b.) O quociente entre eles ser negativo. c.) Os dois numeros terem o mesmo sinal.\n");

    // Conjunto de 4 números (2 positivos e 2 negativos)
    int conjunto[] = {1, 2, -1, -2};
    int total_elementos = 4;

    int total_possibilidades = 0;
    int sucessos_a = 0;
    int sucessos_b = 0;
    int sucessos_c = 0;

    // dois loops simulam o sorteio de 2 números COM reposição
    for (int i = 0; i < total_elementos; i++) {
        for (int j = 0; j < total_elementos; j++) {
            total_possibilidades++;

            int n1 = conjunto[i];
            int n2 = conjunto[j];

            // A) Exatamente um deles ser negativo
            if ((n1 < 0 && n2 > 0) || (n1 > 0 && n2 < 0)) {
                sucessos_a++;
            }

            // B) O quociente (divisão n1 / n2) ser negativo
            // a divisão só é negativa se um for positivo e o outro negativo
            if (((float)n1 / (float)n2) < 0) {
                sucessos_b++;
            }

            // C) Os dois números terem o mesmo sinal
            // ambos positivos OU ambos negativos
            if ((n1 > 0 && n2 > 0) || (n1 < 0 && n2 < 0)) {
                sucessos_c++;
            }
        }
    }

    float prob_a = (float)sucessos_a / (float)total_possibilidades;
    float prob_b = (float)sucessos_b / (float)total_possibilidades;
    float prob_c = (float)sucessos_c / (float)total_possibilidades;

    printf("a) Probabilidade de um ser negativo: %.2f%%\n", prob_a * 100);
    printf("b) Probabilidade do quociente ser negativo: %.2f%%\n", prob_b * 100);
    printf("c) Probabilidade de terem o mesmo sinal: %.2f%%\n", prob_c * 100);

    return 0;
}
