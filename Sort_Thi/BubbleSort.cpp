#include<iostream>

using namespace std;

typedef struct SinhVien{
	int ma;
	string ten;
	string lop;
	float dtk;
}SV;

void nhap(SV *a , int n){
	for (int i = 0; i < n; ++i)
	{
		cout << "Nhap ma : ";
		cin >> a[i].ma;
		cout << "Nhap ten : ";
		fflush(stdin);
		getline(cin,a[i].ten);
		cout << "Nhap lop : ";
		fflush(stdin);
		getline(cin,a[i].lop);
		cout << "Nhap diem tong ket : ";
		cin >> a[i].dtk;
	}
}

void xuat1SV(SV a){
	cout << a.ma << " - " << a.ten << " - " << a.lop << " - " << a.dtk << endl;
}

void xuat(SV *a , int n){
	for(int i = 0 ; i < n ; i++){
		xuat1SV(a[i]);
	}
}

void bubbleSort(SV *a , int n){
	for(int i = 0 ; i < n ; i++){
		for(int j = n - 1 ; j > i ; j--){
			if(a[j].dtk < a[j - 1].dtk){
				swap(a[j],a[j - 1]);
			}
		}
	}
}

int binarySearch(SV *a , int n , int dtk){
	int left = 0 , right = n - 1;
	int mid;
	do{
		mid = (left + right) / 2;
		if(a[mid].dtk == dtk) return mid;
		if(a[mid].dtk > dtk){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	while(left <= right);
	return -1;
}

int main(){
	int n;
	cout << "Nhap so luong : " ;
	cin >> n;
	SV *a = new SV[n];
	nhap(a,n);
	cout << "Danh sach : " << endl;
	xuat(a,n);

	bubbleSort(a,n);
	cout << "Danh sach : " << endl;
	xuat(a,n);

	float dtk;
	cout << "Nhap diem tong ket : ";
	cin >> dtk;

	int kq = binarySearch(a,n,dtk);
	if(kq == -1){
		cout << "Khong co sinh vien nao" << endl;
	}
	else{
		xuat1SV(a[kq]);

		int t = kq - 1;
		while(t >= 0 && a[t].dtk == dtk){
			xuat1SV(a[t]);
			t--;
		}

		int p = kq + 1;
		while(p < n && a[p].dtk == dtk){
			xuat1SV(a[p]);
			p++;
		}
	}
}