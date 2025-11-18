#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para uso de exit()

// Estrutura para representar uma carta do Super Trunfo (País)
typedef struct {
    char nome_pais[50];
    char codigo_carta[5];
    int populacao;          // Em milhões de habitantes
    float area;             // Em milhares de km²
    float pib;              // Em trilhões de R$
    int pontos_turisticos;
    float densidade_demografica; // Calculado
} CartaSuperTrunfo;

// Array de nomes dos atributos para exibição
const char *ATRIBUTOS_NOMES[] = {
    "", // Índice 0 não usado para corresponder às opções do menu (1-5)
    "População (Milhões)",
    "Área (Milhares de km²)",
    "PIB (Trilhões de R$)",
    "Pontos Turísticos",
    "Densidade Demográfica (VENCE O MENOR)"
};

/**
 * @brief Função para calcular a densidade demográfica.
 * @param carta Ponteiro para a struct CartaSuperTrunfo a ser atualizada.
 */
void calcular_atributos_derivados(CartaSuperTrunfo *carta) {
    if (carta->area > 0) {
        carta->densidade_demografica = (float)carta->populacao / carta->area;
    } else {
        carta->densidade_demografica = 0.0;
    }
}

/**
 * @brief Retorna o valor de um atributo específico da carta.
 * @param carta A carta a ser inspecionada.
 * @param opcao O índice do atributo (1-5) conforme o menu.
 * @return O valor float do atributo.
 */
float get_valor_atributo(CartaSuperTrunfo carta, int opcao) {
    switch (opcao) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontos_turisticos;
        case 5: return carta.densidade_demografica;
        default: return 0.0; // Opção inválida
    }
}

/**
 * @brief Exibe o menu dinâmico de escolha de atributos.
 * @param atributo_ja_escolhido O índice do atributo já selecionado (0 se for a primeira escolha).
 */
void exibir_menu_dinamico(int atributo_ja_escolhido) {
    printf("\nOpcoes de Atributo:\n");
    for (int i = 1; i <= 5; i++) {
        // Verifica se o atributo atual é o que já foi escolhido
        if (i != atributo_ja_escolhido) {
            printf("%d - %s\n", i, ATRIBUTOS_NOMES[i]);
        }
    }
}

/**
 * @brief Função principal para execução do desafio.
 */
int main() {
    // 1. DADOS DAS CARTAS (Países) - Reutilização do desafio anterior
    
    // Carta 1: Brasil
    CartaSuperTrunfo carta1;
    strcpy(carta1.nome_pais, "Brasil");
    strcpy(carta1.codigo_carta, "A001");
    carta1.populacao = 214; 
    carta1.area = 8516;     
    carta1.pib = 1.6;       
    carta1.pontos_turisticos = 40;

    // Carta 2: Alemanha
    CartaSuperTrunfo carta2;
    strcpy(carta2.nome_pais, "Alemanha");
    strcpy(carta2.codigo_carta, "A002");
    carta2.populacao = 84;   
    carta2.area = 357;      
    carta2.pib = 4.4;       
    carta2.pontos_turisticos = 25;

    // 2. CÁLCULO DE ATRIBUTOS DERIVADOS
    calcular_atributos_derivados(&carta1);
    calcular_atributos_derivados(&carta2);
    
    int escolha1 = 0;
    int escolha2 = 0;
    
    printf("==========================================\n");
    printf("   SUPER TRUNFO - DESAFIO NIVEL MESTRE\n");
    printf("------------------------------------------\n");
    printf("Comparando: **Carta 1 (%s)** vs **Carta 2 (%s)**\n", carta1.nome_pais, carta2.nome_pais);
    printf("==========================================\n");

    // 3. ESCOLHA DO PRIMEIRO ATRIBUTO (Menu Dinâmico - Escolha 1)
    exibir_menu_dinamico(0); // 0 indica que nenhum atributo foi escolhido ainda
    printf("Digite a **primeira** escolha (1-5): ");
    if (scanf("%d", &escolha1) != 1 || escolha1 < 1 || escolha1 > 5) {
        printf("\nErro: Entrada invalida para o primeiro atributo. Encerrando.\n");
        return 1;
    }

    // 4. ESCOLHA DO SEGUNDO ATRIBUTO (Menu Dinâmico - Escolha 2)
    exibir_menu_dinamico(escolha1); // Passa a primeira escolha para removê-la do menu
    printf("Digite a **segunda** escolha (1-5): ");
    if (scanf("%d", &escolha2) != 1 || escolha2 < 1 || escolha2 > 5) {
        printf("\nErro: Entrada invalida para o segundo atributo. Encerrando.\n");
        return 1;
    }

    // 5. TRATAMENTO DE CONFLITO: Garante que os atributos são diferentes
    if (escolha1 == escolha2) {
        printf("\nErro: Os dois atributos escolhidos devem ser diferentes. Encerrando.\n");
        return 1;
    }

    // 6. OBTENÇÃO DOS VALORES E REGRAS
    float v1_a1 = get_valor_atributo(carta1, escolha1);
    float v2_a1 = get_valor_atributo(carta2, escolha1);
    float v1_a2 = get_valor_atributo(carta1, escolha2);
    float v2_a2 = get_valor_atributo(carta2, escolha2);
    
    // As regras de vitória são fixas: Densidade (5) vence o menor, os outros vencem o maior.
    int maior_vence_a1 = (escolha1 == 5) ? 0 : 1; // Operador Ternário
    int maior_vence_a2 = (escolha2 == 5) ? 0 : 1; // Operador Ternário

    // 7. CÁLCULO DA SOMA DOS ATRIBUTOS
    float soma_c1 = v1_a1 + v1_a2;
    float soma_c2 = v2_a1 + v2_a2;

    // 8. EXIBIÇÃO E DETERMINAÇÃO DO VENCEDOR (Baseado na Soma)
    printf("\n==========================================\n");
    printf("     RESULTADO DA COMPARACAO AVANCADA\n");
    printf("==========================================\n");

    // Exibição Detalhada
    printf("\n--- Atributo 1: %s ---\n", ATRIBUTOS_NOMES[escolha1]);
    printf("Carta 1 (%s): %.2f\n", carta1.nome_pais, v1_a1);
    printf("Carta 2 (%s): %.2f\n", carta2.nome_pais, v2_a1);

    printf("\n--- Atributo 2: %s ---\n", ATRIBUTOS_NOMES[escolha2]);
    printf("Carta 1 (%s): %.2f\n", carta1.nome_pais, v1_a2);
    printf("Carta 2 (%s): %.2f\n", carta2.nome_pais, v2_a2);

    printf("\n--- Soma Total ---\n");
    printf("Soma Carta 1 (%s): %.2f\n", carta1.nome_pais, soma_c1);
    printf("Soma Carta 2 (%s): %.2f\n", carta2.nome_pais, soma_c2);
    printf("------------------\n");

    // Lógica Final de Vitória (baseada na soma total)
    if (soma_c1 > soma_c2) {
        printf("VENCEDOR: **Carta 1 (%s)** - A soma dos atributos foi maior! (%.2f > %.2f)\n", 
               carta1.nome_pais, soma_c1, soma_c2);
    } else if (soma_c2 > soma_c1) {
        printf("VENCEDOR: **Carta 2 (%s)** - A soma dos atributos foi maior! (%.2f > %.2f)\n", 
               carta2.nome_pais, soma_c2, soma_c1);
    } else {
        printf("**Resultado: Empate!** - A soma dos atributos é igual (%.2f)\n", soma_c1);
    }
    printf("==========================================\n");

    // Nota: O programa não compara o 'ganhador individual' do atributo, 
    // apenas a soma total, conforme o requisito do nível mestre.

    return 0;
}