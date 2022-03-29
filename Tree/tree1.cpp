#include<iostream>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};
typedef Node* Tree;

void init(Tree &root){
	root = NULL;
}

Node* taoNode(int x){
	Node *p = new Node;
	if(p != NULL){
		p->left = NULL;
		p->right = NULL;
		p->data = x;
	}
	
	return p;	
}

void chenNut(Tree &root , Node *p){
	if(root != NULL){
		if(root->data == p->data){
			return;
		}
		if(root->data < p->data){
			chenNut(root->right,p);
		}
		else{
			chenNut(root->left,p);
		}
	}
	else{
		root = p;
	}
}

void taoCay(Tree &root){
	int x,n;
	cout << "Nhap n : " ;
	cin >> n;
	for(int i = 1; i <= n ; i++){
		cin >> x;
		Node *p = taoNode(x);
		chenNut(root,p);
	}
}

void duyetTruoc(Tree root){
	if(root != NULL){
		cout << root->data << " " ;
		duyetTruoc(root->left);
		duyetTruoc(root->right);
	}
}

void duyetGiua(Tree root){
	if(root != NULL){
		duyetGiua(root->left);
		cout << root->data << " " ;
		duyetGiua(root->right);
	}
}

void duyetSau(Tree root){
	if(root != NULL){
		duyetSau(root->left);
		duyetSau(root->right);
		cout << root->data << " " ;
	}
}

int main(){
	Tree root;
	init(root);
	taoCay(root);
	cout<<"duyet truoc : " ;
	duyetTruoc(root);
	cout<<"\n";
	cout<<"duyet giua : " ;
	duyetGiua(root);
	cout<<"\n";
	cout<<"duyet sau : " ;
	duyetSau(root);
}
