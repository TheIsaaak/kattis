#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

struct Item {
    string name;
    unordered_set<string> suss;
    bool jessie = true;
    bool walter = true;
};

int main() {
    ios_base::sync_with_stdio(false);  // Faster input/output

    int itemcount;
    cin >> itemcount;

    unordered_map<string, Item> itemmap;

    for (int i = 0; i < itemcount; ++i) {
        Item item;
        cin >> item.name;
        itemmap[item.name] = item;
    }

    int susscount;
    string suss1, suss2;
    cin >> susscount;

    for (int i = 0; i < susscount; ++i) {
        cin >> suss1 >> suss2;
        itemmap[suss1].suss.insert(suss2);
        itemmap[suss2].suss.insert(suss1);
    }

    unordered_set<string> walterItems;
    unordered_set<string> jessieItems;

    for (const auto& pair : itemmap) {
        const Item& item = pair.second;

        if(!item.suss.empty()) {
            for (const auto& s : item.suss) {
                if (jessieItems.count(s)) {
                    itemmap[item.name].jessie = false;
                }
                if (walterItems.count(s)) {
                    itemmap[item.name].walter = false;
                }
            }

            if (item.jessie) {
                jessieItems.insert(item.name);
            } else if (item.walter) {
                walterItems.insert(item.name);
            } else {
                cout << "impossible";
                exit(0);
            }
        }else{
            if(walterItems.size() <= jessieItems.size()){
                walterItems.insert(item.name);
            }else{
                jessieItems.insert(item.name);
            }
        }
    }

    for (const auto& i : walterItems) {
        cout << i << " ";
    }
    cout << endl;

    for (const auto& i : jessieItems) {
        cout << i << " ";
    }
    cout << endl;
}
