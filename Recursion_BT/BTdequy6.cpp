//Viet chuong trinh de qui tinh tong cac phan tu cua 1 mang A (nguyen, n phan tu) ra man hinh

#include<iostream>

using namespace std;

void nhap(int a[] , int n , int i)
{
	if(i < n)
	{
		cout << "Nhap phan tu thu " << i << " : " ;
		cin >> a[i];
		nhap(a,n,i + 1);
	}
}

int tong(int a[] , int n)
{
	if(n > 0)
	{
		return a[n - 1] + tong(a,n-1);
	}
}

int main()
{
	int n;
	int i = 0;
	cout << "Nhap so phan tu : " ;
	cin >> n;
	int a[n];
	nhap(a,n,i);
	cout << "Tong cac phan tu : ";
	cout << tong(a,n);
}
