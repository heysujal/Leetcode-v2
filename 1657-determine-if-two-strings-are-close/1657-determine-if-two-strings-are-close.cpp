class Solution {
public:
       
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;


        // only perform operation 2
        // we check if freq of w1 and w2 are anagrams
        vector<int> f1(26), f2(26);
        for(int i = 0; i < word1.size(); i++){
            f1[word1[i] - 'a']++;
            f2[word2[i] - 'a']++;
        }
        // jo word f1 mei hai wo f2 mein hona chahiye
        for(int i = 0; i < 26; i++){
            if(f1[i] != 0 and f2[i] != 0)
                continue;
            if(f1[i] == 0 and f2[i] == 0)
                continue;
            else
                return false;
        }
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());
        return f1 == f2;
    }
};