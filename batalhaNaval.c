#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para posicionar um navio horizontalmente no tabuleiro
int posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Valida se o navio cabe dentro do tabuleiro
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 0; // Falha no posicionamento
    }
    // Valida se não há sobreposição com outros navios
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] == NAVIO) {
            printf("Erro: Sobreposição de navios detectada na horizontal.\n");
            return 0; // Falha no posicionamento
        }
    }
    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
    return 1; // Sucesso no posicionamento
}

// Função para posicionar um navio verticalmente no tabuleiro
int posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    // Valida se o navio cabe dentro do tabuleiro
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: Navio vertical ultrapassa os limites do tabuleiro.\n");
        return 0; // Falha no posicionamento
    }
    // Valida se não há sobreposição com outros navios
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] == NAVIO) {
            printf("Erro: Sobreposição de navios detectada na vertical.\n");
            return 0; // Falha no posicionamento
        }
    }
    // Posiciona o navio
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
    return 1; // Sucesso no posicionamento
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j); // Imprime os números das colunas
    }
    printf("\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Imprime os números das linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // Declara e inicializa o tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Define as coordenadas iniciais dos navios
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 3;
    int linhaNavioVertical = 6;
    int colunaNavioVertical = 1;

    printf("Posicionando navios...\n\n");

    // Posiciona o navio horizontalmente
    if (posicionarNavioHorizontal(tabuleiro, linhaNavioHorizontal, colunaNavioHorizontal)) {
        printf("Navio horizontal posicionado em (%d, %d).\n", linhaNavioHorizontal, colunaNavioHorizontal);
    }

    // Posiciona o navio verticalmente
    if (posicionarNavioVertical(tabuleiro, linhaNavioVertical, colunaNavioVertical)) {
        printf("Navio vertical posicionado em (%d, %d).\n", linhaNavioVertical, colunaNavioVertical);
    }

    printf("\nTabuleiro com navios posicionados:\n");
    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}