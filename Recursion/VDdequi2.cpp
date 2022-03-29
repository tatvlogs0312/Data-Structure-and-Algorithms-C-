#include <iostream>

using namespace std;

int dem = 0;
int fibo(int n)
{
	cout << ++dem << " - fibo : " << n << endl;
	if(n < 3)
	{
		return 1;
	}
	return fibo(n - 1) + fibo(n - 2);
}

int main()
{
	int n;
	cout << "Nhap n : ";
	cin >> n;
	int kq = fibo(n);
	cout << "Fibo(" << n << ") : " << kq;
}

