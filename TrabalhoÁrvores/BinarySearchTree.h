#ifndef BINARY_SEARCH_TREE

    #define BINARY_SEARCH_TREE

    //inclusão dos arquivos externos
    #include "Types.h"
    #include<iostream>
    using namespace std;

    //função de inserir um nó na arvore
    Bin_Node_Point BST_Insert_Node(Bin_Node_Point root, Bin_Node_Point node) {
        if (root == nullptr)
            return node;
        if (node->data < root->data)
            root->left = BST_Insert_Node(root->left, node);
        else
            root->right = BST_Insert_Node(root->right, node);
        return root;
    }

    //função de busca por valor do nó
    Bin_Node_Point BST_Search(Bin_Node_Point root, int valor) {
        if (root == nullptr)
            return nullptr;
        if (root->data == valor)
            return root;
        if (root->data > valor)
            return BST_Search(root->left, valor);
        return BST_Search(root->right, valor);
    }

    //função auxiliar para a remoção
    Bin_Node_Point BST_Search_Aux(Bin_Node_Point root, int valor, Bin_Node_Point* father) {
        *father = nullptr;
        while (root) {
            if (root->data == valor) 
                return root;
            *father = root;
            if (valor < root->data) 
                root = root->left;
            else 
                root = root->right;
        }
        return nullptr;
    }

    //função para remover nó da árvore por valor
    Bin_Node_Point BST_Remove_Node(Bin_Node_Point root, int valor) {
        Bin_Node_Point father,  node,  aux_father,  aux_childen;
        node = BST_Search_Aux(root, valor, &father);
        if (node == nullptr) 
            return root;
        if (!node->left || !node->right) {
            if (!node->left) aux_childen = node->right;
            else aux_childen = node->left;
        }
        else {
            aux_father = node;
            aux_childen = node->left;
            while (aux_childen->right) {
                aux_father = aux_childen;
                aux_childen = aux_childen->right;
            }
            if (aux_father != node) {
                aux_father->right = aux_childen->left;
                aux_childen->left = node->left;
            }
            aux_childen->right = node->right;
        }
        if (!father) {
            delete node;
            return aux_childen;
        }
        if (valor < father->data) 
            father->left = aux_childen;
        else 
            father->right = aux_childen;
        delete node;
        return root;
    }

    //função de percurso em ordem
    void BST_Route_InOrder(Bin_Node_Point root) {
        if (root == nullptr)
            return;
        BST_Route_InOrder(root->left);
        cout << root->data << " ";
        BST_Route_InOrder(root->right);
    }    
    
    //função de percurso pre ordem
    void BST_Route_PreOrder(Bin_Node_Point root) {
        if (root == nullptr)
            return;
        cout << root->data << " ";
        BST_Route_PreOrder(root->left);
        BST_Route_PreOrder(root->right);
    }

    //função de percurso pós ordem
    void BST_Route_PostOrder(Bin_Node_Point root) {
        if (root == nullptr)
            return;
        BST_Route_PreOrder(root->left);
        BST_Route_PreOrder(root->right);
        cout << root->data << " ";
    }

    //função de percurso por nível
    void BST_Route_LevelOrder(Bin_Node_Point root) {

    }
    void imprimirNivel(Bin_Node_Point no, int nivel) {
        if (no == nullptr) {
            return;
        }
        if (nivel == 1) {
            cout << no->data << " ";
        }
        else if (nivel > 1) {
            imprimirNivel(no->left, nivel - 1);
            imprimirNivel(no->right, nivel - 1);
        }
    }
    int calcularAltura(Bin_Node_Point no) {
        if (no == nullptr) {
            return 0;
        }
        int alturaEsquerda = calcularAltura(no->left);
        int alturaDireita = calcularAltura(no->right);
        return max(alturaEsquerda, alturaDireita) + 1;
    }
    void imprimirPorAltura(Bin_Node_Point raiz) {
        int altura = calcularAltura(raiz);
        for (int i = 1; i <= altura; i++) {
            cout << "Nivel " << i << ": ";
            imprimirNivel(raiz, i);
            cout << endl;
        }
    }

    //função para exibir o menu
    Bin_Node_Point BST_menu(Bin_Node_Point root) {
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
                root = BST_Insert_Node(root, Bin_CreateNode(x));
                cout << "No inserido!" << endl << endl;
                break;
            case 1:
                cout << "Digite um valor para a busca: ";
                cin >> x;
                aux = BST_Search(root, x);
                if (aux)
                    cout << x << " esta na arvore! " << endl << endl;
                else
                    cout << x << " nao esta na arvore!" << endl << endl;
                break;
            case 2:
                cout << "Digite um valor para ser removido: ";
                cin >> x;
                root = BST_Remove_Node(root, x);
                cout << "No removido!" << endl << endl;
                break;
            case 3:
                BST_Route_PreOrder(root);
                cout << endl << endl;
                break;
            case 4:
                BST_Route_PostOrder(root);
                cout << endl << endl;
                break;
            case 5:
                BST_Route_InOrder(root);
                cout << endl << endl;
                break;
            case 6:
                imprimirPorAltura(root);
                cout << endl << endl;
                break;
            default:
                break;
            }
        }
        return root;
    }

#endif