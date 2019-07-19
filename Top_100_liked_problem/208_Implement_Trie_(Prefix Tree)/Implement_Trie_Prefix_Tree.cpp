#include <iostream>

#include "../../Utils/Utils.h"

using namespace std;

class Trie {
public:
    TrieNode* root[128] = {NULL};
    Trie() {
        
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(word.length() == 0) return ;
        int child_idx = word[0];
        TrieNode* temp = NULL;
        if(root[child_idx] == NULL) root[child_idx] = new TrieNode();
        temp = root[child_idx];
        for(int i = 1; i < word.length(); ++i) {
            child_idx = CharToInt(word[i]);
            if(temp->child[child_idx] == NULL) temp->child[child_idx] = new TrieNode();
            temp = temp->child[child_idx];
        }
        temp->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(word.length() == 0) return true;
        int child_idx = word[0];
        TrieNode* temp = NULL;
        if(root[child_idx] == NULL) return false;
        temp = root[child_idx];
        for(int i = 1; i < word.length(); ++i) {
            child_idx = CharToInt(word[i]);
            if(temp->child[child_idx] == NULL) return false;
            temp = temp->child[child_idx];
        }
        if(temp->isEnd) return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(prefix.length() == 0) return true;
        int child_idx = CharToInt(prefix[0]);
        TrieNode* temp = NULL;
        if(root[child_idx] == NULL) return false;
        temp = root[child_idx];
        for(int i = 1; i < prefix.length(); ++i) {
            child_idx = CharToInt(prefix[i]);
            if(temp->child[child_idx] == NULL) return false;
            temp = temp->child[child_idx];
        }
        return true;
    }
};


int main()
{
    Trie* trie = new Trie();
    cout << "true" << endl;
    trie->insert("apple");
    cout << trie->search("apple") << endl;// returns true
    cout << trie->search("app") << endl;     // returns false
    cout << trie->startsWith("app") << endl; // returns true
    trie->insert("app");   
    cout << trie->search("app") << endl;     // returns true
    return 0;
}