#include <iostream>
#include <queue>
#include <fstream>

using namespace std;
#define MAX 100

struct Graph
{
    int n;
    int a[MAX][MAX]; // Ma tran luu cac dinh ke cua tat ca cac dinh v
    int Index[MAX];  // Mang luu so dinh ke voi moi dinh v
};

bool DocFile(Graph &g)
{
    ifstream fi;
    fi.open("TimKiem.txt");
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
        return true;
    }
    else
    {
        cout << "Mo file khong thanh cong";
        return false;
    }
}

void Xuat(Graph g)
{
    cout << "So dinh = " << g.n << endl;
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            cout << g.a[i][j] << " ";
        }
        cout << endl;
    }
}

void Bread_First_search(Graph g, int start, int goal)
{
    queue<int> Open;
    int Close[MAX];
    int Father[MAX];
    bool kq = false;
    int u;
    //khoi tao
    for (int i = 0; i < g.n; i++)
    {
        Father[i] = -1;
    }

    Open.push(start);

    while (!Open.empty())
    {
        u = Open.front(); // Đỉnh đầu của ds Open
        Open.pop();
        if (u == goal) // Nếu u = goal -> trả về đường đi
        {
            kq = true;
            break;
        }
        Close[u] = 1; // Đánh dấu u là đỉnh đã xét
        for (int v = 0; v < g.n; v++)
        {
            if (g.a[u][v] == 1) // v là đỉnh kề với u
            {
                if (Father[v] == -1 && Close[v] == 0)
                {
                    Open.push(v);
                    Father[v] = u;
                }
            }
        }
    }
    if (kq == true)
    {
        cout << u << " ";
        u = Father[u];
        while (u != start)
        {
            cout << " <-- " << u;
            u = Father[u];
        }
        cout << " <-- " << start << endl;
    }
    else
        cout << "Khong tim duoc duong di";
}

int main()
{
    Graph g;
    if (DocFile(g) == true)
    {
        Xuat(g);
    }

    int start, goal;
    cout << "Nhap dinh bat dau: ";
    cin >> start;
    cout << "Nhap dinh ket thuc: ";
    cin >> goal;
    Bread_First_search(g, start, goal);
}