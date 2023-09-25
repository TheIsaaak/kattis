#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class country {
public:
    bool left;
    int incoming;
    int neighborsleft;
    vector<int> neighbors;
};

int main() {
    int countries; int partnerships; int myCountry; int first2leave;
    cin >> countries >> partnerships >> myCountry >> first2leave;

    //List of countries
    vector<country> countryList;
    for (int i = 0; i < countries+1; ++i) {
        country con;
        con.left = false;
        con.incoming = 0;
        con.neighborsleft = 0;
        countryList.push_back(con);
    }

    //List of partnerships
    for(int i = 0; i < partnerships; i++) {
        int partnerwith, partnerTo;
        cin >> partnerwith >> partnerTo;

        countryList[partnerwith].incoming++;
        countryList[partnerwith].neighborsleft++;
        countryList[partnerwith].neighbors.push_back(partnerTo);

        countryList[partnerTo].incoming++;
        countryList[partnerTo].neighborsleft++;
        countryList[partnerTo].neighbors.push_back(partnerwith);
    }

    //One country has already left
    countryList[first2leave].left = true;

    queue<int> toCheck;
    for (auto i : countryList[first2leave].neighbors) {
        countryList[i].neighborsleft--;
        toCheck.push(i);
    }

    while (!toCheck.empty()) {
        int current = toCheck.front();
        toCheck.pop();

        if (countryList[current].left) {
            continue;
        }

        if (countryList[current].neighborsleft <= countryList[current].incoming / 2) {
            countryList[current].left = true;
            for (auto i : countryList[current].neighbors) {
                countryList[i].neighborsleft--;
                toCheck.push(i);
            }
        }
    }

    if (countryList[myCountry].left) {
        cout << "leave" << endl;
        return 0;
    }else{
        cout << "stay" << endl;
        return 0;
    }
}
