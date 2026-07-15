class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int eSum = n*(n+1);
        int oSum = n*n;
        return __gcd(eSum, oSum);
    }
};