//Viet chuong trinh de qui in cac so chan tu n den 0

#include<iostream>

using namespace std;

int inSoChan(int n)
{
	if(n == 0) return 0;
	if(n % 2 == 0)
	{
		cout << n << "\n" ;
		return inSoChan(n - 1);
	}
	else
	{
		return inSoChan(n - 1);
	}
	
}

int main()
{
	int n;
	cout << "Nhap n : " ;
	cin >> n;
	int kq = inSoChan(n);
	cout << kq;
}
