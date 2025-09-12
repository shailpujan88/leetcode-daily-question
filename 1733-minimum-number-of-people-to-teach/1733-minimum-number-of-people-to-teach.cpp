class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> sadUsers;

        for(auto &friends:friendships){
            int u=friends[0]-1; // 0 based indexing
            int v=friends[1]-1; // 0 based indexing
            unordered_set<int> langSet(begin(languages[u]),end(languages[u]));
            bool cantalk=false;
            for(auto lang: languages[v] ){
                if(langSet.count(lang)){
                    cantalk=true;
                    break;
                }

            }
            if(!cantalk){
                sadUsers.insert(u);
                sadUsers.insert(v);
            }

        }
        vector<int>language(n+1,0);
        int mostknownlang=0;
        for(int user:sadUsers){
            for(int lang:languages[user]){
                language[lang]++;
                 mostknownlang=max( mostknownlang,language[lang]);
 
            }
        }
         return sadUsers.size()-mostknownlang;
     }
};