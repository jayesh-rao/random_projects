#include <iostream>
#include <unordered_map>
#include <list>

class LRUCache {
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> c_;
    std::list<int> lru_; // MRU : lru_.begin(), LRU: lru_.end()
    int cap_;
public:
    LRUCache(int capacity) {
        cap_ = capacity;
    }
    
    int get(int key) {
        auto it = c_.find(key);

        // if key does not exist
        if (it == c_.end() || cap_ == 0) {
            return -1;
        }
        
        // if it exists
        // 1. update the lru by promoting it
        // 2. update the map with the latest iterator
        // 3. return the val

        int val = it->second.first;
        
        lru_.erase(it->second.second);
        lru_.push_front(key);
        it->second.second = lru_.begin();
        
        return val;
    }
    
    void set(int key, int value) {
        if (cap_ == 0) return;
        auto it = c_.find(key);
        
        // if element exists
        if (it != c_.end()) {
            lru_.erase(it->second.second);
            lru_.push_front(key);
            it->second.second = lru_.begin();
            c_[key] = {value, lru_.begin()};
            return;
        }
        // if element does not exist
        // 1. check the capacity
        // 2. actual insertion
        if (c_.size() == cap_) {
            // remove the LRU element
            c_.erase(lru_.back());
            lru_.pop_back();
        }
        
        lru_.push_front(key);
        c_.insert({key, {value, lru_.begin()}});
        return;
    }
};


int main() {
    LRUCache *cache = new LRUCache(2);
    
    cache->set(2, 2);
    cache->set(1, 1);


    cache->set(3, 33);
    std::cout << std::endl << cache->get(1); // return -1
    std::cout << std::endl << cache->get(2); // return 22

}
