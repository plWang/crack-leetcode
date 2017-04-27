#include <iostream>
#include <cmath>

using namespace std;

string longestPalindrome(string s) {
    int maxLen = 0;
    int j, k, Len;
    string longest;
    for (int i=0; i < s.size(); i++) {
        // odd case 
        j = 1;
        Len = 1;
        while (i-j >= 0 && i+j < s.size() && s[i-j] == s[i+j]) {
            j++;
            Len += 2;
        }
        if (Len > maxLen) {
            maxLen = Len;
            longest = s.substr(i-j+1, Len);
        }
        // even case 1 
        k = i+1;
        j = 1;
        if (k < s.size() && s[i] == s[k]) {
            Len = 2;
            while (i-j >= 0 && k+j < s.size() && s[i-j] == s[k+j]) {
                j++;
                Len += 2;
            }
        }
        if (Len > maxLen) {
            maxLen = Len;
            longest = s.substr(i-j+1, Len);
        }

        // even case 2
        k = i-1;
        j = 1;
        if (k >= 0 && s[i] == s[k]) {
            Len = 2;
            while (k-j >= 0 && i+j < s.size() && s[k-j] == s[i+j]) {
                j++;
                Len += 2;
            }
        }
        if (Len > maxLen) {
            maxLen = Len;
            longest = s.substr(k-j+1, Len);
        }

    }

    return longest;
}