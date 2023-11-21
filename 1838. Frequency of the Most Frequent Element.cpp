class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size(),i=0,j=0,len=0;
        sort(nums.begin(),nums.end());
        vector<long long>pre(n); 
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=nums[i]+pre[i-1];
        }
        while(j<n){
            while(1ll*(j-i+1)*nums[j] > pre[j]-(i==0?0:pre[i-1])+k){
                    i++;
            }
            len=max(len,j-i+1);
            j++;
        }
    return len;
    }
};
