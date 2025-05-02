#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

int main() {
    // Declaração da matriz do tabuleiro 10x10, inicializada com água (0)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios (definidas manualmente no código)
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 1;

    // Posicionando navio horizontal
    if (coluna_horizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = NAVIO;
        }
    } else {
        printf("Erro: o navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Posicionando navio vertical
    if (linha_vertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            // Verifica se já existe um navio nessa posição
            if (tabuleiro[linha_vertical + i][coluna_vertical] == NAVIO) {
                printf("Erro: sobreposição de navios na posição (%d, %d).\n",
                       linha_vertical + i, coluna_vertical);
                return 1;
            }
            tabuleiro[linha_vertical + i][coluna_vertical] = NAVIO;
        }
    } else {
        printf("Erro: o navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // Impressão do tabuleiro
    printf("=== Tabuleiro de Batalha Naval ===\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Impressão das coordenadas dos navios
    printf("\nCoordenadas do Navio Horizontal (tamanho 3):\n");
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        printf("(%d, %d)\n", linha_horizontal, coluna_horizontal + i);
    }

    printf("\nCoordenadas do Navio Vertical (tamanho 3):\n");
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        printf("(%d, %d)\n", linha_vertical + i, coluna_vertical);
    }

    return 0;
}

