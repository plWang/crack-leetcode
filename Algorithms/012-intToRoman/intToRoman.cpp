# include <iostream>

using namespace std;

string intToRoman(int num) {
    int divide[] = {1, 5, 10, 50, 100, 500, 1000};
    char d[] = {'I','V','X','L','C','D','M'};
    int res;
    int n;
    string result;
    int k=0;
    for (int i=6; i>=0; i--) {
        if (i == 1 || i==3 || i==5) {
            n = num / divide[i-1];
            if (n == 9) {
                result.push_back(d[i-1]);
                result.push_back(d[i+1]);
                num -= n*divide[i-1];
                i--;
            }
            else if (n == 4) {
                result.push_back(d[i-1]);
                result.push_back(d[i]);
                num -= n*divide[i-1];
                i--;
            }
            else {
                n = num / divide[i];
                num -= n*divide[i];
                for (int j=0; j < n; j++) {
                    result.push_back(d[i]);
                }
            }
        }
        else {
            n = num / divide[i];
            num -= n*divide[i];
            for (int j=0; j < n; j++) {
                result.push_back(d[i]);
            }
        }
    }

    return result;
}

int main() {
    int num = 4;
    string res = intToRoman(num);
    cout << res << endl;
    return 0;
}