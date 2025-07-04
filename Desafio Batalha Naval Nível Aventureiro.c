#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para inicializar o tabuleiro com 0s (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se uma posição é válida para colocar um navio
bool posicaoValida(int linha, int coluna, int tamanho, int direcao, int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Direções:
    // 0 - horizontal
    // 1 - vertical
    // 2 - diagonal principal (linha e coluna aumentam)
    // 3 - diagonal secundária (linha aumenta, coluna diminui)
    
    // Verifica se o navio cabe no tabuleiro a partir da posição inicial
    switch (direcao) {
        case 0: // horizontal
            if (coluna + tamanho > TAMANHO_TABULEIRO) return false;
            break;
        case 1: // vertical
            if (linha + tamanho > TAMANHO_TABULEIRO) return false;
            break;
        case 2: // diagonal principal
            if (linha + tamanho > TAMANHO_TABULEIRO || coluna + tamanho > TAMANHO_TABULEIRO) return false;
            break;
        case 3: // diagonal secundária
            if (linha + tamanho > TAMANHO_TABULEIRO || coluna - tamanho + 1 < 0) return false;
            break;
        default:
            return false;
    }
    
    // Verifica se todas as posições estão livres (valor 0)
    for (int i = 0; i < tamanho; i++) {
        switch (direcao) {
            case 0: // horizontal
                if (tabuleiro[linha][coluna + i] != 0) return false;
                break;
            case 1: // vertical
                if (tabuleiro[linha + i][coluna] != 0) return false;
                break;
            case 2: // diagonal principal
                if (tabuleiro[linha + i][coluna + i] != 0) return false;
                break;
            case 3: // diagonal secundária
                if (tabuleiro[linha + i][coluna - i] != 0) return false;
                break;
        }
    }
    
    return true;
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, int direcao) {
    for (int i = 0; i < tamanho; i++) {
        switch (direcao) {
            case 0: // horizontal
                tabuleiro[linha][coluna + i] = 3;
                break;
            case 1: // vertical
                tabuleiro[linha + i][coluna] = 3;
                break;
            case 2: // diagonal principal
                tabuleiro[linha + i][coluna + i] = 3;
                break;
            case 3: // diagonal secundária
                tabuleiro[linha + i][coluna - i] = 3;
                break;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro de Batalha Naval:\n");
    printf("   0 1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializa o tabuleiro com água (0s)
    inicializarTabuleiro(tabuleiro);
    
    printf("Posicionando navios no tabuleiro...\n");
    
    // Navio 1: Horizontal (linha 2, coluna 3)
    int linha1 = 2, coluna1 = 3;
    if (posicaoValida(linha1, coluna1, TAMANHO_NAVIO, 0, tabuleiro)) {
        posicionarNavio(tabuleiro, linha1, coluna1, TAMANHO_NAVIO, 0);
        printf("Navio horizontal posicionado em (%d,%d)\n", linha1, coluna1);
    } else {
        printf("Erro: Posicao invalida para navio horizontal em (%d,%d)\n", linha1, coluna1);
        return 1;
    }
    
    // Navio 2: Vertical (linha 5, coluna 7)
    int linha2 = 5, coluna2 = 7;
    if (posicaoValida(linha2, coluna2, TAMANHO_NAVIO, 1, tabuleiro)) {
        posicionarNavio(tabuleiro, linha2, coluna2, TAMANHO_NAVIO, 1);
        printf("Navio vertical posicionado em (%d,%d)\n", linha2, coluna2);
    } else {
        printf("Erro: Posicao invalida para navio vertical em (%d,%d)\n", linha2, coluna2);
        return 1;
    }
    
    // Navio 3: Diagonal principal (linha 1, coluna 1)
    int linha3 = 1, coluna3 = 1;
    if (posicaoValida(linha3, coluna3, TAMANHO_NAVIO, 2, tabuleiro)) {
        posicionarNavio(tabuleiro, linha3, coluna3, TAMANHO_NAVIO, 2);
        printf("Navio diagonal principal posicionado em (%d,%d)\n", linha3, coluna3);
    } else {
        printf("Erro: Posicao invalida para navio diagonal principal em (%d,%d)\n", linha3, coluna3);
        return 1;
    }
    
    // Navio 4: Diagonal secundária (linha 2, coluna 8)
    int linha4 = 2, coluna4 = 8;
    if (posicaoValida(linha4, coluna4, TAMANHO_NAVIO, 3, tabuleiro)) {
        posicionarNavio(tabuleiro, linha4, coluna4, TAMANHO_NAVIO, 3);
        printf("Navio diagonal secundaria posicionado em (%d,%d)\n", linha4, coluna4);
    } else {
        printf("Erro: Posicao invalida para navio diagonal secundaria em (%d,%d)\n", linha4, coluna4);
        return 1;
    }
    
    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);
    
    return 0;
}