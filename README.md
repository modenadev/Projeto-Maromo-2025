🎬 Projeto Maromo 2025
Sistema simples desenvolvido em C para gerenciamento de um catálogo de filmes, incluindo funcionalidades de cadastro, listagem e armazenamento em arquivo CSV.

🛠️ Ambiente de Desenvolvimento
Desenvolvido na IDE CLion (JetBrains).

Compatível com Windows e Linux.

Requer um compilador C (recomenda-se GCC).

⚠️ Nota: Embora o CLion utilize o CMake internamente para compilar os projetos, este projeto foi desenvolvido e testado diretamente no CLion, e não via CMake puro.

📦 Como Instalar
Via CLion
Clone ou baixe o repositório para uma pasta local.

Abra o projeto no CLion.

O CLion irá detectar automaticamente o CMakeLists.txt e configurar o ambiente.

Compile o projeto clicando em Build Project ou usando o atalho Ctrl + F9.

mkdir build
cd build
cmake ..
cmake --build .
O executável será gerado na pasta build.

▶️ Como Executar
No CLion
Clique em Run ou use o atalho Shift + F10.

No terminal
Linux/macOS:

bash
Copiar
Editar
./Projeto_Maromo
Windows:

Execute o arquivo Projeto_Maromo.exe dentro da pasta build, ou

Clique duas vezes sobre o executável.

Também é possível utilizar os executáveis prontos que estão na raiz do projeto, se fornecidos.

📁 Estrutura do Projeto
kotlin
Copiar
Editar
├── main.c              # Arquivo principal
├── filmes.c            # Implementação das funções
├── filmes.h            # Declarações e estruturas
├── filmes.csv          # Base de dados dos filmes
├── CMakeLists.txt      # Configuração do projeto para CLion/CMake
├── Projeto_Maromo.exe  # Executável gerado
├── .idea/              # Configurações do CLion (podem ser ignoradas)
✅ Funcionalidades
Cadastro de filmes

Listagem dos filmes cadastrados

Salvamento em arquivo CSV

📌 Requisitos
Compilador C (GCC ou equivalente)

CLion instalado (recomendado)

Sistema operacional Windows ou Linux

