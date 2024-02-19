class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        
        int p=mod_binsearch(A,target,0,n);
        return p;
      
    }
    
    
    
    int mod_binsearch(int A[],int target,int l,int n)
    {
            int low=0,high=n;
           int mid;
        
     
         while (low <= high)
         {
        mid=(low+high)/2;
      
              if (A[mid] == target)
                    return mid   ;         
              else if (A[mid] < target)
                 low = mid+1;
              else
                 high = mid-1;
        }
        
       if(target>mid) mid++;
        return mid;
        else
        mid--;
        return mid;
        
   
        
    }
};