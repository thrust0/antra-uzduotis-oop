#pragma once
#include "student.hpp"

/** @file io.h
 *  @brief Input/output and helper function declarations for the app.
 */

// Input functions
/**
 * @brief Prompt the user for a student's name and grades interactively.
 * @param group Vector to append the created Students object to.
 */
void manual_input(vector<Students>& group);

/**
 * @brief Prompt for a student's name then generate random grades.
 * @param group Vector to append the created Students object to.
 */
void generate_grades_input(std::vector<Students>& group);

/**
 * @brief Generate random student names and prompt for grades/exam.
 * @param group Vector to append the created Students object to.
 */
void generate_names_input(std::vector<Students>& group);

/**
 * @brief Read students from a text file using the Students stream operator.
 * @param group Vector to append parsed Students to.
 * @param filename Path to the input file.
 * @throws runtime_error if file cannot be opened.
 */
void file_input(std::vector<Students>& group, const std::string& filename);

// Output functions
/**
 * @brief Print selection of students to the terminal (average/median choice).
 * @param group Vector of students to print.
 */
void terminal_output(std::vector<Students>& group);

/**
 * @brief Print a full students table to the terminal (both median and average).
 * @param group Vector of students to print.
 */
void temp_output(std::vector<Students>& group);

/**
 * @brief Write a formatted students table to a file.
 * @param group Students to write.
 * @param filename Destination file path.
 */
void file_output(const vector<Students>& group, const string filename);

// Sorting / splitting helpers
/**
 * @brief Sort students according to the selected option.
 * @param group Vector of students to sort in-place.
 * @param sort_option 1=name,2=lastname,3=avg,4=median
 */
void sort_output(std::vector<Students>& group, int sort_option);

/**
 * @brief Split students into two vectors (>=5 and <5) by moving elements.
 */
void split_students_by_grades(vector<Students>& group,vector<Students>& above_five, vector<Students>& below_five);

/**
 * @brief Alternative splitting strategy (pop from back while <5).
 */
void split_strategy_two(vector<Students>& group, vector<Students>& below_five);

/**
 * @brief Partition-based split: keeps >=5 first then extracts the rest.
 */
void split_strategy_three(vector<Students> & group, vector<Students>& below_five);

// Student data generating functions
/**
 * @brief Generate a raw student data file with randomized names/grades.
 * @return Path to the generated file or empty string on failure.
 */
string generate_raw_student_file(int student_amount, int grade_amount);

// Timing / test helpers
string test_generate_raw_student_file(int student_amount, int grade_amount); ///< helper for timing tests
void test_data_processing(const string& filename); ///< second timing test helper

// Helper functions
/** @brief Print a decorative separator line to the terminal. */
void print_line();

/**
 * @brief Read an integer in [start..end] from stdin. Returns -1 if user enters ';'.
 * @param start Minimum accepted value.
 * @param end Maximum accepted value.
 * @return The parsed integer or -1 if terminated by ';'.
 */
int get_int(int start, int end);