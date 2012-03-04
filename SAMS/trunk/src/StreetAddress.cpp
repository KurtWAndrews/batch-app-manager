/**
 * @file StreetAddress.cpp
 * @brief StreetAddress definition
 * @author Kurt Andrews & Brian Royer
 */
#include "StreetAddress.h"

using namespace std;

StreetAddress::StreetAddress(const string& addressLine1,
                             const string& addressLine2,
                             const string& city,
                             const string& state,
                             const string& zip) : addressLine1(""),
                                                  addressLine2(""),
                                                  city(""),
                                                  state(""),
                                                  zip("") {}

StreetAddress::~StreetAddress() {
  cout << "Executing StreetAddress Destructor" << endl;
}

void StreetAddress::display() const {
  cout << "Address Line 1 [" << getAddressLine1() << "]" << endl;
  cout << "Address Line 2 [" << getAddressLine2() << "]" << endl;
  cout << "City           [" << getCity() << "]" << endl;
  cout << "State          [" << getState() << "]" << endl;
  cout << "Zip Code       [" << getZip() << "]" << endl;
}

void StreetAddress::populate() {
  cout << "Enter Address Line 1: ";
  string line1Str;
  getline(cin, line1Str);
  setAddressLine1(line1Str);

  cout << "Enter Address Line 2: ";
  string line2Str;
  getline(cin, line2Str);
  setAddressLine2(line2Str);

  cout << "Enter City: ";
  string cityStr;
  getline(cin, cityStr);
  setCity(cityStr);

  cout << "Enter State: ";
  string stateStr;
  getline(cin, stateStr);
  setState(stateStr);

  cout << "Enter Zipcode: ";
  string zipStr;
  getline(cin, zipStr);
  setZip(zipStr);
}

void StreetAddress::startUp(ifstream& inFile) {
  string line1Str;
  getline(inFile, line1Str, '\t');
  setAddressLine1(line1Str);

  string line2Str;
  getline(inFile, line2Str, '\t');
  setAddressLine2(line2Str);

  string cityStr;
  getline(inFile, cityStr, '\t');
  setCity(cityStr);

  string stateStr;
  getline(inFile, stateStr, '\t');
  setState(stateStr);

  string zipStr;
  getline(inFile, zipStr);
  setZip(zipStr);
}

void StreetAddress::shutDown(ofstream& outFile) {
  outFile << getAddressLine1() << "\t"
          << getAddressLine2() << "\t"
          << getCity() << "\t"
          << getState() << "\t"
          << getZip() << endl;
}

std::ostream& operator<<(std::ostream& os, StreetAddress& addr) {
  addr.display();
  return os;
}

