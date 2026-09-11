#include <stdio.h>

int main() {
    printf("Uma companhia monta radios cujas pecas sao produzidas em tres de suas fbricas denominadas A1, A2 e A3. Elas produzem, respecti- vamente, 15%, 35% e 50% do total. As probabilides das fabricas A1, A2 e A3 produzirem pecas defeituosas sao 1%; 5% e 2%, respectivamente. Uma peca e escolhida ao acaso do con- junto das pecas produzidas. Essa peca e testada e verifica-se que e defeituosa. Qual e a probabilidade que tenha sido produzida pela fabrica Ai, para i = 1, 2, 3?\n");

    int total_pecas = 10000;

    //  peças por fábrica (15% 35%  50%)
    int total_A1 = total_pecas * 0.15; // 1500 peças
    int total_A2 = total_pecas * 0.35; // 3500 peças
    int total_A3 = total_pecas * 0.50; // 5000 peças

    int defeituosas_A1 = 0;
    int defeituosas_A2 = 0;
    int defeituosas_A3 = 0;

    // fabrica A1 1% defeito = 1 a cada 100
    int c1 = 0;
    for (int i = 1; i <= total_A1; i++) {
        c1++;
        if (c1 == 100) {
            defeituosas_A1++;
            c1 = 0;
        }
    }

    // A2 5% defeito = 1 a cada 20
    int c2 = 0;
    for (int i = 1; i <= total_A2; i++) {
        c2++;
        if (c2 == 20) {
            defeituosas_A2++;
            c2 = 0;
        }
    }

    // Fábrica A3 (2% defeito = 1 a cada 50
    int c3 = 0;
    for (int i = 1; i <= total_A3; i++) {
        c3++;
        if (c3 == 50) {
            defeituosas_A3++;
            c3 = 0;
        }
    }

    // total são as peças com defeito
    int total_defeituosas = defeituosas_A1 + defeituosas_A2 + defeituosas_A3;

    // cheance ter vindo de cada fábrica
    float prob_A1 = (float)defeituosas_A1 / (float)total_defeituosas;
    float prob_A2 = (float)defeituosas_A2 / (float)total_defeituosas;
    float prob_A3 = (float)defeituosas_A3 / (float)total_defeituosas;

    printf("Sabendo que a peça é defeituosa:\n");
    printf("Probabilidade de ser da fábrica A1: %.2f%\n", prob_A1 * 100);
    printf("Probabilidade de ser da fábrica A2: %.2f%\n", prob_A2 * 100);
    printf("Probabilidade de ser da fábrica A3: %.2f%\n", prob_A3 * 100);

    return 0;
}