#include "cifras.h"

// Cifra de Cesar

void cifrar_Cesar(char *texto, int tamanho, int chave) {
    int i;
    for (i = 0; i < tamanho; i++) {
        texto[i] = (texto[i] + chave) % 256;
    }
}

void cifrar_Vernam_Mauborgne(char *texto, int tamanho, char *chave) {
    int i;
    for (i = 0; i < tamanho; i++) {
        texto[i] = (texto[i] + chave[i]) % 256;
    }
}
void cifrar_Rail_Fence(char *texto, int tamanho, uint32_t chave)  {
    int linhas = chave;
    int colunas = tamanho;
    int direcao = 1;
    int i, j, k;

    // Aloca a matriz rail fence
    char **matriz = (char**) malloc(linhas * sizeof(char*));
    for (i = 0; i < linhas; i++) {
        matriz[i] = (char*) malloc(colunas * sizeof(char));
    }

    // Inicializa a matriz com espaços em branco
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            matriz[i][j] = ' ';
        }
    }

    // Preenche a matriz com a mensagem
    int linha = 0;
    for (i = 0; i < tamanho; i++) {
        matriz[linha][i] = texto[i];
        linha += direcao;
        if (linha == 0 || linha == linhas - 1) {
            direcao *= -1;
        }
    }

    // Cria a mensagem cifrada a partir da matriz
    char *cifrada = (char*) malloc(tamanho * sizeof(char));
    k = 0;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            if (matriz[i][j] != ' ') {
                cifrada[k++] = matriz[i][j];
            }
        }
    }
    cifrada[k] = '\0';

    // Copia a mensagem cifrada de volta para o texto original
    strcpy(texto, cifrada);

    // Libera a memória alocada
    free(cifrada);
    for (i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}
void cifrar_Vigenere(char *texto, int tamanho, uint32_t chave){
    int i, j;
    int chave_tamanho = strlen((char*) &chave);

    for (i = 0; i < tamanho; i++) {
        int chave_atual = chave % 26;
        int deslocamento = chave_atual;

        if (texto[i] >= 'a' && texto[i] <= 'z') {
            texto[i] = ((texto[i] - 'a' + deslocamento) % 26) + 'a';
        }
        else if (texto[i] >= 'A' && texto[i] <= 'Z') {
            texto[i] = ((texto[i] - 'A' + deslocamento) % 26) + 'A';
        }

        chave /= 10;
        if (chave == 0) {
            chave = chave_tamanho;
        }
    }
}

void decifrar_Cesar(char *texto, int tamanho, int chave) {
    int i;
    for (i = 0; i < tamanho; i++) {
        texto[i] = (texto[i] - chave) % 256;
    }
}

void decifrar_Vernam_Mauborgne(char *texto, int tamanho, char *chave) {
    int i;
    for (i = 0; i < tamanho; i++) {
        texto[i] = (texto[i] - chave[i]) % 256;
    }
}
