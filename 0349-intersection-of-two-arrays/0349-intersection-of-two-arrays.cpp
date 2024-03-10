class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // sorting + binary Search
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans;
        int i = 0;
        int j = 0;
        while(i < m and j < n){
            if(nums1[i] == nums2[j]){
                ans.push_back(nums1[i]);
                while(i < m-1 and nums1[i] == nums1[i+1]){
                    i++;
                }
                while(j < n-1 and nums2[j] == nums2[j+1]){
                    j++;
                }
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};