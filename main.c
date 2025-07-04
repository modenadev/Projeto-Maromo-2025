#include <stdio.h>
#include "filmes.h" // Certifique-se de que filmes.h inclui o protótipo de buscarPorNome()


void menu() {
    int opcao;
    do {
        printf("\n--- Catalogo de Filmes ---\n");
        printf("1. Adicionar filme\n");
        printf("2. Buscar por diretor\n");
        printf("3. Filtrar por genero\n");
        printf("4. Atualizar avaliacao\n");
        printf("5. Listar filmes\n");
        printf("6. Buscar por nome do filme\n"); // <-- Adicionei esta linha!
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarFilme(); break;
            case 2: buscarPorDiretor(); break;
            case 3: filtrarPorGenero(); break;
            case 4: atualizarAvaliacao(); break;
            case 5: listarFilmes(); break;
            case 6: buscarPorNome(); break; // <-- Corrigi para buscarPorNome()!
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