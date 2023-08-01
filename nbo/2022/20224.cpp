#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string sentence;

    getline(cin, sentence);

    vector<int> startIndices{ 0 };
    vector<long unsigned> endIndices{ sentence.length() - 1 };

    auto target = find_if(sentence.begin(), sentence.end(), [](char item) {
        return item == ' ';
    });

    while (target != sentence.end()) {
        startIndices.push_back(target - sentence.begin() + 1);
        endIndices.push_back(target - sentence.begin() - 1);

        target = find_if(target + 1, sentence.end(), [](char item) {
            return item == ' ';
        });
    }

    sort(endIndices.begin(), endIndices.end(), [](long unsigned a, long unsigned b) {
        return a > b;
    });

    for (int _startIndex : startIndices) {
        for (long unsigned _endIndex : endIndices) {

            int startIndex = _startIndex;
            int endIndex = _endIndex;
            
            while (!isalpha(sentence[startIndex])) startIndex++;
            while (!isalpha(sentence[endIndex])) endIndex--;

            if (endIndex <= startIndex) break;
            if (strncasecmp(&sentence[startIndex], &sentence[endIndex], sizeof(char)) != 0) continue;

            // cout << sentence[startIndex] << "(" << startIndex << ") - " << sentence[endIndex] << "(" << endIndex << ")" << endl;


            int front = startIndex;
            int back = endIndex;
            bool valid = true;

            while (front < back) {
                front += 1;
                back -= 1;

                while (!isalpha(sentence[front])) front += 1;
                while (!isalpha(sentence[back])) back -= 1;

                if (strncasecmp(&sentence[front], &sentence[back], sizeof(char)) == 0) continue;

                valid = false;
                break;
            }

            if (!valid) continue;

            for (int index = _startIndex; index <= _endIndex; index++) {
                cout << sentence[index];
            }
            cout << endl;

            break;
        }
    }
}