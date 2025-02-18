class Solution {
public:
    string smallestNumber(string pattern) {
        stack<int> st;
        int n=pattern.size();
        string num="";
        for(int i=0;i<n+1;++i){
            st.push(i+1);
           if(i==n || pattern[i]=='I'){
            while(!st.empty()){
               num.push_back(char('0'+st.top()));
               st.pop();
            }
            
           }
        }
        return num;
    }
};