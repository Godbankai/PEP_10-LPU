#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2){
        int i=0,j=0,n=version1.size(),m=version2.size();
        while(i<n||j<m){
            int num1=0;
            while(i<n && version1[i]!='.') num1=num1*10+(version1[i++]-'0');
            int num2=0;
            while(j<m && version2[j]!='.') num2=num2*10+(version2[j++]-'0');
            if(num1!=num2) return num1<num2 ? -1:1;
            i++; j++;
        }
        return 0;
    }
};
