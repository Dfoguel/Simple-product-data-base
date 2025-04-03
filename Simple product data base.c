#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
} Produto;

Produto produtos[MAX_PRODUTOS];
int quantidadeProdutos = 0;

void exibirMenu() {
    printf("\n=== Options Menu ===\n");
    printf("1. Insert Product\n");
    printf("2. List all the products\n");
    printf("3. Search product by name\n");
    printf("4. Delete product by name\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

void inserirProduto() {
    if (quantidadeProdutos >= MAX_PRODUTOS) {
        printf("Database full. Unable to add more products.\n");
        return;
    }

    Produto novoProduto;
    printf("Enter the product code: ");
    scanf_s("%d", &novoProduto.codigo);

    // Verificar se o código é único
    for (int i = 0; i < quantidadeProdutos; i++) {
        if (produtos[i].codigo == novoProduto.codigo) {
            printf("A product with this code already exists. Please enter a unique code\n");
            return;
        }
    }

    printf("Enter the product name: ");
    scanf_s(" %[^\n]s", novoProduto.nome, sizeof(novoProduto.nome));
    printf("Enter the product price: ");
    scanf_s("%f", &novoProduto.preco);
    printf("Enter the product quantity: ");
    scanf_s("%d", &novoProduto.quantidade);

    produtos[quantidadeProdutos] = novoProduto;
    quantidadeProdutos++;
    printf("Product inserted successfully!\n");
}

void listarProdutos() {
    if (quantidadeProdutos == 0) {
        printf("No products registered.\n");
        return;
    }

    for (int i = 0; i < quantidadeProdutos; i++) {
        printf("Code: %d, Name: %s, Price: %.2f, Quantity: %d\n",
            produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }
}

void buscarProdutoPorNome() {
    char nomeBusca[50];
    printf("Enter product name to search: ");
    scanf_s(" %[^\n]s", nomeBusca, sizeof(nomeBusca));

    int encontrado = 0;
    for (int i = 0; i < quantidadeProdutos; i++) {
        if (strcmp(produtos[i].nome, nomeBusca) == 0) {
            printf("Code: %d, Name: %s, Price: %.2f, Quantity: %d\n",
                produtos[i].codigo, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Product not found.\n");
    }
}

void excluirProdutoPorNome() {
    char nomeExclusao[50];
    printf("Enter product name to delete: ");
    scanf_s(" %[^\n]s", nomeExclusao, sizeof(nomeExclusao));

    int encontrado = 0;
    for (int i = 0; i < quantidadeProdutos; i++) {
        if (strcmp(produtos[i].nome, nomeExclusao) == 0) {
            // Deslocar os elementos para excluir o produto
            for (int j = i; j < quantidadeProdutos - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            quantidadeProdutos--;
            printf("Product deleted successfully!\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Product not found.\n");
    }
}

void navegarMenu() {
    int opcao = 0;
    do {
        exibirMenu();
        scanf_s("%d", &opcao);

        switch (opcao) {
        case 1:
            inserirProduto();
            break;
        case 2:
            listarProdutos();
            break;
        case 3:
            buscarProdutoPorNome();
            break;
        case 4:
            excluirProdutoPorNome();
            break;
        case 5:
            printf("Leaving program...\n");
            break;
        default:
            printf("Invalid option. Try again.\n");
        }
    } while (opcao != 5);
}

int main() {
    navegarMenu();
    return 0;
}
