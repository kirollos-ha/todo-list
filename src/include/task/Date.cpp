#include "Date.hpp"

Date Date::from(int day, int month, int year) {
    auto possible_error = check_error(day, month, year);
    if (possible_error.has_value()) {
        std::cerr<<*possible_error<<std::endl;
        return void_date;
    }
    else {
        return Date(day, month, year);
    }
}

bool Date::is_void() const {
    // we use -1 -1 -1 as THE void date
    // this function is only meant to test against that
    return day==-1 && month==-1 && year==-1;
            
}

int Date::get_year() const {
    return year;
}

int Date::get_month() const {
    return month;
}

int Date::get_day() const {
    return day;
}

char cmp(int a, int b) {
    if(a==b)
        return 0;
    if(a>b)
        return 1;
    return -1;
}

bool Date::is_past(const Date& other) const {
    switch(cmp(year, other.year)) {
    case 1:
        return true;
    case -1:
        return false;
    default:
        switch(cmp(month, other.month)) {
        case 1:
            return true;
        case -1:
            return false;
        default:
            return day > other.day;
        }
    }
}

void Date::operator=(Date& right) {
    day = right.day;
    month = right.month;
    year = right.year;
}

const Date& Date::get_current() {
    // sotituibile con return Date::get_now();
    // se vuoi che il programma resista all'essere usato a mezzanotte
    return current;
}

bool Date::is_leap(int year) {
    if((year % 400) == 0)
        return true;
    if((year % 100) == 0)
        return false;
    if((year % 4) == 0)
        return true;
    return false;
}

int Date::days_in_month(int month, int year) {
    switch(month) {
    case 1: return 31;
    case 2: return is_leap(year)?29:28;
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
    default: return -1;
    }
}

std::optional<std::string> Date::check_error(int day, int month, int year) {
    if(month < 1 || month > 12) {
        std::stringstream ss;
        ss << "invalid month number " << month;
        return std::optional<std::string>(ss.str());
    }
    int max_days = days_in_month(month, year);
    if(day > max_days) {
        std::stringstream ss;
        ss << "invalid month number " << month<< '\n';
        ss << day << "-th day of month " <<month << " in year " << year << " which only has " << max_days << " days";
        return std::optional<std::string>(ss.str());
    }
    if(day < 1) {
        std::stringstream ss;
        ss << "day number " << day << " cannot be less than 1";
        return std::optional<std::string>(ss.str());
    }
    return std::optional<std::string>();
}

Date::Date(int day, int month, int year)
    :day(day), month(month), year(year) {}

Date Date::get_now() {
    // merçi beaucoup https://stackoverflow.com/questions/58151350/more-elegant-way-to-get-the-current-year-in-c
    std::time_t t = std::time(nullptr);
    std::tm *const pTInfo = std::localtime(&t);
    return from(pTInfo->tm_mday,
                1+pTInfo->tm_mon,
                1900+pTInfo->tm_year);
}
const Date Date::current = Date::get_now();
const Date Date::void_date = Date(-1, -1, -1);
