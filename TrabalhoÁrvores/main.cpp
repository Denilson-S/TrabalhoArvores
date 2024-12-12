
//inclusão dos arquivos externos
#include "Types.h"

#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"
//#include "BTree.h"
#include "HeapTree.h"
#include "TrieTree.h"

//inclusão das bibliotecas
#include<iostream>
using namespace std;

int main()
{
    Bin_Node_Point Bin_root = nullptr;
    Bin_Node_Point BST_root = nullptr;
    AVL_Node_Point AVL_root = nullptr;
    Heap_Node_Point Heap_root = Heap_CreateNode();
    Trie_Node_Point Trie_root = Trie_CreateNode();

    int control = 1;
    while (control) {
        cout << "Qual arvore deseja manipular? " << endl
            << "Sair:.................0" << endl
            << "Binaria:..............1" << endl
            << "Binaria de busca:.....2" << endl
            << "Arvore AVL:...........3" << endl
            << "Arvore Heap:..........4" << endl
            << "Arvore Trie:..........5" << endl
            << "Arvore B:.............6" << endl << endl
            << "Arvore: ";

        if (!(cin >> control)) {
            cin.clear();
            cin.ignore(1000, '\n');
            control = -1;
            cout << endl;
        }

        while (control < 0 || control>6) {
            cout << "Opcao invalida!" << endl
                << "Digite novamente: ";
            if (!(cin >> control)) {
                cin.clear();
                cin.ignore(1000, '\n');
                control = -1;
            }
            cout << endl;
        }

        switch (control)
        {
        case 1:
            Bin_root = Bin_menu(Bin_root);
            break;
        case 2:
            BST_root = BST_menu(BST_root);
            break;
        case 3:
            AVL_root = AVL_menu(AVL_root);
            break;
        case 4:
            Heap_root = Heap_menu(Heap_root);
            break;
        case 5:
            Trie_root = Trie_menu(Trie_root);
            break;
        default:
            break;
        }
    }

    return 0;
}