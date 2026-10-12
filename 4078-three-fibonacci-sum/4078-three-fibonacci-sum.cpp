class Solution {
public:
    bool threeFibonacciSum(int n) {
        if(n&1)return false;
        int sum=n/2;
        int a=0,b=1;
        int c= a+b;
        while(c <= sum){
            c=a+b;
            if(c==sum)return true;
            a=b;
            b=c;
        }
        return false;
    }
};