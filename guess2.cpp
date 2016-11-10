#include <iostream>
#include <stdio.h>
#define toGuess 1702766710

using namespace std;

int guess(int num)
{
    if(num == toGuess) return 0;
    else if(num < toGuess) return -1;
    else return 1;
}

int guessNumber(int n)
{
    if (guess(n) == 0) return n;
    int left = 1, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2, t = guess(mid);
        if (t == 0) return mid;
        else if (t == 1) left = mid;
        else right = mid;
    }
    return left;
}

int main()
{
    int n = 2126753390;
    cout << n << endl;
    return 0;
}
