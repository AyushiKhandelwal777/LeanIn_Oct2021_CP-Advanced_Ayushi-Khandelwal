#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class Treenode{
	public:
		T data;
		vector<Treenode<T>*> children;
		Treenode(T data){
			this->data = data;
		}
		
		~Treenode(){
			for(int i=0;i<children.size();i++){
				delete children[i];
			}
		}
};


Treenode<int>* inputLevelWise(){
	int rootData;
	cout<<"\nEnter root data : ";
	cin>>rootData;
	Treenode<int>* root = new Treenode<int>(rootData);
	queue<Treenode<int>*> q;
	q.push(root);
	while(q.size()!=0){
		Treenode<int> *front = q.front();
		q.pop();
		int childNo;
		cout<<"\nEnter no. of children of "<<front->data<<" : ";
		cin>>childNo;
		for(int i=0;i<childNo;i++){
			int childData;
			cout<<"\nEnter "<<i<<"th child of "<<front->data<<" : ";
			cin>>childData;
			Treenode<int>* child = new Treenode<int>(childData);
			front->children.push_back(child);
			q.push(child);
		}
	}
	return root;
}

int countNodes(Treenode<int>* root)
{
	if(root==NULL){
		return 0;
	}
	int count=0;
	if(root->children.size()==0){
		return 1;
	}
	for(int i=0;i<root->children.size();i++)
	{
		count = count + countNodes(root->children[i]);
		
	}
	return count;
}

int main(){
	
	Treenode<int>* root= inputLevelWise();
	int x = countNodes(root);
	cout<<"\n\n\nCount : "<<x;
	return 0;
}
