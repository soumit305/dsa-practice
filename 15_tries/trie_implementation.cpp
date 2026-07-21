#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* list[26];
    bool flag;

    bool containsKey(char c) {
        return (list[c - 'a'] != nullptr);
    }

    void put(char c, Node* node) {
        node->list[c - 'a'] = new Node();
    }

    Node* getKey(char c) {
        return list[c - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return (flag == true);
    }
};

class Trie {
   private:
    Node* root;

   public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], node);
            }
            node = node->getKey(word[i]);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->getKey(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->getKey(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */