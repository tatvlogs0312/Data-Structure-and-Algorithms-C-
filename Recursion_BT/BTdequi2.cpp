//Viet chuong trinh de qui in cac so le tu n den 1

#include<iostream>

using namespace std;

int inSoLe(int n)
{
	if(n == 1) return 1;
	if(n % 2 != 0)
	{
		cout << n << "\n" ;
		return inSoLe(n - 1);
	}
	else
	{
		return inSoLe(n - 1);
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
