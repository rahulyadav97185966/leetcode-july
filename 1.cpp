// Arranging Coins

class Solution {
public:
    int arrangeCoins(int n) {
        long long num=n;
        return (-1+sqrt(1+8*num))/2;
    }
};
