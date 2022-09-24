//when only +ve elements

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        // Complete the function
        //variable sized sliding window
        int i=0,j=0;
        int sum=0, max_size=0;
        
        while(j<N){
            sum+=A[j] ; 
            if(sum<k) j++;
            
            else if(sum==k){
                //candidate of answer
                int window_size = j-i+1;
                max_size = max(max_size,window_size);
                j++;
            }
            
        //3rd case found in variable sliding window
        else if(sum>k){
            //we need to remove some elements
          while(sum>k){
              sum-=A[i];
              i++;
          }
          if(sum==k){
              int window_size = j-i+1;
                max_size = max(max_size,window_size);
          }
          j++;
        }
        }
        
        return max_size;
    } 
};
