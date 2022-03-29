#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

struct GraphTag
{
    int n;
    int a[MAX][MAX];
};
typedef struct GraphTag Graph;

void nhap(Graph &g)
{
    // D:\DaiHocDienLuc\ki_4\CauTrucDuLieuGiaiThuatNangCao\code\graph.txt

    // b1 : mo file
    ifstream fi("D:\\DaiHocDienLuc\\ki_4\\CauTrucDuLieuGiaiThuatNangCao\\code\\DoThi\\graph.txt");
    // b2 : doc du lieu tu file

    if (fi.is_open() == true)
    {
        fi >> g.n; // doc so dinh cua do thi

        for (int i = 0; i < g.n; i++)
        {
            for (int j = 0; j < g.n; j++)
            {
                fi >> g.a[i][j];
            }
        }
        // dong file
        fi.close();
    }
    else
    {
        cout << "Mo file khong thanh cong" << endl;
    }
}

void xuat(Graph g)
{
    cout << "So dinh : " << g.n << endl;

    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            cout << g.a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(int argc, char const *argv[])
{
    Graph g;
    nhap(g);
    xuat(g);
    return 0;
}
