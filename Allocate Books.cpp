/*Given number of pages in n different books and m students. 
The books are arranged in ascending order of number of pages. 
Every student is assigned to read some consecutive books. 
The task is to assign books in such a way that the maximum 
number of pages assigned to a student is minimum. */

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int possible(int a[], int n, int m){
	int sum = 0;
	int student = 1;

	for(int i=0; i<n; i++){
		sum += a[i];

		if(sum>m){
			sum = a[i];
			student++;
		}
	}

	return student;
}

int pagePartition(int pages[], int n, int m)
{
	int mx = 0, sum=0;

	for(int i=0; i<n; i++){
		sum += pages[i];
		mx = max(mx, pages[i]);
	}

	int low = mx;
	int high = sum;

	while(low < high){
		int mid = (low + high)/2;

		if(possible(pages, n, mid) <= m){
			high = mid;
		}

		else
			low = mid+1;
	}

	return low;
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    int n = 5;
    int m = 2;
    cout << "Minimum possible maximum pages : " << pagePartition(a, n, m);

    return 0;
}
