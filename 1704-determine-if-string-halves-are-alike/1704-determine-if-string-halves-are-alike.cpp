class Solution {
public:
    
    int countVowel(string s, int low , int high) {
        
        
        int count = 0;
        
        
        for(int i = low; i <= high ; i++){
            char ele = tolower(s[i]);
            
            if((ele=='a') or
             ( ele=='e') or
              (ele=='i') or
              (ele=='o') or
              (ele=='u') ){
               count++;
                
            }
            
            
        }
        
        
        return count;
    }
    bool halvesAreAlike(string s) {
        int limit = (s.size()/2) -1;
        
        int c1 = countVowel(s, 0, limit);
        int c2 = countVowel(s,limit+1, s.size()-1);
        
        if(c1==c2)
            return true;
        
        return false
            
            ;
        
        
    }
};