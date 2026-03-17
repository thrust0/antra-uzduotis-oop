#pragma once

#include "io.h"

const vector<int> STUDENT_COUNTS = {1000, 10000, 100000, 1000000, 10000000};

const vector<string> FILE_PATHS = {
    "../../studentInput/kursiokai.txt",
    "../../studentInput/studentai10000.txt",
    "../../studentInput/studentai100000.txt",
    "../../studentInput/studentai1000000.txt",
    "../../studentInput/studentai_gen1000.txt",
    "../../studentInput/studentai_gen10000.txt",
    "../../studentInput/studentai_gen100000.txt",
    "../../studentInput/studentai_gen1000000.txt",
    "../../studentInput/studentai_gen10000000.txt",
};

//functions
void intro_text(); //message for user intro options
void input_method(vector<Students>& group, int& menu_option); //input option 1-6
void sort_method(vector<Students>& group, int& sort_option);
void output_method(vector<Students>& group, int& menu_option,int& output_option);
void menu(); //main menu declaration