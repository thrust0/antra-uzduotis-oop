#pragma once
#include "student.h"
#include "menu.h"

//input functions
void manual_input(std::list<Students>& group);
void generate_grades_input(std::list<Students>& group);
void generate_names_input(std::list<Students>& group);
void file_input(std::list<Students>& group, const std::string& filename);

//output functions
void output(std::list<Students>& group);
void temp_output(std::list<Students>& group);
void file_output(std::list<Students>& group, std::string filename);

//sorting functions
void sort_output(std::list<Students>& group, int sort_option);
void split_students_by_grades(std::list<Students>& group,std::list<Students>& above_five, std::list<Students>& below_five);
void split_strategy_two(list<Students>& group, list<Students>& below_five);
void split_strategy_three(list<Students> & group, list<Students>& below_five);

//student data generating functions
std::string generate_raw_student_file(int student_amount, int grade_amount);

//time esting functions
std::string test_generate_raw_student_file(int student_amount, int grade_amount); // 1 tyrimas
void test_data_processing(const std::string& filename); //2 tyrimas

//helper functions
void print_line(); // prints long ----
int get_int(int start, int end); //prompts for an integer picked by programmer