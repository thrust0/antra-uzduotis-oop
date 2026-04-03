#pragma once
//libraries
#include <iomanip>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <random>
#include <ctime>
#include <stdio.h>
#include <fstream>
#include <cctype>
#include <sstream>
#include <chrono>
#include <stdexcept>
#include <filesystem>
#include <utility>


using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::ifstream;
using std::ofstream;
using std::cerr;
using std::getline;
using std::stringstream;
using std::setw;
using std::fixed;
using std::setprecision;
using std::sort;
using std::move;
using std::ostringstream;
using std::milli;
using std::invalid_argument;
using std::to_string;
using std::runtime_error;
using std::move;
using std::istream;
using std::ostream;


class Students
{
private:
    string first_name_;
    string last_name_;
    int exam_;
    vector<int> grade_;
    double result_, median_;

    //private helper functions
    double calc_result() const;
    double calc_median() const;

    void random_grades_generator();
    vector <string> random_name_generator();
public:
    Students() : first_name_(""), last_name_(""),  exam_(0), result_(0), median_(0){ } //default contstructor
    Students(istream& is) { read_students(is); }
    //getters
    inline string first_name() const { return first_name_; }
    inline string last_name() const { return last_name_; }
    inline int exam() const { return exam_; }
    inline double result() const { return calc_result(); }
    inline double median() const { return calc_median(); }
    //setters
    istream& read_students(istream&);//file input setter
    //default setters
    void set_first_name(const string& name) { first_name_= name; }
    void set_last_name(const string& name) { last_name_= name; }
    void set_exam(int exam) { exam_ = exam; }
    void add_grade(int grade) {grade_.push_back(grade);}
    void set_result() { result_ = calc_result(); }
    void set_median() { median_ = calc_median(); }
    //random setters
    void set_random_grades();
    void set_random_name();

    //rule of 5
    Students(const Students& other); //copy konstruktorius
    Students(Students&& other); //move konstruktorius
    Students& operator=(const Students& other); //copy priskirimas
    Students& operator=(Students&& other); //move priskyrimas
    ~Students() {grade_.clear(); first_name_.clear(); last_name_.clear();} //destruktorius
};

//io operatoriai
istream& operator>>(istream& is, Students& student);
ostream& operator<<(ostream& os, const Students& student);

//palyginimo funkcijos
bool compare_by_first_name(const Students& a, const Students& b);
bool compare_by_last_name(const Students& a, const Students& b);
bool compare_by_result(const Students& a, const Students& b);
bool compare_by_median(const Students& a, const Students& b);

