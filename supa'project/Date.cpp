#include "Date.h"
#include<iostream>
using namespace std;

Date::Date()//Sets default value.
{
	Day = 16;
	Month = 9;
	Year = 2022;
}
Date::Date(int d, int m, int y):Date(d,m)

{
	if (y >= 99999 || y <= 0)						//Checks if the year is correct, otherwise puts 1900
		Year = 1900;
	else
		Year = y;

	if (d > DaysInMonth() || d < 0)				//Checks if the day is correct, otherwise puts 1
		Day = 1;

	if (m > 12 || m < 0)						//Checks if the month is correct, otherwise puts 1
		Month = 1;

}
Date::Date(int d, int m):Date(d)
{
	Month = m;
	Year = 2022;
}
Date::Date(int d)
{

	Day = d;
	Month = 9;
	Year = 2022;
}


void Date::Print()const //Prints respective date in a console.
{
	cout << Day << '.' << Month << "." << Year << endl;
}
bool Date::IsLeap() const //Returns true if a year is leap, otherwise returns false.
{
	if (Year % 4 == 0) return true; //If year % 4, then it's Leap.
	return false;
}
short Date::DaysInMonth() const
{
	if (Month == 1 || Month == 3 || Month == 5 || Month == 7 || Month == 8 || Month == 10 || Month == 12) { //Checking months with 31 days
		return 31;
	}
	if (Month == 4 || Month == 6 || Month == 9 || Month == 11) { //Checking months with 30 days
		return 30;
	}
	if (Month == 2) {
		if (IsLeap()) return 29; // If Leap, returns 29, otherwise returns 28
		else return 28;
	}
	return -1;
}

Date Date::operator+(int a)const //Addtion operation via int value. Will try to add an int value to a respective date.
{
	int MonthDaysTemp; //MonthDaysTemp for correct work of DaysInMonth() with Day field.
	int MonthBuffer = 0; //For Months field never be more than 12 in the first while cycle. 
	Date temp(*this);
	temp.Day += a; //Adds new days.
	while (temp.Day > temp.DaysInMonth()) { //While Days > Days in Current Months, Days - Days in Current Months, Months ++.
		temp.Day -= temp.DaysInMonth();
		temp.Month++;
		MonthDaysTemp = temp.DaysInMonth();
		temp.Month--;	
		MonthBuffer++;
	}
	temp.Month += MonthBuffer; //Adds MonthBuffer to a Month field.
	while (temp.Month > 12) { //While Month > 12. Month -= 12? Year++.
		temp.Year++;
		temp.Month -= 12;
	}
	return temp; //Returns temp object
}
Date Date::operator+(const Date& obj)const //Addtion operation via int value. Will try to add an a date to a respective date.
{
	Date temp(*this); //Creating temp object.
	temp.Day += obj.Day; //Adds new days.
	int MonthDaysTemp; //MonthDaysTemp for correct work of DaysInMonth() with Day field.
	int MonthBuffer = 0; //For Months field never be more than 12 in the first while cycle.
	while (temp.Day > temp.DaysInMonth()) {  //While Days > Days in Current Months, Days - Days in Current Months, Months ++.
		temp.Month--;
		temp.Day -= temp.DaysInMonth();
		MonthDaysTemp = temp.DaysInMonth();
		temp.Month++;
		MonthBuffer++;
	}
	temp.Month += obj.Month + MonthBuffer;//Adds MonthBuffer to a Month field.
	while (temp.Month > 12) {  //While Month > 12. Month -= 12? Year++.
		temp.Year++;
		temp.Month -= 12;
	}
	temp.Year += obj.Year;
	return temp; //Returns temp object
}
Date Date::operator-(int a)const //Subtraction operation via int value. Will try to subtract an int value from a respective date.
{
	int MonthDaysTemp; //MonthDaysTemp for correct work of DaysInMonth() with Day field.
	Date temp(*this); //Creating temp object.

	temp.Day -= a; //Substract days.
	while (temp.Day < 1) { //While Days < 1, Month--, Day+= MonthDaysTemp.
		MonthDaysTemp = temp.DaysInMonth();
		temp.Month--;
		temp.Day += MonthDaysTemp;
		while (Month < 1) { //While Months < 1 Year --, Month +=12.
			temp.Year--;
			temp.Month += 12;
		}
	}
	return temp; //Returns temp object
}
Date Date::operator-(const Date& obj)const
{
	Date temp(*this); //Creating temp object.
	temp.Day -= obj.Day; //Substract days.
	int MonthDaysTemp; //MonthDaysTemp for correct work of DaysInMonth() with Day field.
	while (temp.Day < 1) {
		MonthDaysTemp = temp.DaysInMonth();
		temp.Month--;
		temp.Day += MonthDaysTemp;
	}
	temp.Month -= obj.Month;
	while (temp.Month > 12) { //While months > 12, Year++, Month -=12.
		temp.Year++;
		temp.Month -= 12;
	}
	temp.Year -= obj.Year;
	return temp; //Returns temp object
}
Date& Date::operator++() //Will add one day to a respective date(Prefix).
{
	Day++;
	if (Day > DaysInMonth()){ //If Day > Days in Month, Sets day to 1 and checks if the month is correct.
		Month++;
		Day = 1;
		if (Month > 12) {
			Month = 1;
			Day = 1;
			Year++;
		}
	}
	return *this; //returns pointer this.
}
Date Date::operator++(int) //Will add one day to a respective date(Postfix).
{
	Date temp(*this); // Creating temp object.
	Day++;
	if (Day > DaysInMonth()) { //If Day > Days in Month, Sets day to 1 and checks if the month is correct.
		Month++;
		Day = 1;
		if (Month > 12) {
			Month = 1;
			Day = 1;
			Year++;
		}
	}
	return temp; // Returns temp object.
}
Date& Date::operator--() //Will substract one day from a respective date(Prefix).
{
	Day--;
	if (Day < 1) {
		Month--;
		Day = DaysInMonth();
		if (Month < 1) {
			Month = 12;
			Day = DaysInMonth();
			Year--;
		}
	}
	return *this; //Returns this pointer.
}
Date Date::operator--(int)//Will substract one day from a respective date(Postfix).
{
	Date temp(*this); // Creating temp object.
	Day--;
	if (Day < 1) {
		Month--;
		Day = DaysInMonth();
		if (Month < 1) {
			Month = 12;
			Day = DaysInMonth();
			Year--;
		}
	}
	return temp;  // Returns temp object.
}
Date& Date::operator+=(int a) //Add AND assignment operator.
{
	int MonthDaysTemp; //MonthDaysTemp for correct work of DaysInMonth() with Day field.
	Day += a; //Adds days.
	while (Day > DaysInMonth()) {  //While Days > Days in Current Months, Days - Days in Current Months, Months ++.
		MonthDaysTemp = DaysInMonth();
		Month++;
		Day -= MonthDaysTemp;
		while (Month > 12) {
			Year++;
			Month -= 12;
		}
	}
	return *this; //returns this pointer
}
Date& Date::operator-=(int a) //Subtract AND assignment operator.
{
	int MonthDaysTemp; //MonthDaysTemp for correct work of DaysInMonth() with Day field.
	Day -= a;//Substract days.
	while (Day < 1) {
		MonthDaysTemp = DaysInMonth();
		Month--;
		Day += MonthDaysTemp;
		while (Month < 1) {
			Year--;
			Month += 12;
		}
	}
	return *this; //returns this pointer
}
bool Date::operator>(const Date& obj)const //Checks if the date larger than other date, it it is, returns true, otherwise returns false.
{
	if (Year > obj.Year) return 1;
	if (Year < obj.Year) return 0;
	if (Month > obj.Month) return 1;
	if (Month < obj.Month) return 0;
	if (Day > obj.Day)return 1;
	return 0;
}
bool Date::operator<(const Date& obj)const //Checks if the date less than other date, it it is, returns true, otherwise returns false.
{
	if (Year < obj.Year) return 1;
	if (Year > obj.Year) return 0;
	if (Month < obj.Month) return 1;
	if (Month > obj.Month) return 0;
	if (Day < obj.Day)return 1;
	return 0;
}
bool Date::operator>=(const Date& obj)const
{
	if (Date::operator>(obj)) return 1; // If Date larger than other date, returns true immediately.
	if (Day == obj.Day && Month == obj.Month && Year == obj.Year) return 1; //Otherwise, checks if the data and other date are identical
	return 0; //If not, returns 0.
}
bool Date::operator<=(const Date& obj)const
{
	if (Date::operator<(obj)) return 1;  // If Date less than other date, returns true immediately.
	if (Day == obj.Day && Month == obj.Month && Year == obj.Year) return 1; //Otherwise, checks if the data and other date are identical
	return 0; // If not, returns 0.
}
bool Date::operator==(const Date& obj)const
{
	if (Year == obj.Year && Month == obj.Month && Day == obj.Day) return 1; //Checks if all the fields are identical, otherwise returns 0.
	return 0;
}
bool Date::operator!=(const Date& obj)const
{
	if (Year != obj.Year || Month != obj.Month || Day != obj.Day) return 1; //Checks if all the fields are NOT identical, otherwise returns 0.
	return 0;
}



