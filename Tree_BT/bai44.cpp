#include<iostream>

using namespace std;

struct taiLieu{
	int matl;
	string name;
	int namxb;
	float gia;
};
typedef struct taiLieu TL;

struct Node{
	TL data;
	Node *left;
	Node *right;
};
typedef Node * Tree;

void khoiTao(Tree &root){
	root = NULL;
}

Node *taoNode(TL x){
	Node *p = new Node();
	if(p != NULL){
		p->data = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}

void chenNode(Tree &root , Node *p){
	if(root != NULL){
		if(root->data.matl == p->data.matl) return;
		if(root->data.matl > p->data.matl){
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

void taoCay(Tree &root , TL &x){
	int n;
	cout << "Nhap so luong tai lieu : ";
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cout << "Nhap ma tai lieu : " ;
		cin >> x.matl;
		cout << "Nhap ten tai lieu : ";
		fflush(stdin);
		getline(cin,x.name);
		cout << "Nhap nam xuat ban : ";
		cin >> x.namxb;
		cout << "Nhap gia ban : " ;
		cin >> x.gia;
		Node *p = taoNode(x);
		chenNode(root,p);
		cout << "\n";
	}
}

void duyet1Node(TL x){
	cout << x.matl << " - " << x.name << " - " << x.namxb << " - " << x.gia << endl;
}

void duyetCay(Tree root){
	if(root != NULL){
		duyet1Node(root->data);
		duyetCay(root->left);
		duyetCay(root->right);
	}
}

void timKiem(Tree root , int ma){
	if(root != NULL){
		if(root->data.matl == ma){
			duyet1Node(root->data);
		}
		if(root->data.matl > ma){
			timKiem(root->left,ma);
		}
		else{
			timKiem(root->right,ma);
		}
	}
	else{
		cout << "Khong co tai lieu nao";
	}
}

int main(){
	Tree root;
	TL x;
	khoiTao(root);
	taoCay(root,x);
	cout << "Danh sach tai lieu : " << endl;
	duyetCay(root);
	
	int ma;
	cout << "Nhap ma can tim : " ;
	cin >> ma;
	timKiem(root,ma);
}
