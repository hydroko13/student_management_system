#include <iostream>
#include <string>
#include "student.h"

int main() {



    std::cout << "Hello world" << std::endl;

    Student student(std::string("Maxim"), std::string("Kozlov"), std::chrono::year_month_day(std::chrono::year(2011), std::chrono::May, std::chrono::day(1)));

    std::cout << student.getFirstName() << std::endl;

    std::cout << student.getAge() << std::endl;
     
    return 0;
}



