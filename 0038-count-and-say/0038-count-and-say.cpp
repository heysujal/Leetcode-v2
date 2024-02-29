class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }

        string say = countAndSay(n-1);
        int size = say.size();
        string result = "";
        // we need to print the count then the digit
        for(int i = 0; i < size; i++){
            int count = 1;
            char ch = say[i];
            int j = i+1;
            while(j < size and say[i] == say[j]){
                count++;
                j++;
            }
            j--;
            i = j;
            result += to_string(count) + string(1, ch);
        }
        return result;
    }
};