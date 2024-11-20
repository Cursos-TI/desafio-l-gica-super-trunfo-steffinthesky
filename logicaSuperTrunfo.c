#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50], codigo[4];
    int populacao, pontosTuristicos;
    float area, pib, densidadePopulacional, pibPerCapita;
} Pais;

void cadastrarPais(Pais* pais);
void calcularPropriedades(Pais* pais);
int compararAtributo(Pais* p1, Pais* p2, int atributo);
void compararCartas(Pais* p1, Pais* p2, int atributo1, int atributo2);
void exibirPais(Pais* pais);
void menuComparacao(Pais* p1, Pais* p2);

int main() {
    Pais* p1 = malloc(sizeof(Pais));
    Pais* p2 = malloc(sizeof(Pais));

    printf("--- Cadastro do País 1 ---\n");
    cadastrarPais(p1);
    calcularPropriedades(p1);

    printf("\n--- Cadastro do País 2 ---\n");
    cadastrarPais(p2);
    calcularPropriedades(p2);

    printf("\n--- Dados dos Países ---\n");
    exibirPais(p1);
    exibirPais(p2);

    menuComparacao(p1, p2);

    free(p1);
    free(p2);
    return 0;
}

void cadastrarPais(Pais* pais) {
    printf("Digite o Nome do País: ");
    scanf(" %[^\n]s", pais->nome);
    printf("Digite o Código da Carta: ");
    scanf("%s", pais->codigo);
    printf("Digite a População: ");
    scanf("%d", &pais->populacao);
    printf("Digite a Área (em km²): ");
    scanf("%f", &pais->area);
    printf("Digite o PIB (em trilhões): ");
    scanf("%f", &pais->pib);
    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pais->pontosTuristicos);
}

void calcularPropriedades(Pais* pais) {
    pais->densidadePopulacional = pais->populacao / pais->area;
    pais->pibPerCapita = pais->pib / pais->populacao * 1000000000;
}

void exibirPais(Pais* pais) {
    printf("\nNome: %s\n", pais->nome);
    printf("Código: %s\n", pais->codigo);
    printf("População: %d\n", pais->populacao);
    printf("Área: %.2f km²\n", pais->area);
    printf("PIB: %.2f trilhões de reais\n", pais->pib);
    printf("Densidade Populacional: %.2f pessoas/km²\n", pais->densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", pais->pibPerCapita);
    printf("Pontos Turísticos: %d\n", pais->pontosTuristicos);
}

int compararAtributo(Pais* p1, Pais* p2, int atributo) {
    float valores1[] = {p1->populacao, p1->area, p1->pib, p1->densidadePopulacional, p1->pibPerCapita, p1->pontosTuristicos};
    float valores2[] = {p2->populacao, p2->area, p2->pib, p2->densidadePopulacional, p2->pibPerCapita, p2->pontosTuristicos};

    if (atributo == 3) {
        return (valores1[atributo] < valores2[atributo]) ? 1 : (valores1[atributo] > valores2[atributo]) ? -1 : 0;
    } else {
        return (valores1[atributo] > valores2[atributo]) ? 1 : (valores1[atributo] < valores2[atributo]) ? -1 : 0;
    }
}

void compararCartas(Pais* p1, Pais* p2, int atributo1, int atributo2) {
    int pontosP1 = 0, pontosP2 = 0;

    printf("\n--- Comparação de Atributos ---\n");

    int resultado1 = compararAtributo(p1, p2, atributo1);
    if (resultado1 > 0) {
        printf("Atributo 1: %s venceu no atributo escolhido!\n", p1->nome);
        pontosP1++;
    } else if (resultado1 < 0) {
        printf("Atributo 1: %s venceu no atributo escolhido!\n", p2->nome);
        pontosP2++;
    } else {
        printf("Atributo 1: Empate!\n");
    }

    int resultado2 = compararAtributo(p1, p2, atributo2);
    if (resultado2 > 0) {
        printf("Atributo 2: %s venceu no atributo escolhido!\n", p1->nome);
        pontosP1++;
    } else if (resultado2 < 0) {
        printf("Atributo 2: %s venceu no atributo escolhido!\n", p2->nome);
        pontosP2++;
    } else {
        printf("Atributo 2: Empate!\n");
    }

    printf("\n--- Resultado Final ---\n");
    if (pontosP1 > pontosP2) {
        printf("A Carta Vencedora é: %s!\n", p1->nome);
    } else if (pontosP1 < pontosP2) {
        printf("A Carta Vencedora é: %s!\n", p2->nome);
    } else {
        printf("O Resultado Final é: Empate!\n");
    }
}

void menuComparacao(Pais* p1, Pais* p2) {
    int atributo1, atributo2;
    printf("\n--- Menu de Comparação ---\n");
    printf("Escolha dois atributos para comparar:\n");
    printf("0 - População\n");
    printf("1 - Área\n");
    printf("2 - PIB\n");
    printf("3 - Densidade Populacional\n");
    printf("4 - PIB per Capita\n");
    printf("5 - Pontos Turísticos\n");
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atributo1);
    printf("Escolha o segundo atributo: ");
    scanf("%d", &atributo2);

    compararCartas(p1, p2, atributo1, atributo2);
}
