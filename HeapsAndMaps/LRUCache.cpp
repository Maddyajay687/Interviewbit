int n;
unordered_map<int, int> mp;
deque<int> l;
LRUCache::LRUCache(int capacity) {
    n = capacity;
    mp.reserve(n);
    mp.clear();
    l.clear();
}

int LRUCache::get(int key) {
    int temp;
    if(mp.find(key) == mp.end()) {
        return -1;
    } else {
        temp = mp[key];
        //mp.erase(key);
        l.erase(find(l.begin(), l.end(), key));
        l.push_back(key);
    }
    return temp;
}

void LRUCache::set(int key, int value) {
    if(mp.find(key) == mp.end()) {
        if(l.size() == n) {
            int temp = l.front();
            l.pop_front();
            mp.erase(temp);
        }
    } else {
        l.erase(find(l.begin(), l.end(), key));
        mp.erase(key);
    }
    l.push_back(key);
    mp[key] = value;
}
