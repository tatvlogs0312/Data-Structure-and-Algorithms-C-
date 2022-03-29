#include<iostream>

using namespace std;

struct TaiLieu
{
    int ma;
    string ten;
    int namxb;
    float gia;
};
typedef struct TaiLieu TL;

void nhap(TL *a , int n){
    for(int i = 0 ; i < n ; i++){
        cout << "Nhap ma tai lieu : ";
        cin >> a[i].ma;
        cout << "Nhap ten tai lieu : ";
        fflush(stdin);
        getline(cin,a[i].ten);
        cout << "Nhap nam xuat ban : ";
        cin >> a[i].namxb;
        cout << "Nhap gia ban : ";
        cin >> a[i].gia;

        cout << "\n";
    }
}

void xuat1TL(TL a){
    cout << a.ma << " - " << a.ten << " - " << a.namxb << " - " << a.gia << endl;
}

void xuat(TL *a , int n){
    for (int i = 0; i < n; ++i)
    {
        xuat1TL(a[i]);
    }
}

void inserttionSort(TL *a , int n){
    int pos;
    for (int i = 1; i < n; i++)
    {
        TL x = a[i];
        pos = i - 1;
        while(pos >= 0 && a[pos].gia > x.gia){
            a[pos+1] = a[pos];
            pos--;
        }
        a[pos+1] = x;
    }
}

int binarySearch(TL *a , int n , int x){
    int mid , left = 0 , right = n - 1;
    do 
    {
    	mid = (left + right)/2;
        if(a[mid].gia == x) return mid;
        if(a[mid].gia > x){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    } while (left <= right);
    return -1;
    
}


int main(int argc, char const *argv[])
{
    int n;
    cout << "Nhap so luong tai lieu : ";
    cin >> n;
    TL * a = new TL[n];

    nhap(a,n);
    cout << "Danh sach tai lieu : " << endl;
    xuat(a,n);

    inserttionSort(a,n);
    cout << "Danh sach tai lieu sau khi sap xep : " << endl;
    xuat(a,n);

    int x;
    cout << "Nhap gia ban tai lieu muon tim : ";
    cin >> x;
    int kq = binarySearch(a,n,x);
    if(kq == -1){
        cout << "Khong co tai lieu nao" << endl;
    }
    else{
        xuat1TL(a[kq]);

        int t = kq - 1;
        while(t >= 0 && a[t].gia == x){
            xuat1TL(a[t]);
            t--;
        }
        int p = kq + 1;
        while(p < n && a[p].gia == x){
            xuat1TL(a[p]);
            p++;
        }
    }

    return 0;
}
