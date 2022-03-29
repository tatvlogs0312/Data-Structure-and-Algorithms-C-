#include <iostream>
#include <fstream>
#include <list>
#define max 100

using namespace std;

typedef struct GraphTag{
    int n;
    list<int>ds[max];
}graph;

void docFile(graph &g){
    ifstream fi("TimKiem1.txt");   
    if(fi.is_open() == true){
        int k , v;
        fi >> g.n;
        for(int i = 0 ; i < g.n ; i++){
            fi >> k;
            for(int j = 1 ; j <= k ; j++){
                fi >> v;
                g.ds[i].push_back(v);
            }
        }
    }
}

void xuat(graph g){
    cout << "So dinh = " << g.n << endl;
	for (int i=0; i<g.n; i++){
		for (list<int>::iterator it=g.ds[i].begin(); it != g.ds[i].end(); it++)
			cout << ' ' << *it << " ";
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
