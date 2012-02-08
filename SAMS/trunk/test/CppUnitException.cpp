#include "CppUnitException.h"

// Construct the exception
CppUnitException::CppUnitException (const std::string& message, 
									long lineNumber, 
									const std::string& fileName)
: m_message (message), m_lineNumber (lineNumber), m_fileName (fileName)
{

}

CppUnitException::CppUnitException (const CppUnitException& other)
: exception (other)
{ 
    m_message       = other.m_message; 
    m_lineNumber    = other.m_lineNumber;
    m_fileName      = other.m_fileName;
}

// Destruct the exception
CppUnitException::~CppUnitException () throw()
{

}

// Perform an assignment
CppUnitException& CppUnitException::operator= (const CppUnitException& other)
{ 
	exception::operator= (other);

    if (&other != this) {
        m_message       = other.m_message; 
        m_lineNumber    = other.m_lineNumber;
        m_fileName      = other.m_fileName;
    }

    return *this; 
}


// Return descriptive message
const char* CppUnitException::what() const throw ()
{ 
	return m_message.c_str(); 
}

// The line on which the error occurred

long CppUnitException::lineNumber() const
{ 
	return m_lineNumber; 
}


// The file in which the error occurred
std::string CppUnitException::fileName () const
{ 
	return m_fileName; 
}