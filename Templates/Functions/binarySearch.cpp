#include<iostream>
#include<cstdio>
using namespace std;

int binSearch(int A[], int length, int item) 
{
    int left = 0, right = length - 1, mid;
    while (left <= right) 
    {
        mid = left + (right - left) / 2;        // finding middle index
        if (A[mid] == item)
            return mid;                // item found
        else if (item < A[mid])
            right = mid - 1;            // recurse on left sub-array
        else
            left = mid + 1;             // recurse on right sub-array
    }
    return -1;                        // item not found
}
int main()
{
    int a[]={1,8,10,90,150};
    cout<<binSearch(a,5,9);
}