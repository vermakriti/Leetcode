/*

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

*/


class Node{
    public:
    int key,value;
    Node*next,*prev;
    Node(int key,int value){
        this->key=key;
        this->value=value;
        next=nullptr;
        prev=nullptr;
    }
};

class LRUCache {
public:
    Node*head,*tail,*prev,*next;
    map<int,Node*> mp;
    int cache_size;
    
    LRUCache(int capacity) {
        cache_size=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;  
        int value=mp[key]->value;
        
        prev=mp[key]->prev;
        next=mp[key]->next;
        prev->next=next;
        next->prev=prev;
        mp.erase(key);
        
        Node*node=new Node(key,value);
        next=head->next;
        head->next=node;
        node->prev=head;
        node->next=next;
        next->prev=node;
        mp[key]=node;
        
        return value;
    }
   
    void put(int key, int value){
        if(mp.find(key)==mp.end()){
            if(cache_size==mp.size()){
                prev=tail->prev->prev;
                mp.erase(prev->next->key);
                tail->prev=prev;
                prev->next=tail;
            }
        }
        else{
            prev=mp[key]->prev;
            next=mp[key]->next;
            prev->next=next;
            next->prev=prev;
            mp.erase(key);
        }     
        Node*node=new Node(key,value);
        next=head->next;
        head->next=node;
        node->prev=head;
        node->next=next;
        next->prev=node;
        mp[key]=node;
    }
};