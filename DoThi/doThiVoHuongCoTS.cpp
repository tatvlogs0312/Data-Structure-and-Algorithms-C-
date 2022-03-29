#include <iostream>
#include <fstream>

#define MAX 100

using namespace std;

typedef struct GraphTag
{
    int n;
    int a[MAX][MAX];
} graph;

void docFile(graph &g)
{
    ifstream fi("D:\\DaiHocDienLuc\\ki_4\\CauTrucDuLieuGiaiThuatNangCao\\code\\DoThi\\graph_4.txt");

    if (fi.is_open() == true)
    {
        fi >> g.n;
        for (int i = 0; i < g.n; i++)
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
        cout << "Mo file that bai" << endl;
    }
}

void xuat(graph g)
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
    graph g;
    docFile(g);
    xuat(g);
    return 0;
}
