class Solution {
  public:
    int countDigits(int n) {
        int c = 0;
        while(n > 0){
            c++;
            n = n/10;
        }
        return c;
    }
};
