#include<iostream>

using namespace std;

struct date{
	int ngay;
	int thang;
	int nam;
};

typedef struct HangHoa{
	int ma;
	string ten;
	date ngayxh;
	float gia;
}HH;

void nhap(HH *a , int n){
	for(int i = 0 ; i < n ; i++){
		cout << "Nhap ma hang : ";
		cin >> a[i].ma;
		cout << "Nhap ten hang : ";
		fflush(stdin);
		getline(cin,a[i].ten);
		cout << "Nhap ngay xuat hang : ";
		cin >> a[i].ngayxh.ngay;
		cout << "Nhap thang xuat hang : ";
		cin >> a[i].ngayxh.thang;
		cout << "Nhap nam xuat hang : ";
		cin >> a[i].ngayxh.nam;
		cout << "Nhap gia : ";
		cin >> a[i].gia;
		cout << "\n";
	}
}

void xuat1HH(HH a){
	cout << a.ma << " - " << a.ten << " - " << a.ngayxh.ngay << "/" << a.ngayxh.thang << "/" << a.ngayxh.nam << " - " << a.gia << endl;
}

void xuat(HH *a , int n){
	for(int i = 0 ; i < n ; i++){
		xuat1HH(a[i]);
	}
}


void insertionSort(HH *a , int n){
	int pos;
	for(int i = 1 ; i < n ; i++){
		pos = i - 1;
		HH x = a[i];
		while(pos >= 0 && a[pos].ma > x.ma){
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos+1] = x;
	}
}

int binarySearch(HH *a , int n , int x){
	int mid , left = 0 , right = n - 1;
	while(left <= right){
		mid = (left + right)/2;
		if(a[mid].ma == x) return mid;
		if(a[mid].ma < x){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	
	return -1;
}

int main(){
	int n;
	cout << "Nhap so luong hang hoa : ";
	cin >> n;
	HH *a = new HH[n];
	nhap(a,n);
	cout << "Danh sach hang hoa : " << endl;
	xuat(a,n);
	
	insertionSort(a,n);
	cout << "Danh sach hang hoa sau khi sap xep : " << endl;
	xuat(a,n);
	
	int x;
	cout << "Nhap ma can tim : ";
	cin >> x;
	
	int pos = binarySearch(a,n,x);
	if(pos == -1){
		cout << "Khong tim thay hang hoa nao" << endl;
	}
	else{
		xuat1HH(a[pos]);
		
		int t = pos - 1;
		while(t >= 0 && a[t].ma == x){
			xuat1HH(a[t]);
			t--;
		}
		
		int p = pos + 1;
		while(p < n && a[p].ma == x){
			xuat1HH(a[p]);
			p++;
		}
	}
}
