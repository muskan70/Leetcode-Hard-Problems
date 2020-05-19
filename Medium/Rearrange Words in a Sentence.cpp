//Rearrange Words in a Sentence : https://leetcode.com/problems/rearrange-words-in-a-sentence/
string arrangeWords(string text) {
    map<int, vector<string>> m;
    int left = 0;
    text[0] = tolower(text[0]);
    for(int i = 0; i <= text.size(); ++i) {
        if (text.size() == i || text[i] == ' ') {
            auto sub = text.substr(left, i - left);
            m[i - left].emplace_back(sub);
            left = i + 1;
        }
    }
    string result;
    for (const auto& count: m) {
        for(const auto & word: count.second) {
            if (result.size() > 0) result += " ";
            result += word;
        }
    }
    result[0] = toupper(result[0]);
    return result;
}