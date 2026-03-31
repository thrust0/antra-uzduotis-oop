#pragma once

#include "io.h"

const vector<int> STUDENT_COUNTS = {1000, 10000, 100000, 1000000, 10000000};

const vector<string> FILE_PATHS = {
    "../studentInput/studentai_gen1000.txt",
    "../studentInput/studentai_gen10000.txt",
    "../studentInput/studentai_gen100000.txt",
    "../studentInput/studentai_gen1000000.txt",
    "../studentInput/studentai_gen10000000.txt",
};

//functions
void intro_text(); //message for user intro options
void input_method(vector<Students>& group, int& menu_option); //input option 1-6
void sort_method(vector<Students>& group, int& sort_option);
void split_method(vector<Students>& group, vector<Students>& above_five, vector<Students>& below_five, int& split_option, int& sort_option);
void output_method(vector<Students>& group, vector<Students>& above_five, vector<Students>& below_five, int& menu_option,int& output_option, int& split_option, int& sort_option);
void menu(); //main menu declaration