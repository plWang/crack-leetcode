#include <iostream>
#include <string>

using namespace std;

string countAndSay(int n) {
    string res = "1";
    for (int i=0; i < n-1; i++) {
        int len = res.size();
        int count = 0;
        char c = '.';
        string tmp = "";
        for (int j=0; j < len; j++) {
            if (c == res[j]) count++;
            else if (c == '.') {
                count++;
            }
            else { 
                tmp += ('0' + count);
                tmp += c;
                count = 1;
            }
            c = res[j];
        }
        tmp += ('0' + count);
        tmp += c;
        res = tmp;
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    string s = countAndSay(n);
    cout << s << endl;
    return 0;
}