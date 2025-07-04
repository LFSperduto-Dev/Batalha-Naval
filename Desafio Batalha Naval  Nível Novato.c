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
bool posicaoValida(int linha, int coluna, int tamanho, bool vertical, int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Verifica se o navio cabe no tabuleiro a partir da posição inicial
    if (vertical) {
        if (linha + tamanho > TAMANHO_TABULEIRO) return false;
    } else {
        if (coluna + tamanho > TAMANHO_TABULEIRO) return false;
    }
    
    // Verifica se todas as posições estão livres (valor 0)
    for (int i = 0; i < tamanho; i++) {
        if (vertical) {
            if (tabuleiro[linha + i][coluna] != 0) return false;
        } else {
            if (tabuleiro[linha][coluna + i] != 0) return false;
        }
    }
    
    return true;
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int tamanho, bool vertical) {
    for (int i = 0; i < tamanho; i++) {
        if (vertical) {
            tabuleiro[linha + i][coluna] = 3;
        } else {
            tabuleiro[linha][coluna + i] = 3;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro de Batalha Naval:\n");
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
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
    
    // Posicionamento do navio horizontal (linha 2, coluna 3)
    int linha_horizontal = 2;
    int coluna_horizontal = 3;
    bool horizontal_valido = posicaoValida(linha_horizontal, coluna_horizontal, TAMANHO_NAVIO, false, tabuleiro);
    
    if (horizontal_valido) {
        posicionarNavio(tabuleiro, linha_horizontal, coluna_horizontal, TAMANHO_NAVIO, false);
        printf("Navio horizontal posicionado com sucesso!\n");
    } else {
        printf("Posicao invalida para navio horizontal! Escolha outras coordenadas.\n");
        return 1;
    }
    
    // Posicionamento do navio vertical (linha 5, coluna 7)
    int linha_vertical = 5;
    int coluna_vertical = 7;
    bool vertical_valido = posicaoValida(linha_vertical, coluna_vertical, TAMANHO_NAVIO, true, tabuleiro);
    
    if (vertical_valido) {
        posicionarNavio(tabuleiro, linha_vertical, coluna_vertical, TAMANHO_NAVIO, true);
        printf("Navio vertical posicionado com sucesso!\n");
    } else {
        printf("Posicao invalida para navio vertical! Escolha outras coordenadas.\n");
        return 1;
    }
    
    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);
    
    return 0;
}