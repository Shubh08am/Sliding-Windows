class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        //fixed sized sliding window 
        int i=0,j=0,sum=0,subarray=0;
        while(j<arr.size()) {
            sum+=arr[j] ; 

            if(j-i+1 == k ) {
                if(sum/k >= threshold) subarray++;
                //remove calculation for i 
                sum-=arr[i];
                i++;
            }
            j++;
        }
        return subarray;
    }
};
