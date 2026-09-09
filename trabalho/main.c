#include <stdio.h>

int main() {
    printf("Considere um cojunto de 4 numeros dos quais nenhum deles é zero, dois sã positivos e dois são negativos. Sorteamos ao acaso, com reposição, 2 numeros desse conjunto. Determine a probabilidade de:\n");
    printf("a) Um deles ser negativo?\n");
    printf("b) O quociente entre eles ser negativo?\n");
    printf("c) Os dois números terem o mesmo sinal?\n");

    // Conjunto de 4 números: 2 positivos e 2 negativos
    int conjunto[] = {1, 2, -1, -2};
    int total_elementos = 4;

    int total_possibilidades = 0;
    int sucessos_a = 0;
    int sucessos_b = 0;
    int sucessos_c = 0;

    // Dois loops simulam o sorteio de 2 números COM reposição
    for (int i = 0; i < total_elementos; i++) {
        for (int j = 0; j < total_elementos; j++) {
            total_possibilidades++;

            int n1 = conjunto[i];
            int n2 = conjunto[j];

            // Item a) Exatamente um deles ser negativo
            if ((n1 < 0 && n2 > 0) || (n1 > 0 && n2 < 0)) {
                sucessos_a++;
            }

            // Item b) O quociente (divisão n1 / n2) ser negativo
            // A divisão só é negativa se um for positivo e o outro negativo
            if (((float)n1 / (float)n2) < 0) {
                sucessos_b++;
            }

            // Item c) Os dois números terem o mesmo sinal
            // Ambos positivos OU ambos negativos
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