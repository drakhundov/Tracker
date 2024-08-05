#ifndef FOODITEM_H
#define FOODITEM_H
#include <string>
using namespace std;
class FoodItem {
   public:
    FoodItem(){};
    FoodItem(const string& name, const string& desc, int cal);
    string getName() const { return this->name; }
    string getDesc() const { return this->desc; }
    int getCal() const { return this->calcnt; }
    void setName(const string& name) { this->name = name; }
    void setDesc(const string& desc) { this->desc = desc; }
    void setCal(int cal) { this->calcnt = cal; }
    int getRating() const { return this->rating; }
    void setRating(int rating) { this->rating = rating; }
    bool isSatisfied() const { return this->satisfied; }
    void setSatisfied(bool satisfied) { this->satisfied = satisfied; }

   private:
    string name;
    string desc;
    int calcnt;//, amountInGrams, amountInMilliLitres;  // TODO
    int rating;  // rating from 1 to 5.
    bool satisfied;
};
void recorditem(FoodItem);
#endif
