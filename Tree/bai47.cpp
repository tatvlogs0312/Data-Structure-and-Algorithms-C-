#include <iostream>

using namespace std;

struct vanDongVien{
	int ma;
	string name;
	int tuoi;
	float luong;
};
typedef struct vanDongVien VDV;

struct Node{
	VDV data;
	Node * left;
	Node * right;
};
typedef Node * Tree;

void khoiTao(Tree &root){
	root = NULL;
}

Node *taoNode(VDV x){
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
		if(root->data.ma == p->data.ma) return;
		if(root->data.ma > p->data.ma){
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

void taoCay(Tree &root , VDV &x){
	int n;
	cout << "Nhap so luong van dong vien : ";
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cout << "Nhap ma vdv : ";
		cin >> x.ma;
		cout << "Nhap ten vdv : ";
		fflush(stdin);
		getline(cin,x.name);
		cout << "Nhap tuoi : ";
		cin >> x.tuoi;
		cout << "Nhap luong : ";
		cin >> x.luong;
		Node *p = taoNode(x);
		chenNode(root,p);
		cout << "\n";
	}
}

void duyet1Node(VDV x){
	cout << x.ma << " - " << x.name << " - " << x.tuoi << " - " << x.luong << endl;
}

void duyetCay(Tree root){
	if(root != NULL){
		duyet1Node(root->data);
		duyetCay(root->left);
		duyetCay(root->right);
	}
}

Node *timKiem(Tree root , int mavdv){
	if(root != NULL){
		if(root->data.ma == mavdv) return root;
		if(root->data.ma > mavdv){
			return timKiem(root->left,mavdv);
		}
		else{
			return timKiem(root->right,mavdv);
		}
	}
	return NULL;
}

int main(){
	Tree root;
	VDV x;
	khoiTao(root);
	taoCay(root,x);
	cout << "Danh sach van dong vien : " << endl;
	duyetCay(root);
	
	int mavdv;
	cout << "Nhap ma can tim : ";
	cin >> mavdv;
	Node *p = timKiem(root,mavdv);
	if(p != NULL){
		duyet1Node(p->data);
	}
	else{
		cout << "Khong co van dong vien nao ";
	}
}
