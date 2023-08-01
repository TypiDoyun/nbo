#include <iostream>
#include <vector>
#include <array>

using namespace std;

struct AdSign {
    int location;
    int revenue;
};

bool sortCompare(AdSign a, AdSign b) {
    return a.revenue > b.revenue;
}

int main(void) {
    int roadLength;
    int amountOfAdSign;

    cin >> roadLength;
    cin >> amountOfAdSign;

    vector<bool> road(roadLength + 1, false);
    vector<AdSign> information(amountOfAdSign);

    for (int index = 0; index < amountOfAdSign; index++) {
        cin >> information[index].location;
    }

    for (int index = 0; index < amountOfAdSign; index++) {
        cin >> information[index].revenue;
    }

    int margin;

    cin >> margin;

    sort(information.begin(), information.end(), sortCompare);

    int totalRevenue = 0;

    for (auto ad : information) {
        if (road[ad.location]) continue;

        totalRevenue += ad.revenue;
        fill(road.begin() + ad.location - margin, road.begin() + ad.location + margin, true);
    }

    cout << totalRevenue;
}