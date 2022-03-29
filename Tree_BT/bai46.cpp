#include<iostream>

using namespace std;

typedef struct DuAn{
	int mda;
	string name;
	float kinhPhi;
}DA;

struct Node{
	DA data;
	Node *left;
	Node *right;
};
typedef Node * Tree;

void khoiTao(Tree &root){
	root = NULL;
}

Node *taoNode(DA x){
	Node *p = new Node;
	if(p != NULL){
		p->data = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}

void chenNode(Tree &root , Node *p){
	if(root != NULL){
		if(root->data.mda == p->data.mda) return;
		if(root->data.mda > p->data.mda){
			chenNode(root->left,p);
		}
		else{
			chenNode(root->right,p);
		}
	}
	else{
		root = p;
	}
}

void taoCay(Tree &root , DA &x){
	int n;
	cout << "Nhap so luong du an : ";
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cout << "Nhap ma du an : ";
		cin >> x.mda;
		cout << "Nhap ten du an : ";
		fflush(stdin);
		getline(cin,x.name);
		cout << "Nhap kinh phi : ";
		cin >> x.kinhPhi;
		Node *p = taoNode(x);
		chenNode(root,p);
		cout << "\n";
	}
}

void duyet1Node(DA x){
	cout << x.mda << " - " << x.name << " - " << x.kinhPhi << " ti dong " << endl;
}

void duyetCay(Tree root){
	if(root != NULL){
		duyet1Node(root->data);
		duyetCay(root->left);
		duyetCay(root->right);
	}
}

Node *timKiem(Tree root , int ma){
	if(root != NULL){
		if(root->data.mda == ma) return root;
		if(root->data.mda > ma){
			return timKiem(root->left,ma);
		}
		else{
			return timKiem(root->right,ma);
		}
	}
	return NULL;
}

int main(){
	Tree root;
	DA x;
	khoiTao(root);
	taoCay(root,x);
	cout << "Danh sach du an : " << endl;
	duyetCay(root);
	
	int ma;
	cout << "Nhap ma can tim : " ;
	cin >> ma;
	Node *p = timKiem(root,ma);
	if(p != NULL){
		duyet1Node(p->data);
	}
	else{
		cout << "Khong co du an nao";
	}
}
