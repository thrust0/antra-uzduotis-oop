#pragma once
#include "student.h"
#include "menu.h"

void manual_input(std::vector<Students>& group);
void generate_grades_input(std::vector<Students>& group);
void generate_names_input(std::vector<Students>& group);
void file_input(std::vector<Students>& group, const std::string& filename);

void output(std::vector<Students>& group);
void temp_output(std::vector<Students>& group);
void file_output(std::vector<Students>& group, std::string filename);

void sort_output(std::vector<Students>& group, int sort_option);
void split_students_by_grades(std::vector<Students>& group,std::vector<Students>& above_five, std::vector<Students>& below_five);


std::string generate_raw_student_file(int student_amount, int grade_amount);

void print_line(); // prints long ----
int get_int(int start, int end); //prompts for an integer picked by programmer