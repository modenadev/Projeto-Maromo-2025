#include <stdio.h>
#include "filmes.h"


void menu() {
    int opcao;
    do {
        printf("\n--- Catalogo de Filmes ---\n");
        printf("1. Adicionar filme\n");
        printf("2. Buscar por diretor\n");
        printf("3. Filtrar por genero\n");
        printf("4. Atualizar avaliacao\n");
        printf("5. Listar filmes\n");
        printf("6. Buscar por nome do filme\n");
        printf("0. Sair\n");
        // Substitua a linha abaixo:
        // printf("Escolha: ");
        // scanf("%d", &opcao);

        // Por esta linha (usando sua função lerInteiro):
        opcao = lerInteiro("Escolha: "); // <-- ESSA É A MUDANÇA!

        switch (opcao) {
            case 1: adicionarFilme(); break;
            case 2: buscarPorDiretor(); break;
            case 3: filtrarPorGenero(); break;
            case 4: atualizarAvaliacao(); break;
            case 5: listarFilmes(); break;
            case 6: buscarPorNome(); break;
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