#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

typedef struct GraphTag
{
    int m, n;
    int a[MAX][MAX];

    int m2, n2;
    int a2[MAX][MAX];
} Graph;

void docFile(Graph &g)
{
    ifstream fi("D:\\DaiHocDienLuc\\ki_4\\CauTrucDuLieuGiaiThuatNangCao\\code\\DoThi\\graph_lt.txt");

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
        
        fi >> g.m2;
        fi >> g.n2;
        for (int i = 0; i < g.m2; i++)
        {
            for (int j = 0; j < g.n2; j++)
            {
                fi >> g.a2[i][j];
            }
        }


        fi.close();
    }
    else
    {
        cout << "Mo ko thanh cong" << endl;
    }
}

void xuat(Graph g)
{
    cout << "Do thi thu nhat : " << endl;
    cout << "So canh : " << g.m << endl;
    cout << "So dinh : " << g.n << endl;
    for (int i = 0; i < g.m; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            cout << g.a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "--------------------------" << endl;
    cout << "Do thi thu hai : " << endl;
    cout << "So canh : " << g.m2 << endl;
    cout << "So dinh : " << g.n2 << endl;
    for (int i = 0; i < g.m2; i++)
    {
        for (int j = 0; j < g.n2; j++)
        {
            cout << g.a2[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(int argc, char const *argv[])
{
    Graph g;
    docFile(g);
    xuat(g);
    return 0;
}
