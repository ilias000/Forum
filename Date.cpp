#include <ctime>
#include <iostream>
#include "Date.h"
using namespace std ;

Date::Date()
{
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	this->day = timePtr->tm_mday ;
	this->month = timePtr->tm_mon + 1 ;
	this->year = timePtr->tm_year + 1900 ;
}

void Date::printDate() const 
{
	cout << this->day << "/" << this->month << "/" << this->year << endl ;
}