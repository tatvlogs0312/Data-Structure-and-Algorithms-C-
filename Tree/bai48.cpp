#include <iostream>

using namespace std;

struct monHoc{
	int ma;
	string name;
	int stc;
	int stdd;
};
typedef struct monHoc MH;

struct Node{
	MH data;
	Node * left;
	Node * right;
};
typedef Node * Tree;

void khoitao(Tree &root){
	root = NULL;
}

Node *taoNode(MH x){
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
		if(root->data.ma == p->data.ma) return ;
		if(root->data.ma > p->data.ma){
			chenNut(root->left,p);
		}
		else{
			chenNut(root->right,p);
		}
	}
	else{
		root = p;
	}
}

void taoCay(Tree &root , MH &x){
	int n;
	cout << "Nhap so luong mon hoc : " ;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cout << "Nhap ma mon hoc : ";
		cin >> x.ma;
		cout << "nhap ten mon hoc : ";
		fflush(stdin);
		getline(cin,x.name);
		cout << "Nhap so ti chi : ";
		cin >> x.stc;
		cout << "Nhap so tiet da day : ";
		cin >> x.stdd;
		Node *p = taoNode(x);
		chenNut(root,p);
		cout << "\n";
	}
}

void duyet1Node(MH x){
	cout << x.ma <<  " - " << x.name << " - " << x.stc << " - " << x.stdd << endl;
}

void duyetCay(Tree root){
	if(root != NULL){
		duyet1Node(root->data);
		duyetCay(root->left);
		duyetCay(root->right);
	}
}

Node *timKiem(Tree root, int mamh){
	if(root != NULL){
		if(root->data.ma == mamh) return root;
		if(root->data.ma > mamh){
			return timKiem(root->left,mamh);
		}
		else{
			return timKiem(root->right,mamh);
		}
	}
	else{
		return NULL;
	}
}

int main(){
	Tree root;
	MH x;
	khoitao(root);
	taoCay(root,x);
	cout << "Danh sach mon hoc : " << endl;
	duyetCay(root);
	
	int mamh;
	cout << "Nhap ma mon hoc can tim : " ;
	cin >> mamh;
	Node *p = timKiem(root,mamh);
	if(p == NULL){
		cout << "Khong tim thay mon hoc";
	}
	else{
		duyet1Node(p->data);
	}
}
