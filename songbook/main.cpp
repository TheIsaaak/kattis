#include <iostream>
#include "vector"
#include <bits/stdc++.h>
using namespace std;

int main() {
    int time, songnr;
    cin >> time >> songnr;
    time = time * 60; //Convert to seconds

    string allsongstime;
    getline(cin, allsongstime); //Buffer still has the \n in it
    getline(cin, allsongstime);

    string s;
    stringstream ss(allsongstime);
    vector<int> songtimes;
    while (getline(ss, s, ' ')) {
        songtimes.push_back(stoi(s));
    }
    sort(songtimes.begin(), songtimes.end());

    int sum = 0;
    for (int i = 0; i < songnr; ++i) {
        if (time - songtimes[i] < 0) {continue;}
        time = time - songtimes[i];
        sum += songtimes[i];
    }

    cout << sum << endl;
}
