#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo (País/Estado)
typedef struct {
    char nome_pais[50];
    char codigo_carta[5];
    int populacao;          // Em milhões de habitantes (int para simplificação)
    float area;             // Em milhares de km² (float)
    float pib;              // Em trilhões de R$ (float)
    int pontos_turisticos;
    float densidade_demografica; // Calculado: Populacao / Area
} CartaSuperTrunfo;

/**
 * @brief Função para calcular a densidade demográfica.
 * @param carta Ponteiro para a struct CartaSuperTrunfo a ser atualizada.
 */
void calcular_atributos_derivados(CartaSuperTrunfo *carta) {
    // Cálculo da Densidade Demográfica (População / Área)
    // As unidades são simplificadas (Milhões / Milhares) mas a proporção é mantida.
    if (carta->area > 0) {
        carta->densidade_demografica = (float)carta->populacao / carta->area;
    } else {
        carta->densidade_demografica = 0.0;
    }
    // NOTA: O PIB per capita não foi incluído no menu, então não é recalculado aqui.
}

/**
 * @brief Função que implementa a lógica de comparação principal usando if-else aninhados.
 * @param carta1 Dados da primeira carta.
 * @param carta2 Dados da segunda carta.
 * @param atributo_valor1 O valor do atributo escolhido para a Carta 1.
 * @param atributo_valor2 O valor do atributo escolhido para a Carta 2.
 * @param maior_valor_vence Regra de comparação: 1 se maior valor vence, 0 se menor valor vence.
 * @param nome_atributo Nome do atributo sendo comparado.
 */
void comparar_cartas(CartaSuperTrunfo carta1, CartaSuperTrunfo carta2, float atributo_valor1, float atributo_valor2, int maior_valor_vence, const char *nome_atributo) {
    
    printf("\n--- Comparacao de Cartas ---\n");
    printf("Atributo: **%s**\n", nome_atributo);
    printf("Carta 1 (%s): %.2f\n", carta1.nome_pais, atributo_valor1);
    printf("Carta 2 (%s): %.2f\n", carta2.nome_pais, atributo_valor2);
    printf("----------------------------\n");
    
    // Início da lógica com estruturas de decisão aninhadas
    if (maior_valor_vence) {
        // Bloco principal: Se o MAIOR valor vence (População, Área, PIB, Pontos Turísticos)
        if (atributo_valor1 > atributo_valor2) {
            printf("Resultado: **Carta 1 (%s) VENCEU!**\n", carta1.nome_pais);
        } else if (atributo_valor2 > atributo_valor1) {
            printf("Resultado: **Carta 2 (%s) VENCEU!**\n", carta2.nome_pais);
        } else {
            printf("Resultado: **Empate!**\n");
        }
    } else {
        // Bloco secundário (aninhado): Se o MENOR valor vence (Densidade Demográfica)
        if (atributo_valor1 < atributo_valor2) {
            printf("Resultado: **Carta 1 (%s) VENCEU!**\n", carta1.nome_pais);
        } else if (atributo_valor2 < atributo_valor1) {
            printf("Resultado: **Carta 2 (%s) VENCEU!**\n", carta2.nome_pais);
        } else {
            printf("Resultado: **Empate!**\n");
        }
    }
    printf("----------------------------\n");
}


/**
 * @brief Função principal para execução do desafio.
 */
int main() {
    // 1. DADOS DAS CARTAS (Países)
    // As cartas são pré-definidas no código (simplificação do nível).
    
    // Carta 1: Brasil
    CartaSuperTrunfo carta1;
    strcpy(carta1.nome_pais, "Brasil");
    strcpy(carta1.codigo_carta, "A001");
    carta1.populacao = 214;       // Aprox. 214 milhões
    carta1.area = 8516;           // Aprox. 8.516 mil km²
    carta1.pib = 1.6;             // Aprox. 1.6 trilhões de R$
    carta1.pontos_turisticos = 40;

    // Carta 2: Alemanha
    CartaSuperTrunfo carta2;
    strcpy(carta2.nome_pais, "Alemanha");
    strcpy(carta2.codigo_carta, "A002");
    carta2.populacao = 84;        // Aprox. 84 milhões
    carta2.area = 357;            // Aprox. 357 mil km²
    carta2.pib = 4.4;             // Aprox. 4.4 trilhões de R$
    carta2.pontos_turisticos = 25;

    // 2. CÁLCULO DE ATRIBUTOS DERIVADOS
    calcular_atributos_derivados(&carta1);
    calcular_atributos_derivados(&carta2);
    
    int escolha = 0;
    
    printf("==========================================\n");
    printf("   SUPER TRUNFO - DESAFIO NIVEL AVENTUREIRO\n");
    printf("------------------------------------------\n");
    printf("Comparando: **Carta 1 (%s)** vs **Carta 2 (%s)**\n", carta1.nome_pais, carta2.nome_pais);
    printf("==========================================\n");

    // 3. MENU INTERATIVO
    printf("\nEscolha o atributo para a comparacao:\n");
    printf("1 - População (Milhoes)\n");
    printf("2 - Área (Milhares de km²)\n");
    printf("3 - PIB (Trilhões de R$)\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica (VENCE O MENOR VALOR)\n");
    printf("------------------------------------------\n");
    printf("Digite sua escolha (1-5): ");
    
    // Leitura da escolha do usuário
    if (scanf("%d", &escolha) != 1) {
        printf("\nErro: Entrada invalida. Por favor, digite um numero.\n");
        return 1; // Encerra com erro
    }

    // Variáveis para armazenar o atributo escolhido e a regra de vitória
    float valor1 = 0.0;
    float valor2 = 0.0;
    const char *nome_atributo;
    int maior_valor_vence = 1; // 1 = Vence o maior valor (padrão)

    // 4. ESTRUTURA SWITCH PARA TRATAR A ESCOLHA DO USUÁRIO
    switch (escolha) {
        case 1:
            nome_atributo = "População";
            valor1 = (float)carta1.populacao;
            valor2 = (float)carta2.populacao;
            maior_valor_vence = 1;
            break;
        case 2:
            nome_atributo = "Área";
            valor1 = carta1.area;
            valor2 = carta2.area;
            maior_valor_vence = 1;
            break;
        case 3:
            nome_atributo = "PIB";
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            maior_valor_vence = 1;
            break;
        case 4:
            nome_atributo = "Pontos Turísticos";
            valor1 = (float)carta1.pontos_turisticos;
            valor2 = (float)carta2.pontos_turisticos;
            maior_valor_vence = 1;
            break;
        case 5:
            nome_atributo = "Densidade Demográfica";
            valor1 = carta1.densidade_demografica;
            valor2 = carta2.densidade_demografica;
            maior_valor_vence = 0; // REVERSÃO DA REGRA: Vence o menor valor
            break;
        default:
            printf("\nOpcao invalida! Por favor, escolha um numero de 1 a 5.\n");
            return 1; // Encerra com erro de opção
    }

    // 5. CHAMADA DA FUNÇÃO DE COMPARAÇÃO
    // A função utiliza o atributo escolhido e a regra de vitória (maior_valor_vence)
    // para determinar o vencedor usando a lógica if-else aninhada.
    comparar_cartas(carta1, carta2, valor1, valor2, maior_valor_vence, nome_atributo);

    return 0;
}