#include<iostream>

using namespace std;

struct sinhVien{
	int masv;
	string ten;
	string lop;
	float dtb;
};
typedef struct sinhVien SV;

void nhap(SV *a , int n){
	for(int i = 0 ; i < n ; i++){
		cout << "Nhap ma sinh vien : ";
		cin >> a[i].masv;
		cout << "Nhap ten sinh vien : ";
		fflush(stdin);
		getline(cin,a[i].ten);
		cout << "Nhap lop : ";
		fflush(stdin);
		getline(cin,a[i].lop);
		cout << "Nhap diem tong ket : ";
		cin >> a[i].dtb;
		cout << "\n" ;
	}
}

void xuat1SV(SV a){
	cout << a.masv << " - " << a.ten << " - " << a.lop << " - " << a.dtb << endl;
}

void xuat(SV *a , int n){
	for(int i = 0 ; i < n ; i++){
		xuat1SV(a[i]);
	}
}

void insertionSort(SV *a , int n){
	int pos;
	for(int i = 1 ; i < n ; i++){
		SV x = a[i];
		pos = i - 1;
		while(pos >= 0 && a[pos].masv > x.masv){
			a[pos+1] = a[pos];
			pos--;
		}
		a[pos+1] = x;
	}
}



int binarySearch(SV *a , int n , int x){
	int left = 0 , right = n - 1 , mid;
	
	do{
		mid = (left + right)/2;
		if(a[mid].masv == x){
			return mid;
		}
		else if(a[mid].masv < x){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	} while(left <= right);
	
	return -1;
}

int main(){
	int n;
	cout << "Nhap so luong sinh vien : " ;
	cin >> n;
	SV *a = new SV[n];
	nhap(a,n);
	cout << "Danh sach sinh vien : " << endl;
	xuat(a,n);
	
	insertionSort(a,n);
	cout << "Danh sach sau khi sap xep : " << endl;
	xuat(a,n);
	
	int x;
	cout << "Nhap ma sinh vien can tim : " ;
	cin >> x;	
	int pos = binarySearch(a,n,x);
	if(pos == -1){
		cout << "Khong co sinh vien nao" << endl;
	}
	else{
		cout << "Thong tin cua sinh vien co ma " << x << " trong mang : " << endl;
		xuat1SV(a[pos]);
		int t = pos - 1;
		while(t >= 0 && a[t].masv == x){
			xuat1SV(a[t]);
			t--;
		}
		int p = pos + 1;
		while(p < n && a[p].masv == x){
			xuat1SV(a[p]);
			p++;
		}
	}
}
