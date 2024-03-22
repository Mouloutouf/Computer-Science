#include <string>
#include <map>

using namespace std;

// EXPLANATION

// A trie is a tree data structure used to efficiently store and retrieve keys of strings. This is used for autocomplete for instance.
// Essentially, this is a tree where every node represents a single character of a word. The words are then stored by chaining the characters in the trie.
// This Trie should support insertion of words, as well as search of a certain word, and search of a prefix in any word.

// This is a great and simple solution

// All operations run in O(n) time and in O(1) space

struct TrieNode
{
    char* c = nullptr;

    map<char, TrieNode*> children;
    bool end = false;

    TrieNode() {}
    TrieNode(char c, bool end = false) : c(&c), end(end) {}
};

class Trie {
public:

    Trie()
    {
        root = new TrieNode();
    }
    
    void insert(string word)
    {
        TrieNode* cur = root;
        for (char& c : word)
        {
            if (cur->children.count(c) == false)
                cur->children[c] = new TrieNode(c);

            cur = cur->children[c];
        }
        cur->end = true;
    }
    
    bool search(string word)
    {
        TrieNode* cur = root;
        for (char& c : word)
        {
            if (cur->children.count(c) == false)
                return false;
            
            cur = cur->children[c];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix)
    {
        TrieNode* cur = root;
        for (char& c : prefix)
        {
            if (cur->children.count(c) == false)
                return false;

            cur = cur->children[c];
        }
        return true;
    }

private:
    TrieNode* root;
};