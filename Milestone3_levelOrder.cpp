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

void levelOrder(Treenode<int>* root)
{
	queue<Treenode<int>*> q;
	q.push(root);
	while(!q.empty()){
		int n = q.size();
		while(n>0){
			Treenode<int> *f = q.front();
			q.pop();
			cout<<f->data<<" ";
			
			for(int i=0;i<f->children.size();i++){
				q.push(f->children[i]);
			}
			n--;
		}
		cout<<endl;
	}
	
}

int main(){ 
	
	Treenode<int>* root= inputLevelWise();
	cout<<"\n\n\nPost Order Traversal is : ";
	levelOrder(root); 
}
