#pragma once
#include "student.h"
#include "menu.h"

//input functions
void manual_input(deque<Students>& group);
void generate_grades_input(deque<Students>& group);
void generate_names_input(deque<Students>& group);
void file_input(deque<Students>& group, const string& filename);

//output functions
void output(deque<Students>& group);
void temp_output(deque<Students>& group);
void file_output(deque<Students>& group, string filename);

//sorting functions
void sort_output(deque<Students>& group, int sort_option);
void split_students_by_grades(deque<Students>& group,deque<Students>& above_five, deque<Students>& below_five);
void split_strategy_two(deque<Students>& group, deque<Students>& below_five);
void split_strategy_three(deque<Students> & group, deque<Students>& below_five);

//student data generating functions
string generate_raw_student_file(int student_amount, int grade_amount);

//time esting functions
string test_generate_raw_student_file(int student_amount, int grade_amount); // 1 tyrimas
void test_data_processing(const string& filename); //2 tyrimas

//helper functions
void print_line(); // prints long ----
int get_int(int start, int end); //prompts for an integer picked by programmer