#pragma once
#include <string>
#include <chrono>



/*
* @class Student
* @brief represents a student 
*   
* This class provides a representation of a student
* It can store the first name, last name, date of birth, etc
*
*/


class Student {

    private:


        std::string first_name;
        std::string last_name;
        std::chrono::year_month_day dob; // Student date of birth is needed to calculate age, grade, etc



    public:

        /*
        * @brief Constructs a new Student object
        *   
        *  This constructor initializes a Student object with the specified first name, last name, and date of birth
        *  
        *   @param first_name The first name of the student represented as a std::string
        *   @param first_name The last name of the student represented as a std::string
        *   @param date_of_birth The date of birth of the student represented using std::chrono::year_month_day
        * 
        */

        Student(std::string first_name, std::string last_name, std::chrono::year_month_day date_of_birth);

        // Setter for first name
        void setFirstName(std::string first_name);
        // Getter for first name
        std::string getFirstName();
        // Setter for last name
        void setLastName(std::string last_name);

        // Getter for last name
        std::string getLastName();

        void setDateOfBirth(std::chrono::year_month_day date_of_birth);

        std::chrono::year_month_day getDateOfBirth();

        std::chrono::years getAge();

        std::chrono::years getAge(std::chrono::time_point<std::chrono::system_clock> timep);
 

 

};