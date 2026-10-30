class Trie {
public:
    struct Node {
        Node* links[26];
        bool flag;
        Node() {
            flag = false;
            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
        }
    };
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->links[index] == nullptr) {
                node->links[index] = new Node();
            }
            node = node->links[index];
        }
        node->flag = true;
    }
    bool search(string word) {
        Node* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (node->links[index] == nullptr) {
                return false;
            }
            node = node->links[index];
        }
        return node->flag;
    }
    bool startsWith(string prefix) {
        Node* node = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (node->links[index] == nullptr) {
                return false;
            }
            node = node->links[index];
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


 
