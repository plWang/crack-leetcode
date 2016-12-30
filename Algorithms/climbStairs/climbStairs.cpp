#include <iostream>

using namespace std;

// int climbStairs(int n) {
//     if (n == 0) return 0;
//     if (n == 1) return 1;
//     if (n == 2) return 2;
//     return climbStairs(n-1) + climbStairs(n-2);
// }

int climbStairs(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    int a = 1;
    int b = 2;
    int c = 0;
    for (int i=3; i<=n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n;
    cin >> n;
    int m = climbStairs(n);
    cout << m << endl;
}