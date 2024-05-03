class Solution{
public:
    int compareVersion(string version1, string version2) {
    string v1 = "", v2 = "";
    size_t i = 0, j = 0;
    
    while (i < version1.size() || j < version2.size()) {
        int num1 = 0, num2 = 0;
        
        while (i < version1.size() && version1[i] != '.') {
            if (version1[i] != '0' || !v1.empty())
                v1 += version1[i];
            i++;
        }
    
        while (j < version2.size() && version2[j] != '.') {
            if (version2[j] != '0' || !v2.empty())
                v2 += version2[j];
            j++;
        }
        
        num1 = v1.empty() ? 0 : stoi(v1);
        num2 = v2.empty() ? 0 : stoi(v2);
        if (num1 < num2) return -1;
        if (num1 > num2) return 1;
        
        v1 = "";
        v2 = "";
        i++;
        j++;
    }
    if (!v1.empty()) return 1;
    if (!v2.empty()) return -1;

    return 0;
    }
};
