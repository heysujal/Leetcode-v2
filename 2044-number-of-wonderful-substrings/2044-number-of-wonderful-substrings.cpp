class Solution {
public:
    long long wonderfulSubstrings(string &word) {
        int n = word.size();
        long long count = 0;
        
        vector<long long> freq((1 << 10) + 1, 0); // Since we have to take only 2^10 possibilies, we can avoid an unordered_map
        
        freq[0] = 1;  // initialize the frequency of 0000000000 as 1 because when no element is encountered, then th bitmask is 0
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            int mask = (1 << (word[i] - 'a'));
            res ^= mask; // toggling bit of the current character to make it from odd to even OR even to odd
            count += freq[res]; // way 1
			
			int chkMask = 1;
            for (int j = 1; j <= 10; j++) {    // Loop for checking all possiblities of different places of the Different Bit
                count += freq[chkMask ^ res];
                chkMask <<= 1;
            }
            
            freq[res]++;  // increasing the frequency of the current bitmask
        }
        
        return count;
    }
};