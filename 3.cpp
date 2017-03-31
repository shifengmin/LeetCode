class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        int a[500]={0};
        int ret = 1;
        int l=0,r=1;
        a[s[l]] = 1;
        while(r<s.length()){
            if(a[s[r]]){
                bool ok = false;
                while(!ok){
                    if(s[l]==s[r]){
                        ok = true;
                        l++;
                    }else{
                        a[s[l]] = 0;
                        l++;
                    }
                }
            }else{
                ret = max(ret,r-l+1);
                a[s[r]] = 1;
            }
            r++;
        }
        return ret;
    }
};
