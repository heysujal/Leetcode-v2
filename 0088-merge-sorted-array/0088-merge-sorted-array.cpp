class Solution {
public:
    // brute
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> arr(m+n);
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < m and j < n){
            arr[k++] = (nums1[i] <= nums2[j]) ? nums1[i++] : nums2[j++];
        }
        while(i < m){
            arr[k++] = nums1[i++];
        }
        while(j < n){
            arr[k++] = nums2[j++];
        }
        nums1 = arr;
    }
};