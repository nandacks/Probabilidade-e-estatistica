#include <stdio.h>

int main() {
    printf("\n|------------------------|\n");
    printf("|------ Questão 174 -----|\n");
    printf("|------------------------|\n\n");

    int total_bolas = 20;

    int total_possibilidades = 0;
    int sucessos_a = 0;

    int total_evento_A = 0; // Quantas vezes a 1ª bola foi verde
    int sucessos_b = 0;     // Quantas vezes (B e C) aconteceram dentro do evento A

    // Dois loops simulam a retirada de 2 bolas SEM reposição (i != j)
    for (int i = 1; i <= total_bolas; i++) {
        for (int j = 1; j <= total_bolas; j++) {
            
            // Não reposição: a mesma bola não pode ser pega duas vezes
            if (i != j) {
                total_possibilidades++;

                int bola1 = i;
                int bola2 = j;

                // Definindo as cores: 1 a 10 verde, 11 a 20 amarela
                // 1 = verde, 0 = amarela
                int bola1_verde = (bola1 <= 10);
                int bola2_verde = (bola2 <= 10);

                // Item a) Duas bolas de cores diferentes
                if (bola1_verde != bola2_verde) {
                    sucessos_a++;
                }

                // Item b) P((B n C) | A)
                // A: primeira bola é verde
                if (bola1_verde) {
                    total_evento_A++;

                    int bola2_amarela = (bola2 > 10);
                    int bola2_par = (bola2 % 2 == 0);

                    // B: segunda é amarela E C: segunda é par
                    if (bola2_amarela && bola2_par) {
                        sucessos_b++;
                    }
                }
            }
        }
    }

    float prob_a = (float)sucessos_a / total_possibilidades;
    
    // Probabilidade condicional: sucessos de (B n C) divididos pelo total do evento A
    float prob_b = (float)sucessos_b / total_evento_A;

    printf("a) Probabilidade de cores diferentes: %.4f (ou %.2f%%)\n", prob_a, prob_a * 100);
    printf("b) P((B n C) | A): %.4f (ou %.2f%%)\n", prob_b, prob_b * 100);

    return 0;
}
