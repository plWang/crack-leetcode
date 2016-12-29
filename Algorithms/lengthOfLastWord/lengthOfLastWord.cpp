#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
    int len = 0;
    for (int i=0; i < s.size(); i++) {
        if (s[i] != ' ') {
            if (i > 0 && s[i-1] == ' ') len = 1;
            else len++;
        }
    }
    return len;
}


int main() {
    string s = "Hello World ";
    int len = lengthOfLastWord(s);
    cout << len << endl;
    return 0;
}