/*
Problem: https://leetcode.com/problems/design-search-autocomplete-system/

Solution:

Simple solution requiring Trie data structure
- Node class - Trie
- Compare class - comparator for inserting into set
                - two criteria : frequency + string
- Autocomplete system

- Idea is that when constructor is called, all sentences are inserted into
  a trie structure

- When a key is typed in, input function is called
    - search query is built
    - dfs is performed
    - insert into set the freq and string
    - reverse the set and push the answer

*/
class Node
{
public:

    // Map child Node* to each char
    unordered_map<char, Node*> children;

    // Flag to indicate if this is sentence ending
    bool isEnd;

    // Freq of a particular sentence
    int freq;

    // Full sentence
    string sentence;
    Node()
    {
        isEnd = false;
        freq = 0;
    }
};

class Compare
{
public:
    bool operator()(const pair<int,string>&a, const pair<int,string>&b) const {

        // Compare the strings
        if(a.first == b.first)
        {
            // return the smaller one
            return b.second < a.second;
        }

        // Return the greater frequency
        return a.first < b.first;
    }
};

class AutocompleteSystem
{
private:

    // Maintain the parent root
    Node* root;

    // String query, built till # is encountered
    string search_query;

    // Trie Iterator
    Node* lastPrefixNode;

    // Set for storing 3 hot results
    set<pair<int,string>,Compare> s;

public:
    void insertIntoTrie(string sentence, int times)
    {
        Node* curr = root;

        // Traverse all the chars in the word
        for(int i = 0; i < sentence.length(); i++) {

            // If doesn't exist already, create a new node
            if(!curr->children[sentence[i]]) {
                Node* child = new Node();
                curr->children[sentence[i]] = child;
            }

            // Advance
            curr = curr->children[sentence[i]];
        }

        // Set sentence end and frequency
        curr->isEnd = true;
        curr->freq += times;
        curr->sentence = sentence;
    }

    // Constructor
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {

        // Create root node
        root = new Node();
        lastPrefixNode = root;

        // Insert all sentences into the trie
        for(int i = 0; i < sentences.size(); i++) {
            insertIntoTrie(sentences[i], times[i]);
        }
    }

    // Recursive depth search
    void dfs(Node* root)
    {
        if(!root) return;

        // If we encountered sentence ending
        if(root->isEnd) {

            // Insert into the set
            s.insert( { root->freq, root->sentence } );

            // If size increases,
            if(s.size() > 3) s.erase(s.begin());
        }

        for(auto it = root->children.begin(); it != root->children.end(); it++) {
            dfs(it->second);
        }
    }

    vector<string> input(char c)
    {
        // result
        vector<string> res;

        // Once we reach '#', insert the entire search_query
        if(c == '#') {
            insertIntoTrie(search_query,1);

            // Clear the search_query overall
            search_query.clear();

            // Reset last prefix node to root
            lastPrefixNode = root;

            // return nothing for '#'
            return {};
        }

        // Push the character into search_query
        // so as to  insert into trie later
        search_query.push_back(c);

        // Check if lastprefixnode is nullptr or has children with nullptr
        if(!lastPrefixNode or !lastPrefixNode->children[c]) {
            lastPrefixNode = nullptr;

            // return nothing for this
            return {};
        }

        // Perform depth first search
        dfs(lastPrefixNode->children[c]);

        // Advance the lastprefixnode
        lastPrefixNode = lastPrefixNode->children[c];

        // Save result from set iterator
        for(auto it = s.begin(); it!=s.end(); it++) {
            res.push_back(it->second);
        }

        // Set, keeps on changing for every input
        s.clear();

        // Reverse the 3 hot results
        reverse(res.begin(),res.end());

        // Return result
        return res;
    }
};