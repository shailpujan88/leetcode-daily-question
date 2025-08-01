class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> mp;
        int ans;
       for(string email:emails){
        string mail;
        int index=email.find('@');
        for(int i=0;i<index;i++){
            if(email[i]=='+') break;
            if(email[i]!='.') mail+=email[i];
        }
        mail+=email.substr(index);
        mp.insert(mail);
        ans=mp.size();
       }
       return ans;
    }
};