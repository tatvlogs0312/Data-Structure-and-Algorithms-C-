#include<iostream>

using namespace std;

struct hangHoa{
	int mahh;
	string name;
	int ngay;
	int thang;
	int nam;
	float gia;
};
typedef struct hangHoa HH;

struct Node{
	HH data;
	Node * left;
	Node * right;
};
typedef Node* Tree;

void khoiTao(Tree &root){
	root = NULL;
}

Node * taoNode(HH x){
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
		if(root->data.mahh == p->data.mahh) return;
		if(root->data.mahh < p->data.mahh){
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

void taoCay(Tree &root , HH &x){
	int n;
	cout << "Nhap so luong hang hoa : ";
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cout << "Nhap ma hang : ";
		cin >> x.mahh;
		cout << ("Nhap ten hang : ");
		fflush(stdin);
		getline(cin,x.name);
		cout << ("Nhap ngay xuat hang : ");
		cin >> x.ngay;
		cout << ("Nhap thang xuat hang : ");
		cin >> x.thang;
		cout << ("Nhap nam xuat hang : ");
		cin >> x.nam;
		cout << "Nhap gia hang : ";
		cin >> x.gia;
		Node *p = taoNode(x);
		chenNut(root,p);
		cout << "\n";		
	}
}

void duyet1Node(HH x){
	cout << x.mahh << " - " << x.name << " - " << x.ngay << "/" << x.thang << "/" << x.nam << " - " << x.gia << "M" << endl;
}

void duyetCay(Tree root){
	if(root != NULL){
		duyet1Node(root->data);
		duyetCay(root->left);
		duyetCay(root->right);
	}
}

Node * timKiem(Tree root , int x){
	Node *p = root;
	while (p != NULL){
		if (x == p->data.mahh){
			return p;
		} 
		else if(x < p->data.mahh){
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	return NULL;
}

int main(){
	Tree root;
	HH x;
	khoiTao(root);
	taoCay(root,x);
	cout << "Danh sach hang hoa : " << endl;
	duyetCay(root);
	
	int mhh;
	cout << "Nhap ma hang : " ;
	cin >> mhh;
	Node * p = timKiem(root,mhh);
	if(p == NULL){
		cout << "Ko co hang" ;
	} 
	else{
		duyet1Node(p->data);
	}
}
