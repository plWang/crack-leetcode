#include <iostream>
#include <string>
#include <vector>

using namespace std;

string simplifyPath(string path) {
    vector<string> result;
    int start = 0;
    for (int i=0; i<path.size(); i++) {
        if (path[i] == '/' || i == path.size()-1) {
            string subpath;
            if (path[i] == '/')
                subpath = path.substr(start, i-start);
            else
                subpath = path.substr(start, i-start+1);
            if (subpath == "/." || subpath == "/" || subpath == "" || subpath == ".") {
                start = i;
                continue;
            }
            else if (subpath == "/.." || subpath == "..") {
                if (result.size() > 0)
                    result.pop_back();
            }
            else 
                result.push_back(subpath);

            start = i;
        }
    }

    if (result.size() == 0) return "/";

    string res = "";
    for (int i=0; i<result.size(); i++)
        res.append(result[i]);

    return res;
}

    
int main() {
    string path;
    cin >> path;
    cout << simplifyPath(path) << endl;
}