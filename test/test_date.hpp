#ifndef TEST_DATE_H
#define TEST_DATE_H

#include "minitest.hpp"
#include "../src/include/task/Date.hpp"

void test_date() {
    test_suite("valide") {
        test_case("normali") {
            Date d1 = Date::from(10, 10, 10);
            ass_eq(d1.get_day(), 10);
            ass_eq(d1.get_month(), 10);
            ass_eq(d1.get_year(), 10);
            ass_t(!d1.is_void());

            Date d2 = Date::from(11, 3, 2024);
            ass_eq(d2.get_day(), 11);
            ass_eq(d2.get_month(), 3);
            ass_eq(d2.get_year(), 2024);
            ass_t(!d2.is_void());
        }
        test_case("bisestile medio") {
            Date d = Date::from(29, 2, 2024);
            ass_eq(d.get_day(), 29);
            ass_eq(d.get_month(), 2);
            ass_eq(d.get_year(), 2024);
            ass_t(!d.is_void())
        }
        test_case("bisestile 400") {
            ass_t(!(Date::from(29, 2, 1600).is_void()));
            ass_t(!(Date::from(29, 2, 2000).is_void()));
        }
    }

    test_suite("invalide") {
        test_case("tutte zero") {
            ass_t(Date::from(0, 0, 0).is_void());
        }
        test_case("tutte negative") {
            ass_t(Date::from(-1, -1, -1).is_void());
        }
        test_case("bisestile non 4") {
            ass_t(Date::from(29, 2, 2022).is_void());
        }
        test_case("bisestile 100") {
            ass_t(Date::from(29, 2, 1900).is_void());
        }
    }

    test_suite("is past") {
        test_case("giorno dopo") {
            ass_t(Date::from(10, 10, 2020).is_past(Date::from(9, 10, 2020)));
            ass_t(!(Date::from(10, 10, 2020).is_past(Date::from(11, 10, 2020))));
        }
        test_case("mese dopo") {
            ass_t(Date::from(10, 10, 2020).is_past(Date::from(10, 9, 2020)));
            ass_t(!(Date::from(10, 10, 2020).is_past(Date::from(11, 11, 2020))));
        }
        test_case("anno dopo") {
            ass_t(Date::from(10, 10, 2020).is_past(Date::from(10, 10, 2019)));
            ass_t(!(Date::from(10, 10, 2020).is_past(Date::from(11, 10, 2021))));
        }
        test_case("uguali") {
            ass_t(!(Date::from(10, 10, 2020).is_past(Date::from(10, 10, 2020))));
        }
    }
}

#endif
