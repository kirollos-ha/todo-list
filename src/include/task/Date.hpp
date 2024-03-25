#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <cstdio>
#include <sstream>
#include<string>
#include<exception>
#include<optional>

#include<ctime>

class Date {
public:
    static Date from(int day, int month, int year); 
    bool is_void() const;
    int get_year() const;
    int get_month() const;
    int get_day() const;
    bool is_past(const Date& other) const ;
    static const Date& get_current() ;
    void operator=(Date& right);

private:
    int day;
    int month;
    int year;

    static bool is_leap(int year) ;
    static int days_in_month(int month, int year) ;
    static std::optional<std::string> check_error(int day, int month, int year) ;
    Date(int day, int month, int year);
    static Date get_now() ;
    const static Date current;
    const static Date void_date;
};

#endif
