#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return 0;
        queue<string> q; q.push(beginWord);
        int steps=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string word=q.front(); q.pop();
                if(word==endWord) return steps;
                for(size_t j=0;j<word.size();j++){
                    char orig=word[j];
                    for(char c='a';c<='z';c++){
                        word[j]=c;
                        if(dict.count(word)){
                            dict.erase(word);
                            q.push(word);
                        }
                    }
                    word[j]=orig;
                }
            }
            steps++;
        }
        return 0;
    }
};
