#pragma once

#include "io.h"

/** @file menu.h
 *  @brief Menu and high-level orchestration helpers for the application.
 */

/// Predefined student counts used by the generator
const vector<int> STUDENT_COUNTS = {1000, 10000, 100000, 1000000, 10000000};

/// Common file paths for test input files
const vector<string> FILE_PATHS = {
    "../studentInput/studentai_gen1000.txt",
    "../studentInput/studentai_gen10000.txt",
    "../studentInput/studentai_gen100000.txt",
    "../studentInput/studentai_gen1000000.txt",
    "../studentInput/studentai_gen10000000.txt",
};

/** @brief Print introductory help text and options. */
void intro_text();

/**
 * @brief Prompt user for input method and populate group accordingly.
 * @param group Destination vector.
 * @param menu_option Set to the chosen menu option (1-6).
 */
void input_method(vector<Students>& group, int& menu_option);

/** @brief Helper to select and apply sorting. */
void sort_method(vector<Students>& group, int& sort_option);

/**
 * @brief Choose a splitting strategy and perform the split.
 * @param group Source vector containing all students.
 * @param above_five Destination vector for students with result() >= 5.
 * @param below_five Destination vector for students with result() < 5.
 * @param split_option Set to the selected split strategy (1..3).
 * @param sort_option Current sorting option (used by some strategies).
 */
void split_method(vector<Students>& group, vector<Students>& above_five, vector<Students>& below_five, int& split_option, int& sort_option);

/**
 * @brief Choose output destination and format and write the students.
 * @param group Primary vector of students to output.
 * @param above_five Vector containing students with result() >= 5 (may be empty).
 * @param below_five Vector containing students with result() < 5 (may be empty).
 * @param menu_option The input-mode selected previously (influences formatting).
 * @param output_option Output target selected by user (1=terminal,2=file,3=two files).
 * @param split_option Split strategy selected earlier (used when creating two files).
 * @param sort_option Sorting preference to apply to outputs.
 */
void output_method(vector<Students>& group, vector<Students>& above_five, vector<Students>& below_five, int& menu_option,int& output_option, int& split_option, int& sort_option);

/** @brief The top-level menu/driver for the program. */
void menu();