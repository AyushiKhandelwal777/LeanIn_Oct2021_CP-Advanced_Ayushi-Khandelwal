#include<iostream>
#include<stdlib.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
	public:
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode() {
		delete left;
		delete right;
	}
};

BinaryTreeNode<int>* lca(BinaryTreeNode<int>* root, int n1,int n2){
	if(root == NULL){
		return NULL;
	}
	
	if(root->data > n1 && root->data > n2){
		return lca(root->left, n1, n2);
	}
	
	if(root->data < n1 && root->data < n2){
		return lca(root->right, n1, n1);
	}
	
	return root;
}
