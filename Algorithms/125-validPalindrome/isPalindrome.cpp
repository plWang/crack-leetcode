#include <iostream>
#include <string>
#include "math.h"
#include <cctype>

using namespace std;

bool isAlphanumeric(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        return true;
    else return false;
}

bool isPalindrome(string s) {
    int i=0, j=s.size()-1;
    while (i < j) {
        while (!isAlphanumeric(s[i])) i++;
        while (!isAlphanumeric(s[j])) j--;
        if (i >= j) return true;
        if (toupper(s[i]) == toupper(s[j])) {
            i++;
            j--;
        }
        else return false;
    }

    return true;
}

int main() {
    string s;
    cin >> s;
    if (isPalindrome(s))
        cout << "True" << endl;
    else 
        cout << "False" << endl;
    return 0;
}