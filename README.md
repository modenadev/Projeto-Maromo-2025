Projeto Maromo 2025
Sistema simples em linguagem C para gerenciamento de um catálogo de filmes, incluindo cadastro, listagem e armazenamento em arquivo CSV.

Ambiente de Desenvolvimento
Desenvolvido no CLion (IDE da JetBrains).

Sistema operacional: Windows ou Linux.

Requer compilador C (recomenda-se GCC).

Observação: Embora o CLion utilize o CMake internamente para gerenciar builds, este projeto foi criado e testado no CLion, não diretamente via CMake puro.

Como Instalar
Baixe ou clone o repositório para uma pasta local.

Abra o projeto no CLion.

O CLion irá detectar automaticamente o arquivo CMakeLists.txt e configurar o ambiente de build.

Compile o projeto clicando em Build Project ou utilizando o atalho Ctrl + F9.

Alternativamente, se desejar compilar via terminal (fora do CLion), execute os comandos abaixo na pasta raiz do projeto:

mkdir build
cd build
cmake ..
cmake --build .
O executável será gerado na pasta build.

Como Executar
Pelo CLion
Execute o projeto diretamente pelo botão Run na IDE.

Pelo terminal
No Linux/macOS:

Copiar
Editar
./Projeto_Maromo
No Windows:

Execute o arquivo Projeto_Maromo.exe gerado na pasta build.

Ou simplesmente clique duas vezes no executável.

Também é possível utilizar os executáveis prontos fornecidos na pasta principal do projeto, se existirem.

Estrutura do Projeto
main.c — Arquivo principal do sistema.

filmes.c — Implementação das funções do sistema.

filmes.h — Declaração das funções e estruturas.

filmes.csv — Arquivo de armazenamento dos filmes cadastrados.

CMakeLists.txt — Configuração de build para CLion/CMake.

.idea/ — Arquivos de configuração do CLion (podem ser ignorados).

Projeto_Maromo.exe — Executável do sistema (Windows).

Funcionalidades
✅ Cadastro de filmes

✅ Listagem dos filmes cadastrados

✅ Salvamento dos dados em arquivo CSV

Requisitos
Compilador C (GCC ou equivalente)

CLion instalado (opcional, mas recomendado)

Windows ou Linux
