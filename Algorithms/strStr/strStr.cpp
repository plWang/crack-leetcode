#include <iostream>

using namespace std;

int strStr(string haystack, string needle) {
    int n = haystack.size();
    int m = needle.size();
    if (n < m ) return -1;
    if (n == 0 || m == 0) return 0;

    for (int i=0; i < n-m+1; i++) {
        if (m == 1) {
            if (haystack[i] == needle[0]) return i;
            else continue;
        }
        else {
            if (haystack.substr(i, m) == needle) return i;
            else continue;
        }
    }
    return -1;
}

int main() {
    string haystack = "aaa";
    string needle = "aa";
    int res = strStr(haystack, needle);
    cout << res << endl;
    return 0;
}