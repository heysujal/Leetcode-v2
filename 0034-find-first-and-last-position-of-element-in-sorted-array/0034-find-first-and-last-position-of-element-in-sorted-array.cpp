class Solution {
public:
    
    
    int bs(vector<int>& arr, int low, int high,int target, bool firstPos){
        int pos =-1;
        
        while(low<=high){
            
            int mid = low +(high-low)/2;
            
            if(arr[mid]==target){
            pos = mid;
                if(firstPos){
                    high = mid-1;
                    
                }else{
                    low=mid+1;
                }
                
            }else if(target > arr[mid]){
                low= mid+1;
                
            }else{
                high = mid-1;
                
            }
            
            
        }
        
        return pos;
        
        
    }
    
    vector<int> searchRange(vector<int>& arr, int target) {
        
        int fi = bs(arr,0, arr.size()-1,target,true);
        int li = bs(arr,0,arr.size()-1, target, false);
        return {fi,li};
        
    }
};