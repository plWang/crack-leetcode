#include <string>
#include <iostream>

using namespace std;
//using std::string;

class Solution {
public:
    string convert(string s, int numRows) {
        int zsize = numRows * 2 - 2;
        //int n = strlen(s);
        string output="";
        if (zsize == 0)
            return s;
        else {
            for (int i=0;i < numRows; i++) {
                for (int j=0; j < s.length(); j=j+zsize) {
                    if (j+i >= s.length())
                        break;
                    output += s[i+j];
                    if (i != 0 && i != numRows-1) {
                        if (j+zsize-i >= s.length())
                            break;
                        output += s[j+zsize-i];
                    }
                }
            }
            return output;
        }
    }
};

int main() {
    string teststr = "PAYPALISHIRING";
    int numRows = 3;
    Solution solution;
    string s = solution.convert(teststr, numRows);
    cout << s << endl;
    return 0;
}