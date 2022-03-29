#include<iostream>

using namespace std;

struct VeMayBay
{
    int ma;
    string khoiHanh;
    string noiDen;
    float gia;
};
typedef struct VeMayBay VMB;

void nhap(VMB *a , int n){
    for(int i = 0 ; i < n ; i++){
        cout << "Nhap ma ve : ";
        cin >> a[i].ma;
        cout << "Nhap noi khoi hanh : ";
        fflush(stdin);
        getline(cin,a[i].khoiHanh);
        cout << "Nhap noi den : ";
        fflush(stdin);
        getline(cin,a[i].noiDen);
        cout << "Nhap gia ve : ";
        cin >> a[i].gia;
    }
}

void xuat1VMB(VMB a){
    cout << a.ma << " - " << a.khoiHanh << " -> " << a.noiDen << " - " << a.gia << endl;
}

void xuat(VMB *a , int n){
    for(int i = 0 ; i < n ; i++){
        xuat1VMB(a[i]);
    }
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
