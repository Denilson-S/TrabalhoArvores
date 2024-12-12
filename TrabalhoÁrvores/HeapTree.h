#ifndef HEAP_TREE

#define HEAP_TREE

//inclus�o dos arquivos externos
#include "Types.h"
#include<iostream>
using namespace std;

//fun��o de troca de valor
void Heap_Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//fun��o de heapifica��o para cima
void Heap_HeapifyUp(Heap_Node_Point root, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (root->heap[parent] < root->heap[index]) { // Max-Heap
            swap(root->heap[parent], root->heap[index]);
            index = parent;
        }
        else {
            break;
        }
    }
}

//fun��o de heapifica��o para baixo
void Heap_HeapifyDown(Heap_Node_Point root, int index) {
    while (2 * index + 1 < root->heap_Size) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (root->heap[left] > root->heap[largest]) {
            largest = left;
        }
        if (right < root->heap_Size && root->heap[right] > root->heap[largest]) {
            largest = right;
        }
        if (largest == index) {
            break;
        }
        swap(root->heap[index], root->heap[largest]);
        index = largest;
    }
}

//fun��o para inser��o
void Heap_Insert_Node(Heap_Node_Point root, int value) {
    if (root->heap_Size == 31) {
        cout << "Heap cheio!" << endl;
        return;
    }
    root->heap[root->heap_Size] = value;
    Heap_HeapifyUp(root, root->heap_Size);
    root->heap_Size++;
}

//fun��o de busca por valor do n�
bool Heap_Search(Heap_Node_Point root, int value) {
    for (int i = 0; i < root->heap_Size; i++) {
        if (root->heap[i] == value) {
            return true;
        }
    }
    return false;
}

//fun��es de remo��o de n� por valor
void Heap_Remove_Root(Heap_Node_Point root) {
    if (root->heap_Size == 0) {
        cout << "Heap vazio!" << endl;
        return;
    }
    root->heap[0] = root->heap[root->heap_Size - 1];
    root->heap_Size--;
    Heap_HeapifyDown(root, 0);
}

//fun��o de percurso em ordem
void Heap_Route_InOrder(Heap_Node_Point root, int index) {
    if (index >= root->heap_Size) return;
    Heap_Route_InOrder(root, 2 * index + 1); // Esquerda
    cout << root->heap[index] << " ";
    Heap_Route_InOrder(root, 2 * index + 2); // Direita
}

//fun��o de percurso em pre ordem
void Heap_Route_PreOrder(Heap_Node_Point root, int index) {
    if (index >= root->heap_Size) return;
    cout << root->heap[index] << " ";
    Heap_Route_PreOrder(root, 2 * index + 1); // Esquerda
    Heap_Route_PreOrder(root, 2 * index + 2); // Direita
}

//fun��o de percurso em p�s ordem
void Heap_Route_PostOrder(Heap_Node_Point root, int index) {
    if (index >= root->heap_Size) return;
    Heap_Route_PostOrder(root, 2 * index + 1); // Esquerda
    Heap_Route_PostOrder(root, 2 * index + 2); // Direita
    cout << root->heap[index] << " ";
}

//fun��o de percurso por n�vel
void Heap_Route_LevelOrder(Heap_Node_Point root) {
    int levelStart = 0; // �ndice de in�cio do n�vel atual
    int levelSize = 1;  // N�mero de elementos no n�vel atual

    while (levelStart < root->heap_Size) {
        for (int i = 0; i < levelSize && levelStart + i < root->heap_Size; i++) {
            cout << root->heap[levelStart + i] << " ";
        }
        cout << endl; // Nova linha para o pr�ximo n�vel

        levelStart += levelSize; // Atualiza o in�cio do pr�ximo n�vel
        levelSize *= 2;          // O pr�ximo n�vel pode ter o dobro de elementos
    }
}

//fun��o para exibir o menu
Heap_Node_Point Heap_menu(Heap_Node_Point root) {
    int control = 0;
    while (control != 7) {
        cout << "Inserir no:..................0" << endl
            << "Procurar no:.................1" << endl
            << "Remover no:..................2" << endl
            << "Exibir percurso pre ordem:...3" << endl
            << "Exibir percurso pos ordem:...4" << endl
            << "Exibir percurso em ordem:....5" << endl
            << "Exibir percurso por nivel:...6" << endl
            << "Sair:........................7" << endl << endl
            << "Opcao: ";

        if (!(cin >> control)) {
            cin.clear();
            cin.ignore(1000, '\n');
            control = -1;
            cout << endl;
        }

        while (control < 0 || control>7) {
            cout << "Opcao invalida!" << endl
                << "Digite novamente : ";
            if (!(cin >> control)) {
                cin.clear();
                cin.ignore(1000, '\n');
                control = -1;
            }
            cout << endl;
        }

        int x;
        AVL_Node_Point aux;
        switch (control)
        {
        case 0:
            cout << "Digite um valor: ";
            cin >> x;
            Heap_Insert_Node(root, x);
            cout << "No inserido!" << endl << endl;
            break;
        case 1:
            cout << "Digite um valor para a busca: ";
            cin >> x;
            cout << x << (Heap_Search(root, x) ? " esta na arvore! " : " nao esta na arvore!") << endl << endl;
            break;
        case 2:
            Heap_Remove_Root(root);
            cout << "No raiz removido!" << endl << endl;
            break;
        case 3:
            Heap_Route_PreOrder(root, 0);
            cout << endl << endl;
            break;
        case 4:
            Heap_Route_PostOrder(root, 0);
            cout << endl << endl;
            break;
        case 5:
            Heap_Route_InOrder(root, 0);
            cout << endl << endl;
            break;
        case 6:
            Heap_Route_LevelOrder(root);
            cout << endl << endl;
            break;
        default:
            break;
        }
    }
    return root;
}

#endif