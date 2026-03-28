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


/*
struct Students 
{
    string first_name , last_name;
    // dynamic container for homework/semester grades
    vector <int> grade;
    // single exam score
    int exam;
    // cached computed final result (average-based) and median-based value
    double result, median;
};
*/
double calc_result(int sum, int n, int exam);
double calc_median(int exam, vector<int>& grade);

class Students
{
private:
    string first_name_;
    string last_name_;
    double exam_;
    vector<double> grade_;
    double result_, median_;

public:
    Students() : exam_(0) { } //default contstructor
    Students(istream& is);
    inline string first_name() const { return first_name_; }
    inline string last_name() const { return last_name_; }
    double getResult(double (*) (vector<double>) = calc_result) const;
    

};


void random_grades_generator(Students& student);
vector <string> random_name_generator();

