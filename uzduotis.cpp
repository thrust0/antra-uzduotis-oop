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

using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::left;
using std::right;
using std::setw;
using std::endl;

// Student grading tool: read or generate names and grades, compute average or median
// Student record: name, homework grades, exam and computed results
//komentarai su ai, pats juos perziurejau
struct Students 
{
    string first_name = "A", last_name = "BB";
    // dynamic container for homework/semester grades
    vector <int> grade;
    // single exam score
    int exam;
    // cached computed final result (average-based) and median-based value
    double result, median;
};

constexpr char print_result = ';';
constexpr char print_median = ':';

// Function prototypes
void manual_input(vector<Students>& group);
void generate_grades_input(vector<Students>& group);
void generate_names_input(vector<Students>& group);
vector <string> random_name_generator();
void output(vector<Students>& group);
double calc_result(int sum, int n, int exam);
double calc_median(int exam, vector<int>& grade);
int get_int(int start, int end);
void print_line();

// Program entry point: initialize RNG and show menu
int main() 
{
    srand(time(0));
    for(int i = 0; i<6; i++) cout << endl;
    vector<Students>group;

    //intro vartotojui
    cout << "\tSveiki, čia yra vidurkio ir medianos iš pažymių skaičiuoklė" << endl << endl;
    cout << "Įveskite:\n\t'1' jei norite ranka suvesti pažymius\n\t'2' jei norite, kad pažymiai būtu sugeneruoti\n\t'3' jei norite, kad būtu sugeneruoti studentų vardai\n\t'4' jei norite išeiti iš programos\n\n";

    
    // validate menu input via get_int
    while(true)
    {
        int menu_option = get_int(1, 4);

        if(menu_option == 1)
        {
            manual_input(group);
            break;
        }
        else if(menu_option == 2)
        {
            generate_grades_input(group);
            break;
        }
        else if(menu_option == 3)
        {
            generate_names_input(group);
            break;
        }
        else if(menu_option == 4)
        {
            cout << "Išeinama is programos...\n";
            return 0;
        }
        else
        {
            cout << "Nėra tokio pasirinkimo!\n";
            cout << "Įveskite:\n\t'1' jei norite ranka suvesti pazymius\n\t'2' jei norite, kad pazymiai butu sugeneruoti\n\t'3' jei norite, kad butu sugeneruoti studentu vardai\n\t'4' jei norite iseiti is programos\n\n";
        }
    }
    output(group);

}

// Interactive input: read name, grades and exam. ';' as name exits.
void manual_input(vector<Students>& group) 
{
    while(true)
    {
        Students student;
        string input;
        int sum = 0;
        int grade_count = 0;

        cout << "Jei norite, kad rezultatai butu išspausdinami, įveskite ';'" << endl;
        cout << "Įveskite vardą ir pavardę studento: ";
        cin >> student.first_name;

        if(student.first_name == ";") //chekinam ar nenori iseit is programos
        {
            cout << endl; return;
        }
        cin >> student.last_name;

        if(student.last_name == ";") //just in case apsiprende
        {
            cout << endl; return;
        }

        //cout << "Įveskite kiek semestro įvertinimų bus. ";
        //int grade_count = get_int(1, INT_MAX);
        //if(grade_count == -1)
        //    return;
        
        print_line();

        while(true)
        {
            int temp;
            cout << "Jei norite pereit į kitą studentą, įveskite ';'\n";
            cout << "Įveskite " << grade_count + 1 << " pažymį:  ";
            temp = get_int(0, 10);
            if(temp == -1) break;
            student.grade.push_back(temp);
            sum += temp;
            grade_count++;
        }

        print_line();
        cout << "Įveskite egzamino pažymį: "; 
        student.exam = get_int(0, 10);
        
        student.result = calc_result(sum, grade_count, student.exam);

        student.median = calc_median(student.exam, student.grade);

        group.push_back(student);
        student.grade.clear();
        print_line();
    // galima priskirti grupej, kai turime A.rez; pushbackinam studento pavadinima
    }
}

// Random-grade input mode (user supplies names)
void generate_grades_input(vector<Students>& group)
{
    while(true)
    {

        Students student;
        
        //name input as usual
        cout << "Jei norite, kad rezultatai butu išspausdinami, įveskite ';'" << endl;
        cout << "Įveskite vardą ir pavardę studento: ";
        cin >> student.first_name;
        cout << endl; 
        if(student.first_name == ";") //chekinam ar nenori iseit is programos
        {
            return;
        }
        cin >> student.last_name;

        if(student.last_name == ";") //just in case apsiprende
        {
            return;
        }

        //random grade generation 
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

        group.push_back(student);
        student.grade.clear();
    }
}

// Generate random names (from vardai/) then prompt for grades/exam
void generate_names_input(vector<Students>& group)
{
    while(true)
    {
        Students student;
        vector<string> full_name = random_name_generator();
        student.first_name = full_name[0];
        student.last_name = full_name[1];
        string input;
        int sum = 0;
        int grade_count = 0;

        cout << endl << "Studento vardas ir pavarde: " << student.first_name << " " << student.last_name << endl;
        //cout << endl << "Iveskite semestro ivertinimus. Kiek ju bus? ";
        //grade_count = get_int(1, INT_MAX);
       // if(grade_count == -1) return; //vistiek reik kazkaip su ; isspausdint
        print_line();


        //ivedimas pazymiu
        while(true)
        {
            int temp;
            cout << endl << "Jei norite, įvesti egzamino balą ir pereit prie kito studento, įveskite ';'" << endl;
            print_line();
            cout << "Įveskite " << grade_count + 1 << " pažymį: "; 
            temp = get_int(0, 10);
            if(temp == -1) break;
            student.grade.push_back(temp);
            sum += temp;
            grade_count++;
        }

        print_line();
        cout << "Iveskite egzamina: "; 
        student.exam = get_int(0, 10);
        print_line();

        student.result = calc_result(sum, grade_count, student.exam);

        student.median = calc_median(student.exam, student.grade);

        group.push_back(student);
        student.grade.clear();

        cout << "Jei norite, kad būtų, išvesti rezultatai, įveskite ';' " << endl;
        cout << "Jeigu norite pereiti prie kito studento, įveskite '1' ";
        int exit_option = get_int(1,1);
        if(exit_option == -1) return;
        print_line();
    }
}

// Read name lists from files under vardai/ and return a random first+last
vector<string> random_name_generator()
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
        first_name_file = "vardai/vyriski-vardai.txt";
        last_name_file = "vardai/vyriskos-pavardes.txt";
    }
    else
    {
        first_name_file = "vardai/moteriski-vardai.txt";
        last_name_file = "vardai/moteriskos-pavardes.txt";
    }

    
    std::ifstream file_first_names(first_name_file);
    std::ifstream file_last_names(last_name_file);

    if(!file_first_names)
    {
        std::cerr << "Error opening the male first names file" << endl;
        return {};
    }
    if(!file_last_names)
    {
        std::cerr << "Error opening the male last names file" << endl;
        return {};
    }

    while(std::getline(file_first_names, line))
    {
        v_first_names.push_back(line);
    }

    while(std::getline(file_last_names, line))
    {
        v_last_names.push_back(line);
    }

    int rand_index = rand() % v_first_names.size();
    full_name.push_back(v_first_names[rand_index]);

    rand_index = rand() % v_last_names.size();
    full_name.push_back(v_last_names[rand_index]);

    return full_name;       
    }

// Print results table: user chooses average (v) or median (m)
void output(vector<Students>& group) 
{
    //this func is for printing all names and result average OR median
    char print_option;
    while(true) //repromt user for wrong input
    {
        cout << endl;
        cout << "Įveskite 'v', jei norite vidurkio rezultatus pamatyti." << endl << "Įveskite 'm', jei norite medianos rezultatus pamatyti." << endl;
        cin >> print_option;
        std::tolower(print_option);

        if(print_option == 'v' || print_option == 'm') break;
        cout << "Tokio išvesties pasirinkimo nėra!" << endl;
    }
    
    switch (print_option)
    {
    case 'v':
        cout << endl;
        cout << left << setw(10) << "Vardas" << left << setw(20) << "Pavardė";
        cout << setw(10) << " Galutinis (Vid.)" << endl;
        print_line();
        for (auto student : group) 
        {
            cout << left << setw(10) << student.first_name << left << setw(20) << student.last_name;

            cout << setw(10) << std::fixed << std::setprecision(2) << student.result << endl;
        }
        break;
    
    case 'm':
        cout << endl;
        cout << left << setw(10) << "Vardas" << left << setw(20) << "Pavardė";
        cout << setw(10) << " Galutinis (Med.)" << endl;
        print_line();
        for (auto student : group) 
        {
            cout << left << setw(10) << student.first_name << left << setw(20) << student.last_name;

            cout << setw(10) << std::fixed << std::setprecision(2) <<" " << student.median << endl;
        }
        break;
    }     
}

// Compute weighted average: 40% homework + 60% exam
double calc_result(int sum, int n, int exam)
{
    return sum * 1.0 / (n * 1.0) * 0.4 + exam * 0.6;
}

// Compute median including exam (returns double)
double calc_median(int exam, vector<int>& grade)
{
    // create a copy that we can sort without modifying the caller's data
    vector <int> v;
    double median;

    for(int x : grade) 
    {
        v.push_back(x);
    }
    
    v.push_back(exam);
    sort(v.begin(), v.end());
    // choose median depending on odd/even size
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


// Read integer in [start..end]; returns -1 if user enters ';'
int get_int(int start, int end)
{
    string input;
    int temp;

     while(true) //check if input is for grade count is int
        {
            bool is_number = true;
            cin >> input;
            if(input == ";") return -1;
            for(auto i : input)
            {
                if(!std::isdigit(static_cast<unsigned char>(i)))
                {
                    if(end==INT_MAX) cout << "Įveskite naturalų skaičių nuo " << start << "! ";
                    else
                    {
                        cout << "Įveskite naturalų skaičių nuo " << start << " iki " << end << "! ";
                    }
                    is_number = false;
                    break;
                }
            }
            
            if(is_number)
                temp = stoi(input);
            if(temp < start  && is_number)
            {
                cout << "Įveskite naturalų skaičių daugiau už " << start - 1  << " ! " ;
            }
            else if(temp > end && is_number) 
            {
                cout << "Įveskite naturalų skaičių mažesnį už " << end + 1 << " ! ";
            }
            else if(temp <= end && temp >= start && is_number) break; //if conditions correct

        }
    return temp;
}

// get_int handles grade input; sentinel ';' returns -1

// Print a separator line
void print_line()
{
    cout << endl << "-----------------------------------------------" << endl;
}