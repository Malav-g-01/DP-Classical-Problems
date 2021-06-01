/*We have to paint n boards of length {A1, A2, .. An}. 
There are k painters available and each takes 1 unit time to paint 1 unit of board. 
The problem is to find the minimum time to get this job done under the constraints 
that any painter will only paint continuous sections of boards, say board {2, 3, 4} 
or only board {1} or nothing but not board {2, 4, 5}.*/

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int possible(int a[], int n, int limit)
{
    int painters = 1;
    int sum = 0;

    for(int i=0; i<n; i++){
        sum += a[i];

        if(sum > limit){
            sum = a[i];
            painters++;
        }
    }

    return painters;
}

int painterPartition(int board[], int n, int m)
{
    int totalLength = 0, k = 0;

    for(int i=0; i<n; i++){
        k = max(k, board[i]);
        totalLength += board[i];
    }

    int low = k;
    int high = totalLength;

    while (low < high)
    {
        /* code */
        int mid = (low+high)/2;
        int painters = possible(board, n, mid);

        if(painters <= m){
            high = mid;
        }

        else
            low = mid+1;
    }
    return low;
}

int main()
{
    int a[] = {10, 20, 30, 40};
    int n = 5;
    int m = 2;
    cout << "Minimum possible painters : " << painterPartition(a, n, m);

    return 0;
}
