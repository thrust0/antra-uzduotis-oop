#pragma once
#include "student.hpp"


//input functions
void manual_input(vector<Students>& group);
void generate_grades_input(std::vector<Students>& group);
void generate_names_input(std::vector<Students>& group);
void file_input(std::vector<Students>& group, const std::string& filename);

//output functions
void terminal_output(std::vector<Students>& group);
void temp_output(std::vector<Students>& group);
void file_output(const vector<Students>& group, const string filename);

//sorting functions
void sort_output(std::vector<Students>& group, int sort_option);
void split_students_by_grades(vector<Students>& group,vector<Students>& above_five, vector<Students>& below_five);
void split_strategy_two(vector<Students>& group, vector<Students>& below_five);
void split_strategy_three(vector<Students> & group, vector<Students>& below_five);

//student data generating functions
string generate_raw_student_file(int student_amount, int grade_amount);

//time esting functions
string test_generate_raw_student_file(int student_amount, int grade_amount); // 1 tyrimas
void test_data_processing(const string& filename); //2 tyrimas

//helper functions
void print_line(); // prints long ----
int get_int(int start, int end); //prompts for an integer picked by programmer