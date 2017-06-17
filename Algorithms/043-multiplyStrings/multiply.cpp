#include <iostream>
#include <string>

using namespace std;

void add(string& s1, string& s2) {
    int addon = 0;
    for (int i=s1.size()-1; i>=0; i--) {
        int sum = s1[i]-'0' + s2[i]-'0';
        s1[i] = (sum+addon) % 10 + '0';
        addon = (sum+addon) / 10;
    }
}

string multiply(string num1, string num2) {
    int n=num1.size(), m=num2.size();
    int p = n+m;
    string result(p, '0');
    for (int i=m-1, k=0; i>= 0; i--, k++) {
        string tmp(p, '0');
        int addon = 0, res;
        int j=n-1, l=0;
        for (j=n-1, l=0; j>=0 ;j--, l++) {
            int product = (num1[j]-'0') * (num2[i] - '0');
            res = (product + addon) % 10;
            addon = (product + addon) / 10;
            tmp[p-k-1-l] = res + '0';
        }
        if (addon) tmp[p-k-1-l] = addon + '0';
        add(result, tmp);
    }

    int i=0;
    while (i<result.size() && result[i]=='0') i++;
    if (i != result.size()) return result.substr(i,result.size()-i);
    else return "0";
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    string result = multiply(num1, num2);
    cout << result << endl;
}