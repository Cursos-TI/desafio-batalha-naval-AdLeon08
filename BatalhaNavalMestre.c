#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            // Exibição amigável: 0 = Água, 3 = Navio, 5 = Habilidade
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se um navio pode ser posicionado
int podePosicionar(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int x, int y, int dx, int dy) {
    for (int i = 0; i < 3; i++) {
        int nx = x + i * dx;
        int ny = y + i * dy;
        if (nx < 0 || nx >= TAM_TABULEIRO || ny < 0 || ny >= TAM_TABULEIRO)
            return 0; // Fora do tabuleiro
        if (tabuleiro[nx][ny] != 0)
            return 0; // Sobreposição
    }
    return 1;
}

// Função para posicionar o navio
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int x, int y, int dx, int dy) {
    for (int i = 0; i < 3; i++) {
        int nx = x + i * dx;
        int ny = y + i * dy;
        tabuleiro[nx][ny] = 3;
    }
}

// Função para aplicar uma habilidade no tabuleiro com base em uma matriz de efeito
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int matriz[TAM_HABILIDADE][TAM_HABILIDADE], int centroX, int centroY) {
    int offset = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int tabX = centroX + i - offset;
            int tabY = centroY + j - offset;

            if (tabX >= 0 && tabX < TAM_TABULEIRO && tabY >= 0 && tabY < TAM_TABULEIRO) {
                if (matriz[i][j] == 1 && tabuleiro[tabX][tabY] == 0)
                    tabuleiro[tabX][tabY] = 5;
            }
        }
    }
}

// Preenche matriz Cone (formato em pirâmide invertida)
void preencherMatrizCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i >= j - TAM_HABILIDADE/2 && i >= TAM_HABILIDADE/2 - j)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Preenche matriz Cruz (formato "+")
void preencherMatrizCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Preenche matriz Octaedro (formato de losango)
void preencherMatrizOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Posicionamento de navios
    if (podePosicionar(tabuleiro, 0, 0, 0, 1))  // Horizontal
        posicionarNavio(tabuleiro, 0, 0, 0, 1);
    if (podePosicionar(tabuleiro, 2, 2, 1, 0))  // Vertical
        posicionarNavio(tabuleiro, 2, 2, 1, 0);
    if (podePosicionar(tabuleiro, 5, 5, 1, 1))  // Diagonal principal
        posicionarNavio(tabuleiro, 5, 5, 1, 1);
    if (podePosicionar(tabuleiro, 5, 4, 1, -1)) // Diagonal secundária
        posicionarNavio(tabuleiro, 5, 4, 1, -1);

    // Criando matrizes de habilidade
    int habilidadeCone[TAM_HABILIDADE][TAM_HABILIDADE];
    int habilidadeCruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int habilidadeOctaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    preencherMatrizCone(habilidadeCone);
    preencherMatrizCruz(habilidadeCruz);
    preencherMatrizOctaedro(habilidadeOctaedro);

    // Aplicando habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, habilidadeCone, 1, 5);     // Cone no topo centro
    aplicarHabilidade(tabuleiro, habilidadeCruz, 7, 2);     // Cruz na parte inferior esquerda
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, 4, 7); // Octaedro na parte central direita

    // Imprimir resultado final
    imprimirTabuleiro(tabuleiro);

    return 0;
}

