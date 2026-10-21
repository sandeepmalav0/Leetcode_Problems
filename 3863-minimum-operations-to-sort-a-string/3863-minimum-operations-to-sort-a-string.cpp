class Solution {
public:
    bool isSort(string str){
        int n=str.length();
        for(int i=0;i<n-1;i++){
            if(str[i]>str[i+1])return false;
        }
        return true;
    }
    int minOperations(string s) {
        int n=s.length();
        if(n==1)return 0;
        bool is = isSort(s);
        if(is)return 0;
        if(n==2)return -1;

        char minC = s[0], maxC = s[0];
        for(char c:s){
            minC = min(minC,c);
            maxC = max(maxC,c);
        }
        if(minC==s[0] || maxC==s[n-1])return 1;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == minC || s[i] == maxC)
                return 2;
        }
        return 3;
    }
};