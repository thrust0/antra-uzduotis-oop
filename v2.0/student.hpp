#pragma once
#include "human.hpp"
#include <vector>
#include <string>
#include <istream>
#include <ostream>
#include <iostream>

using std::vector;
using std::string;
using std::istream;
using std::ostream;

/**
 * @brief Student model storing homework grades, exam, and computed results.
 *
 * Derives from Human and provides helpers to compute weighted average
 * and median including the exam. It also contains utilities for random
 * data generation and file I/O.
 */
class Students : public Human
{
private:
    int exam_;             ///< exam grade
    vector<int> grade_;    ///< homework grades
    double result_, median_; ///< cached values (can be recalculated)

    // private helper functions
    /**
     * @brief Compute weighted average (40% homework, 60% exam).
     * @return The weighted average as double. Returns 0 if no homework grades.
     */
    double calc_result() const;

    /**
     * @brief Compute median including the exam grade.
     * @return The median value (double). If number of elements is even, returns the average of the two middle values.
     */
    double calc_median() const;

    void random_grades_generator();
    vector <string> random_name_generator();
public:
    /**
     * @brief Default constructor: empty student.
     */
    Students() : Human(),  exam_(0), result_(0), median_(0){ }

    /**
     * @brief Construct by reading a single student record from a stream.
     * @param is Input stream containing one student record (line-based).
     */
    Students(istream& is) { read_students(is); }

    /* Getters */
    inline int exam() const { return exam_; }
    inline double result() const { return calc_result(); }
    inline double median() const { return calc_median(); }

    /**
     * @brief Parse a single student from the provided stream.
     *
     * The implementation expects one student per line: first_name last_name grades... exam
     * @param is Input stream to read the line from.
     * @return Reference to the same input stream.
     */
    istream& read_students(istream&);

    /* Setters */
    void set_exam(int exam) { exam_ = exam; }
    void add_grade(int grade) { grade_.push_back(grade); }
    void set_result() { result_ = calc_result(); }
    void set_median() { median_ = calc_median(); }

    // Random helpers
    void set_random_grades();
    void set_random_name();

    /**
     * @brief Print a formatted single-line representation of the student.
     */
    void print() const override;

    // Rule of 5
    Students(const Students& other); // copy constructor
    Students(Students&& other); // move constructor
    Students& operator=(const Students& other); // copy assignment
    Students& operator=(Students&& other); // move assignment
    ~Students() { grade_.clear(); first_name_.clear(); last_name_.clear(); }
};

// I/O operators
/** Read a Students from a stream (delegates to Students::read_students). */
istream& operator>>(istream& is, Students& student);
/** Write a Students to a stream in aligned columns (first last avg median). */
ostream& operator<<(ostream& os, const Students& student);

// Comparison helpers used for sorting
bool compare_by_first_name(const Students& a, const Students& b);
bool compare_by_last_name(const Students& a, const Students& b);
bool compare_by_result(const Students& a, const Students& b);
bool compare_by_median(const Students& a, const Students& b);

