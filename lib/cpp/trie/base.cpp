#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

struct Trie
{
    Trie *next[26] = {};
    bool isEnd = false;

    void insert(const string &w)
    {
        Trie *node = this;
        for (char c : w)
        {
            if (!node->next[c - 'a'])
                node->next[c - 'a'] = new Trie();
            node = node->next[c - 'a'];
        }
        node->isEnd = true;
    }

    bool search(const string &w)
    {
        Trie *node = this;
        for (char c : w)
        {
            if (!node->next[c - 'a'])
                return false;
            node = node->next[c - 'a'];
        }
        return node->isEnd;
    }

    bool startsWith(const string &p)
    {
        Trie *node = this;
        for (char c : p)
        {
            if (!node->next[c - 'a'])
                return false;
            node = node->next[c - 'a'];
        }
        return true;
    }
};