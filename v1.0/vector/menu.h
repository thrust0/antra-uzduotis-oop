#pragma once

#include "io.h"

//functions
void intro_text(); //message for user intro options
void input_method(vector<Students>& group, int& menu_option); //input option 1-6
void sort_method(vector<Students>& group, int& sort_option);
void output_method(vector<Students>& group, int& menu_option,int& output_option);
void menu(); //main menu declaration