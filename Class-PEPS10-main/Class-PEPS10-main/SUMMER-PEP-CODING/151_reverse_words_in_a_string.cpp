#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s){
        istringstream iss(s);
        vector<string> words;
        string w;
        while(iss>>w) words.push_back(w);
        reverse(words.begin(), words.end());
        string res;
        for(size_t i=0;i<words.size();i++){ res+=words[i]; if(i+1!=words.size()) res+=" "; }
        return res;
    }
};
