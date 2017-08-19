#include <iostream>
#include <string>
#include <queue>

using namespace std;


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordDict;             // 关键：先建立一个hashtable, 可以快速删除
    for (int i=0; i<wordList.size(); i++)   
        wordDict.insert(wordList[i]);

    queue<string> q;
    wordDict.erase(beginWord);
    wordDict.insert(endWord);
    q.push(beginWord);


    int dist = 1;
    while (!q.empty()) {
        int n = q.size();
        for (int i=0; i<n; i++) {
            string word = q.front();
            q.pop();
            if (word == endWord) return dist;
            // wordList.erase(word);
            for (int j=0; j<word.size(); j++) {
                char letter = word[j];
                for (int k=0; k<26; k++) {
                    word[j] = 'a' + k;
                    if (wordDict.find(word) != wordDict.end()) {
                        q.push(word);
                        wordDict.erase(word);
                    }
                }
            }
        }
        dist++;
    }

    return 0;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList;
    wordList.push_back("hot");
    wordList.push_back("dot");
    wordList.push_back("dog");
    wordList.push_back("lot");
    wordList.push_back("log");

    int dist = ladderLength(beginWord, endWord, wordList);
    return 0;
}