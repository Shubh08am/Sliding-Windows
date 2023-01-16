class Solution {
public:
    int slidingWindow(vector<int> &nums1, vector<int> &nums2) {

        int Length  = 0 , i=0;
        while (i < nums2.size()) {
            int cnt = 0 , j=0;
            while (j < nums1.size() && i + j < nums2.size()) {
                if (nums1[j] == nums2[i + j]) cnt++;
                else cnt = 0;
                
                Length  = max(Length , cnt);
                j++;
            }
            i++;
        }
        return Length ;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
          int ans1 = slidingWindow(nums1, nums2);
         int ans2 =  slidingWindow(nums2, nums1);

         return max(ans1,ans2);
    }
};
