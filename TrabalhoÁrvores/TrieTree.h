#ifndef RETRIVAL_TREE

    #define RETRIVAL_TREE

    //inclusão dos arquivos externos
    #include "Types.h"
    #include<iostream>
    using namespace std;

    //função de mapeamento
    int Trie_Mapping(char character) {
        return ((int)character - (int)'a');
    }

    //função de inserir uma palavra na arvore
    void Trie_Insert_Node(Trie_Node_Point root, string key) {
        int lenght = key.length();
        int index;

        Trie_Node_Point temp = root;
        for (int level = 0; level < lenght; level++) {
            index = Trie_Mapping(key[level]);
            if (!temp->filhos[index])
                temp->filhos[index] = Trie_CreateNode();
            temp = temp->filhos[index];
        }
        temp->end=true;
    }

    //função de busca por prefixo
    void Trie_Search(Trie_Node_Point root, string prefix = "", int level =0, int length =0) {
        if (!root) return;
        if (!length)
            length = prefix.length();
        if (level < length) {
            int index = Trie_Mapping(prefix[level]);
            Trie_Search(root->filhos[index], prefix, level + 1, length);
        }
        else {
            if (root->end) {
                cout << prefix << endl;
            }
            for (int i = 0; i < 26; i++) {
                if (root->filhos[i])
                    Trie_Search(root->filhos[i], prefix + char('a' + i), level + 1, length);
            }
        }
    }


    //função de remoção de palavra
    Trie_Node_Point Trie_Remove_Node(Trie_Node_Point root, string key, int length =0, int level = 0) {
        if (!root)
            return nullptr;
        if (!length)
            length = key.length();
        int index = Trie_Mapping(key[level]);

        if (length > level)
            root->filhos[index] = Trie_Remove_Node(root->filhos[index], key, length, level + 1);

        if (length == level)
            root->end = false;
        if (!root->end) {
            for (int i = 0; i < 26; i++)
                if (root->filhos[i])
                    return root;
            delete root;
            return nullptr;
        }
        return root; 
    }

    //função de percurso em ordem
    void Trie_Route_InOrder(Trie_Node_Point root, int index = 0) {
        if (!root) return;
        int aux = 0;
        for (int i = 0; i < 26; i++) {
            if (root->filhos[i]) {
                Trie_Route_InOrder(root->filhos[i], i + 'a');
                if (!aux) {
                    cout << char(index) << " ";
                    aux++;
                }
            }
        }
        if (!aux) {
            cout << char(index) << " ";
            aux++;
        }
    }

    //função de percurso pre ordem
    void Trie_Route_PreOrder(Trie_Node_Point root, int index=0) {
        if (!root) return;
        if (index) {
            cout << char(index) << " ";
        }
        for (int i = 0; i < 26; i++) {
            if (root->filhos[i]) {
                Trie_Route_PreOrder(root->filhos[i],i+'a');
            }
        }
    }

    //função de percurso pós ordem
    void Trie_Route_PostOrder(Trie_Node_Point root, int index = 0) {
        if (!root) return;
        for (int i = 0; i < 26; i++) {
            if (root->filhos[i]) {
                Trie_Route_PostOrder(root->filhos[i], i + 'a');
            }
        }
        if (index) {
            cout << char(index) << " ";
        }
    }

    //exibir todas as palavras em ordem alfabetica
    void Trie_Route_AlfaOrder(Trie_Node_Point root, string prefix = "") {
        if (!root) return;
        if (root->end) {
            cout << prefix << endl;
        }
        for (int i = 0; i < 26; i++) {
            if (root->filhos[i]) {
                Trie_Route_AlfaOrder(root->filhos[i], prefix + char('a' + i));
            }
        }
    }

    //funções de percurso por nível
    int Trie_Height(Trie_Node_Point root) {
        if (!root) return 0;

        int maxHeight = 0;
        for (int i = 0; i < 26; i++) {
            if (root->filhos[i]) {
                maxHeight = max(maxHeight, Trie_Height(root->filhos[i]));
            }
        }
        return maxHeight + 1; // Contabiliza o nó atual
    }

    // Função auxiliar para imprimir todos os nós de um nível específico
    void Trie_Print_Level(Trie_Node_Point root, int level, char prefix = ' ') {
        if (!root) return;

        if (level == 0) { // Estamos no nível desejado
            cout << prefix << " "; // Imprime o prefixo até o nó atual
        }
        else {
            for (int i = 0; i < 26; i++) {
                if (root->filhos[i]) {
                    Trie_Print_Level(root->filhos[i], level - 1, char('a' + i));
                }
            }
        }
    }

    // Função principal para percurso por nível
    void Trie_Route_LevelOrder(Trie_Node_Point root) {
        int height = Trie_Height(root);

        for (int i = 0; i < height; i++) {
            cout << "Nivel " << i << ": ";
            Trie_Print_Level(root, i); // Imprime todos os nós no nível i
            cout << endl;
        }
    }

    //função para exibir o menu
    Trie_Node_Point Trie_menu(Trie_Node_Point root) {
        int control = 0;
        while (control != 8) {
            cout << "Inserir palavra:.............0" << endl
                 << "Procurar por prefixo:........1" << endl
                 << "Remover palavra:.............2" << endl
                 << "Exibir percurso pre ordem:...3" << endl
                 << "Exibir percurso pos ordem:...4" << endl
                 << "Exibir percurso em ordem:....5" << endl
                 << "Exibir percurso por nivel:...6" << endl
                 << "Exibir em ordem alfabetica:..7" << endl
                 << "Sair:........................8" << endl << endl
                 << "Opcao: ";

            if (!(cin >> control)) {
                cin.clear();
                cin.ignore(1000, '\n');
                control = -1;
                cout << endl;
            }

            while (control < 0 || control>8) {
                cout << "Opcao invalida!" << endl
                    << "Digite novamente : ";
                if (!(cin >> control)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    control = -1;
                }
                cout << endl;
            }

            string x;
            Bin_Node_Point aux;
            switch (control)
            {
            case 0:
                cout << "Digite uma palavra: ";
                cin >> x;
                Trie_Insert_Node(root,x);
                cout << "Palavra inserida!" << endl << endl;
                break;
            case 1:
                cout << "Digite uma palavra para a busca: ";
                cin >> x;
                Trie_Search(root, x);
                cout << endl << endl;
                break;
            case 2:
                cout << "Digite uma palavra para ser removida: ";
                cin >> x;
                root = Trie_Remove_Node(root, x);
                if (!root)
                    root = Trie_CreateNode();
                cout << "Palavra removida!" << endl << endl;
                break;
            case 3:
                Trie_Route_PreOrder(root);
                cout << endl << endl;
                break;
            case 4:
                Trie_Route_PostOrder(root);
                cout << endl << endl;
                break;
            case 5:
                Trie_Route_InOrder(root);
                cout << endl << endl;
                break;
            case 6:
                Trie_Route_LevelOrder(root);
                cout << endl << endl;
                break;
            case 7:
                Trie_Route_AlfaOrder(root);
                cout << endl << endl;
                break;
            default:
                break;
            }
        }
        return root;
    }

#endif