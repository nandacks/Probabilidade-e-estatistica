#include <stdio.h>

int main() {
    printf("Hemofilia e um disturbio genetico associado a um gene pertencente ao cromossomo X. A doenca acomete somente meninos e e transmitido exclusivamente pela mae. Dado o historico familiar de uma mulher, determinou-se que havia 15% de probabilidade de que ela portasse o gene. Suponha que, se a mae for portadora do gene entao cada filho tera, independentemente, 30% de chance de ter a doenca2, e se a mae nao for portadora, o filho nao tera a doenca. Sabendo que esta mulher teve tres filhos sem a doenca, qual e a probabilidade que seja portadora do gene?\n");

    int total_mulheres = 100000;

    // mulheres portam o gene (15.000)
    int portadoras = total_mulheres * 0.15;
    // não portam o gene (85.000)
    int nao_portadoras = total_mulheres * 0.85;

    int portadoras_com_3_saudaveis = 0;
    
    // mae NÃO portadora: 100% dos seus 3 filhos nascem saudáveis
    int nao_portadoras_com_3_saudaveis = nao_portadoras; 

    // mae PORTADORA: a chance dos 3 filhos nascerem saudáveis é 343 a cada 1000 mães 
    int c_portadoras = 0;
    for (int i = 1; i <= portadoras; i++) {
        c_portadoras++;

        // cada 1000 mães portadoras, 343 têm 3 filhos saudáveis
        if (c_portadoras <= 343) {
            portadoras_com_3_saudaveis++;
        }

        // Reseta o ciclo a cada 1000 mães
        if (c_portadoras == 1000) {
            c_portadoras = 0;
        }
    }

    // total de mães com 3 filhos saudáveis
    int total_com_3_saudaveis = portadoras_com_3_saudaveis + nao_portadoras_com_3_saudaveis;

    // P(G|K) portadoras com 3 filhos saudáveis / total de mães com 3 filhos saudáveis
    float prob_final = (float)portadoras_com_3_saudaveis / (float)total_com_3_saudaveis;

    printf("Probabilidade da mãe ser portadora sabendo que teve 3 filhos saudáveis:\n");
    printf("Resultado: %.2f%%\n", prob_final * 100);

    return 0;
}