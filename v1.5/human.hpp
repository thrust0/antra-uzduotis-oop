#pragma once

//libraries
#include <iomanip>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <random>
#include <ctime>
#include <stdio.h>
#include <fstream>
#include <cctype>
#include <sstream>
#include <chrono>
#include <stdexcept>
#include <filesystem>
#include <utility>


using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::ifstream;
using std::ofstream;
using std::cerr;
using std::getline;
using std::stringstream;
using std::setw;
using std::fixed;
using std::setprecision;
using std::sort;
using std::move;
using std::ostringstream;
using std::milli;
using std::invalid_argument;
using std::to_string;
using std::runtime_error;
using std::move;
using std::istream;
using std::ostream;

class Human
{
protected:
    string first_name_;
    string last_name_;
public:
    Human() : first_name_(""), last_name_("") {}

    //getteriai
    inline string first_name() const { return first_name_; }
    inline string last_name() const { return last_name_; }

    //setteriai
    void set_first_name(const string& name) { first_name_= name; }
    void set_last_name(const string& name) { last_name_= name; }

    //copy konstruktorius
    Human(const Human& other) : first_name_(other.first_name_),
                                last_name_(other.last_name_)
    { }

    //move konstruktorius
    Human(Human&& other) : first_name_(std::move(other.first_name_)),
                            last_name_(std::move(other.last_name_))
    { }
    //funkcijos
    virtual void print() const = 0; //human yra abstrakti klase
    virtual ~Human() {} //destruktorius
};