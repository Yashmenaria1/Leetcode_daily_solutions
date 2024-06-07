class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
    sort(dictionary.begin(), dictionary.end(), [](const string &a, const string &b) {
        return a.length() < b.length();
    });
    
    unordered_set<string> dictSet(dictionary.begin(), dictionary.end());
    
    istringstream iss(sentence);
    string word;
    vector<string> words;
    while (iss >> word) {
        words.push_back(word);
    }
    
    for (string &word : words) {
        for (const string &root : dictionary) {
            if (word.compare(0, root.length(), root) == 0) {
                word = root;
                break; 
            }
        }
    }
    ostringstream oss;
    for (size_t i = 0; i < words.size(); ++i) {
        if (i > 0) oss << " ";
        oss << words[i];
    }
    
    return oss.str();
}
};
