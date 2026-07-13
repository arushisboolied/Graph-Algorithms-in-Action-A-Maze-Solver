class Trie {
    struct Node {
        Node* child[26];
        bool isEnd = false;
        Node() {
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };
    Node* root;

public:
    Trie() : root(new Node()) {}

    void insert(const string& w) {
        Node* c = root;
        for (char ch : w) {
            int i = ch - 'a';
            if (!c->child[i])
                c->child[i] = new Node();
            c = c->child[i];
        }
        c->isEnd = true;
    }

    bool search(const string& w) {
        Node* c = walk(w);
        return c && c->isEnd;
    }

    bool startsWith(const string& p) { return walk(p) != nullptr; }

private:
    Node* walk(const string& s) {
        Node* c = root;
        for (char ch : s) {
            int i = ch - 'a';
            if (!c->child[i])
                return nullptr;
            c = c->child[i];
        }
        return c;
    }
};
