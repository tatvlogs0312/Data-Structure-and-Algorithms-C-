#include<iostream>

using namespace std;

int inSoChan(int n)
{
	if(n == 0) return 0;
	if(n % 2 == 0)
	{
		cout << n << " " ;
	}
	return inSoChan(n - 1);
	
}

int main()
{
	int n;
	cout << "Nhap n : " ;
	cin >> n;
	int kq = inSoChan(n);
	cout << kq;
}
