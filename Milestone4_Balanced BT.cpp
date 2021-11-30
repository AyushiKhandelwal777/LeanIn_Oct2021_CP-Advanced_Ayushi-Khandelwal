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

int max(int a, int b)
{
    return (a >= b) ? a : b;
}

int height(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

boolean isBalanced(BinaryTreeNode<int>* root){
	if(root==NULL){
		return true;	
	}else{
		int lh = height(root->left);
		int rh = height(root->right);
		if(abs(lh-rh) <= 1 && isBalanced(root->left) && is Balanced(root->right)){
			return true;
		}
	}
	
	return false;
}
