// tracks daily food intake.
// searches calorie count on the internet if needed.
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

#include "date.h"
#include "fooditem.h"
using namespace std;
// tracker
// >> help
// ... list commands
// >> add
// Name: airfried potatoes
// Description:
// Calories: 270
// Satisfied (yes/no): n
// [system] added successfully.
// >> report today
//     Food                        Cal
// (Red) 1. Airfried potatoes            270
// (Green) 2. Cheese                        80
// >> remove
//  1. Airfried potatoes.
//  2. Cheese
// >> 2
// [system] removed successfully.
void takeinput(string&, string = "", bool = true);
void executecmd(string&);
int main() {
    string cmd;
    while (true) {
        takeinput(cmd);
        executecmd(cmd);
    }
    return 0;
}
void executecmd(string& cmd) {
    void add();
    void remove();
    static map<string, function<void()>> commands = {
        {"help", []() {}},           {"add", add},
        {"remove", remove},          {"report", []() {}},
        {"quit", []() { exit(0); }}, {"exit", []() { exit(0); }},
        {"q", []() { exit(0); }}};
    auto it = commands.find(cmd);
    if (it != commands.end()) {
        it->second();
    } else {
        cout << "[system] unknown command. type \"help\" for help." << endl;
    }
}
void add() {
    FoodItem _fitem;
    string name, desc, __s;
    bool satisfied;
    int rating, cal;
    takeinput(name, "  Name: ");
    takeinput(desc, "  Description: ");
    takeinput(__s, "  Calories: ");
    if (__s.empty()) {
        // TODO: fetch the data from the internet.
        cal = 0;
    } else {
        cal = stoi(__s);
    }
    takeinput(__s, "  Satisfied (yes/no): ");
    satisfied = (__s == "yes") || (__s == "y");
    do {
        takeinput(__s, "  Rating (1-5): ");
        rating = stoi(__s);
    } while (rating < 1 || rating > 5);
    _fitem = FoodItem(name, desc, cal);
    _fitem.setSatisfied(satisfied);
    _fitem.setRating(rating);
    recorditem(_fitem);
}
void remove() { cout << "remove executed" << endl; }
void takeinput(string& ln, string msg, bool flush) {
    if (msg.empty()) {  // taking user commands.
        cout << ">> ";
    } else {
        cout << msg;
    }
    getline(cin, ln);
    string::iterator it;
    for (it = ln.begin(); it != ln.end(); it++) {
        if (!isspace(*it)) {
            it--;
            break;
        }
        cout << "|" << *ln.begin() << "|" << *it << "|" << endl;
    }
    ln.erase(ln.begin(), (it == ln.end()) ? ln.end() : it + 1);
    for (it = ln.end() - 1; it != ln.begin() - 1; it--) {
        if (!isspace(*it)) {
            it++;
            break;
        }
    }
    ln.erase((it == ln.begin()) ? ln.begin() : it, ln.end());
    if (flush) cout.flush();
}
