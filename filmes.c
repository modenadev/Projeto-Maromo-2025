#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filmes.h"

#include <ctype.h>

Filme* filmes[MAX_FILMES];
int numFilmes = 0;

void inicializa() {
    FILE* arquivo = fopen("../filmes.csv", "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char linha[512];
    fgets(linha, sizeof(linha), arquivo); // cabeçalho

    while (fgets(linha, sizeof(linha), arquivo)) {
        Filme* f = (Filme*)malloc(sizeof(Filme));
        int lidos = sscanf(linha, "%d,%[^,],%[^,],%d,%[^,],%f",
                           &f->id,
                           f->titulo,
                           f->diretor,
                           &f->ano,
                           f->genero,
                           &f->avaliacao);

        if (lidos == 6) {
            filmes[numFilmes++] = f;
            printf("Filme carregado: %s (%d) - %s - Nota %.1f\n",
                   f->titulo, f->ano, f->genero, f->avaliacao);
        } else {
            printf("⚠️ Erro ao ler linha: %s", linha);
            free(f);
        }
    }

    fclose(arquivo);
}

void salvarDados() {
    FILE* arquivo = fopen("../filmes.csv", "w");
    if (!arquivo) {
        printf("Erro ao salvar arquivo!\n");
        return;
    }

    fprintf(arquivo, "ID,Titulo,Diretor,Ano,Genero,Avaliação\n");
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
// Função para limpar o buffer de entrada, essencial após leituras.
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para ler uma string de forma segura
void lerString(const char* prompt, char* destino, int tamanho) {
    printf("%s", prompt);
    fgets(destino, tamanho, stdin);
    destino[strcspn(destino, "\n")] = '\0'; // Remove o \n do final
}

int lerInteiro(const char* prompt) {
    char buffer[100];
    int valor;
    char char_extra;

    while (1) {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);

        int itens_lidos = sscanf(buffer, "%d%c", &valor, &char_extra);

        if (itens_lidos == 2 && char_extra == '\n') {
            return valor;
        }
        else if (itens_lidos == 1) {

            int apenas_digitos = 1;
            buffer[strcspn(buffer, "\n")] = 0;
            for(int i=0; buffer[i] != '\0'; i++){
                if(!isdigit(buffer[i]) && (i > 0 || buffer[i] != '-')) {
                    apenas_digitos = 0;
                    break;
                }
            }
            if(apenas_digitos) return valor;
        }

        printf("    ⚠️ Erro: Entrada inválida. Por favor, digite apenas o número.\n");
    }
}

// Função para verificar se um ID de filme já existe
int idExiste(int id) {
    for (int i = 0; i < numFilmes; i++) {
        if (filmes[i]->id == id) {
            return 1; // Verdadeiro, ID já existe
        }
    }
    return 0; // Falso, ID está disponível
}


void adicionarFilme() {
    if (numFilmes >= MAX_FILMES) {
        printf("Catálogo de filmes está cheio!\n");
        return;
    }

    Filme* f = (Filme*)malloc(sizeof(Filme));
    if (!f) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    // --- Validação do ID ---
    do {
        f->id = lerInteiro("ID do filme: ");
        if (idExiste(f->id)) {
            printf("⚠️ Erro: Este ID já está em uso. Tente outro.\n");
        }
    } while (idExiste(f->id));


    // --- Leitura das Strings ---
    lerString("Título: ", f->titulo, MAX_STR);
    lerString("Diretor: ", f->diretor, MAX_STR);


    // --- Validação do Ano ---
    do {
        f->ano = lerInteiro("Ano de lançamento: ");
        if (f->ano < 1888 || f->ano > 2025) { // 1888 é o ano do primeiro filme
            printf("⚠️ Erro: Ano parece inválido. Tente novamente.\n");
        }
    } while (f->ano < 1888 || f->ano > 2025);


    // --- Validação da Avaliação ---
    float avaliacao;
    do {
        printf("Avaliação (0.0 a 10.0): ");
        scanf("%f", &avaliacao);
        limparBuffer(); // Limpa o buffer após o scanf de float
        if (avaliacao < 0.0 || avaliacao > 10.0) {
            printf("⚠️ Erro: A avaliação deve ser entre 0 e 10.\n");
        }
    } while (avaliacao < 0.0 || avaliacao > 10.0);
    f->avaliacao = avaliacao;


    // --- Adicionar e Salvar ---
    filmes[numFilmes++] = f;
    salvarDados();
    printf("\n✅ Filme '%s' adicionado com sucesso!\n", f->titulo);
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

void buscarPorNome() {
    char tituloBusca[MAX_STR];
    printf("Título do filme para buscar: ");
    limparBuffer();
    lerString("", tituloBusca, MAX_STR);

    int encontrado = 0;
    for (int i = 0; i < numFilmes; i++) {
        if (strstr(filmes[i]->titulo, tituloBusca) != NULL) {
            printf("-> [%d] %s (%d) - Dir: %s, Gênero: %s, Nota: %.1f\n",
                   filmes[i]->id, filmes[i]->titulo,
                   filmes[i]->ano, filmes[i]->diretor,
                   filmes[i]->genero, filmes[i]->avaliacao);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum filme encontrado com o titulo '%s'.\n", tituloBusca);
    }
}


