class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //fixed size sliding window question 
        int i=0,j=0,n=s.size();
         vector<string>ans;
        unordered_map<string,int>freq; 
        string dna ="";
        while(j<n){
            dna+=s[j];
            if(j-i+1==10){
                freq[dna]++;
                //update dna 
                 i++;
                dna = s.substr(i,j-i+1);
            }
            j++;
        }
      for(auto it : freq){
          if(it.second>1) ans.push_back(it.first);
      }
      return ans;
    }
};
