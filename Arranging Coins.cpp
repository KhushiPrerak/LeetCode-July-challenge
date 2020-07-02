// O(n) approach. This was my first approach. Had to look at the discussions for the binary search approach.
class Solution {
public:
    int arrangeCoins(int n) {
        int count = 0;
        int i=1;
        while(n>=i){
            count++;
            n=n-i;
            i++;
        }
        return count;
    }
};


// Binary search O(logn) [Mind blowing approach]
// total full rows are 1+2+3+.....+k = k*(k+1)/2
// condition: k*(k+1)/2<=n
class Solution {
public:
    int arrangeCoins(int n) {
        long low = 0, high = n;
        int ans = 0;
        while(low<=high) {
            long k = low + (high-low)/2;
            long curr = k*(k+1)/2;
            if(n<curr) {
                high = k-1;
            } else {
                low = k+1;
                ans = k;
            }
        }
        return ans;
    }
};
