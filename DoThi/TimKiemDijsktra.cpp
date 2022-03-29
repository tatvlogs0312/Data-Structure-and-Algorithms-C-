#include <iostream>
#include <fstream>

#define MAX 100
#define VoCung 1000

using namespace std;

typedef struct GraphTag
{
    int n;
    int a[MAX][MAX];
} graph;

bool DocFile(graph &g)
{
    ifstream fi("Dijsktra.txt");
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
        cout << "Khong tim thay file" << endl;
        return false;
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
    }
}

int timMIN(int d[], int close[], int n)
{
    int min = 100;
    int u;
    for (int i = 0; i < n; i++)
    {
        if (close[i] == 0 && d[i] < min)
        {
            u = i;
            min = d[i];
        }
    }
    return u;
}

void Dijisktra(graph g, int start, int goal)
{
    int d[MAX], truoc[MAX];
    int close[MAX] = {0};
    //close[]: mang danh dau, close[u]=1 ->da danh dau, close[u]=0 ->chua danh dau
    int i, k;
    // Khoi tao
    for (i = 0; i < g.n; i++)
    {
        d[i] = g.a[start][i];
        truoc[i] = start;
    }
    close[start] = 1;

    // lặp

    for (k = 1; k <= g.n - 2; k++)
    {
        int u = timMIN(d, close, g.n);
        close[u] = 1;
        for (int v = 0; v < g.n; v++)
        {
            if (close[v] == 0 && d[v] > d[u] + g.a[u][v])
            {
                d[v] = d[u] + g.a[u][v];
                truoc[v] = u;
            }
        }
    }

    // in đường đi
    cout << "Duong di tu dinh " << start << " den dinh " << goal << endl;
    if (d[goal] != VoCung)
    {
        int u = goal;
        cout << u << "<--";
        u = truoc[u];
        while (u != start)
        {
            cout << u << "<--";
            u = truoc[u];
        }
        cout << start << endl;
    } else {
        cout << "Khong co duong di " << endl;
    }
    cout << "_________________________" << endl;
    cout << "Duong di tu dinh " << start << " den dinh con lai " << endl;
    for (int i = 0; i < g.n; i++)
    {
        if (i != start)
        {
            int u = i;
            cout << goal << "<--";
            u = truoc[u];
            while (u != start)
            {
                cout << u << "<--";
                u = truoc[u];
            }
            cout << start << endl;
        }
    }
}

// void Dijisktra(graph g, int start, int goal)
// {
//     int d[MAX], truoc[MAX], close[MAX] = {0};
//     // close[]: mang danh dau, close[u]=1 ->da danh dau, close[u]=0 ->chua danh dau

//     int i, k;
//     // khoi tao
//     for (i = 0; i < g.n; i++)
//     {
//         d[i] = g.a[start][i];
//         truoc[i] = start;
//     }
//     close[start] = 1;
//     // lap
//     for (k = 1; k <= g.n - 2; k++)
//     {
//         int u = timMIN(d, close, g.n);
//         close[u] = 1;
//         for (int v = 0; v < g.n; v++)
//             if (close[v] == 0 && d[v] > d[u] + g.a[u][v])
//             {
//                 d[v] = d[u] + g.a[u][v];
//                 truoc[v] = u;
//             }
//     }
//     // in duong di
//     cout << "\nDuong di tu dinh " << start << " den dinh " << goal << ":\n";
//     if (d[goal] != VoCung)
//     {
//         int u = goal;
//         cout << u << "<--";
//         u = truoc[u];
//         while (u != start)
//         {
//             cout << u << "<--";
//             u = truoc[u];
//         }
//         cout << start;
//     }
//     else
//     {
//         cout << "Khong co duong di!";
//     }
//     /*
//     cout << "\n_______________________\n";
//     cout << "Duong di tu dinh " << start << " Den cac dinh con lai:\n";

//     for (int i=0; i<g.n; i++){
//         if (i!=start){
//             cout << "\nDuong di tu dinh " << start << " den dinh " << i << ":\n";
//             int u = i;
//             cout << u << "<--";
//             u = truoc[u];
//             while(u!=start){
//                 cout << u << "<--";
//                 u = truoc[u];
//             }
//             cout << start;
//             cout << "\n";
//         }
//     }
//     */
// }

int main()
{
    graph g;
    if (DocFile(g) == true)
    {
        Xuat(g);
        int start, goal;
        cout << "Nhap dinh bat dau : ";
        cin >> start;
        cout << "Nhap dinh ket thuc : ";
        cin >> goal;
        Dijisktra(g, start, goal);
    }
}