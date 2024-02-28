class Solution {
public:
    
    
    
    /**
 * @type of s: string
 * @return type: integer
 */
 
    
    int getValue(char ch){
        
        
     switch(ch){
     
         case 'I': return 1;
             break;
             
               case 'V': return 5;
             break;
               case 'X': return 10;
             break;
               case 'L': return 50;
             break;
               case 'C': return 100;
             break;
               case 'D': return 500;
             break;
             
                            case 'M': return 1000;
             break;
             
       
     
     }   
             return -1; 
    }
    
    
    
    int romanToInt(string s) {
        // write your awesome code here
        int ans =0 ;
        
        int i =0
            ;
        for(  i = 0; i<s.length()-1  ;i++){
            
            if(getValue(s[i]) >= getValue(s[i+1]))
            	ans+=getValue(s[i]);
               
               
             else
               ans-=getValue(s[i]);
               
               
                
        
        
    }
        
        ans+=getValue(s[i]);
        
             return ans;  
               }
};