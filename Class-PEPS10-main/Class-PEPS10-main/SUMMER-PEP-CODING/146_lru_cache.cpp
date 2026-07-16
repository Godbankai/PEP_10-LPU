#include <bits/stdc++.h>
using namespace std;
class LRUCache {
    int capacity;
    list<pair<int,int>> items; // front = most recently used
    unordered_map<int, list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int capacity): capacity(capacity) {}
    int get(int key){
        if(!mp.count(key)) return -1;
        items.splice(items.begin(), items, mp[key]);
        return mp[key]->second;
    }
    void put(int key, int value){
        if(mp.count(key)){
            items.splice(items.begin(), items, mp[key]);
            mp[key]->second=value;
            return;
        }
        if((int)items.size()==capacity){
            auto last=items.back();
            mp.erase(last.first);
            items.pop_back();
        }
        items.push_front({key,value});
        mp[key]=items.begin();
    }
};
