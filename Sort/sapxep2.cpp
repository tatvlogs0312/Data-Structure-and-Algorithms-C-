#include <iostream>

using namespace std;

void nhap(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] : ";
		cin >> a[i];
	}
}

void xuat(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void insertionSort(int *a, int n)
{
	int pos;
	for (int i = 1; i < n; i++)
	{
		int x = a[i];
		pos = i - 1;
		while (pos >= 0 && a[pos] > x)
		{
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}

void quickSort(int *a, int left, int right)
{
	int x, i, j;
	// phân hoạch dãy cần sắp thành 3 phần
	int mid = (left + right) / 2;
	x = a[mid];
	i = left;
	j = right;
	while (i <= j)
	{
		while (a[i] < x)
		{
			i++;
		}
		while (a[j] > x)
		{
			j--;
		}
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	//đệ quy quick sort dãy bên trái
	if (left < j)
	{
		quickSort(a, left, j);
	}
	//đệ quy quick sort dãy bên phải
	if (right > i)
	{
		quickSort(a, i, right);
	}
}

int binarySearch(int *a, int n, int x)
{
	int mid, left = 0, right = n - 1;
	do
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
		{
			return mid;
		}
		if (a[mid] < x)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	} while (left <= right);

	return -1;
}

int main()
{
	int n;
	cout << "Nhap so phan tu : ";
	cin >> n;
	int *a = new int[n];
	nhap(a, n);
	cout << "Danh sach so nguyen : " << endl;
	xuat(a, n);
	// insertionSort(a, n);
	quickSort(a, 0, n - 1);
	cout << "\nDanh sach so nguyen sau khi sap xep : " << endl;
	xuat(a, n);

	// int x;
	// cout << "\nNhap so can tim : ";
	// cin >> x;
	// int kq = binarySearch(a,n,x);
	// if(kq == -1){
	// 	cout << "khong co " << x << " trong mang !" << endl;
	// } else {
	// 	cout << "Vi tri cua " << x << " trong mang : ";
	// 	cout << kq << " ";
	// 	int t = kq - 1;
	// 	while (t >= 0 && a[t] ==x){
	// 		cout << t << " ";
	// 		t--;
	// 	}
	// 	int p = kq + 1;
	// 	while (p < n && a[p] == x){
	// 		cout << p << " ";
	// 		p++;
	// 	}
	// }
}
