// Viet chuong trinh de qui in dao nguoc ca ky tu cua 1 chuoi

#include<iostream>
#include <string.h>

using namespace std;

void daonguoc(char s[],int n,int m){
	if(n >= m) return;
	else{
		char temp = *(s + n);
		*(s + n) = *(s + m);
		*(s + m) = temp;
		daonguoc(s,++n,--m);
	}
}

int main(){
	char s[50];
	cout << "Nhap chuoi : " ;
	gets(s);
	cout << s << endl;
	cout << "Chuoi dao nguoc : " << endl;
	daonguoc(s,0,strlen(s)-1);
	cout << s;
}
