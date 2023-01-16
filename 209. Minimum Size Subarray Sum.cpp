class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //sliding window -> variable sized window 
        int i=0,j=0;
        int sum=0 , minWindow=INT_MAX;
        while(j<nums.size()) {
             sum+=nums[j] ; 

             //if target reached 
             if(sum>=target){
                 //take this window in ans and look for min window
                 minWindow = min(minWindow,j-i+1);
                 //remove calculation for i 
                 sum-=nums[i]; 
               //  cout<<sum<<" fi\n";
                 i++;
             } 
         //again keep checking after removing calculation for i
         while(sum>=target){
                  minWindow = min(minWindow,j-i+1);
                  sum-=nums[i]; 
                // cout<<sum<<" si\n";
                  i++;
         }
             j++;
        }
        if(minWindow==INT_MAX) return 0;
        return minWindow;
    }
};
