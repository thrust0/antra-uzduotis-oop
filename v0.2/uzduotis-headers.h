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

constexpr char print_result = ';';
constexpr char print_median = ':';

void random_grades_generator(Students& student);
void manual_input(std::vector<Students>& group);
void generate_grades_input(std::vector<Students>& group);
void generate_names_input(std::vector<Students>& group);
void file_input(std::vector<Students>& group, const std::string& filename);
std::vector <std::string> random_name_generator();
void output(std::vector<Students>& group);
void temp_output(std::vector<Students>& group);
void file_output(std::vector<Students>& group);
void sort_output(std::vector<Students>& group, int sort_option);
double calc_result(int sum, int n, int exam);
double calc_median(int exam, std::vector<int>& grade);
int get_int(int start, int end);
void print_line();