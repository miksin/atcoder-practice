#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main () {
    int n, q;
    cin >> n >> q;

    vector<int> ratings(n + 1);
    vector<int> belongs(n + 1);
    map<int, multiset<int> > hasRatings;

    // 'multiset' to store duplicated elements;
    multiset<int> kinderRatings;

    for (int i = 1; i <= n; i++) {
        cin >> ratings[i] >> belongs[i];
        hasRatings[belongs[i]].insert(ratings[i]);
    }

    for (auto it = hasRatings.begin(); it != hasRatings.end(); ++it) {
        int greatest = *(it->second.rbegin());
        kinderRatings.insert(greatest);
    }

    for (int i = 0; i < q; i++) {
        int target, to;
        cin >> target >> to;
        int rate = ratings[target];
        int from = belongs[target];
        belongs[target] = to;

        // Use 'find' here to prevent from erasing more than one elements.
        kinderRatings.erase(kinderRatings.find(*(hasRatings[from].rbegin())));
        if (!hasRatings[to].empty()) {
            kinderRatings.erase(kinderRatings.find(*(hasRatings[to].rbegin())));
        }

        hasRatings[from].erase(hasRatings[from].find(rate));
        hasRatings[to].insert(rate);

        if (!hasRatings[from].empty()) {
            kinderRatings.insert(*(hasRatings[from].rbegin()));
        }
        kinderRatings.insert(*(hasRatings[to].rbegin()));

        int worstKinderRating = *(kinderRatings.begin());
        cout << worstKinderRating << endl;
    }
}
