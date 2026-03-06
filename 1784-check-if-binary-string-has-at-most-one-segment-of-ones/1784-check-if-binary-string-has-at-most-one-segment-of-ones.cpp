class Solution {
public:
    bool checkOnesSegment(string s) {
        bool seen1=false;
        bool seen01=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                if(seen01==true) return false;
                seen1=true;
            }     else if(seen1==true)  
                          seen01=true;
    }
    return true;
    }
};