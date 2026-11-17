#include <stdio.h>

int main(void) {
    float preco_etanol, preco_gasolina;

    printf("Por favor digite o preço de 1L de ETANOL: ");
    scanf("%f", &preco_etanol);

    printf("\nPor favor digite o preço de 1L de GASOLINA: ");
    scanf("%f", &preco_gasolina);

    if (preco_etanol > preco_gasolina * 0.7f) {
        printf("\nCompre GASOLINA pois o ETANOL custa mais de 70%% do preço da GASOLINA.\n");
    } else {
        printf("\nCompre ETANOL pois o ETANOL não custa mais de 70%% do preço da GASOLINA.\n");
    }

    return 0;
}
