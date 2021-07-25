/*
Problem: https://leetcode.com/problems/design-add-and-search-words-data-structure/

Design Add and Search Words Data Structure

TC: O(n) best case, worst case O(num of chars ^ n)
SC: O(n)
*/class Node
{
  
public:
    unordered_map<char, Node*> children;
    bool isEnd;
    string word;
    Node() {
        isEnd = false;
    }  
};
class WordDictionary {
private:
    Node* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* curr = root;
        for(auto c: word)
        {
            if(curr->children[c] == nullptr) curr->children[c] = new Node();
            curr = curr->children[c];
        }
        curr->isEnd = true;
        curr->word = word;
        
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word, Node* head = nullptr) {
        Node* curr = head;
        int i = 0;
        if(head == nullptr) curr = root;
        for(; i < word.size(); i++)
        {
            if(word[i] == '.')
            {
                cout << word << endl;
                for(auto child : curr->children)
                {
                    bool found = search(word.substr(i+1), child.second);
                    if(found == true) return true;    
                }
                return false;
            }
            else
            {
                if(curr->children[word[i]] == nullptr) return false;
                curr = curr->children[word[i]];
            }
        }
        return curr->isEnd;
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */