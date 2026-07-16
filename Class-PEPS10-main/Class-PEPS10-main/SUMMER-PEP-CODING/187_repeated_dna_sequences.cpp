#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s){
        unordered_map<string,int> count;
        vector<string> res;
        for(int i=0;i+10<=(int)s.size();i++){
            string sub=s.substr(i,10);
            if(++count[sub]==2) res.push_back(sub);
        }
        return res;
    }
};
