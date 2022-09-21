class Solution {
  public:
    int smallestSubstring(string s) {
        // Code here
        //variable sized sliding window
        int i=0 , j=0 , ans=0;
        int min_size = INT_MAX;
        map<char,int>mp;
        while(j<s.size()){
            mp[s[j]]++;
            if(mp.size()<3) j++;
        else if(mp.size()==3){
             
             while(mp.size()==3){
                min_size=min(min_size,j-i+1);
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
             }
                j++;
            }
        
        }
        if(min_size==INT_MAX) return -1;
        else return min_size;
    }
};
