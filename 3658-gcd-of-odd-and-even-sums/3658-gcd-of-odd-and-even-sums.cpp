class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int eSum = n*(n+1);
        n*=2;
        int oSum = (n*(n+1))/2-eSum;
        return __gcd(eSum, oSum);
    }
};