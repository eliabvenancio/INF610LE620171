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

int exibeAltura(TipoArvore a);
int contarFolhas(TipoArvore a);
int contarNos(TipoArvore a);

//Inicializa uma arvore como vazia

void Inicializa(TipoArvore &a) {
    a = NULL;
}

//Imprime conteudo da arvore

void Imprime(TipoArvore a, int nivel) {
    //cout << "Imprimindo a arvore:\n\n";
    if (a == NULL) {
        //cout <<"Arvore vazia!\n\n";
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
    } else if (x.chave < a->item.chave) {
        Insere(a->subArvEsq, x);
    } else if (x.chave > a->item.chave) {
        Insere(a->subArvDir, x);
    } else {
        cout << "Elemento já existe na arvore, portanto não será inserido novamente! \n";
    }
    return 0;
}

int insert(TipoArvore a, TipoItem x) {

    do {
        cout << "informe um numero e pressione [enter]. Para sair  pressione '0':";
        cin >> x.chave;
        Insere(a, x);
    } while (x.chave != 0);
    
    cout << "\n\n"; 
    cout << "Imprimindo a arvore:\n";
    Imprime(a, 0);
    //------------------------
    cout << "\n\n";
    cout << "Altura da arvore: ";
    int alt = exibeAltura(a);
    cout <<alt;
    //---------------------
    cout <<"\n\n";
    cout << "Qtd. folhas da arvore: ";
    int qtdfolhas;
    qtdfolhas = contarFolhas(a);
    cout << qtdfolhas;
    cout << "\n\n";
    //----------------
    cout << "Qtd. de nós da arvore: ";
    int qtdnos;
    qtdnos = contarNos(a);
    cout << qtdnos;
    cout << "\n\n";
}

int contarFolhas(TipoArvore a){
   if(a == NULL)
        return 0;
   if(a->subArvEsq == NULL && a->subArvDir == NULL)
        return 1;
   return contarFolhas(a->subArvEsq) + contarFolhas(a->subArvDir);
}

int contarNos(TipoArvore a){
   if(a == NULL)
        return 0;
   else
        return 1 + contarNos(a->subArvEsq) + contarNos(a->subArvDir);
}

//Pesquisa e retorna um item com a chave ‘x’ pesquisada

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

// Devolve o altura de um nó h em uma árvore binária.

int exibeAltura(TipoArvore a) {
    
   if (a == NULL) 
      return -1; // altura da árvore vazia
   else {
      int he = exibeAltura (a->subArvEsq);
      int hd = exibeAltura (a->subArvDir);
      if (he < hd) return hd + 1;
      else return he + 1;
   }
}

//Direcionamento para a operaÃ§Ã£o desejada pelo usuÃ¡rio de acordo com sua opÃ§Ã£o

void opcao(int op, TipoArvore a, TipoItem x) {


    switch (op) {

        case 0:
            system("cls || clear");
            printf("Saindo do menu...\n");
            break;

        case 1:
            insert(a, x);
            break;

        case 2:
            Imprime(a, 0);
            //insert(a, x , 's');
            break;

        case 3:
            system("cls || clear");
            int z;
            //z = exibeAltura(a);
            cout << "\nAltura da Arvore:";
            cout << z;
            cout << "\n\n";
            //insert(a, x , 's');
            break;

        default:
            printf("Comando invalido\n\n");
    }
}

int menu(void) {
    int opt;

    // Lista a opÃ§Ãµes de menu para escolha do usuÃ¡rio;
    printf("---| Escolha uma das opcoes abaixo: |---\n");
    printf("0. Sair\n");

    printf("---| ARVORE BINARIA  |---");
    printf("\n");

    printf("1. Adicionar elemento na arvore\n");
    printf("2. Imprimpir arvore\n");
    printf("3. Exibir altura da arvore\n");


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