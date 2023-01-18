class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
/*
use a map and store freq of every char of p 
iterate through s and decrease the freq if size hits to 0 
take that i in ans and remove cal for i(update its freq in map) and move to next window
*/
int i=0,j=0,n=s.size() , windowSize = p.size();
vector<int>ans; 
unordered_map<int,int>freq;
for(auto it : p) freq[it]++;
int uniqueElement = freq.size() ;

while(j<n){
       //decrease the freq of char of s if present in p 
         if(freq.find(s[j])!=freq.end()) {
             freq[s[j]]--;
            //when 0 remove it 
            if(freq[s[j]]==0) {
                uniqueElement--;//that char is removed completely
            }
         }
      //  cout<<freq['a']<<" "<<freq['b']<<" "<<freq['c']<<" "<<i<<" "<<j<<" "<<uniqueElement<<"\n";
     if(j-i+1 == windowSize){
        //restore every char freq 
        //restore ith char frequency
         if(uniqueElement==0) 
             //take in answer
             ans.push_back(i);
            if(freq.find(s[i])!=freq.end()){ freq[s[i]]++;
            //not always therefore in loop
            if(freq[s[i]] == 1) uniqueElement++;//that char is back
            }
         i++;
    }
    j++;
}
 return ans;
    }
};
