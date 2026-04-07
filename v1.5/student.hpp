#pragma once
#include "human.hpp"
class Students : public Human //inheritina Students klase Human klase
{
private:
    //nebera first name ir lastname nes derivinam is Human klases
    int exam_;
    vector<int> grade_;
    double result_, median_;

    //private helper functions
    double calc_result() const;
    double calc_median() const;

    void random_grades_generator();
    vector <string> random_name_generator();
public:
    Students() : Human(),  exam_(0), result_(0), median_(0){ } //default contstructor
    Students(istream& is) { read_students(is); }
    //getters
    //nebera getteriu vardui ir pavardei
    inline int exam() const { return exam_; }
    inline double result() const { return calc_result(); }
    inline double median() const { return calc_median(); }
    //setters
    istream& read_students(istream&);//file input setter
    //default setters
    //nebera set first ir last name
    void set_exam(int exam) { exam_ = exam; }
    void add_grade(int grade) {grade_.push_back(grade);}
    void set_result() { result_ = calc_result(); }
    void set_median() { median_ = calc_median(); }
    //random setters
    void set_random_grades();
    void set_random_name();
    //del v1.5 prideta print funckija kad pademonstruoti abstrakcija
    void print() const override;
    //rule of 5
    Students(const Students& other); //copy konstruktorius
    Students(Students&& other); //move konstruktorius
    Students& operator=(const Students& other); //copy priskirimas
    Students& operator=(Students&& other); //move priskyrimas
    ~Students() {grade_.clear(); first_name_.clear(); last_name_.clear();} //destruktorius
};

//io operatoriai
istream& operator>>(istream& is, Students& student);
ostream& operator<<(ostream& os, const Students& student);

//palyginimo funkcijos
bool compare_by_first_name(const Students& a, const Students& b);
bool compare_by_last_name(const Students& a, const Students& b);
bool compare_by_result(const Students& a, const Students& b);
bool compare_by_median(const Students& a, const Students& b);

