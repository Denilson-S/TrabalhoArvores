#ifndef AVL_TREE

#define AVL_TREE

//inclusão dos arquivos externos
#include "Types.h"
#include<iostream>
using namespace std;

int AVL_Height(AVL_Node_Point root) {
    if (!root)
        return -1;
    return root->height;
}

AVL_Node_Point AVL_Turn_Right(AVL_Node_Point root) {
    AVL_Node_Point aux = root->left;
    root->left = aux->right;
    aux->right = root;

    root->height = max(AVL_Height(root->right), AVL_Height(root->left)) + 1;
    aux->height = max(AVL_Height(aux->left), root->height) + 1;

    return aux;
}

AVL_Node_Point AVL_Turn_Left(AVL_Node_Point root) {
    AVL_Node_Point aux = root->right;
    root->right = aux->left;
    aux->left = root;

    root->height = max(AVL_Height(root->right), AVL_Height(root->left)) + 1;
    aux->height = max(AVL_Height(aux->right), root->height) + 1;

    return aux;
}

AVL_Node_Point AVL_Turn_Left_Right(AVL_Node_Point root) {
    root->left = AVL_Turn_Left(root->left);
    return AVL_Turn_Right(root);
}

AVL_Node_Point AVL_Turn_Right_Left(AVL_Node_Point root) {
    root->right = AVL_Turn_Right(root->right);
    return AVL_Turn_Left(root);
}

//função de inserir um nó na arvore
AVL_Node_Point AVL_Insert_Node(AVL_Node_Point root, AVL_Node_Point node) {
    if (!root)
        return node;
    if (node->data < root->data) {
        root->left = AVL_Insert_Node(root->left, node);
        if (AVL_Height(root->left) - AVL_Height(root->right) == 2 || AVL_Height(root->left) - AVL_Height(root->right) == -2)
            if (node->data < root->left->data)
                root = AVL_Turn_Right(root);
            else
                root = AVL_Turn_Left_Right(root);

    }
    else
        if (node->data > root->data) {
            root->right = AVL_Insert_Node(root->right, node);
            if (AVL_Height(root->right) - AVL_Height(root->left) == 2 || AVL_Height(root->right) - AVL_Height(root->left) == -2)
                if (node->data > root->right->data)
                    root = AVL_Turn_Left(root);
                else
                    root = AVL_Turn_Right_Left(root);
        }
    root->height = max(AVL_Height(root->right), AVL_Height(root->left)) + 1;
    return root;
}

//função de busca por valor do nó
AVL_Node_Point AVL_Search(AVL_Node_Point root, int valor) {
    if (root == nullptr)
        return nullptr;
    if (root->data == valor)
        return root;
    if (root->data > valor)
        return AVL_Search(root->left, valor);
    return AVL_Search(root->right, valor);
}

//função de remoção de nó por valor
AVL_Node_Point AVL_Remove_Node(AVL_Node_Point root, int data) {
    if (!root)
        return nullptr;

    // Etapa 1: Localizar o nó a ser removido
    if (data < root->data) {
        root->left = AVL_Remove_Node(root->left, data);
    }
    else if (data > root->data) {
        root->right = AVL_Remove_Node(root->right, data);
    }
    else {
        // Nó encontrado
        if (!root->left || !root->right) {
            // Caso 1: Nó com 0 ou 1 filho
            AVL_Node_Point temp = root->left ? root->left : root->right;
            free(root); // Libera o nó
            return temp;
        }
        else {
            // Caso 2: Nó com 2 filhos
            AVL_Node_Point temp = root->right;
            while (temp->left) // Encontra o menor nó da subárvore direita
                temp = temp->left;
            root->data = temp->data; // Substitui o valor do nó
            root->right = AVL_Remove_Node(root->right, temp->data);
        }
    }

    // Etapa 2: Atualizar a altura do nó
    root->height = max(AVL_Height(root->left), AVL_Height(root->right)) + 1;

    // Etapa 3: Rebalancear a árvore
    int balance = AVL_Height(root->left) - AVL_Height(root->right);

    // Caso 1: Desbalanceamento à esquerda
    if (balance > 1) {
        if (AVL_Height(root->left->left) >= AVL_Height(root->left->right)) {
            root = AVL_Turn_Right(root);
        }
        else {
            root = AVL_Turn_Left_Right(root);
        }
    }

    // Caso 2: Desbalanceamento à direita
    if (balance < -1) {
        if (AVL_Height(root->right->right) >= AVL_Height(root->right->left)) {
            root = AVL_Turn_Left(root);
        }
        else {
            root = AVL_Turn_Right_Left(root);
        }
    }

    return root;
}

//função de percurso em ordem
void AVL_Route_InOrder(AVL_Node_Point root) {
    if (root == nullptr)
        return;
    AVL_Route_InOrder(root->left);
    cout << root->data << " ";
    AVL_Route_InOrder(root->right);
}

//função de percurso pre ordem
void AVL_Route_PreOrder(AVL_Node_Point root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    AVL_Route_PreOrder(root->left);
    AVL_Route_PreOrder(root->right);
}

//função de percurso pós ordem
void AVL_Route_PostOrder(AVL_Node_Point root) {
    if (root == nullptr)
        return;
    AVL_Route_PreOrder(root->left);
    AVL_Route_PreOrder(root->right);
    cout << root->data << " ";
}

//função de percurso por nível
void AVL_Print_LevelOrder(AVL_Node_Point no, int nivel) {
    if (no == nullptr) {
        return;
    }
    if (nivel == 1) {
        cout << no->data << " ";
    }
    else if (nivel > 1) {
        AVL_Print_LevelOrder(no->left, nivel - 1);
        AVL_Print_LevelOrder(no->right, nivel - 1);
    }
}
int AVL_Get_Height(AVL_Node_Point no) {
    if (no == nullptr) {
        return 0;
    }
    int alturaEsquerda = AVL_Get_Height(no->left);
    int alturaDireita = AVL_Get_Height(no->right);
    return max(alturaEsquerda, alturaDireita) + 1;
}
void AVL_Route_LevelOrder(AVL_Node_Point raiz) {
    int altura = AVL_Get_Height(raiz);
    for (int i = 1; i <= altura; i++) {
        cout << "Nivel " << i << ": ";
        AVL_Print_LevelOrder(raiz, i);
        cout << endl;
    }
}


//função para exibir o menu
AVL_Node_Point AVL_menu(AVL_Node_Point root) {
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
            root = AVL_Insert_Node(root, AVL_CreateNode(x));
            cout << "No inserido!" << endl << endl;
            break;
        case 1:
            cout << "Digite um valor para a busca: ";
            cin >> x;
            aux = AVL_Search(root, x);
            if (aux)
                cout << x << " esta na arvore! " << endl << endl;
            else
                cout << x << " nao esta na arvore!" << endl << endl;
            break;
        case 2:
            cout << "Digite um valor para ser removido: ";
            cin >> x;
            root = AVL_Remove_Node(root, x);
            cout << "No removido!" << endl << endl;
            break;
        case 3:
            AVL_Route_PreOrder(root);
            cout << endl << endl;
            break;
        case 4:
            AVL_Route_PostOrder(root);
            cout << endl << endl;
            break;
        case 5:
            AVL_Route_InOrder(root);
            cout << endl << endl;
            break;
        case 6:
            AVL_Route_LevelOrder(root);
            cout << endl << endl;
            break;
        default:
            break;
        }
    }
    return root;
}
#endif