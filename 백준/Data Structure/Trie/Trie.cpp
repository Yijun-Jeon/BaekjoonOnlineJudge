#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

class Trie {
    const static int M = 26;
    const static char OFFSET = 'a';

    struct TrieNode {
        int child[M];
        bool is_terminal;

        TrieNode() {
            memset(child, -1, sizeof(int) * M);
            is_terminal = false;
        }
    };

    vector<TrieNode> nodes;

public:
    Trie() : nodes(1) {}

    void init() {
        nodes.resize(1);
        nodes[0] = TrieNode();
    }

    void insert(const string& str) {
        int node_id = 0;
        for (const char c : str) {
            if (nodes[node_id].child[c - OFFSET] == -1) {
                nodes[node_id].child[c - OFFSET] = nodes.size();
                nodes.__emplace_back(TrieNode());
            }
            node_id = nodes[node_id].child[c - OFFSET];
        }
        nodes[node_id].is_terminal = true;
    }

    void remove(const string& str) {
        int node_id = 0;
        for (const char c : str) {
            if (nodes[node_id].child[c - OFFSET] == -1) {
                return;
            }
            node_id = nodes[node_id].child[c - OFFSET];
        }
        nodes[node_id].is_terminal = false;
    }

    bool find(const string& str) const {
        int node_id = 0;
        for (const char c : str) {
            if (nodes[node_id].child[c - OFFSET] == -1) {
                return false;
            }
            node_id = nodes[node_id].child[c - OFFSET];
        }
        return nodes[node_id].is_terminal;
    }
};

int main(void){
    Trie trie = Trie();

    trie.insert("apple");
    cout << trie.find("apple") << endl; // 1

    trie.remove("apple");
    cout << trie.find("apple") << endl; // 0
    return 0;
}