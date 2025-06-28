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

void buscarPorDiretor() {
    char nome[MAX_STR];
    printf("Nome do diretor: ");
    getchar();
    fgets(nome, MAX_STR, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    for (int i = 0; i < numFilmes; i++) {
        if (strcmp(filmes[i]->diretor, nome) == 0) {
            printf("-> [%d] %s (%d) - %s, Nota: %.1f\n",
                   filmes[i]->id, filmes[i]->titulo,
                   filmes[i]->ano, filmes[i]->genero,
                   filmes[i]->avaliacao);
        }
    }
}

void filtrarPorGenero() {
    char genero[MAX_STR];
    printf("Gênero: ");
    getchar();
    fgets(genero, MAX_STR, stdin);
    genero[strcspn(genero, "\n")] = '\0';

    for (int i = 0; i < numFilmes; i++) {
        if (strcmp(filmes[i]->genero, genero) == 0) {
            printf("-> [%d] %s (%d) - Dir: %s, Nota: %.1f\n",
                   filmes[i]->id, filmes[i]->titulo,
                   filmes[i]->ano, filmes[i]->diretor,
                   filmes[i]->avaliacao);
        }
    }
}

void filtrarPorGenero() {
    char genero[MAX_STR];
    printf("Gênero: ");
    getchar();
    fgets(genero, MAX_STR, stdin);
    genero[strcspn(genero, "\n")] = '\0';

    for (int i = 0; i < numFilmes; i++) {
        if (strcmp(filmes[i]->genero, genero) == 0) {
            printf("-> [%d] %s (%d) - Dir: %s, Nota: %.1f\n",
                   filmes[i]->id, filmes[i]->titulo,
                   filmes[i]->ano, filmes[i]->diretor,
                   filmes[i]->avaliacao);
        }
    }
}

void atualizarAvaliacao() {
    int id;
    printf("ID do filme para atualizar nota: ");
    scanf("%d", &id);

    for (int i = 0; i < numFilmes; i++) {
        if (filmes[i]->id == id) {
            printf("Nota atual: %.1f\n", filmes[i]->avaliacao);
            printf("Nova avaliação (0-10): ");
            scanf("%f", &filmes[i]->avaliacao);
            salvarDados();
            printf("Avaliação atualizada com sucesso.\n");
            return;
        }
    }

    printf("Filme com ID %d não encontrado.\n", id);
}

int comparar(const void* a, const void* b) {
    Filme* f1 = *(Filme**)a;
    Filme* f2 = *(Filme**)b;

    if (f1->ano != f2->ano)
        return f1->ano - f2->ano;
    return strcmp(f1->titulo, f2->titulo);
}

void listarFilmes() {
    qsort(filmes, numFilmes, sizeof(Filme*), comparar);
    for (int i = 0; i < numFilmes; i++) {
        printf("[%d] %s (%d) - Dir: %s | %s | Nota: %.1f\n",
               filmes[i]->id, filmes[i]->titulo,
               filmes[i]->ano, filmes[i]->diretor,
               filmes[i]->genero, filmes[i]->avaliacao);
    }
}


