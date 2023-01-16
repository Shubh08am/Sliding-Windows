class Solution {
public:
    int countGoodSubstrings(string s) {
        //fixed size sliding window 
        int i=0,j=0,cnt=0;
        map<char,int>st;
        while(j<s.size()) {
            st[s[j]]++;
            if(j-i+1==3) {
                if(st.size()==3) cnt++;
                st[s[i]]--;
                if(st[s[i]]==0) st.erase(s[i]) ;
                i++; 
            }
            j++;
        }
        return cnt;
    }
};
