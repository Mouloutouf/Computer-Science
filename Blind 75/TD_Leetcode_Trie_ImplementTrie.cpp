#include <string>
#include <map>

using namespace std;

struct TrieNode
{
    char* c = nullptr;

    map<char, TrieNode*> children;
    bool end = false;

    TrieNode() {}
    TrieNode(char c, bool end = false) : c(&c), end(end) {}
};

// TODO

// This is a great and simple solution

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