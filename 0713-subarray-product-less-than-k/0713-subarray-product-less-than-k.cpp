class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Number of subarrays will be given by head-tail+1
        // i.e. length of subarray because 
        // this time all the subarrays will include a new
        // character/element present at head
        // All the subarrays for previous elements will 
        // be covered already by this time.  
        
        int head = 0;
        int tail = 0;
        int ans = 0;
        int prod = 1;
        // if k is 0 or 1 then return 0 arr[i] >= 1
        if(k == 1 or k == 0)
            return 0;
        for(head=0;head<nums.size();head++){       
            prod*=nums[head];
            while(prod >= k){
                prod/=nums[tail];
                tail++;
            }
            ans = ans + head-tail+1;
        }
        return ans;
    }
};