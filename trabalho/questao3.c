#include <stdio.h>

int main() {
    printf("Uma caixa contem bolas, indistinguıveis ao tato, numeradas de 1 a 20. As bolas numeradas de 1 a 10 tem cor verde, e as numeradas de 11 a 20 tem cor amarela. Considere o experimento que consiste em retirar sucessivamente, duas bolas da caixa, nao repondo a primeira bola retirada, e em seguida registar a cor das bolas retiradas. a.) Determine a probabilidade das duas bolas retiradas da caixa terem cores diferentes. b.) No mesmo experimento considere os acontecimentos: A: A primeira bola e verde. B: A segunda bola retirada e amarela. C: O numero da segunda bola e par. Calcule P ((B ∩ C)|A)\n");

    int total_bolas = 20;

    int total_possibilidades = 0;
    int sucessos_a = 0;

    int total_evento_A = 0; // vezes que a 1ª bola foi verde
    int sucessos_b = 0;     // quantas vezes (B e C) aconteceram dentro do evento A

    // dois loops simulam a retirada de 2 bolas SEM reposição (i != j)
    for (int i = 1; i <= total_bolas; i++) {
        for (int j = 1; j <= total_bolas; j++) {
            
            // não reposição: a mesma bola não pode ser pega duas vezes
            if (i != j) {
                total_possibilidades++;

                int bola1 = i;
                int bola2 = j;

                // definindo as cores: 1 a 10 verde, 11 a 20 amarela
                // 1 = verde, 0 = amarela
                int bola1_verde = (bola1 <= 10);
                int bola2_verde = (bola2 <= 10);

                // A) Duas bolas de cores diferentes
                if (bola1_verde != bola2_verde) {
                    sucessos_a++;
                }

                // B) P((B n C) | A)
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

    float prob_a = (float)sucessos_a / (float) total_possibilidades;
    // sucessos de (B n C) divididos pelo total do evento A
    float prob_b = (float)sucessos_b / (float) total_evento_A;

    printf("a) Probabilidade de cores diferentes: %.2f%%\n", prob_a * 100);
    printf("b) P((B n C) | A): %.2f%%\n", prob_b * 100);

    return 0;
}
