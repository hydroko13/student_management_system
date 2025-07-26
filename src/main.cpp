#include <iostream>
#include <string>
#include "student.h"
#include <unordered_map>
#include <random>
#include <algorithm>
#include <cctype>
#include <cstdlib>




int generate_unique_student_id(std::mt19937& rd, const std::unordered_map<int, Student>& students_map) {
    std::uniform_int_distribution<int> dist(1, 999999999);
    int r = dist(rd);
    while (students_map.count(r) > 0) {
        r = dist(rd);

    }

    return r;
}  

int main() {


    
    std::uniform_int_distribution<int> sdist(-15000000, 15000000);
    std::mt19937 rng(std::random_device{}());

    
    
    


    

    std::cout << "==== student management system by Maxim Kozlov ====" << std::endl;
    std::cout << "This software comes with absolutely no warranty" << std::endl;
   

    std::unordered_map<int, Student> students_map;

    int selected_student_id = -1;
    
    while(true) {
        std::cout << "ENTER A COMMAND >> ";
        std::string in_string;
        std::getline(std::cin, in_string);

        

        if (in_string == "list") {
            for (auto pair : students_map) {
                Student student = pair.second;
                int id = pair.first;
                if (id == selected_student_id) {
                    std::cout << "(Selected) Student ID: " << id << ", Name: " << student.getFirstName() << " " << student.getLastName() << ", Age: " << student.getAge().count() << std::endl;
                } else {
                    std::cout << "           Student ID: " << id << ", Name: " << student.getFirstName() << " " << student.getLastName() << ", Age: " << student.getAge().count() << std::endl;
                }
                
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
                    if (id == selected_student_id) {
                        std::cout << "(Selected) Student ID: " << id << ", Name: " << student.getFirstName() << " " << student.getLastName() << ", Age: " << student.getAge().count() << std::endl;
                    } else {
                        std::cout << "           Student ID: " << id << ", Name: " << student.getFirstName() << " " << student.getLastName() << ", Age: " << student.getAge().count() << std::endl;
                    }
                }
                else if (student.getLastName().contains(in_string_qr)) {
                    if (id == selected_student_id) {
                        std::cout << "(Selected) Student ID: " << id << ", Name: " << student.getFirstName() << " " << student.getLastName() << ", Age: " << student.getAge().count() << std::endl;
                    } else {
                        std::cout << "           Student ID: " << id << ", Name: " << student.getFirstName() << " " << student.getLastName() << ", Age: " << student.getAge().count() << std::endl;
                    }
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

        else if (in_string == "delete") {
            
            if (selected_student_id == -1) {
                std::cout << "No student selected." << std::endl;
            } else {
                try {
                    Student student = students_map.at(selected_student_id);

                    std::cout << "Sucessfully deleted: Student ID: " << selected_student_id << ", Name: " << student.getFirstName() << " " << student.getLastName() << ", Age: " << student.getAge().count() << std::endl;
                    students_map.erase(selected_student_id);

                }  catch (const std::out_of_range&) {
                    std::cout << "Invalid student ID" << std::endl;
                }
                

                
            }

        }
        

        else if (in_string == "select") {
            
            std::cout << "STUDENT ID: ";
            std::string in_string_id;
            std::getline(std::cin, in_string_id);

            selected_student_id = std::atoi(in_string_id.c_str());

        }

        
        


    }


    
    return 0;

}





