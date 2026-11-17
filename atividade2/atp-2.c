#include <stdio.h>
#include <stdlib.h>

int menu(void) {
    int tipo_cliente;

    do {
        system("clear");
        printf(" --------------------------------------- \n");
        printf(" - TIPO DE CLIENTE                     - \n");
        printf(" - 1) Motorista de Aplicativo          - \n");
        printf(" - 2) Frota de Carros                  - \n");
        printf(" - 3) Cliente Comum                    - \n");
        printf(" --------------------------------------- \n");
        printf(" - Digite uma das opcoes validas 1|2|3 -\n");
        printf(" --------------------------------------- \n");

        printf("Digite o tipo de cliente: ");
        scanf("%d", &tipo_cliente);

    } while (tipo_cliente < 1 || tipo_cliente > 3);

    return tipo_cliente;
}

float calcular_valor(float quantidade, float preco, float desconto) {
    float preco_total = preco * quantidade;

    if (quantidade >= 30.0f) {
        preco_total = preco_total * (1.0f - desconto);
    }

    return preco_total;
}

void mostrar(const char *tipo_cliente, float desconto,
             float preco_alcool, float quantidade_alcool, float valor_alcool,
             float preco_gasolina, float quantidade_gasolina, float valor_gasolina) {
    float preco_alcool_aplicado = preco_alcool;
    float preco_gasolina_aplicado = preco_gasolina;

    if (quantidade_alcool > 0.0f) {
        preco_alcool_aplicado = valor_alcool / quantidade_alcool;
    }
    if (quantidade_gasolina > 0.0f) {
        preco_gasolina_aplicado = valor_gasolina / quantidade_gasolina;
    }

    printf("\nTipo de cliente: %s\n", tipo_cliente);
    printf("Desconto: %.0f%% (abastecimento de 30 litros ou mais)\n", desconto * 100);

    printf("\n ------------------- Valores sem desconto ------------------ \n");
    printf("\nAlcool sem desconto:   R$ %.2f/L | total: R$ %.2f\n",
       preco_alcool, preco_alcool * quantidade_alcool);

    printf("Gasolina sem desconto: R$ %.2f/L | total: R$ %.2f\n",
       preco_gasolina, preco_gasolina * quantidade_gasolina);

    printf("\n ------------------- Valores com desconto ------------------ \n");
    if (quantidade_alcool >= 30) {
        printf("Alcool com desconto: (preço por litro)R$ %.2f | total: R$ %.2f\n", valor_alcool / quantidade_alcool, valor_alcool);
    } else {
        printf("Alcool sem desconto por a quantidade minima de 30 litros nao ter sido atingida.\n");
    }

    if (quantidade_gasolina >= 30) {
        printf("Gasolina com desconto: (preço por litro)R$ %.2f | total: R$ %.2f\n", valor_gasolina / quantidade_gasolina, valor_gasolina);
    } else {
        printf("Gasolina sem desconto por a quantidade minima de 30 litros nao ter sido atingida.\n");
    }

    printf("\n ------------------- Valor total a pagar ------------------ \n");
    printf("%.2f litros de alcool   * %.2f = (%.2f)\n", quantidade_alcool, preco_alcool_aplicado, valor_alcool);
    printf("%.2f litros de gasolina * %.2f = (%.2f)\n", quantidade_gasolina, preco_gasolina_aplicado, valor_gasolina);

    printf("\nValor sem desconto: \033[9mR$ %.2f\033[0m\n",
       (quantidade_alcool * preco_alcool) +
       (quantidade_gasolina * preco_gasolina));

    printf("\nValor total a pagar: R$ %.2f\n",
           valor_alcool + valor_gasolina);
}

int main(void) {
    float preco_alcool, preco_gasolina;
    float desconto;
    float quantidade_alcool, quantidade_gasolina;
    float valor_alcool, valor_gasolina;
    int tipo_cliente;
    const char *tipo_cliente_str;
    system("clear");

    printf("Digite o preco do Alcool (R$/L):   ");
    scanf("%f", &preco_alcool);

    printf("Digite o preco da Gasolina (R$/L): ");
    scanf("%f", &preco_gasolina);

    tipo_cliente = menu();

    switch (tipo_cliente) {
        case 1:
            desconto = 0.06f;
            tipo_cliente_str = "Motorista de Aplicativo";
            break;

        case 2:
            desconto = 0.05f;
            tipo_cliente_str = "Frota de Carros";
            break;

        case 3:
            desconto = 0.03f;
            tipo_cliente_str = "Cliente Comum";
            break;

        default:
            desconto = 0.0f;
            tipo_cliente_str = "Desconhecido";
            break;
    }
    printf("Digite a quantidade de litros de alcool:   ");
    scanf("%f", &quantidade_alcool);
    printf("Digite a quantidade de litros de gasolina: ");
    scanf("%f", &quantidade_gasolina);

    system("clear");

    valor_alcool = calcular_valor(quantidade_alcool, preco_alcool, desconto);
    valor_gasolina = calcular_valor(quantidade_gasolina, preco_gasolina, desconto);

    mostrar(tipo_cliente_str, desconto,
            preco_alcool, quantidade_alcool, valor_alcool,
            preco_gasolina, quantidade_gasolina, valor_gasolina);

    return 0;
}
