## Problem 

Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.


## 思路1
先考虑overflow的情况：
1. 除数是0
2. 被除数是INT_MIN, 除数是-1

被除数循环减去除数，相减的次数即是两数相除的值。
但是当被除数很大，除数很小的情况时，循环次数过多，造成超时。

```c++
int divide(int dividend, int divisor) {
    if (divisor == 0) return INT_MAX;
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    int res = 0;
    int sign = (dividend<0 ^ divisor<0) ? -1:1;
    long dvd = fabs(dividend);
    long dvs = fabs(divisor);
    while (dvd >= dvs) {
        dvd -= dvs;
        res++;
    }
    
    res = (sign == 1)?res:-res;
    return res;
}
```

## 思路2

看一个例子：15 / 3
首先15 > 3, 然后将3左移一位（即扩大2倍）， 此时15>6, 
3继续左移一位，变为12， 此时15>12
3继续左移一位，变为24， 此时15<24, 不能继续除下去

因为3左移了两次，因此相当于15除了3的4倍。

15 - 12 = 3
得到的余数3继续与除数3相除

15 = 3 * 4 + 3；

```c++
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
```
