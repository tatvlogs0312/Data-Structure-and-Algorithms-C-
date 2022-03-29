#include<iostream>

using namespace std;

struct sinhVien{
	int masv;
	string name;
	float dtk;
};
typedef struct sinhVien sv;

void nhap(sv *a , int n){
	for(int i = 0 ; i < n ;i++){
		cout << "Nhap ma sinh vien : " ;
		cin >> a[i].masv;
		cout << "Nhap ten : ";
		fflush(stdin);
		getline(cin,a[i].name);
		cout << "Nhap diem tong ket : ";
		cin >> a[i].dtk;
		cout << "\n";
	}
}

void xuat(sv *a , int n){
	for(int i = 0 ; i < n ;i++){
		cout << a[i].masv << " - " << a[i].name << " - " << a[i].dtk << endl;
	}
}

void InsertionSort(sv *a , int n){
	for(int i = 0 ; i < n - 1 ; i++){
		for(int j = i + 1 ; j < n ; j++){
			if(a[j].masv < a[i].masv){
				sv temp = a[i];
				a[i] = a[j];
				a[j] = temp;
//				swap(a[i],a[j]);
			}
		}
	}
}

void SelectionSort(sv *a , int n){
	for(int i = 0 ; i < n - 1 ; i++){
		int min = i;
		for(int j = i + 1 ; j < n ; j++){
			if(a[j].masv < a[min].masv){
//				sv temp = a[min];
//				a[min] = a[j];
//				a[j] = temp;
				swap(a[min],a[j]);
			}
		}
	}
}

void BubbleSort(sv *a , int n){
	for(int i = 0 ; i < n ; i++){
		for(int j = n - 1 ; j > i ; j--){
			if(a[j].masv < a[j-1].masv){
				swap(a[j],a[j-1]);
			}
		}
	}
}

void BubbleSort_2(sv *a , int n){
	for(int i = n - 1 ; i > 0 ; i--){
		for(int j = n - 1 - i ; j < i ; j++){
			if(a[j].masv > a[j+1].masv){
				swap(a[j], a[j+1]);
			}
		}
	}
}


int main(){
	int n ; 
	cout << "Nhap so luong sinh vien : ";
	cin >> n;
	sv *a = new sv[n];
	nhap(a,n);
	cout << "Danh sach sinh vien : " << endl;
	xuat(a,n);
	
	//InsertionSort(a,n);
	//SelectionSort(a,n);
	BubbleSort_2(a,n);
	cout << "Danh sach sinh vien sau khi sap xep : " << endl;
	xuat(a,n);
}
