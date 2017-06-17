#include <iostream>

using namespace std;

int divideTowInts(int dividend, int divisor) {
    if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
    int sign = (dividend < 0 ^ divisor < 0)? -1: 1;
    long long dvd, dvs;
    dvd = fabs(dividend);
    dvs = fabs(divisor);
    int res = 0;
    while (dvd >= dvs) {
        long long multiple = 1, tmp = dvs;
        while (dvd >= tmp<<1) {
            tmp <<= 1;
            multiple <<= 1;
        }
        res += multiple;
        dvd -= tmp;
    }

    res = (sign == 1)?res:-res;

    return res;
}

int main() {
    return 0;
}