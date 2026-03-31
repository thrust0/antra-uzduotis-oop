#include "student.hpp"

void Students::random_grades_generator()
{
    int grade_count = rand() % 10;

    for(int i = 0; i<grade_count; i++)
        grade_.push_back(rand() % 10);

    exam_ = rand() % 10;
}

void Students::set_random_grades() 
{
    random_grades_generator();
    
    for(size_t i = 0; i<grade_.size(); i++)
    {
        cout << "\t" << i+1 << "pažymys iš " << grade_.size() << ": " << grade_[i] << "\n"; 
    }
    cout << "\tEgzamino pažymys: " << exam_ << "\n";
}
// Read name lists from files under vardai/ and return a random first+last
vector<string> Students::random_name_generator()
{
    vector<string> v_first_names;
    vector<string> v_last_names;
    vector<string> full_name;

    string first_name_file;
    string last_name_file;
    string line;
    int gender = rand() % 2;

    if(gender == 0)
    {
        first_name_file = "../vardai/vyriski-vardai.txt";
        last_name_file = "../vardai/vyriskos-pavardes.txt";
    }
    else
    {
        first_name_file = "../vardai/moteriski-vardai.txt";
        last_name_file = "../vardai/moteriskos-pavardes.txt";
    }
    
    ifstream file_first_names(first_name_file);
    ifstream file_last_names(last_name_file);

    if(!file_first_names)
    {
        cerr << "Error opening the male first names file" << endl;
        return {};
    }
    if(!file_last_names)
    {
        cerr << "Error opening the male last names file" << endl;
        return {};
    }

    while(getline(file_first_names, line))
    {
        v_first_names.push_back(line);
    }

    while(getline(file_last_names, line))
    {
        v_last_names.push_back(line);
    }

    int rand_index = rand() % v_first_names.size();
    full_name.push_back(v_first_names[rand_index]);

    rand_index = rand() % v_last_names.size();
    full_name.push_back(v_last_names[rand_index]);

    return full_name;       
}

void Students::set_random_name()
{
    vector<string> full_name = random_name_generator();
    first_name_ = full_name[0];
    last_name_ = full_name[1];

    cout << "Studento vardas ir pavardė: " << first_name_ << " " << last_name_ << "\n";
    set_random_grades();
}

// Compute weighted average: 40% homework + 60% exam
double Students::calc_result() const
{
    int sum = 0;
    for(size_t i = 0; i < grade_.size(); i++)
        sum += grade_[i];
    
    return sum * 1.0 / (grade_.size() * 1.0) * 0.4 + exam_ * 0.6;
}

// Compute median including exam (returns double)
double Students::calc_median() const
{
    // create a copy that we can sort without modifying the caller's data
    vector <int> v;
    double median;

    for(int x : grade_) 
        v.push_back(x);
    
    v.push_back(exam_);
    sort(v.begin(), v.end());
    // median calculation depending on odd/even size
    if(v.size() % 2 == 1) // odd
    {
        median = v[v.size()/2]; 
        return median;
    }
    else // even
    {
        median = (v[(v.size()-1)/2] + v[(v.size()/2)]);
        return median/2;
    }
}

istream& Students::read_students(istream& is)
{
    is >> first_name_ >> last_name_;

    int grade;
    while(is >> grade)
        grade_.push_back(grade);
    
    if(!grade_.empty())
    {
        exam_ = grade_.back();
        grade_.pop_back();
    }

    result_ = calc_result();
    median_ = calc_median();

    return is;
}

//compare functions
//palyginimo funkcijos
bool compare_by_first_name(const Students& a, const Students& b) {
    return a.first_name() < b.first_name();
}
bool compare_by_last_name(const Students& a, const Students& b) {
    return a.last_name() < b.last_name();
}
bool compare_by_result(const Students& a, const Students& b) {
    return a.result() > b.result();
}
bool compare_by_median(const Students& a, const Students& b) {
    return a.median() > b.median();
}

