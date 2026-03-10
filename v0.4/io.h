#pragma once
#include "student.h"
#include "menu.h"

void manual_input(std::vector<Students>& group);
void generate_grades_input(std::vector<Students>& group);
void generate_names_input(std::vector<Students>& group);
void file_input(std::vector<Students>& group, const std::string& filename);

void output(std::vector<Students>& group);
void temp_output(std::vector<Students>& group);
void file_output(std::vector<Students>& group);
void sort_output(std::vector<Students>& group, int sort_option);

void generate_raw_student_file(int student_amount, int grade_amount);

void print_line(); // prints long ----
int get_int(int start, int end); //prompts for an integer picked by programmer