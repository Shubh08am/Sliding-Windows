class Solution {
public:
    int numberOfSubstrings(string s) {
        //sliding window of variable size 
        //just see for a,b,c if found after that don't need to see only take count of difference in position of (size-1-j) 
        //keep track of a,b,c either use 3 variable or single or mapping
        int i=0,j=0,cnt=0,a=0,b=0,c=0,n=s.size();
        while(j<n) {
            if(s[j]=='a') a++ ; if(s[j]=='b') b++ ; if(s[j]=='c') c++;
            
            //when we got atleast every character once 
            if(a>0 and b>0 and c>0) {
                 cnt++;//that window
                 int leftWindow=n-j-1;
                 cnt+=leftWindow;

                //restore freq of ith character
             while(a>0 and b>0 and c>0){ 
             if(s[i]=='a') a-- ; 
             if(s[i]=='b') b-- ; 
             if(s[i]=='c') c--;
             if(a>0 and b>0 and c>0) {
                 cnt++;
                 int leftWindow=n-j-1;
                 cnt+=leftWindow;
             }
                i++;//remove calc for i 
             }
             
            }
            j++;
        }
        return cnt;
    }
};
