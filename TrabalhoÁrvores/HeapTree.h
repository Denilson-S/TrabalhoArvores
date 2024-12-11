#ifndef HEAP_TREE

	#define HEAP_TREE

    //inclusão dos arquivos externos
    #include "Types.h"
    #include<iostream>
    using namespace std;

    //função de inserir um nó na arvore
    AVL_Node_Point Heap_Insert_Node(AVL_Node_Point root, AVL_Node_Point node) {
        return root;
    }

    //função de busca por valor do nó
    AVL_Node_Point Heap_Search(AVL_Node_Point root, int valor) {
            return Heap_Search(root->right, valor);
    }

    //funções de remoção de nó por valor
    AVL_Node_Point Heap_Search_Aux(AVL_Node_Point root, int valor, AVL_Node_Point* father) {
        return nullptr;
    }

    AVL_Node_Point Heap_Remove_Node(AVL_Node_Point root, int valor) {
        return root;
    }

    //função de percurso em ordem
    void Heap_Route_InOrder(AVL_Node_Point root) {

    }

    //função de percurso em pre ordem
    void Heap_Route_PreOrder(AVL_Node_Point root) {

    }

    //função de percurso em pós ordem
    void Heap_Route_PostOrder(AVL_Node_Point root) {

    }

    //função de percurso por nível
    void Heap_Route_LevelOrder(AVL_Node_Point root) {

    }

    //função para exibir o menu
    AVL_Node_Point Heap_menu(AVL_Node_Point root) {
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
                root = Heap_Insert_Node(root, AVL_CreateNode(x));
                cout << "No inserido!" << endl << endl;
                break;
            case 1:
                cout << "Digite um valor para a busca: ";
                cin >> x;
                aux = Heap_Search(root, x);
                if (aux)
                    cout << x << " esta na arvore! " << endl << endl;
                else
                    cout << x << " nao esta na arvore!" << endl << endl;
                break;
            case 2:
                cout << "Digite um valor para ser removido: ";
                cin >> x;
                root = Heap_Remove_Node(root, x);
                cout << "No removido!" << endl << endl;
                break;
            case 3:
                Heap_Route_PreOrder(root);
                cout << endl << endl;
                break;
            case 4:
                Heap_Route_PostOrder(root);
                cout << endl << endl;
                break;
            case 5:
                Heap_Route_InOrder(root);
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