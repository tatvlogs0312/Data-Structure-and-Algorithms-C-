#include <iostream>
#include <fstream>
#include <list>

using namespace std;

typedef struct EdgeTag
{
    int u; 
    int v;
} edge;

typedef struct GraphTag
{
    list<edge> ds;
    int m;
} graph;

void nhap(graph &g)
{
    ifstream fi("Canh.txt");
    if (fi.is_open() == true)
    {
        fi >> g.m;
        edge e;
        for (int i = 0; i < g.m; i++)
        {
            fi >> e.u >> e.v;
            g.ds.push_back(e);
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
    for(list<edge>::iterator it = g.ds.begin() ; it != g.ds.end() ; it ++){
        cout << (*it).u << " " << (*it).v << endl;
    }
}

int main(int argc, char const *argv[])
{
    graph g;
    nhap(g);
    xuat(g);
    return 0;
}
