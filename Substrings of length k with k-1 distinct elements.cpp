
class Solution {
  public:
    int countOfSubstrings(string S, int K) {
        // code here
        int i=0,j=0,cnt=0;
        map<char,int>mp;
        
        while(j<S.size()){
            mp[S[j]]++;
            if(j-i+1<K) {
                j++;
            }
            
            else if(j-i+1==K){
                
                if(mp.size()==K-1) cnt++;
                
                mp[S[i]]--;
                if(mp[S[i]]==0) mp.erase(S[i]);
                i++;
                j++;
            }
        }
        return cnt;
    }
};
