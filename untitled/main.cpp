#include <iostream>
#include <string>
using namespace std;

void permute(string str, int l, int r) {
    if (l == r)
        cout << str << endl;
    else {
        for (int i = l; i <= r; i++) {
            swap(str[l], str[i]);
            permute(str, l + 1, r);
            swap(str[l], str[i]); // backtrack
        }
    }
}

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;
    permute(word, 0, word.length() - 1);
    return 0;
}
