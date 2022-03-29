#include <iostream>
#include <fstream>

#define max 100

using namespace std;

typedef struct EdgeTag
{
    int u;
    int v;
} edge;

typedef struct GraphTag
{
    edge e[max];
    int m;
} graph;

void nhap(graph &g)
{
    ifstream fi("Canh.txt");
    if (fi.is_open() == true)
    {
        fi >> g.m;
        for (int i = 0; i < g.m; i++)
        {
            fi >> g.e[i].u >> g.e[i].v;
        }
        fi.close();
    }
    else
    {
        cout << "Mo file ko thanh cong" << endl;
    }
}

void xuat(graph g)
{
    cout << "Danh sach canh : " << g.m << endl;
    for (int i = 0; i < g.m; i++)
    {
        cout << g.e[i].u << " " << g.e[i].v << endl;
    }
}

int main(int argc, char const *argv[])
{
    graph g;
    nhap(g);
    xuat(g);
    return 0;
}
