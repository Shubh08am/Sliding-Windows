class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size(),i=0,j=0,ans=0,zero=0;
        while(j<n){
            zero+=(nums[j]==0);
            while(zero>1){
                zero-=(nums[i++]==0);
            }
            ans=max(ans,j-i);
        j++;
        }
    return ans;
    }
};
