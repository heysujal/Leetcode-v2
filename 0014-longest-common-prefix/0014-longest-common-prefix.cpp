class Solution {
public:
    // Using Trie
    class TrieNode{
        public :
            char data;
            TrieNode *children[26];
            int childCount;
            bool isTerminal;
        TrieNode(char ch){
            data = ch;
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
            childCount = 0;
            isTerminal = false;
        }

    };

    class Trie{
        public : 
            TrieNode* root;
            Trie(char ch){
                root = new TrieNode(ch);
            }

            void insertUtil(TrieNode *root, string word){
                // base case
                if(word.size() == 0){
                    root->isTerminal = true;
                    return;
                }

                int idx = word[0] - 'a';
                // character doesn't exist already
                if(root->children[idx] == nullptr){
                    root->children[idx] = new TrieNode(word[0]);
                    root->childCount++;
                }
                // passing on this node to rest of the characters
                insertUtil(root->children[idx], word.substr(1));
            }

            void insert(string word){
                insertUtil(root, word);
                return;
            }

            void lcp(string s, string &ans){
                for(int i = 0; i < s.size(); i++){
                    if(root->childCount == 1){
                        char ch = s[i];
                        int idx = ch - 'a';
                        ans += ch;
                        root = root->children[idx];
                    }
                    else{
                        break;
                    }
                    if(root->isTerminal == true){
                        break;
                    }
                }
            }
    };
    string longestCommonPrefix(vector<string>& strs) {
        Trie *t = new Trie('\0'); // this is root;
        for(auto &word : strs){
            if(word == ""){
                return "";
            }
            else{
                t->insert(word);
            }
        }

        // assume first one to be the answer
        string first = strs[0];
        string ans = "";
        t->lcp(first, ans);
        return ans;
    }
};