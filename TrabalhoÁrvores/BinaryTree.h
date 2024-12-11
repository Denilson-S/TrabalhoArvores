#ifndef BINARY_TREE

	#define BINARY_TREE

    //inclusão dos arquivos externos
    #include "Types.h"
    #include<iostream>
    using namespace std;

    //função de inserir um nó na arvore
    Bin_Node_Point Bin_Insert_Node(Bin_Node_Point root, Bin_Node_Point node) {
        if (root == nullptr)
            return node;
        if (!root->left)
            root->left = node;
        else if (!root->right)
            root->right = node;
        else
            root->left = Bin_Insert_Node(root->left, node);
        return root;
    }

    //função de busca por valor do nó
    Bin_Node_Point Bin_Search(Bin_Node_Point root, int valor) {
        if (root == nullptr)
            return nullptr;
        if (root->data == valor)
            return root;
        if (root->right)
            if(root->right->data == valor)
                return root->right;        
        if (root->left) {
            if (root->left->data == valor)
                return root->left;
            return Bin_Search(root->left, valor);
        }
        return nullptr;
    }

    //função de remoção de nó por valor
    Bin_Node_Point Bin_Remove_Node(Bin_Node_Point root, int valor) {
        if (root == nullptr)
            return nullptr;
        int aux_Right = 0;
        Bin_Node_Point aux_Delete;
        if (!root->left) {
            if (root->data == valor) {
                delete root;
                root = nullptr;
            }
            return root;
        }
        if(root->right) {
            if (root->right->data == valor) {
                delete root->right;
                root->right = nullptr;
                return root;
            }
            aux_Right++;
        }
        if (root->data == valor) {
            if (aux_Right) {
                aux_Delete = root;
                root->right->left = root->left;
                root = root->right;
                delete aux_Delete;
            }else {
                aux_Delete = root;
                root = root->left;
                delete aux_Delete;
            }
            return root;
        }
        root->left = Bin_Remove_Node(root->left, valor);
        return root;
    }

    //função de percurso em ordem
    void Bin_Route_InOrder(Bin_Node_Point root) {
        if (root == nullptr)
            return;
        Bin_Route_InOrder(root->left);
        cout << root->data << " ";
        Bin_Route_InOrder(root->right);
    }

    //função de percurso pre ordem
    void Bin_Route_PreOrder(Bin_Node_Point root) {
        if (root == nullptr)
            return;
        cout << root->data << " ";
        Bin_Route_PreOrder(root->left);
        Bin_Route_PreOrder(root->right);
    }

    //função de percurso pós ordem
    void Bin_Route_PostOrder(Bin_Node_Point root) {
        if (root == nullptr)
            return;
        Bin_Route_PreOrder(root->left);
        Bin_Route_PreOrder(root->right);
        cout << root->data << " ";
    }

    //função de percurso por nível
    void Bin_Route_LevelOrder(Bin_Node_Point root) {

    }

    //função para exibir o menu
    Bin_Node_Point Bin_menu(Bin_Node_Point root) {
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
            Bin_Node_Point aux;
            switch (control)
            {
            case 0:
                cout << "Digite um valor: ";
                cin >> x;
                root = Bin_Insert_Node(root, Bin_CreateNode(x));
                cout << "No inserido!" << endl << endl;
                break;
            case 1:
                cout << "Digite um valor para a busca: ";
                cin >> x;
                aux = Bin_Search(root, x);
                if (aux)
                    cout << x << " esta na arvore! " << endl << endl;
                else
                    cout << x << " nao esta na arvore!" << endl << endl;
                break;
            case 2:
                cout << "Digite um valor para ser removido: ";
                cin >> x;
                root = Bin_Remove_Node(root, x);
                cout << "No removido!" << endl << endl;
                break;
            case 3:
                Bin_Route_PreOrder(root);
                cout << endl << endl;
                break;
            case 4:
                Bin_Route_PostOrder(root);
                cout << endl << endl;
                break;
            case 5:
                Bin_Route_InOrder(root);
                cout << endl << endl;
                break;
            case 6:
                Bin_Route_LevelOrder(root);
                cout << endl << endl;
                break;
            default:
                break;
            }
        }
        return root;
    }

#endif