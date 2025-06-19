#include "fooditem.h"

#include <ctime>
#include <fstream>

#include "date.h"
using namespace std;
FoodItem::FoodItem(const string& name, const string& desc, int cal) {
  this->name = name;
  this->desc = desc;
  this->calcnt = cal;
}
void recorditem(FoodItem fitems) {
  // TODO: record based on date. (can use directories)
  ofstream datafile("fooditems.csv", ios::app);
  datafile << fitems.getName() << "," << fitems.getDesc() << ","
           << fitems.getCal() << "," << fitems.getRating() << ","
           << fitems.isSatisfied() << "," << time(nullptr) << endl;
  datafile.close();
}
