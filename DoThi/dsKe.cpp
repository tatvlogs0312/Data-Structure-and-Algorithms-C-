#include <iostream>
#include <fstream>
#define max 100

using namespace std;

typedef struct GraphTag
{
    int m;      // so dinh
    int A[max]; // mang luu cac dinh ke cua tat ca cac dinh v trong do thi
    int I[max]; // mang luu chi so vi tri dau cua moi doan dinh ke
} graph;

void nhap(graph &g)
{
    ifstream fi("dsKe.txt");
    if (fi.is_open() == true)
    {
        int k, d = 0;
        fi >> g.m;
        for (int i = 0; i < g.m; i++)
        {
            fi >> k;
            g.I[i] = d;
            for (int j = 1; j <= k; j++)
            {
                fi >> g.A[d];
                d = d + 1;
            }
        }
        g.I[g.m] = d;
        fi.close();
    }
    else
    {
        cout << "Mo file ko thanh cong" << endl;
    }
}

void xuat(graph g)
{
    cout << "So dinh : " << g.m << endl;
    for (int i = 0; i < g.m; i++)
    {
        int k = g.I[i + 1] - g.I[i];
        cout << k << " ";
        for (int j = g.I[i]; j < g.I[i + 1]; j++)
        {
            cout << g.A[j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    graph g;
    nhap(g);
    xuat(g);
    return 0;
}
