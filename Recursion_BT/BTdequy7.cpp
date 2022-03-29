//Viet chuong trinh de qui tinh UCLN cua 2 so a, b(ap dung giaii thuat Euclid)

#include <iostream>

using namespace std;

int UCLN(int a, int b)
{
    while ( a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

    return a;
}

int BCNN(int a, int b)
{
    int kq = UCLN(a, b);
    return a * b / kq;
}

int main()
{
    int a, b;
    cout << "Nhap a :  ";
    cin >> a;
    cout << "Nhap b :  "; 
    cin >> b;
    int kq = UCLN(a, b);   
    cout << "UCLN : "<< kq << endl;
    kq = BCNN(a, b);
    cout << "BCNN : " << kq<< endl;
}
