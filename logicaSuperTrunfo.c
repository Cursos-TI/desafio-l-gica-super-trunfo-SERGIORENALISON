#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[3];
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;

    float densidadePopulacional;
    float pibPerCapita;
};

int main() {
    // =========================
    // Cadastro da Carta 1
    // =========================
    struct Carta carta1;

    strcpy(carta1.estado, "SP");
    strcpy(carta1.codigo, "A01");
    strcpy(carta1.nomeCidade, "São Paulo");
    carta1.populacao = 12300000;
    carta1.area = 1521.11;
    carta1.pib = 699.28; // em bilhões (exemplo)
    carta1.pontosTuristicos = 20;

    // Cálculos
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao;

    // =========================
    // Cadastro da Carta 2
    // =========================
    struct Carta carta2;

    strcpy(carta2.estado, "RJ");
    strcpy(carta2.codigo, "B02");
    strcpy(carta2.nomeCidade, "Rio de Janeiro");
    carta2.populacao = 6710000;
    carta2.area = 1182.30;
    carta2.pib = 364.00;
    carta2.pontosTuristicos = 15;

    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao;

    // ===============================================
    // Atributo escolhido para comparação: PIB per capita
    // ===============================================

    printf("Comparação de Cartas (Atributo: PIB per capita)\n\n");

    printf("Carta 1 - %s (%s): %.2f\n",
           carta1.nomeCidade, carta1.estado, carta1.pibPerCapita);

    printf("Carta 2 - %s (%s): %.2f\n\n",
           carta2.nomeCidade, carta2.estado, carta2.pibPerCapita);

    // Regra: para PIB per capita, MAIOR valor vence
    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}