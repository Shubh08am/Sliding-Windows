class Solution {
public:

    int longestNiceSubarray(vector<int>& nums) {
       vector<int>setBitFreq(31,0);
       int left=0,n=nums.size(),ans=0;

       //keep track of set bit freq if at any time it's >1 than remove calulation for i i.e start pointer 

       for(int i=0;i<n;i++){
           bool alreadySet=false;
           for(int bit=0;bit<31;bit++){
               //whether that bit is set for nums[i] or not 
                if(nums[i] & (1<<bit)){
                    setBitFreq[bit]++;
                    //if it become >1 i.e no more that subarray is valid 
                    if(setBitFreq[bit]>1){ 
                        alreadySet=true;
                    }
               }
           }
           if(alreadySet==false){
               //maximize the ans 
             //  cout<<i-left+1<<" ";
               ans=max(ans,i-left+1);
           }
              else{
               //remove the calulation till the setBitFreq of every num is 1 
               while(left<=i){
                   for(int bit=0;bit<31;bit++){
               //whether that bit is set for nums[i] or not 
                if(nums[left] & (1<<bit)){
                     setBitFreq[bit]--;
                     } 
                 }         
               left++;
               bool alreadySet2=false;
                 for(int bit=0;bit<31;bit++){
                    if(setBitFreq[bit]>1)  {
                        alreadySet2=1;
                        }
                }
                 if(alreadySet2==0)   { 
                     break;
                     }
                }
           }
       }
    return ans;
    }
};
