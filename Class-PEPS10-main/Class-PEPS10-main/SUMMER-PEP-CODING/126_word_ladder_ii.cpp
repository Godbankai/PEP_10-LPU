#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if(!dict.count(endWord)) return res;
        unordered_map<string, vector<string>> parents;
        unordered_set<string> level1{beginWord}, level2;
        dict.erase(beginWord);
        bool found=false;
        while(!level1.empty() && !found){
            for(auto& w: level1) dict.erase(w);
            for(auto& word: level1){
                string tmp=word;
                for(size_t i=0;i<tmp.size();i++){
                    char orig=tmp[i];
                    for(char c='a';c<='z';c++){
                        if(c==orig) continue;
                        tmp[i]=c;
                        if(dict.count(tmp)){
                            level2.insert(tmp);
                            parents[tmp].push_back(word);
                            if(tmp==endWord) found=true;
                        }
                    }
                    tmp[i]=orig;
                }
            }
            level1=level2;
            level2.clear();
        }
        if(!found) return res;
        vector<string> path{endWord};
        function<void(string)> backtrack = [&](string word){
            if(word==beginWord){
                vector<string> p(path.rbegin(), path.rend());
                res.push_back(p);
                return;
            }
            for(auto& p: parents[word]){
                path.push_back(p);
                backtrack(p);
                path.pop_back();
            }
        };
        backtrack(endWord);
        return res;
    }
};
