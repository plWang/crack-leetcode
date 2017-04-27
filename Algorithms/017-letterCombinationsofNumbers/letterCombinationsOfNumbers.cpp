vector<string> letterCombinations(string digits) {
    if (digits.empty()) return vector<string>();
    vector<string> charmap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res; // seed
    res.push_back("");
    for (int i=0; i<digits.size(); i++) {
        string letters = charmap[digits[i]-'0'];
        if (letters.empty()) continue;
        vector<string> tmp;
        for (int j=0; j<letters.size(); j++) {
            for (int k=0; k<res.size(); k++) {
                tmp.push_back(res[k]+letters[j]);
            }
        }
        res = tmp;
    }

    return res;
}