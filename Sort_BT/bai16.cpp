#include <iostream>

using namespace std;

struct date
{
    int ngay;
    int thang;
    int nam;
};

struct NhanVien
{
    int ma;
    string ten;
    date ngay;
    int luong;
};
typedef struct NhanVien NV;

void nhap(NV *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap ma nhan vien : ";
        cin >> a[i].ma;

        cout << "Nhap ten nhan vien : ";
        fflush(stdin);
        getline(cin, a[i].ten);

        cout << "Nhap ngay sinh : ";
        cin >> a[i].ngay.ngay;
        cout << "Nhap thang sinh : ";
        cin >> a[i].ngay.thang;
        cout << "Nhap nam sinh : ";
        cin >> a[i].ngay.nam;

        cout << "Nhap luong : ";
        cin >> a[i].luong;

        cout << "\n";
    }
}

void xuat1NV(NV a)
{
    cout << a.ma << " - " << a.ten << " - " << a.ngay.ngay << "/" << a.ngay.thang << "/" << a.ngay.nam << " - " << a.luong << endl;
}

void xuat(NV *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        xuat1NV(a[i]);
    }
}

void inserttionSort(NV *a, int n)
{
    int pos;
    for (int i = 1; i < n; i++)
    {
        NV x = a[i];
        pos = i - 1;
        while (pos >= 0 && a[pos].luong > x.luong)
        {
            a[pos + 1] = a[pos];
            pos--;
        }
        a[pos + 1] = x;
    }
}

int binarySearch(NV *a, int n, int x)
{
    int mid, left = 0, right = n - 1;
    do
    {
        mid = (left + right) / 2;
        if (a[mid].luong == x)
            return mid;
        if (a[mid].luong > x)
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

int main(int argc, char const *argv[])
{
    int n;
    cout << "Nhap so luong nhan vien : ";
    cin >> n;
    NV *a = new NV[n];
    nhap(a, n);
    cout << "Danh sach nhan vien : " << endl;
    xuat(a, n);

    inserttionSort(a, n);
    cout << "Danh sach nhan vien sau khi sap xep : " << endl;
    xuat(a, n);

    int x;
    cout << "Nhap luong cua nhan vien muon tim : ";
    cin >> x;
    int kq = binarySearch(a, n, x);
    if (kq == -1)
    {
        cout << "Khong co nhan vien nao" << endl;
    }
    else
    {
        xuat1NV(a[kq]);

        int t = kq - 1;
        while (t >= 0 && a[t].luong == x)
        {
            xuat1NV(a[t]);
            t--;
        }

        int p = kq + 1;
        while (p < n && a[p].luong == x)
        {
            xuat1NV(a[p]);
            p++;
        }
    }

    return 0;
}
