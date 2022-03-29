#include<iostream>

using namespace std;

struct veMayBay{
	int ma;
	string khoiHanh;
	string noiDen;
	float gia;
};
typedef struct veMayBay Ve;

struct Node{
	Ve data;
	Node *left;
	Node *right;
};
typedef Node * Tree;

void khoiTao(Tree &root){
	root = NULL;
}

Node *taoNode(Ve x){
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


void taoCay(Tree &root , Ve &x){
	int n;
	cout << "Nhap so luong ve : ";
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cout << "Nhap ma ve : ";
		cin >> x.ma;
		cout << "Nhap noi khoi hanh : ";
		fflush(stdin);
		getline(cin,x.khoiHanh);
		cout << "Nhap noi den : ";
		fflush(stdin);
		getline(cin,x.noiDen);
		cout << "Nhap gia ve : ";
		cin >> x.gia;
		Node *p = taoNode(x);
		chenNode(root,p);
		cout << "\n";
	}
}

void duyet1Node(Ve x){
	cout << x.ma << " - " << x.khoiHanh << " - " << x.noiDen << " - " << x.gia << endl;

}

void duyetCay(Tree root){
	if(root != NULL){
		duyet1Node(root->data);
		duyetCay(root->left);
		duyetCay(root->right);
	}
}

Node *timKiem(Tree root,int maVe){
	if(root != NULL){
		if(root->data.ma == maVe) return root;
		if(root->data.ma > maVe){
			return timKiem(root->left,maVe);
		}
		else{
			return timKiem(root->right,maVe);
		}
	}
	return NULL;
}

int main(){
	Tree root;
	Ve x;
	khoiTao(root);
	taoCay(root,x);
	cout << "Danh sach ve : " << endl;
	duyetCay(root);
	
	int maVe;
	cout << "Nhap ma ve can tim : ";
	cin >> maVe;
	Node *p = timKiem(root,maVe);
	if(p != NULL){
		duyet1Node(p->data);
	}
	else{
		cout << "Khong co ve nao" ;
	}
}
