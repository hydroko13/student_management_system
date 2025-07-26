#include <iostream>
#include <string>
#include "student.h"
#include <unordered_map>
#include <random>
#include <algorithm>
#include <cctype>
#include <cstdlib>




int generate_unique_student_id(std::mt19937& rd, std::unordered_map<int, Student> students_map) {
    std::uniform_int_distribution<int> dist(0, 999999999);
    int r = dist(rd);
    while (students_map.count(r) > 0) {
        r = dist(rd);

    }

    return r;
}  

int main() {


    std::random_device rd;
    std::uniform_int_distribution<int> sdist(-15000000, 15000000);
    std::mt19937 rng(rd());

    rng.seed(sdist(rd));
    
    
    


    system("clear");

    std::cout << "==== student management system by Maxim Kozlov ====" << std::endl;
    std::cout << "This software comes with absolutely no warranty" << std::endl;
   

    std::unordered_map<int, Student> students_map;

    
    
    while(true) {
        std::cout << "ENTER A COMMAND >> ";
        std::string in_string;
        std::getline(std::cin, in_string);

        

        if (in_string == "list") {
            for (auto pair : students_map) {
                Student student = pair.second;
                int id = pair.first;

                std::cout << "Student ID: " << id << ", Name: " << student.getFirstName() << " " << student.getLastName() << ", Age: " << student.getAge().count() << std::endl;
            }
        }
        else if (in_string == "search") {
            std::cout << "QUERY: ";
            std::string in_string_qr;
            std::getline(std::cin, in_string_qr);

            for (auto pair : students_map) {
                Student student = pair.second;
                int id = pair.first;
                
                if (student.getFirstName().contains(in_string_qr)) {
                    std::cout << "Student ID: " << id << ", Name: " << student.getFirstName() << " " << student.getLastName() << ", Age: " << student.getAge().count() << std::endl;
                }
                else if (student.getLastName().contains(in_string_qr)) {
                    std::cout << "Student ID: " << id << ", Name: " << student.getFirstName() << " " << student.getLastName() << ", Age: " << student.getAge().count() << std::endl;
                }

                
            }
        }
        else if (in_string == "add") {
            
            std::cout << "FIRST NAME: ";
            std::string in_string_fn;
            std::getline(std::cin, in_string_fn);

            std::cout << "LAST NAME: ";
            std::string in_string_ln;
            std::getline(std::cin, in_string_ln);

            std::cout << "DATE OF BIRTH year: ";
            std::string in_string_dob_year;
            std::getline(std::cin, in_string_dob_year);

            std::cout << "DATE OF BIRTH month (1-12): ";
            std::string in_string_dob_month;
            std::getline(std::cin, in_string_dob_month);

            std::cout << "DATE OF BIRTH day: ";
            std::string in_string_dob_day;
            std::getline(std::cin, in_string_dob_day);

            int year = std::atoi(in_string_dob_year.c_str());
            int month = std::atoi(in_string_dob_month.c_str());
            int day = std::atoi(in_string_dob_day.c_str());


            
            std::cout << "Successfully added student: " << std::endl;

            

            

            
            int id = generate_unique_student_id(rng, students_map);


            Student student(in_string_fn, in_string_ln, std::chrono::year_month_day{std::chrono::year(year), std::chrono::month(month), std::chrono::day(day)});
            std::cout << "Student ID: " << id << ", Name: " << student.getFirstName() << " " << student.getLastName() << ", Age: " << student.getAge().count() << std::endl;
            students_map.insert(std::pair<int, Student>(id, student));
        }
        


    }

    // Student student(std::string("Maxim"), std::string("Kozlov"), std::chrono::year_month_day(std::chrono::year(2011), std::chrono::May, std::chrono::day(1)));
    
    // int uuid = generate_unique_student_id(rng, students_map);
    
    // students_map.insert(std::pair<int, Student>(uuid, student));

    // std::cout << student.getFirstName() << std::endl;

    // std::cout << student.getAge() << std::endl;
     
    
    return 0;

}





