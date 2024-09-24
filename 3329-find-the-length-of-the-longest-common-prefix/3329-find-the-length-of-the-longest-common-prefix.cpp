class TrieNode {
public:
    TrieNode* children[10]; // Assuming only digits 0-9 are present
    TrieNode() {
        for (int i = 0; i < 10; ++i)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(int num) {
        TrieNode* curr = root;
        string str = to_string(num);
        for (char c : str) {
            int index = c - '0';
            if (!curr->children[index])
                curr->children[index] = new TrieNode();
            curr = curr->children[index];
        }
    }

    int findMaxPrefix(int num) {
        TrieNode* curr = root;
        string str = to_string(num);
        int prefixLength = 0;
        for (char c : str) {
            int index = c - '0';
            if (!curr->children[index])
                break;
            curr = curr->children[index];
            prefixLength++;
        }
        return prefixLength;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
       Trie trie;
        for (int num : arr2)
            trie.insert(num);
        
        int maxPrefixLength = 0;
        for (int num : arr1)
            maxPrefixLength = max(maxPrefixLength, trie.findMaxPrefix(num));
        
        return maxPrefixLength;
    }
};