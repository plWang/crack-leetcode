vector<vector<string> > groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string s : strs) {
        string t = sort(s.begin(), s.end());
        mp[t].push_back(s);
    }

    vector<vector<string> > anagrams;
    for (auto m : mp) {
        anagrams.push_back(m.second);
    }

    return anagrams;
}