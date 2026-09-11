#include <stdio.h>

int main() {
    printf("Amostras de vidrarias de laboratorio sao embaladas em pacotes pequenos e leves ou em pacotes grandes e pesados. Suponha que 2% e 1% da amostra despachada em pequenos e grandes pacotes, respectivamente, quebrem durante o transporte. Se 60% das amostras forem despachadas em grandes pacotes e 40% forem despachadas em pequenos pacotes, qual sera aproporcao de amostras que quebrarao durante o transporte?\n");

    int total_amostras = 10000; // quantidade para teste
    int quebradas = 0;

    int pequenos = total_amostras * 0.40; // 4000
    int grandes = total_amostras * 0.60;  // 6000

    // pacotes pequenos (a cada 50)
    int contador_pequenos = 0;
    for (int i = 1; i <= pequenos; i++) {
        contador_pequenos++; // vai contato de um em um

        if (contador_pequenos == 50) {
            quebradas++;         // achou a 50 amostra ele quebra
            contador_pequenos = 0; // zera o contador para contar as próximas 50
        }
    }

    // pacotes grandes (a cada 100) 
    int contador_grandes = 0;
    for (int i = 1; i <= grandes; i++) {
        contador_grandes++;
        if (contador_grandes == 100) {
            quebradas++;        // achou a 100 amostra 
            contador_grandes = 0; // zera o contador para contar as próximas 100
        }
    }

    float proporcao = (float)quebradas / (float)total_amostras;
    printf("Proporção de amostras quebradas: %.2f%%\n", proporcao * 100);

    return 0;
}
