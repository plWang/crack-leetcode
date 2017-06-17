#include <stdlib.h> 
#include <string>
#include <iostream>

using namespace std;

bool isPalindrome(int x) {
    int result = 0;
    int tmp;
    int xx = x;
    if (x < 0) return false;
    while (x != 0) {
        tmp = result * 10 + x%10;
        x = x/10;
        if (result != tmp/10) //overflow
            return false;
        result = tmp;
    }
    cout << result << endl;
    if (result == xx) return true;
    else return false;
}

int main() {
    int a;
    cin >> a;
    if (isPalindrome(a))
        cout << a << " is Palindrome number" << endl;
    else
        cout << a << " is not Palindrome number" << endl;
    return 0;
}
