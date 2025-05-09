#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Estrutura da carta
typedef struct {
    char nome[50];
    int forca;
    int velocidade;
    int inteligencia;
} Carta;

// Função para mostrar os dados da carta
void mostrarCarta(Carta c) {
    printf("\nCarta: %s\n", c.nome);
    printf("For\x87a: %d\n", c.forca);
    printf("Velocidade: %d\n", c.velocidade);
    printf("Intelig\x8ancia: %d\n", c.inteligencia);
}

// Compara os atributos escolhidos
int compararAtributo(Carta c1, Carta c2, int atributo) {
    switch(atributo) {
        case 1: return c1.forca - c2.forca;
        case 2: return c1.velocidade - c2.velocidade;
        case 3: return c1.inteligencia - c2.inteligencia;
        default: return 0;
    }
}

int main() {
    srand(time(NULL));

    // Lista de cartas
    Carta baralho[] = {
        {"Drag\x8ao", 90, 60, 70},
        {"F\x82nix", 85, 65, 80},
        {"Grifo", 75, 80, 60},
        {"Minotauro", 88, 50, 55},
        {"Hidra", 92, 40, 85}
    };
    int totalCartas = sizeof(baralho) / sizeof(Carta);

    // Sorteia cartas diferentes para jogador e oponente
    int iJogador = rand() % totalCartas;
    int iOponente;
    do {
        iOponente = rand() % totalCartas;
    } while (iOponente == iJogador);

    Carta jogador = baralho[iJogador];
    Carta oponente = baralho[iOponente];

    printf("=== Sua Carta ===");
    mostrarCarta(jogador);

    printf("\nEscolha um atributo para jogar:\n");
    printf("1 - For\x87a\n");
    printf("2 - Velocidade\n");
    printf("3 - Intelig\x8ancia\n");
    int escolha;
    scanf("%d", &escolha);

    int resultado = compararAtributo(jogador, oponente, escolha);

    printf("\n=== Carta do Oponente ===");
    mostrarCarta(oponente);

    printf("\n=== Resultado ===\n");
    if (resultado > 0)
        printf("Voc\x8a venceu!\n");
    else if (resultado < 0)
        printf("Voc\x8a perdeu!\n");
    else
        printf("Empate!\n");

    return 0;
}
