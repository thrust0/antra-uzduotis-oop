#pragma once

#include "io.h"

const deque<int> STUDENT_COUNTS = {1000, 10000, 100000, 1000000, 10000000};

const deque<string> FILE_PATHS = {
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
void input_method(deque<Students>& group, int& menu_option); //input option 1-6
void sort_method(deque<Students>& group, deque<Students>& below_five, deque<Students>& above_five, int& sort_option, int& split_option);
void output_method(deque<Students>& group, int& menu_option,int& output_option);
void menu(); //main menu declaration