#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

struct doThi
{
    int n;
    int a[MAX][MAX];
};
typedef struct doThi graph;

void Nhap(graph &g)
{
    ifstream fi("bai6.txt");
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
}

void Xuat(graph g)
{
    cout << "So dinh : " << g.n << endl;
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            cout << g.a[i][j] << "\t";
        }
        cout << endl;
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    graph g;
    Nhap(g);
    Xuat(g);
    return 0;
}