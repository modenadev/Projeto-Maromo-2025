#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filmes.h"

Filme* filmes[MAX_FILMES];
int numFilmes = 0;

void inicializa() {
    FILE* arquivo = fopen("filmes.csv", "r");
    if (!arquivo) {
        printf("Arquivo 'filmes.csv' não encontrado. Iniciando vazio.\n");
        return;
    }

    char linha[512];
    fgets(linha, sizeof(linha), arquivo); // cabeçalho
    while (fgets(linha, sizeof(linha), arquivo)) {
        Filme* f = (Filme*)malloc(sizeof(Filme));
        sscanf(linha, "%d,%[^,],%[^,],%d,%[^,],%f",
               &f->id,
               f->titulo,
               f->diretor,
               &f->ano,
               f->genero,
               &f->avaliacao);
        filmes[numFilmes++] = f;
    }

    fclose(arquivo);
}
