class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        if(!n) return 0;
        int left = 0;   // Lose Power, Gain Score from here
        int right = n-1; // Lose Score, Gain Power from here
        sort(tokens.begin(), tokens.end());
        if(power < tokens[0]){
            return 0;
        }
        int score = 0;
        while(left < right){
            while(left < right and power >= tokens[left]){
                power -= tokens[left];
                score++;
                left++;
            }
            if(power < tokens[left]){
                while(left < right and power < tokens[left]){
                    power += tokens[right];
                    score--;
                    right--;
                }
            }
        }
        return tokens[left] <= power ? score + 1 : score;       
    }
};