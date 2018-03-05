#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include "vector.h"
#include <cmath>
#include <string>
using std::cout;
using pep::vector;
using std::string;

// TODO: your code goes here

class Item {
protected:
  double latitude;
  double longitude;
  string id;
  int time;

public:
  Item(const double latitudeIn, const double longitudeIn, const string idIn, const int timeIn)
    : latitude(latitudeIn), longitude(longitudeIn), id(idIn), time(timeIn) {
    }

  double getLatitude() const {
        return latitude;
    }

  double getLongitude() const {
        return longitude;
    }

  string getId() const{
    return id;
  }

  int getTime() const{
    return time;
  }

  double distanceTo(const Item& secondItem) {
    double dlon = (secondItem.getLongitude() * 0.0174533) - (longitude * 0.0174533);
    double dlat = (secondItem.getLatitude() * 0.0174533) - (latitude * 0.0174533);

    double a = pow((sin(dlat/2)), 2) + cos(getLatitude() * 0.0174533) * cos(secondItem.getLatitude() * 0.0174533) * pow((sin(dlon/2)), 2);
    double c = 2 * atan2( sqrt(a), sqrt(1-a) );
    double distance = 6373000 * c;

    return distance;
  }

};

std::ostream& operator << (std::ostream& out, Item& item) {
  out<<"{"<<item.getLatitude()<<", "<<item.getLongitude()<<", "<<"\""<<item.getId()<<"\""<<", "<<item.getTime()<<"}";
  return out;
}


// don't write any code below this line

#endif
