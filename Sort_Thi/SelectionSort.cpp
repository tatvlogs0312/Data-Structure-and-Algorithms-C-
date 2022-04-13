#include<iostream>

using namespace std;

typedef struct sinhvien{
    int ma;
    string name;
    string lop;
    float tk;
}SV;

void nhap(SV *a , int n){
    for(int i = 0 ; i < n ; i++){
        cout << "Nhap ma : ";
        cin >> a[i].ma;
        cout << "Nhap ten : ";
        fflush(stdin);
        getline(cin,a[i].name);
        cout << "Nhap lop : ";
        fflush(stdin);
        getline(cin,a[i].lop);
        cout << "Nhap diem tong ket : ";
        cin >> a[i].tk;
    }
}

void xuat1SV(SV a){
    cout << a.ma << " - " << a.name << " - " << a.lop << " - " << a.tk << endl;
}

void xuat(SV *a , int n){
    for(int i = 0 ; i < n ; i++){
        xuat1SV(a[i]);
    }
}

void selectionSort(SV *a , int n){
    for(int i = 0 ; i < n ; i++){
        int min = i;
        for(int j = i + 1 ; j < n ; j++){
            if(a[j].tk < a[min].tk){
                min = j;
            }
        }
        swap(a[i],a[min]);
    }
}

int binarySearch(SV *a , int n , int tk){
    int mid;
    int left = 0 , right = n - 1;
    do{
        mid = (left + right)/2;
        if(a[mid].tk == tk) return mid;
        if(a[mid].tk > tk){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    while(left <= right);
    return -1;
}

int main(){
    int n;
    cout << "Nhap so luong : ";
    cin >> n;
    SV * a = new SV[n];
    nhap(a,n);
    cout << "Danh sach : " << endl;
    xuat(a,n);

    selectionSort(a,n);
    cout << "Danh sach : " << endl;
    xuat(a,n);

    int tk;
    cout << "Nhap diem tong ket :";
    cin >> tk;
    int kq = binarySearch(a,n,tk);
    if(kq == -1){
        cout << "Khong co ai" << endl;
    }
    else{
        xuat1SV(a[kq]);

        int t = kq - 1;
        while(t >= 0 && a[t].tk == tk){
            xuat1SV(a[t]);
            t--;
        }

        int p = kq + 1;
        while(p < n && a[p].tk == tk){
            xuat1SV(a[p]);
            p++;
        }
    }
}