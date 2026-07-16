#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<string, vector<string>> memo;
    vector<string> wordBreakHelper(string s, unordered_set<string>& dict){
        if(memo.count(s)) return memo[s];
        vector<string> res;
        if(dict.count(s)) res.push_back(s);
        for(size_t i=1;i<s.size();i++){
            string prefix=s.substr(0,i);
            if(dict.count(prefix)){
                vector<string> rest = wordBreakHelper(s.substr(i), dict);
                for(auto& r: rest) res.push_back(prefix+" "+r);
            }
        }
        memo[s]=res;
        return res;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict){
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        memo.clear();
        return wordBreakHelper(s, dict);
    }
};
