#include <iostream>
#include "math.h"

#define INT_MIN -2147483648

using namespace std;

bool equal(double x, double y) {
    if (fabs(x-y) < 0.000001) return true;
    else return false;
}

double powHelp(double x, int n) {
    if (n==0) return 1.0;
    if (n==1) return x;
    if (n%2 == 0) {
        double tmp = powHelp(x, n/2);
        return tmp*tmp;
    }
    else {
        double tmp = powHelp(x, n/2);
        return tmp*tmp*x;
    }

}

double myPow(double x, int n) {
    if (equal(x, 0.0) && n==0) return 0;
    if (equal(x, 0.0) && n<0) return 0;

    if (n == 0) return 1.0;
    int sign = (n < 0)? 1:0;
    int flag = 0;
    if (n == INT_MIN) {
        n = n+1;
        flag = 1;
    } 
    n = fabs(n);
    double result = pow(x, n);
    if (flag) result *= x;
    return (sign == 1)?(1.0/result):result;
}

int main() {
    double x;
    int n;
    cin >> x >> n;
    cout << myPow(x, n) << endl;
}