#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
struct WordCompare {
    bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        if (a.second != b.second)
            return a.second < b.second;
        return a.first > b.first;
    }
};
int main() {
    std::ifstream file("Text.txt");
    if (!file.is_open())
        return 1;
    std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    std::string separators = " ,?!.";
    std::map<std::string, int> wordCounts;
    size_t start = text.find_first_not_of(separators);
    while (start != std::string::npos) {
        size_t end = text.find_first_of(separators, start);
        std::string word = text.substr(start, end - start);
        for (int i = 0; i < word.length(); i++)
            if (word[i] >= 'A' && word[i] <= 'Z')
                word[i] = word[i] + ('a' - 'A');
        if (!word.empty())
            wordCounts[word]++;
        if (end == std::string::npos) break;
        start = text.find_first_not_of(separators, end);
    }
    std::priority_queue<std::pair<std::string, int>,std::vector<std::pair<std::string, int>>,WordCompare> pq;
    for (const auto& pair : wordCounts)
        pq.push(pair);
    while (!pq.empty()) {
        std::cout << pq.top().first << " => " << pq.top().second << "\n";
        pq.pop();
    }
    return 0;
}