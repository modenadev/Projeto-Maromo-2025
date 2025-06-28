#include <stdio.h>
#include "filmes.h"

void menu() {
    int opcao;
    do {
        printf("\n--- Catálogo de Filmes ---\n");
        printf("1. Adicionar filme\n");
        printf("2. Buscar por diretor\n");
        printf("3. Filtrar por gênero\n");
        printf("4. Atualizar avaliação\n");
        printf("5. Listar filmes\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarFilme(); break;
            case 2: buscarPorDiretor(); break;
            case 3: filtrarPorGenero(); break;
            case 4: atualizarAvaliacao(); break;
            case 5: listarFilmes(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida.\n");
        }

    } while (opcao != 0);
}

int main() {
    inicializa();
    menu();
    return 0;
}
