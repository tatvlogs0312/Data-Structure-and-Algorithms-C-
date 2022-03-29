#include <iostream>
#include <list>
#include <fstream>

using namespace std;
#define MAX 100

struct Graph
{
	int n;
	list<int>ds[MAX];
};

bool Nhap(Graph &g){
	int v;
	ifstream fi("dske.txt");
	int k;
	if (fi.is_open()){
		fi >> g.n;
		for (int i=0; i<g.n; i++){
			fi >> k;
			for (int j=1; j<=k; j++){
				fi >> v;
				g.ds[i].push_back(v);
			}
		}
		fi.close();
		return true;
	}
	else{
		cout << "Mo file khong thanh cong!";
		return false;
	}	
}

void Xuat(Graph g){
	cout << "So dinh = " << g.n << endl;
	for (int i=0; i<g.n; i++){
		for (list<int>::iterator it=g.ds[i].begin(); it != g.ds[i].end(); ++it)
			cout << ' ' << *it << " ";
		cout << "\n";
	}
}

int main(){
	Graph g;
	if (Nhap(g)==true){
		cout << "Do thi da nhap\n";
		Xuat(g);
	}
}