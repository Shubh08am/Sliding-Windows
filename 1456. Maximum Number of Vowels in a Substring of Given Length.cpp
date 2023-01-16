class Solution {
public: 
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ;
    }
    int maxVowels(string s, int k) {
        //fixed sized sliding window 
        int vowels=0 , maxVowels_Window = 0;
        int i=0,j=0;
        while(j<s.size()) {
           if(isVowel(s[j])) vowels++;

            if((j-i+1) == k ) {
             maxVowels_Window = max(maxVowels_Window ,vowels);
             if(maxVowels_Window==k){
                 break;
             }
             //remove calculation for i 
             vowels-=(isVowel(s[i]));
             i++;
            }
            j++;
        }
        return maxVowels_Window;
    }
};
