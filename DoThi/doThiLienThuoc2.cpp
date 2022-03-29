#include <iostream>
#include <fstream>
#define max 100

using namespace std;

struct GraphTag
{
    int m, n;
    int a[max][max];
};
typedef struct GraphTag graph;

void docFile(graph &g)
{
    ifstream fi("graph_lt_2.txt");
    if (fi.is_open() == true)
    {
        fi >> g.m >> g.n;
        for (int i = 0; i < g.m; i++)
        {
            for (int j = 0; j < g.n; j++)
            {
                fi >> g.a[i][j];
            }
        }
        fi.close();
    } 
    else {
        cout << "Khong tim thay file !";
    }
}

void xuat(graph g)
{
    cout << "So dinh : " << g.m << endl;
    cout << "So canh : " << g.n << endl;
    for (int i = 0; i < g.m; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            cout << g.a[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    graph g;
    docFile(g);
    xuat(g);
    return 0;
}
