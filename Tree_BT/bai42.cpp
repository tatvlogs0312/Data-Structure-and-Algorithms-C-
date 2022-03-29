#include<iostream>

using namespace std;

struct khachhang{
	int makh;
	string name;
	long sdt;
	long thanhtoan;
};
typedef struct khachhang kh;

struct Node{
	kh data;
	Node * left;
	Node * right;
};
typedef Node * Tree;

void khoitao(Tree &root){
	root = NULL;
}

Node *taoNode(kh x){
	Node *p = new Node();
	if(p != NULL){
		p->data = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}

void chenNut(Tree &root , Node *p){
	if(root != NULL){
		if(root->data.makh == p->data.makh) return;
		if(root->data.makh < p->data.makh){
			chenNut(root->right,p);
		}
		else {
			chenNut(root->left,p);
		}
	}
	else {
		root = p;	
	}
}

void taoCay(Tree &root, kh &x){
	int n;
	cout << "Nhap so phan tu : " ;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cout << "Nhap ma khach hang : " ;
		cin >> x.makh;
		cout << "Nhap ten : " ;
		fflush(stdin);
		getline(cin,x.name);
		cout << "Nhap so dien thoai : " ;
		cin >> x.sdt;
		cout << "Tien thanh toan : " ;
		cin >> x.thanhtoan;
		Node *p = taoNode(x);
		chenNut(root,p);
		cout << "\n" ;
	}
}

void duyet1Node(kh x){
	cout << x.makh << " - " << x.name << " - " << x.sdt <<  " - " << x.thanhtoan << "VND" << endl;
}

void duyetCay(Tree root){
	if(root != NULL){
		duyet1Node(root->data);
		duyetCay(root->left);
		duyetCay(root->right);
	}
}

Node *timKiem(Tree root , int x){
	Node *p = root;
	if(p->data.makh == x){
		return p;
	}
	else if(p->data.makh > x){
		p = p->left;
	}
	else {
		p = p->right;
	}
}

int main(){
	Tree root;
	kh x;
	khoitao(root);
	taoCay(root,x);
	cout << "Danh sach khach hang : " << endl;
	duyetCay(root);
	
	int mkh;
	cout << "Nhap ma khach hang can tim kiem : ";
	cin >> mkh;
	Node *p = timKiem(root,mkh);
	if(p == NULL){
		cout << "Ko co khach hang" ;
	} 
	else{
		duyet1Node(p->data);
	}
}
