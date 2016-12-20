#include <string>
#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string pref = "";
    int n = strs.size();
    int flag = 0;
    if (n == 0) return pref;
    for (int i=0; ; i++) {
        if (i >= strs[0].length()) {
            flag = 1;
            break;
        }
        char a = strs[0][i];
        cout << a << endl;
        for (int j=1; j < n; j++) {
            cout << "strs[j][i]= " << strs[j][i] <<endl;
            if (i >= strs[j].length() || a != strs[j][i]) {
                flag = 1;
                break;
            }
        }
        if (flag) break;
        else pref += a;
    }
    return pref;
}

int main() {
    vector<string> strs;
    string s = "init";
    while (s != "$$$") {
        cin >> s;
        if (s != "$$$") strs.push_back(s);
        //cout << strs.size() << endl;
        //cout << "out: " << s << "%^$#^" << endl;
    }
    string res = longestCommonPrefix(strs);
    cout << "Pref: " << res <<endl;
    return 0;
}