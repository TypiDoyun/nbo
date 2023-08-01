#include <iostream>
#include <string>
#include <regex>
#include <cmath>

using namespace std;

double toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

void print(double x, double y) {
    cout << "(" << x << ", " << y << ")";
}

const int hourStick = 120;
const int minuteStick = 200;
const int secondStick = 180;

int main(void) {
    string timeTemplate;

    cin >> timeTemplate;

    regex condition("(\\d\\d):(\\d\\d):(\\d\\d)");
    smatch result;

    regex_match(timeTemplate, result, condition);

    int hour = stoi(result[1]);
    int minute = stoi(result[2]);
    int second = stoi(result[3]);

    double hourAngle = hour * 360 / -12 + 90;
    double minuteAngle = minute * 360 / -60 + 90;
    double secondAngle = second * 360 / -60 + 90;

    cout << hourAngle << ", " << minuteAngle << ", " << secondAngle << endl;
    cout << fixed;
    cout.precision(0);
    print(cos(toRadians(hourAngle)) * hourStick, (sin(toRadians(hourAngle)) * hourStick));
    print(cos(toRadians(minuteAngle)) * minuteStick, (sin(toRadians(minuteAngle)) * minuteStick));
    print(cos(toRadians(secondAngle)) * secondStick, (sin(toRadians(secondAngle)) * secondStick));
}