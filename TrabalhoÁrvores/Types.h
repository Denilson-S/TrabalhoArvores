#ifndef TYPE_H
#define TYPE_H

//criação do tipo nó binário
struct Bin_Node {
	long long data;
	Bin_Node* left;
	Bin_Node* right;
};

//criação do tipo nó binário AVL
struct AVL_Node {
	int data;
	int height;
	AVL_Node* left;
	AVL_Node* right;
};

//criação do tipo nó Trie
struct Trie_Node {
	Trie_Node* filhos[26];
	bool end;
};

//criação do tipo nó B
struct B_Node {
	int key;
	B_Node* next;
};

//criação do tipo page B
struct B_Page {
	B_Node pages[4];
	B_Page* previous;
	bool is_Leaf;
	int cont;
};

//criação do tipo heap node
struct Heap_Node {
	int heap[31] = { 0 };
	int heap_Size = 0;
};

//criação do tipo ponteiro para os tipos criados anteriormente
typedef Bin_Node* Bin_Node_Point;
typedef AVL_Node* AVL_Node_Point;
typedef Trie_Node* Trie_Node_Point;
typedef B_Node* B_Node_Point;
typedef B_Page* B_Page_Point;
typedef Heap_Node* Heap_Node_Point;

//função de criação de nó Trie
Trie_Node_Point Trie_CreateNode() {
	Trie_Node_Point temp = new Trie_Node;
	temp->end = false;
	for (int i = 0; i < 26; i++)
		temp->filhos[i] = nullptr;

	return temp;
}

//função de criação de nó binário
Bin_Node_Point Bin_CreateNode(int valor) {
	Bin_Node_Point temp = new Bin_Node;
	temp->data = valor;
	temp->left = nullptr;
	temp->right = nullptr;

	return temp;
}
//função de criação de nó binário
AVL_Node_Point AVL_CreateNode(int valor) {
	AVL_Node_Point temp = new AVL_Node;
	temp->data = valor;
	temp->height = 0;
	temp->left = nullptr;
	temp->right = nullptr;

	return temp;
}

Heap_Node_Point Heap_CreateNode() {
	return new Heap_Node;
}

#endif 