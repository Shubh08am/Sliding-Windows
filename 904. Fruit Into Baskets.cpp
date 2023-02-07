class Solution {
public:
    int totalFruit(vector<int>& fruits) {
    // 2 basket -> single type 
    // sliding window - longest subarray with 2 unique elements
   int i=0,j=0,n=fruits.size(); 
   int maxiFruit=0,currFruit=0;
    unordered_map<int,int>freq; unordered_set<int>s;
    for(auto it : fruits) s.insert(it);
   while(j<n){
         freq[fruits[j]]++;
        //when 2 unique elements found 
     
        if(freq.size()==2){ 
        //    cout<<"here\n"; 
            while(freq.size()==2 && j<n){
                j++; 
        //    cout<<"here\n";
    if(j!=n)     freq[fruits[j]]++; 
        } 
        //remove freq 
    //    cout<<"remove - " << j<<"\n";
    if(j!=n)    freq[fruits[j]]--;
    if(j!=n)     {  if(freq[fruits[j]]==0) freq.erase(fruits[j]);}
          j--;
            currFruit = j-i+1 ; 

            maxiFruit=max(maxiFruit,currFruit); 
        //    cout<<currFruit<<" "<<i<<" "<<j<<"\n";
            //remove calculation for i 
        //    cout<< freq.size() << "\n";
            while(freq.size()==2 && i<n){ 
            //    cout<<"here\n";
                freq[fruits[i]]--;
                if(freq[fruits[i]]==0) freq.erase(fruits[i]);
                i++;
            }
        } 
    //    cout<<"after "<<i<<"\n";
        j++;
   } 
   //when only 1 type of fruit than answer is size of fruit
   return (s.size()<2)?n:maxiFruit;
    }
}; 
