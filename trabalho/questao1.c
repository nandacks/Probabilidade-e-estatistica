#include <stdio.h>

int main() {
    printf("Considere o lançamento de um dado equilibrado, qual a probabilidade de cair a face 3?\n");

    int total_possibilidades = 0;
    int sucessos = 0;

    // loop de exaustão: testa todas as 6 faces do dado
    for (int dado = 1; dado <= 6; dado++) {
        total_possibilidades++;

        if (dado == 3) {
            sucessos++; //quando der um resul igual a 3 acabou, vai ser 1/6
        }
    }

    float probabilidade = (float)sucessos / (float) total_possibilidades;

    printf("Probabilidade: %.2f%%\n", probabilidade * 100);

    return 0;
}
