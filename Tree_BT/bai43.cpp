#include <iostream>

using namespace std;

struct Date{
	int ngay;
	int thang;
	int nam;
};

struct nhanVien{
	int manv;
	string name;
	Date date;
	long luong;
};
typedef struct nhanVien NV;

struct Node{
	NV data;
	Node * left;
	Node * right;
};
typedef Node * Tree;

void khoitao(Tree &root){
	root = NULL;
}

Node *taoNode(NV x){
	Node *p = new Node();
	if(p != NULL){
		p->data = x;
		p->left = NULL;
		p->right = NULL;
	}
	return p;
}

void chenNut(Tree &root, Node *p){
	if(root != NULL){
		if(root->data.manv == p->data.manv){
			return;
		}
		if(root->data.manv > p->data.manv){
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


void taoCay(Tree &root, NV &x){
	int n;
	cout << "Nhap so nhan vien : ";
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cout << "Nhap ma nhan vien : ";
		cin >> x.manv;
		cout << "Nhap ten : ";
		fflush(stdin);
		getline(cin,x.name);
		cout << "Nhap ngay sinh : ";
		cin >> x.date.ngay;
		cout << "Nhap thang sinh : ";
		cin >> x.date.thang;
		cout << "Nhap nam sinh : ";
		cin >> x.date.nam;
		cout << "Nhap luong : ";
		cin >> x.luong;
		Node *p = taoNode(x);
		chenNut(root,p);
		cout << "\n";
	}
}

void duyet1Node(NV x){
	cout << x.manv << " - " << x.name << " - " << x.date.ngay << "/" << x.date.thang << "/" << x.date.nam << " - " << x.luong << endl;
}

void duyet(Tree root){
	if(root != NULL){
		duyet1Node(root->data);
		duyet(root->left);
		duyet(root->right);
	}
}

void timKiem(Tree root , int ma){
	if(root != NULL){
		if(root->data.manv == ma){
		duyet1Node(root->data);
			} 
		if(root->data.manv > ma){
			timKiem(root->left,ma);
		}
		else{
			timKiem(root->right,ma);
		}
	}
	else{
		cout << "Khong co nhan vien";
	}
	
}

int main(){
	Tree root;
	khoitao(root);
	NV x;
	taoCay(root,x);
	cout << "Danh sach nhan vien : " << endl;
	duyet(root);
	
	int ma;
	cout << "Nhap ma can tim : ";
	cin >> ma;
	timKiem(root,ma);
}
