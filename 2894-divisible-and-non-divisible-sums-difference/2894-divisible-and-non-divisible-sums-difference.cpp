class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sumofdiv=0;
        for(int range=0;range<=n;range++){
            if(range%m==0){
                sumofdiv-=range;
            }
            else{
                sumofdiv+=range;
            }
        }
        return sumofdiv;
    }
};