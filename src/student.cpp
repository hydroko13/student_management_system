#include "student.h"



Student::Student(std::string first_name, std::string last_name, std::chrono::year_month_day date_of_birth) {
    this->first_name = first_name;
    this->last_name = last_name;
    this->dob = date_of_birth;
}



void Student::setFirstName(std::string first_name) {
    this->first_name = first_name;
}

std::string Student::getFirstName() {
    return this->first_name;
}

void Student::setLastName(std::string last_name) {
    this->last_name = last_name;
}


std::string Student::getLastName() {
    return this->last_name;
}

void Student::setDateOfBirth(std::chrono::year_month_day date_of_birth) {
    this->dob = date_of_birth;
}

std::chrono::year_month_day Student::getDateOfBirth() {
    return this->dob;
}


std::chrono::years Student::getAge() {
    std::chrono::time_point<std::chrono::system_clock> timep = std::chrono::system_clock::now();

    auto today = std::chrono::floor<std::chrono::days>(timep);

    std::chrono::year_month_day ymd_today = std::chrono::year_month_day{today};

    return ymd_today.year() - this->dob.year();


}

std::chrono::years Student::getAge(std::chrono::time_point<std::chrono::system_clock> timep) {
    auto today = std::chrono::floor<std::chrono::days>(timep);

    std::chrono::year_month_day ymd_today = std::chrono::year_month_day{today};

    return ymd_today.year() - this->dob.year();

}
 