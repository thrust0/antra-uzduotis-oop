#include "student.h"

void random_grades_generator(Students& student)
{
    int grade_count = rand() % 10 + 1; //kad butu nuo 1-10 o ne 0-11
    int sum = 0;
    for(int i = 0; i<grade_count; i++)
    {
        int temp = rand() % 10;
        student.grade.push_back(temp);
        sum += temp;
        cout << '\t' << i+1 << " pažymys iš " << grade_count << ": " << temp << endl;
    }

    student.exam = rand() % 10;
    cout << "\tEgzamino pažymys: " << student.exam << endl << endl;

    student.result = calc_result(sum, grade_count, student.exam);

    student.median = calc_median(student.exam, student.grade);
}


// Read name lists from files under vardai/ and return a random first+last
list<string> random_name_generator()
{
    list<string> v_first_names;
    list<string> v_last_names;
    list<string> full_name;
    string first_name_file;
    string last_name_file;
    string line;
    int gender = rand() % 2;

    if(gender == 0)
    {
        first_name_file = "../../vardai/vyriski-vardai.txt";
        last_name_file = "../../vardai/vyriskos-pavardes.txt";
    }
    else
    {
        first_name_file = "../../vardai/moteriski-vardai.txt";
        last_name_file = "../../vardai/moteriskos-pavardes.txt";
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
    auto it = v_first_names.begin();
    advance(it, rand_index);
    full_name.push_back(*it);

    rand_index = rand() % v_last_names.size();
    auto it2 = v_last_names.begin();
    advance(it2, rand_index);
    full_name.push_back(*it2);

    return full_name;       
    }

// Compute weighted average: 40% homework + 60% exam
double calc_result(int sum, int n, int exam)
{
    return sum * 1.0 / (n * 1.0) * 0.4 + exam * 0.6;
}

// Compute median including exam (returns double)
double calc_median(int exam, list<int>& grade)
{
    // create a copy that we can sort without modifying the caller's data
    list <int> l(grade);
    l.push_back(exam);
    l.sort(); //automatically lowest to highest

    int size = l.size();
    auto i = l.begin(); //iterator

    // choose median depending on odd/even size
    if(size % 2 == 1) // odd
    {
        advance(i, size / 2);
        return *i;
    }
    else // even
    {
        advance(i, size / 2);
        double left = *i;
        advance(i, 1);
        double right = *i;
        return (left + right) / 2.0;
    }
}