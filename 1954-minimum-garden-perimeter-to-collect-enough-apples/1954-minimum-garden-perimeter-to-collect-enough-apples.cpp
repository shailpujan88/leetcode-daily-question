class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long index=0;
        for(long long i=1;i<=100000000;i++){
            if(neededApples <= 2*i*(i+1)*(2*i+1) ){
                index=i;
                break;
            }
        }
        return index*8;
    }
};