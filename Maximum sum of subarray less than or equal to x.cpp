class Solution{
public:
	int findMaxSubarraySum(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    int i=0,j=0,max_sum=0,msum=INT_MIN;
	    
	     while(j<n){
	     max_sum+=arr[j];
	     
	    while(max_sum > sum){
	        //remove cal for i
	        max_sum-=arr[i];
	        i++;
	    }
	         msum=max(max_sum,msum);
	         j++;
	     }
	 return msum;
}
};
