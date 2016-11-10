#include<stdio.h>
#include <vector>

using std::vector;
using namespace std;

int binarySearch(vector<int> a, int key)
{
    int lo = 0;
    int hi = a.size()-1;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (key < a[mid]) hi = mid-1;
        else if (key > a[mid]) lo = mid+1;
        else return mid;
    }
    return -1;
}

int main()
{
    int N = 5;
    vector<int> a{1,2,3,4,5};
    int b=sizeof(a)/sizeof(int);
    printf("length of a = %d", b);
    int key = binarySearch(a,2);
    printf("key=%d", key);
    return 0;
}
