/**
 * @file Account.h
 * @brief Account declaration
 * @author Kurt Andrews & Brian Royer
 */
#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>
#include <fstream>
#include <string>

class Account {
public:
	/**
	 * The Account constructor
	 * @param _accountId - new account id
	 * @param _desc - description of the new account
	 * @param _balance - the inital balance in the account
	 */
	Account(const std::string& _accountId = "",
			 const std::string& _desc = "",
			 const double _balance = 0.00);
	
	/**
	 * Account destructor
	 */
	virtual ~Account();
	 
	/**
	 * Display the account
	 */
	void display() const;

	/**
	 * Deposit money into the benefits account
   * @param - amount to deposit into account
	 */
	void makeDeposit(double amount);

	/**
	 * Withdraw money from the benefits account
   * @param - amount to withdraw from the account
	 */
	void makeWithdrawal(double amount);
	
	/**
	 * @return the accounts account id
	 */
	std::string getAccountId() const;
	
	/**
	 * @return the account description
	 */
	std::string getDesc() const;
	
	/**
	 * @return the default application for the account
	 */
	double getBalance() const;
	
	/**
	 * Update the account id with the specified value
	 * @param _accountId - the new account id
	 */
	void setAccountId(const std::string& _accountId);
	
	/**
	 * Update the account description with the specified value
	 * @param -_desc - the new account description
	 */
	void setDesc(const std::string& _desc);
	
	/**
	 * Update the accounts default application
	 * @param - _balance - the new default app for the account
	 */
	void setBalance(const double _balance);
	/**
	 * Start up method to call all necessary methods to load account data
   * @param - inFile - the input file stream that has the account data
	 */
	void startup(std::ifstream& inFile);
	
	/**
	 * Shut down method to call all necessary methods to persist account data 
   * @param - outFile - the output file stream used to save the account data
	 */
	void shutdown(std::ofstream& outFile);
	
private:
	std::string accountId;
	std::string desc;
	double balance;
	
	
	/**
	 * Display Non member attributes
	 */
	void _display() const;  
};

inline std::string Account::getAccountId() const {return accountId;}
inline void Account::setAccountId(const std::string& _accountId) {accountId = _accountId;}
inline std::string Account::getDesc() const {return desc;}
inline void Account::setDesc(const std::string& _desc) {desc = _desc;}
inline double Account::getBalance() const {return balance;}
inline void Account::setBalance(const double _balance) {balance = _balance;}
inline void Account::makeDeposit(const double amount) {balance = balance + amount;}

#endif /* ACCOUNT_H_ */
