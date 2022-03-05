#include<iostream>

using namespace std;

struct sinhvien{
	int masv;
	string name;
	string lop;
	float dtb;
	string hk;
};
typedef sinhvien sv;

struct Node{
	sv data;
	Node* left;
	Node* right;
};
typedef Node* Tree;

void khoitao(Tree &root){
	root = NULL;
}

Node * taoNode(sv x){
	Node *p = new Node();
	if(p != NULL){
		p->data = x;
		p->left = NULL;
		p->right = NULL;
	} 
	return p;
}

void chenNut(Tree &root,Node *p){
	if(root != NULL){
		if(root->data.masv == p->data.masv) return;
		if(root->data.masv < p->data.masv){
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

void taoCay(Tree &root,sv &x){
	int n;
	cout << "Nhap so luong sinh vien : ";
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cout << "\n";
		cout << "Nhap sinh vien thu " << i+1 << ": " << endl;
		cout << "Nhap ma sinh vien : ";
		cin >> x.masv;
		cout << "Nhap ten : ";
		fflush(stdin);
		getline(cin,x.name);
		cout << "Nhap lop : ";
		fflush(stdin);
		getline(cin,x.lop);
		cout << "Nhap diem trung binh : ";
		cin >> x.dtb;
		cout << "Nhap hanh kiem : ";
		fflush(stdin);
		getline(cin,x.hk);
		Node *p = taoNode(x);
		chenNut(root,p);
	}
}

void duyet(sv x){
	cout << x.masv << " - " << x.name << " - " << x.lop << " - " << x.dtb << " - " << x.hk << endl;
}

void duyetTruoc(Tree root){
	if(root != NULL){
		duyet(root->data);
		duyetTruoc(root->left);
		duyetTruoc(root->right);
	}
}

Node * timKiem(Tree root , int x){
	if (root != NULL){
		if (x == root->data.masv){
			return root;
		} 
		else if(x < root->data.masv){
			return timKiem(root->left,x);
		}
		else {
			return timKiem(root->right,x);
		}
	}
	return NULL;
}

int main(){
	Tree root;
	sv x;
	khoitao(root);
	taoCay(root,x);
	cout << "\nDanh sach sinh vien : " << endl;
	duyetTruoc(root);
	
	int msv;
	cout << "Nhap ma sinh vien : " ;
	cin >> msv;
	Node * p = timKiem(root,msv);
	if(p == NULL){
		cout << "Ko co sv" ;
	} 
	else{
		duyet(p->data);
	}
}
