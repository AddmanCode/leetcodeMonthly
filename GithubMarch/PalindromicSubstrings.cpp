class Solution {
public:
    int countSubstrings(string s) {
        int len = s.length();
        bool dpmat[s.length()][s.length()];
        int count = 0;
        int g = 0;
        
        for(g=0; g<len; g++) {
            for(int i=0,j=g; j < len; j++) {
                if(g == 0)
                    dpmat[i][j] = true;
                else if(g == 1) {
                    if(s[i] == s[j])
                        dpmat[i][j] = true;
                    else
                        dpmat[i][j] = false;
                }
                else {
                    if((s[i] == s[j]) && (dpmat[i+1][j-1] == true)) {
                        dpmat[i][j] = true;
                    }
                    else
                        dpmat[i][j] = false;
                }
                
                if(dpmat[i][j] == true)
                    count++;
                i++;
            }
        }
        return count;
    }
};