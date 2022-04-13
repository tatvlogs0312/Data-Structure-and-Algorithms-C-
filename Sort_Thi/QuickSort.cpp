#include <iostream>
#include <string>

using namespace std;

void Nhap(int * a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout<<"Nhap a["<<i<<"] = ";
		cin>>a[i];
	}
}

void Xuat(int * a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<"\t";
	}
}

void QuickSort(int * a, int left, int right)
{
	int mid = a[(left + right) / 2];
	int i = left, j = right;
	while(i <= j)
	{
		while(a[i] < mid)
			i++;
		while(a[j] > mid)
			j--;

		if(i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	if(left < j)
		QuickSort(a,left,j);
	if(i < right)
		QuickSort(a,i,right);
}

int BinarySearch(int * a, int n, int x)
{
	int left = 0, right = n-1, mid;
	do
	{
		mid = (left + right) /2;
		if(a[mid] == x)
			return mid;
		else if (a[mid] < x)
			left = mid + 1;
		else
			right = mid - 1;
	}
	while(left <= right);
	return -1;
}

int main()
{
	int n;
	cout<<"Nhap so phan tu cua mang: ";
	cin>>n;

	int * a = new int[n];
	Nhap(a,n);
	cout<<"\n====Mang sau khi nhap la===="<<endl;
	Xuat(a,n);

	QuickSort(a,0,n-1);
	cout<<"\n====Mang sau khi sap xep la===="<<endl;
	Xuat(a,n);

	int x;
	cout<<"\nNhap gia tri can tim: ";
	cin>>x;
	int check = BinarySearch(a,n,x);
	if(check != -1)
	{
		cout<<"\n====Cac phan tu co gia tri = "<<x<<" la===="<<endl;
		cout<<a[check]<<" o vi tri "<<check<<endl;
		int l = 0;
		while(l < check && a[l] == x)
		{
			cout<<a[l]<<" o vi tri "<<l<<endl;
			l++;
		}
		int r = check + 1;
		while(r < n && a[r] == x)
		{
			cout<<a[r]<<" o vi tri "<<r<<endl;
			r++;
		}
	}
	else
		cout<<"\n"<<x<<" khong co trong mang";
}