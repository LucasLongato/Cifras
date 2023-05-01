#include "cifras.h"

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

