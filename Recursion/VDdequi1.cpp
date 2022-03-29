#include <iostream>

using namespace std;

int GT(int n)
{
	if(n == 0)
	{
		return 1;
	}
	else
	{
		return n * GT(n - 1);
	}
}

int main(){
	int n;
	cout << "Nhap n : " ;
	cin >> n;
	int kq = GT(n);
	cout << n << "! = " << kq;
}
