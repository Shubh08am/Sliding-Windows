class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        /*
 10,5,[10,5] , 2,[5,2] , 6 , [5,2,6] , [2,6]
  
        */
        if(k<=1) return 0;
        long long int i=0,j=0,product=1,cnt=0;
        while(j<nums.size()) {
            product*=nums[j];

          if(product>=k){
                //remove cal for i 
                while(product>=k){
                    product/=nums[i];
                    i++;
                }
            }
          if(product<k) {
                  int leftWindow = j-i+1; 
                  cnt+=leftWindow;
              }
        j++;
        }
        return cnt;
    }
};
