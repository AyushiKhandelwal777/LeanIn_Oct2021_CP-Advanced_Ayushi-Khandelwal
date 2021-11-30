#include<iostream>
#include<queue>
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

void levelOrder(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}
	BinaryTreeNode<int>* curr;
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	q.push(NULL);
	
	while(q.size() > 1){
		curr = q.front();
		q.pop();
		
		if(curr == NULL){
			q.push(NULL);
			cout<<endl;
		}else{
			if(curr->left){
				q.push(curr->left);
			}
			if(curr->right){
				q.push(curr->right);
			}
			
			cout<<curr->data<<" ";
		}
	}	
}
