class Solution {
public:
    bool halvesAreAlike(string s) {
        int mid = (0 + s.size() - 1) / 2;
        int a = 0, b = 0;
    
        for(int i = 0; i <= mid; i++){
            if(s[i]=='a'|| s[i]=='e'|| s[i]== 'i'|| s[i]== 'o'|| s[i]=='u'|| s[i]=='A'|| s[i]=='E'|| s[i]=='I'|| s[i]=='O'|| s[i]=='U')
                a++;
        }
    
        for(int i = mid + 1; i < s.size(); i++){
            if(s[i]=='a'|| s[i]=='e'||s[i]== 'i'||s[i]== 'o'||s[i]== 'u'||s[i]== 'A'||s[i]== 'E'||s[i]== 'I'||s[i]== 'O'|| s[i]=='U')
                b++;
        }
    
        return a == b; 
    }
};
