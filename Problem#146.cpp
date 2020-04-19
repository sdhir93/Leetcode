/*
Problem: https://leetcode.com/problems/lru-cache/

Solution:

- Require two data structures:

a double linked list of a pair of a two ints -
first is key, second is value.
                    and
an unordered map that maps the key to the list iterator

- If get is called and
    - key not available, return  -1
    - key available, bring it to front and return value
    - update map to set key to beginning of list

- If put is called and
    - key available, bring to front and set new value
    - key not available, make a pair and insert in list
    - cache size limit reached, delete last element in list
    - update map to set key to beginning of list

Time complexity : O(1)
Space complexity : O(1)
*/

class LRUCache
{
private:
    unordered_map<int, list<pair<int, int>>::iterator> umap; // Unordered map to store key and list iterator
    list<pair<int,int>> dlist;  // Linked list to store pair of key, value
    int csize = 0;              // Cache size

public:
    LRUCache(int capacity)
    {
        csize = capacity;
    }
    
    int get(int key)
    {
        // search for key in the map
        if(umap.find(key) == umap.end()) return -1;
        
        // bring the key to front
        dlist.splice(dlist.begin(), dlist, umap[key]);
        
        // update the map
        umap[key] = dlist.begin();
        
        // return the value
        return dlist.begin()->second;
    }
        
        
    void put(int key, int value)
    {
        // search for key in the map
        if(umap.find(key) != umap.end())
        {
            // bring the key to front
            dlist.splice(dlist.begin(), dlist, umap[key]);
            
            // update the value
            dlist.begin()->second = value;
        }
        else
        {
            // check cache size
            if(umap.size() >= csize)
            {   
                // delete the key
                umap.erase(dlist.back().first);
                
                // remove the pair from list
                dlist.pop_back();
            }
            
            // create a pair and bring to front
            dlist.push_front(make_pair(key,value));
        }
       
        // update the map
        umap[key] = dlist.begin();
    }
};

