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
void salvarDados() {
    FILE* arquivo = fopen("filmes.csv", "w");
    if (!arquivo) {
        printf("Erro ao salvar arquivo!\n");
        return;
    }

    fprintf(arquivo, "ID,Titulo,Diretor,Ano,Genero,Avaliacao\n");
    for (int i = 0; i < numFilmes; i++) {
        fprintf(arquivo, "%d,%s,%s,%d,%s,%.1f\n",
                filmes[i]->id,
                filmes[i]->titulo,
                filmes[i]->diretor,
                filmes[i]->ano,
                filmes[i]->genero,
                filmes[i]->avaliacao);
    }

    fclose(arquivo);
}

void adicionarFilme() {
    Filme* f = (Filme*)malloc(sizeof(Filme));

    printf("ID do filme: ");
    scanf("%d", &f->id);
    getchar();

    printf("Título: ");
    fgets(f->titulo, MAX_STR, stdin);
    f->titulo[strcspn(f->titulo, "\n")] = '\0';

    printf("Diretor: ");
    fgets(f->diretor, MAX_STR, stdin);
    f->diretor[strcspn(f->diretor, "\n")] = '\0';

    printf("Ano: ");
    scanf("%d", &f->ano);
    getchar();

    printf("Gênero: ");
    fgets(f->genero, MAX_STR, stdin);
    f->genero[strcspn(f->genero, "\n")] = '\0';

    printf("Avaliação (0-10): ");
    scanf("%f", &f->avaliacao);
    getchar();

    filmes[numFilmes++] = f;
    salvarDados();
    printf("Filme adicionado com sucesso!\n");
}