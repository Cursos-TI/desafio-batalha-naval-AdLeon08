#include <stdio.h>

#define TAM 10        // Tamanho do tabuleiro 10x10
#define NAVIO 3       // Valor representando parte de navio
#define TAM_NAVIO 3   // Tamanho fixo dos navios

// Função para verificar se as posições estão livres
int posicao_livre(int tabuleiro[TAM][TAM], int x[], int y[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (tabuleiro[x[i]][y[i]] != 0)
            return 0; // Posição já ocupada
    }
    return 1;
}

// Função para posicionar navio no tabuleiro
void posicionar_navio(int tabuleiro[TAM][TAM], int x[], int y[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabuleiro[x[i]][y[i]] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Inicializa com água (0)

    // NAVIO 1: Horizontal (linha 2, colunas 1 a 3)
    int x1[] = {2, 2, 2};
    int y1[] = {1, 2, 3};

    // NAVIO 2: Vertical (coluna 6, linhas 5 a 7)
    int x2[] = {5, 6, 7};
    int y2[] = {6, 6, 6};

    // NAVIO 3: Diagonal Principal (posição 0,0 até 2,2)
    int x3[] = {0, 1, 2};
    int y3[] = {0, 1, 2};

    // NAVIO 4: Diagonal Secundária (posição 0,9 até 2,7)
    int x4[] = {0, 1, 2};
    int y4[] = {9, 8, 7};

    // Validação e posicionamento dos navios
    if (posicao_livre(tabuleiro, x1, y1, TAM_NAVIO))
        posicionar_navio(tabuleiro, x1, y1, TAM_NAVIO);
    else
        printf("Erro: Sobreposição no navio 1.\n");

    if (posicao_livre(tabuleiro, x2, y2, TAM_NAVIO))
        posicionar_navio(tabuleiro, x2, y2, TAM_NAVIO);
    else
        printf("Erro: Sobreposição no navio 2.\n");

    if (posicao_livre(tabuleiro, x3, y3, TAM_NAVIO))
        posicionar_navio(tabuleiro, x3, y3, TAM_NAVIO);
    else
        printf("Erro: Sobreposição no navio 3 (diagonal principal).\n");

    if (posicao_livre(tabuleiro, x4, y4, TAM_NAVIO))
        posicionar_navio(tabuleiro, x4, y4, TAM_NAVIO);
    else
        printf("Erro: Sobreposição no navio 4 (diagonal secundária).\n");

    // Impressão do tabuleiro
    printf("\n=== Tabuleiro de Batalha Naval (Aventureiro) ===\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}

