/**
 * @file StreetAddress.h
 * @brief StreetAddress declaration
 * @author Kurt Andrews & Brian Royer
 */
#ifndef STREETADDRESS_H_
#define STREETADDRESS_H_

#include <string>
#include <iostream>
#include <fstream>

/**
 * @brief Implements a common street address
 */
class StreetAddress
{
  public:
    /**
     * default StreetAddress constructor
     * @param addressLine1 - first address line
     * @param addressLine2 - second address line
     * @param city - city/town
     * @param state - state or porvince
     * @param zip - postal code
     */
    StreetAddress(const std::string& addressLine1 = "",
                  const std::string& addressLine2 = "",
                  const std::string& city = "",
                  const std::string& state = "",
                  const std::string& zip = "");
    /**
     * StreetAddress destructor
     */
    ~StreetAddress();


    /**
     * Clear all attributes of StreetAddress
     */
    void clearAttributes();

    /**
     * @return the first address line
     */
    std::string getAddressLine1() const;

    /**
     * @return the second address line
     */
    std::string getAddressLine2() const;

    /**
     * @return the city
     */
    std::string getCity() const;

    /**
     * @return the state
     */
    std::string getState() const;

    /**
     * @return the postal code
     */
    std::string getZip() const;

    /**
     * set the first address line to the specified value
     * @param addressLine the new first address line
     */
    void setAddressLine1(const std::string& addressLine);

    /**
     * set the second address line to the specified value
     * @param addressLine the new second address line
     */
    void setAddressLine2(const std::string& addressLine);

    /**
     * set the city to the specified value
     * @param city the new city
     */
    void setCity(const std::string& city);

    /**
     * set the state to the specified value
     * @param state the new state
     */
    void setState(const std::string& state);

    /**
     * set the postal code to the specified value
     * @param zip the new postal code
     */
    void setZip(const std::string& zip);

    /**
     * display the StreetAddress members
     */
    void display() const;

    /**
     * populate the StreetAddress from user input
     */
    void populate();

    /**
     * read address information from the Employee files when the system starts
     * up and set the StreetAddress members accordingly
     * @param inFile - the file containing the StreetAddress data
     */
    void startUp(std::ifstream& inFile);

    /**
     * write Address information to the employee files when the system shuts
     * down
     * @param outFile - the file containing the StreetAddress data
     */
    void shutDown(std::ofstream& outFile);

  private:
    std::string addressLine1;
    std::string addressLine2;
    std::string city;
    std::string state;
    std::string zip;
};

std::ostream& operator<<(std::ostream& os, StreetAddress& addr);

inline std::string StreetAddress::getAddressLine1() const {return addressLine1;}
inline std::string StreetAddress::getAddressLine2() const {return addressLine2;}
inline std::string StreetAddress::getCity() const {return city;}
inline std::string StreetAddress::getState() const {return state;}
inline std::string StreetAddress::getZip() const {return zip;}
inline void StreetAddress::setAddressLine1(const std::string& addressLine) {addressLine1 = addressLine;}
inline void StreetAddress::setAddressLine2(const std::string& addressLine) {addressLine2 = addressLine;}
inline void StreetAddress::setCity(const std::string& city) {this->city = city;}
inline void StreetAddress::setState(const std::string& state) {this->state = state;}
inline void StreetAddress::setZip(const std::string& zipCode) {zip = zipCode;}

#endif /*STREETADDRESS_H_*/
