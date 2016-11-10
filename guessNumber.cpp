#include <iostream>
#include <stdio.h>
#define toGuess 2147483647

using namespace std;

int guess(int num)
{
    if(num == toGuess) return 0;
    else if(num < toGuess) return -1;
    else return 1;
}

int guessNumber(int n)
{
    int lo = 1;
    int hi = n;
    int myguess = 1 + (n-1)/2;
    while(guess(myguess) != 0)
    {
        if (guess(myguess) == -1)
        {
        	lo = myguess+1;
            myguess = lo + (hi-lo)/2;
        }
        else
        {
            hi = myguess-1;
            myguess = lo + (hi-lo)/2;
        }
        cout << "myguess=" << myguess <<endl;
    }
    return myguess;
}

int main()
{
    int n = 2147483647;
    int rightNum = guessNumber(n);
    cout << rightNum<<endl;
    return 0;
}
