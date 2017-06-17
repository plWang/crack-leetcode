#include <iostream>
#include <string>

using namespace std;

string compress(string &str) {
    int n = str.size();
    int flag = 0;
    for (int i=0; i < n; i++) {
        if (flag == 0 && str[i] == '0') { 
            str.erase(i, 1);
            i--;
        }
        else flag=1;
        if (i>=0 && str[i] == ':') flag = 0;
    }

    return str;
}


string decompress(string &str) {
    int n = str.size();
    int start=0;
    int stdlen = 6;
    int topad;
    int i=0;
    while (i < n) {
        int curlen = 0;
        while ((i < n) && (str[i] != ':')) {
            curlen++;
            i++;
        }
        topad = stdlen - curlen;
        for (int j=0;j<topad; j++) {
            str.insert(start, "0");
            i++;
            n++;
        }
        i++;
        start = start + stdlen + 1 ;
    }
    if (str[n-1] == ':') str.insert(start, 6, '0');

    return str;
}

int main() {
    int mode;
    string s, res;
    cin >> mode >> s;
    if (mode == 0)
        res = compress(s);
    else
        res = decompress(s);

    cout << res<< endl;
}