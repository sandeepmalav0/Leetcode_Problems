class Solution {
public:
    int minRotations(string s) {
        int st=s[0]-'0';
        int rot=min(st,10-st);
        for(int i=1;i<10;i++){
            int d = abs(s[i]-s[i-1]); 
            rot += min(d,10-d);
        }
        return rot;
    }
};