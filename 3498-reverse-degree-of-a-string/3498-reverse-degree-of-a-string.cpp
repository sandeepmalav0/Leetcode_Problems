class Solution {
public:
    int reverseDegree(string s) {
        int degree = 0;
        int n=s.length();
        for(int i=0;i<n;i++){
            int ch = 'z'-s[i]+1;
            degree += ch*(i+1);
        }
        return degree;
    }
};