#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

struct GraphTag
{
    int m, n;
    int a[MAX][MAX];
};
typedef struct GraphTag Graph;

void nhap(Graph &g)
{
    cout << "nhap so hang : ";
    cin >> g.m;
    cout << "nhap so cot : ";
    cin >> g.n;

    for (int i = 0; i < g.m; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            cout << "Nhap a[i][j] : ";
            cin >> g.a[i][j];
        }
    }
}

void ghiFile(Graph g)
{
    ofstream fo("D:\\DaiHocDienLuc\\ki_4\\CauTrucDuLieuGiaiThuatNangCao\\code\\DoThi\\graph_2.txt");
    fo << g.m << " " << g.n << endl;
    for (int i = 0; i < g.m; ++i)
    {
        for (int j = 0; j < g.n; ++j)
        {
            fo << g.a[i][j] << " ";
        }
        fo << endl;
    }
    fo.close();

    if (fo == NULL)
    {
        cout << "GHI FILE THAT BAI";
    }
    else
    {
        cout << "GHI FILE THANH CONG" << endl;
    }
}

// void ghiFile(Graph g)
// {
//     ofstream fo("D:\\DaiHocDienLuc\\ki_4\\CauTrucDuLieuGiaiThuatNangCao\\code\\graph_2.txt");

//     fo.write(g.m);
//     fo.write(g.n);

//     for (int i = 0; i < g.m; i++)
//     {
//         for (int j = 0; j < g.n; j++)
//         {
//             fo.write(g.a[i][j]);
//         }
//     }
// }

void docFile(Graph &g)
{
    ifstream fi("D:\\DaiHocDienLuc\\ki_4\\CauTrucDuLieuGiaiThuatNangCao\\code\\DoThi\\graph_2.txt");

    if (fi.is_open() == true)
    {
        fi >> g.m;
        fi >> g.n;

        for (int i = 0; i < g.m; i++)
        {
            for (int j = 0; j < g.n; j++)
            {
                fi >> g.a[i][j];
            }
        }
        fi.close();
    }
    else
    {
        cout << "Mo file khong thanh cong" << endl;
    }   
}

void xuat(Graph g)
{
    cout << "So hang : " << g.m << endl;
    cout << "So cot : " << g.n << endl;

    for (int i = 0; i < g.m; i++)
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
    ghiFile(g);
    docFile(g);
    xuat(g);
    return 0;
}
