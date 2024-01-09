class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i >= 0 and j >= 0) {
            if(nums1[i] < nums2[j]) {
                nums1[k--] = nums2[j--];
            } else {
                nums1[k--] = nums1[i--];
            }
        }
// let's say if there are some elements left in n1 and n2 is 
// completely traversed , 
// then elements of n1 are already in there correct positions.
        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};