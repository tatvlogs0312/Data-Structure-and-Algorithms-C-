#include <iostream>
#include <fstream>
#include <stack>
#include <queue>

#define max 100

using namespace std;

typedef struct GraphTap
{
    int n;
    int a[max][max];
} graph;

void docFile(graph &g)
{
    ifstream fi("TimKiem3.txt");

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
        cout << "Khong tim thay file";
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
        cout << endl;
    }
}

void Bread_First_Search(graph g, int start, int goal)
{
    stack<int> Open; // danh sach open chua cac dinh se duoc phat trien
    int Close[max] = {0};
    int Father[max];
    int kq = false;
    int u;
    // khoi tao
    Father[start] = start;
    for (int i = 0; i < g.n; i++)
        if (i != start)
            Father[i] = -1;

    Open.push(start);
    // lap
    while (!Open.empty())
    {
        u = Open.top();
        Open.pop();
        if (u == goal)
        { // kiem neu u = goal
            kq = true;
            break;
        }
        Close[u] = 1; // danh dau u la dinh da xet
        for (int v = 0; v < g.n; v++)
            if (g.a[u][v] == 1) // v la dinh ke voi u
            {
                if (Father[v] == -1 && Close[v] == 0)
                {
                    Open.push(v);
                    Father[v] = u;
                }
            }
    }
    if (kq == true)
    {
        // in ra duong di
        cout << u;
        u = Father[u];
        while (u != start)
        {
            cout << "<--" << u;
            u = Father[u];
        }
        cout << "<--" << start << endl;
    }
    else
    {
        cout << "Khong tim duoc duong di!";
    }
}

void DFS(graph g , int start , int goal){
    stack<int> open;
    int close[max] = {0};
    int father[max];
    int isCheck = false;
    int u;
    father[start] = start;
    for(int i = 0 ; i < g.n ; i++){
        if(i != start){
            father[i] = -1;
        }        
    }
    open.push(start);

    while(!open.empty()){
        u = open.top();
        open.pop();
        if(u == goal){
            isCheck = true;
            break;
        }
        close[u] = 1;
        for (int v = 0 ; v < g.n ; v++){
            if(g.a[u][v] == 1){
                if(father[v] == -1 && close[v] == 0){
                    open.push(v);
                    father[v] = u;
                }
            }
        }
    }

    if(isCheck == true){
        cout << u << " ";
        u = father[u];
        while(u != start){
            cout << " <- " << u;
            u = father[u];
        }
        cout << " <- " << start << endl;
    }else{
        cout << "Khong tim dc duong di" << endl;
    }
}

// void DFS(graph g, int start, int goal)
// {
//     stack<int> open;
//     // int close[max];
//     int father[max];

//     bool isCheck = false;
//     int u;

//     father[start] = start;
//     for (int i = 0; i < g.n; i++)
//     {
//         if (i != start)
//         {
//             father[i] = -1;
//         }
//     }

//     open.push(start);

//     while (!open.empty())
//     {
//         u = open.top();
//         open.pop();
//         if (u == goal)
//         {
//             isCheck = true;
//             break;
//         }
//         // close[u] = 1;
//         for (int v = 0; v < g.n; v++)
//         {
//             if (g.a[u][v] == 1)
//             {
//                 if (father[v] == -1 /*&& close[v] == 0*/)
//                 {
//                     open.push(v);
//                     father[v] = u;
//                 }
//             }
//         }
//     }

//     if (isCheck == true)
//     {
//         cout << u << " ";
//         u = father[u];
//         while (u != start)
//         {
//             cout << " <- " << u;
//             u = father[u];
//         }
//         cout << " <- " << start << endl;
//     }
//     else
//     {
//         cout << "Khong tim dc duong di" << endl;
//     }
// }

int main()
{
    graph g;
    docFile(g);
    xuat(g);
    int start, goal;
    cout << "Nhap dinh bat dau : ";
    cin >> start;
    cout << "Nhap dinh ket thuc : ";
    cin >> goal;
    DFS(g, start, goal);
}