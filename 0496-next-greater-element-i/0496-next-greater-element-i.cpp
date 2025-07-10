class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int,int> mpp; // A map to store the next greater number for each element in nums2
      stack<int> st; // A stack to help find the next greater number

      for(int i = nums2.size()-1 ; i>=0; i--){
        
        // Pop elements from the stack while the top of the stack is less than or equal to nums2[i]
        while(!st.empty() && st.top() <= nums2[i]){
            st.pop(); // Remove smaller elements because they can't be the "next greater"
        }
        
        // If the stack is not empty, the top of the stack is the next greater element for nums2[i]
        if(!st.empty()) {
            mpp[nums2[i]] = st.top(); // Store this next greater element in the map
        } 
        else {
            mpp[nums2[i]] = -1; // If the stack is empty, there is no greater element, so set -1
        }
        
        // Push the current element onto the stack
        st.push(nums2[i]);
      }

      // Now, for each element in nums1, we just look up the next greater element from the map
      vector<int> ans;
      for(int num: nums1){
        ans.push_back(mpp[num]); // Add the result to the answer array
      }

      return ans; // Return the result array
    }
};
