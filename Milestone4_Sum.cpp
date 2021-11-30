#include<iostream>
#include<stack>
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

void allPairs(BinaryTreeNode<int>* root, int target){
	stack<BinaryTreeNode<int>*> s1;
	stack<BinaryTreeNode<int>*> s2;
	
	BinaryTreeNode<int>* root1 = root;
	BinaryTreeNode<int>* root2 = root;
	BinaryTreeNode<int>* cur1 = NULL;
	BinaryTreeNode<int>* cur2 = NULL;
	
	bool find1 = false, find2 = false;
	
	while(1){
		if(find1==false){
			while(root!=NULL){
				s1.push(root1);
				root1=root1->left;
			}
			cur1=s1.top();
			s1.top();
			root1=cur1->right;
			find1=true;
		}
		
		if(find2==false){
			while(root2!=NULL){
				s2.push(root2);
				root2 = root2->right;
			}
			cur2=s2.top();
			s2.top();
			root2=cur2->left;
			find2=true;
		}
		
		if(cur1->data >= cur2->data){
			break;
		}
		
		if(cur1->data + cur2->data < target){
			find1 = false;
		}else{
			find2 = false;
		}
	}
}
