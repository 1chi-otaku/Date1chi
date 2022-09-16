#pragma once
class Date
{
	int Day;
	int Month;
	int Year;

public:
	Date(); //Constructor by default will initialize an object with current date. 
	Date(int, int, int); //Constructor fills an object with user's data. Delegation below.
	Date(int, int);
	Date(int);

	void Print()const; //Prints date in a console.
	bool IsLeap()const; //Checks if the year is leap, returns true if it is.
	short DaysInMonth()const; //Returns days of a respective month.

	//Operations overload.
	Date operator+(int a) const; //Addtion operation via int value.
	Date operator+(const Date& obj)const; //Addition operation date + date.

	Date operator-(int a)const; //Subtraction operation via int value.
	Date operator-(const Date& obj)const; //Subtraction operation date + date.

	Date& operator++(); //++a Prefix increment operation
	Date operator++(int); //a++ Postfix increment operation.

	Date& operator--(); //--a Prefix decrement operation.
	Date operator--(int); //a-- Postfix increment operation.

	Date& operator+=(int a); //Add AND assignment operator.
	Date& operator-=(int a); //Subtract AND assignment operator.

	bool operator>(const Date& obj)const; //Greater Than operator.
	bool operator<(const Date& obj)const; //Less Than operator.
	bool operator>=(const Date& obj)const; //Greater Than or Equal To operator.
	bool operator<=(const Date& obj)const; //Less Than or Equal To operator.
	bool operator==(const Date& obj)const; //The equality operator.
	bool operator!=(const Date& obj)const; //The not-equal-to operator.
};

