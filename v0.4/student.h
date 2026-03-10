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


struct Students 
{
    std::string first_name = "A", last_name = "BB";
    // dynamic container for homework/semester grades
    std::vector <int> grade;
    // single exam score
    int exam;
    // cached computed final result (average-based) and median-based value
    double result, median;
};

void random_grades_generator(Students& student);
std::vector <std::string> random_name_generator();

double calc_result(int sum, int n, int exam);
double calc_median(int exam, std::vector<int>& grade);