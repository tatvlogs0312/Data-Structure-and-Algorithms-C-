#include <iostream>

using namespace std;

struct khachHang
{
    int ma;
    string name;
    string sdt;
    long thanhToan;
};
typedef struct khachHang KH;

void nhap(KH *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap ma khach hang : ";
        cin >> a[i].ma;
        cout << "Nhap ten khach hang : ";
        fflush(stdin);
        getline(cin, a[i].name);
        cout << "Nhap so dien thoai : ";
        fflush(stdin);
        getline(cin, a[i].sdt);
        cout << "Nhap tien thanh toan : ";
        cin >> a[i].thanhToan;
        cout << "\n";
    }
}

void xuat1KH(KH a)
{
    cout << a.ma << " - " << a.name << " - " << a.sdt << " - " << a.thanhToan << endl;
}

void xuat(KH *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        xuat1KH(a[i]);
    }
}

void inserttionSort(KH *a, int n)
{
    int pos;
    for (int i = 1; i < n; i++)
    {
        KH x = a[i];
        pos = i - 1;
        while (pos >= 0 && a[pos].thanhToan > x.thanhToan)
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}

int binarySearch(KH *a, int n, int x)
{
    int mid, left = 0, right = n - 1;
    do
    {
        mid = (left + right) / 2;
        if (a[mid].thanhToan == x)
            return mid;
        if (a[mid].thanhToan > x)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    } while (left <= right);
    return -1;
}

int main()
{
    int n;
    cout << "Nhap so luong khach hang : ";
    cin >> n;
    KH *a = new KH[n];
    nhap(a, n);
    cout << "Danh sach khach hang : " << endl;
    xuat(a, n);

    inserttionSort(a, n);
    cout << "Danh sach khach hang sau khi sap xep : " << endl;
    xuat(a, n);

    int x;
    cout << "Nhap so tien muon tim : ";
    cin >> x;
    int kq = binarySearch(a, n, x);
    if (kq == -1)
    {
        cout << "Khong co khach hang nao ";
    }
    else
    {
        xuat1KH(a[kq]);
        int t = kq - 1;
        while(t >= 0 && a[t].thanhToan == x){
            xuat1KH(a[t]);
            t--;
        }
        int p = kq + 1;
        while(p < n && a[p].thanhToan == x){
            xuat1KH(a[p]);
            p++;
        }
    }
}