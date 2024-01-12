class Solution {
public:
    
    int countVowel(string s, int low , int high) {
        int count = 0;
        vector<char> vowels = {
            'a', 'e', 'i', 'o', 'u'
        };
        for(int i = low; i <= high ; i++){
            char ele = tolower(s[i]);
            auto it = find(vowels.begin(), vowels.end(), ele);
            if(it != vowels.end()){
               count++;
            }   
        }
        return count;
    }
    bool halvesAreAlike(string s) {
        int limit = (s.size()/2) -1;
        int c1 = countVowel(s, 0, limit);
        int c2 = countVowel(s,limit+1, s.size()-1);
        return c1 == c2;
    }
};