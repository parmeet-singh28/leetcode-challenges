class Solution {
public:
    int maxProduct(int n) {
        int maxi1 = -1, maxi2 = -1;
        while(n){
            int dig = n%10;
            n/=10;
            if(dig>=maxi1){
                maxi2 = max(maxi2, maxi1);
                maxi1 = dig;
            }
            else if(dig>=maxi2){
                maxi2 = dig;
            }
        }
        return maxi1*maxi2;
    }
};