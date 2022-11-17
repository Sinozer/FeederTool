#include "Biberon.h"
#pragma warning(disable : 4996)
#include<stdio.h>

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

Biberon::Biberon() {
    this->quantity = 0;
    this->give = true;
    Timer();
}

Biberon::~Biberon() {
}

void Biberon::Timer() {
    time_t curr_time;;
    string current_day;
    int sec;
    int alarm = NULL;
    char temp;
    cout << "do you wan't start the timer ? y or n\n";
    cin >> temp;
    if (temp == 'y') {
        this->give = false;
    }
    while (this->give == false) {
        curr_time = time(NULL);
        char* tm = ctime(&curr_time);
        string timer = tm;
        string save_day;
        string cont;
        if (current_day == "") {
            for (unsigned int i = 0; i < 3; i++) { //check day
                char c = timer[i];
                current_day = current_day + c;
            }
            for (unsigned int i = 17; i < 20; i++) {
                char s = timer[i];
                cont = cont + s;
            }
            sec =  stoi(cont);
            switch (sec) {
            case 55 :
                alarm = 01;
                break;
            case 56 :
                alarm = 02;
                break;
            case 57 :
                alarm = 03;
                break;
            case 58 :
                alarm = 04;
                break;
            case 59 :
                alarm = 05;
                break;
            default:
                alarm = sec + 5;
                break;
            }
            cout << "\n" << sec << "\nalarm set at " << alarm;
            save_day = current_day;
            cout << "\ncurrent day register : " << save_day << "\n\n";
        }
        cout << tm;
        if (alarm != NULL) {
            for (unsigned int i = 17; i < 20; i++) {
                char s = timer[i];
                cont = cont + s;
            }
            sec = stoi(cont);
            if (sec == alarm) {
                char answer;
                cout << "\nDrinnnnnnng    Drinnnnnng";
                cout << "\n did you have finished to give milk to the baby ? y or n\n";
                cin >> answer;
                if (answer == 'y') {
                    this->give = false;
                }
                else {
                    this->give = true;
                }
            }
        }
        _sleep(1000);
    }

}

//int main() {
//    Biberon* main_biberon = new Biberon();
//    return 0;
//}