#ifndef FILMES_H
#define FILMES_H

#define MAX_FILMES 1000
#define MAX_STR 100

typedef struct {
    int id;
    char titulo[MAX_STR];
    char diretor[MAX_STR];
    int ano;
    char genero[MAX_STR];
    float avaliacao;
} Filme;

extern Filme* filmes[MAX_FILMES];
extern int numFilmes;

void inicializa();
void salvarDados();

#endif
