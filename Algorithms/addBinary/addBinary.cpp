#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addBinary(string a, string b) {
    //std::reverse(a.begin(), a.end());
    //std::reverse(b.begin(), b.end());
    //int maxL = (a.size() > b.size())?a.size():b.size();
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string result = "";
    int cur;
    while(i >= 0 || j >= 0) {
        int ai = (i >= 0)?(a[i]-'0'):0;
        int bi = (j >= 0)?(b[j]-'0'):0;
        cur = (ai + bi + carry) % 2;
        carry = (ai + bi + carry) / 2;
        result.insert(result.begin(), cur+'0');
        i--;
        j--;
    }
    if (carry > 0) result.insert(result.begin(), carry+'0');
    return result;
}

int main() {
    string a = "101";
    string b = "1";
    string res = addBinary(a, b);
    cout << res << endl;
    return 0;
}