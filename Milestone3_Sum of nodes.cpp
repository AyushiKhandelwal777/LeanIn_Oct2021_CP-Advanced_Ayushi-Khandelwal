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
	static int sum;
	sum = sum + root->data;
	for(int i=0;i<root->children.size();i++)
	{
		countNodes(root->children[i]);
	}
	return sum;
}

int main(){
//	1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0 
	
	Treenode<int>* root= inputLevelWise();
	int x = countNodes(root);
	cout<<"\n\n\nSum : "<<x;
	return 0;
}
