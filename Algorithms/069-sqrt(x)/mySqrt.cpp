#include <iostream>

using namespace std;

int mySqrt(int x) {
    if (x == 0) return 0; //0作为特殊情况处理，否则可能会出现除数为0
    int lo=1;
    int hi=x;
    int mid;
    while (lo <= hi) {
        mid = lo + (hi-lo) / 2;  
        if (mid == x/mid) return mid;  //不使用mid*mid与x比较的方法，因为mid*mid可能会越界
        else if (mid > x/mid) hi=mid-1;
        else {
            if ((mid+1) > x/(mid+1)) return mid;
            lo = mid+1;
        }
    }

    return (mid*mid < x)?mid:mid-1;;
}

int main() {
    int x;
    cin >> x;
    cout << mySqrt(x) << endl;
}