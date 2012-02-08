
#ifndef CPPUNIT_CPPUNITEXCEPTION_H
#define CPPUNIT_CPPUNITEXCEPTION_H


/* 
 * CppUnitException is an exception that serves
 * descriptive strings through its what () method
 *
 */

#include <exception>
#include <string>

#define CPPUNIT_UNKNOWNFILENAME        "<unknown>"
#define CPPUNIT_UNKNOWNLINENUMBER      (-1)


class CppUnitException : public std::exception {
public:
    CppUnitException(const std::string&  message    = "", 
                     long  lineNumber = CPPUNIT_UNKNOWNLINENUMBER, 
                     const std::string&  fileName   = CPPUNIT_UNKNOWNFILENAME);

    CppUnitException(const CppUnitException& other);

    virtual ~CppUnitException () throw();

    CppUnitException& operator=(const CppUnitException& other);

    const char *what() const throw ();

    long lineNumber() const;
    std::string fileName() const;

private:
    std::string         m_message;
    long                m_lineNumber;
    std::string         m_fileName;

};


#endif

