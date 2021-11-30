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

void inorder(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

BinaryTreeNode<int>* leafDelete(BinaryTreeNode<int>* root){
	if(root==NULL){
		return NULL;
	}
	
	if(root->left==NULL && root->right){
		free(root);
		return NULL;
	}
	
	root->left = leafDelete(root->left);
	root->right = leafDelete(root->right);
	
	return root;
}
