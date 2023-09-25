#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <functional>
#include <string_view>
using namespace std;

int main() {
    map<string, vector<string>> userMessages; //Map to store each user's messages
    map<string, int> allWords; //Map to store all words and counter

    //Get the message count
    string messageCount;
    getline(cin, messageCount);

    //Start to read the messages
    string input;
    for (int i = 0; i < stoi(messageCount); ++i) {
        getline(cin, input);

        //Read the username, then the message.
        stringstream ss(input);

        string username;
        ss >> username;

        string word;
        while (ss >> word) {
            userMessages[username].push_back(word);
            allWords[word]++;
        }
    }

    //Remove words that haven't been used by all users
    auto it = allWords.begin();
    while(it != allWords.end()){
        auto death = it;
        it++;
        for (auto& users: userMessages) {
            if (find(users.second.begin(), users.second.end(), death->first) == users.second.end()){
                allWords.erase(death->first);
            }
        }
    }

    //Create a vector for sorting
    vector<pair<string, int>> sortedWords(allWords.begin(), allWords.end());

    //Sort the vector
    sort(sortedWords.begin(), sortedWords.end(),
              [](const pair<string, int>& a, const pair<string, int>& b) {
                  return a.second > b.second;
              });

    //Print!
    if (sortedWords.empty()){
        cout << "ALL CLEAR" << endl;
    }else{
        for (const auto& pair : sortedWords) {
            cout << pair.first << endl;
        }
    }
    return 0;
}