// Viet chuong trinh de quy in cac so le tu 1 den n

#include<iostream>

using namespace std;

int i = 1 ;

int inSoLe(int n)
{
	i++;
	if(i < n && i % 2 != 0)
	{
		cout << i << "\t" ;
		inSoLe(n);
	}
	else
	{
		inSoLe(n);
	}
}

int main()
{
	int n;
	cout << "Nhap n : " ;
	cin >> n;
	int kq = inSoLe(n);
	cout << kq;
}
