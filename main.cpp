// INF610 - Estruturas de Dados e Algoritmos
//
// Implementacao de Arvore Binaria de Pesquisa
//
// Autor: Andre Gustavo dos Santos
//        05/04/2017
//////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>


//Biblioteca usada para verfiicar o tempo de processamento
//#include <windows.h> 


using namespace std;

int menu(void);
void opcao(int op);

typedef int TipoChave;

struct TipoItem {
    TipoChave chave;
    // outros componentes
};

typedef struct TipoNodo *TipoArvore;

struct TipoNodo {
    TipoItem item;
    TipoArvore subArvEsq;
    TipoArvore subArvDir;
};

//Inicializa uma arvore como vazia

void Inicializa(TipoArvore &a) {
    a = NULL;
}


//Imprime conteudo da arvore

void Imprime(TipoArvore a, int nivel) {
    if (a == NULL) {
        cout <<"Arvore vazia!\n\n";
        return;
    }

    Imprime(a->subArvDir, nivel + 1);
    cout << setw(nivel * 3) << a->item.chave << endl;
    Imprime(a->subArvEsq, nivel + 1);

}


//Insere item x na arvore

int Insere(TipoArvore &a, TipoItem x) {

    if (a == NULL) {
        a = new TipoNodo;
        a->item = x;
        a->subArvEsq = NULL;
        a->subArvDir = NULL;
    } else if (x.chave < a->item.chave)
        Insere(a->subArvEsq, x);
    else
        Insere(a->subArvDir, x);


    return 0;
}

int insert(TipoArvore a, TipoItem x) {

    do {
        cout << "informe um numero e pressione [enter]. Para sair  pressione '0':";
        cin >> x.chave;
        Insere(a, x);
    }    while (x.chave != 0);

    Imprime(a, 0);
}



//Pesquisa e retorna um item com a chave �x� pesquisada

TipoItem* Pesquisa(TipoArvore a, TipoChave x) {
    if (a == NULL)
        return NULL;
    //sem sucesso
    if (x == a->item.chave)
        return &(a->item); //com sucesso
    if (x < a->item.chave)
        return Pesquisa(a->subArvEsq, x); //pesquisa na subarvo
    if (x > a->item.chave)
        return Pesquisa(a->subArvDir, x); //pesquisa na subarvo
}

void exibeArvore(TipoArvore a) {
    cout << "Imprimindo a arvore:\n\n";
    Imprime(a, 0);

}



//Direcionamento para a operação desejada pelo usuário de acordo com sua opção

void opcao(int op, TipoArvore a, TipoItem x) {


    switch (op) {

        case 0:
            break;

        case 1:
            insert(a, x);
            break;

        case 2:
            exibeArvore(a);
            break;

        default:
            printf("Comando invalido\n\n");
    }
}

int menu(void) {
    int opt;

    // Lista a opções de menu para escolha do usuário;
    printf("---| Escolha uma das opcoes abaixo: |---\n");
    printf("0. Sair\n");

    printf("---| ARVORE BINARIA  |---");
    printf("\n");

    printf("1. Adicionar elemento na arvore\n");
    printf("2. Imprimpir arvore\n");


    printf("Opcao: ");
    scanf("%d", &opt);

    return opt;
}

int main(void) {
    TipoArvore a;
    TipoItem x;
    Inicializa(a);

    int opt;

    do {
        opt = menu();
        opcao(opt, a, x);
    } while (opt);

    free(a);
    //free(x);

    return 0;
}