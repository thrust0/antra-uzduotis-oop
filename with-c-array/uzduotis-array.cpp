#include <iomanip>
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

// Simple student grading tool
// - Reads or generates student names and grades
// - Calculates final score as average or median + exam weight
// - Prints results in a simple table
// Notes:
// - Program expects the "vardai/" folder to be present when generating names
// - Input validation functions ensure numeric input where required
/*

    naudojau AI komentaram, pats perziurejau ar jie teisingi

*/


// Student record holds name, a list of grades, exam score and computed results
struct Students 
{
    string first_name = "A", last_name = "BB";
    // dynamic container for homework/semester grades
    int* grade = nullptr;
    int grade_count = 0;
    // single exam score
    int exam;
    // cached computed final result (average-based) and median-based value
    double result, median;
};

constexpr char print_result = ';';
constexpr char print_median = ':';

// Function prototypes
// manual_input: prompt user to type names and grades
// generate_grades_input: prompt for names, randomly generate grades
// generate_names_input: generate random names and prompt for grades
// random_name_generator: picks two random strings from files under vardai/
// output: display the table using average or median as requested
// calc_result: compute weighted average (40% homework avg, 60% exam)
// calc_median: compute median including exam score
// get_positive_int / get_grade: validated numeric input helpers
// print_line: helper to print a separator line
void manual_input(Students*& group, int& size, int& capacity);
void generate_grades_input(Students*& group, int& size, int& capacity);
void generate_names_input(Students*& group, int& size, int& capacity);
// returns a pointer to a dynamic array of two strings: [first, last]
string* random_name_generator();
void output(Students* group, int size);
double calc_result(int sum, int n, int exam);
double calc_median(int exam, int* grade, int count);
int get_int(int start, int end);
void print_line();
void resize_group(Students*& group, int &capacity);

// Program entry point
// - initializes random seed
// - shows a simple menu to choose input mode
int main() 
{
    srand(time(0));
    for(int i = 0; i<6; i++) cout << endl;
    //allocatinam memory 
    int capacity = 10;
    int size = 0;
    Students* group = new Students[capacity];


    //intro vartotojui
    cout << "\tSveiki, čia yra vidurkio ir medianos iš pažymių skaičiuoklė" << endl << endl;
    cout << "Įveskite:\n\t'1' jei norite ranka suvesti pažymius\n\t'2' jei norite, kad pažymiai būtų sugeneruoti\n\t'3' jei norite, kad būtų sugeneruoti studentų vardai\n\t'4' jei norite išeiti iš programos\n\n";


    while(true)
    {
        int menu_option = get_int(1,4);

        if(menu_option == 1)
        {
            manual_input(group, size, capacity);
            break;
        }
        else if(menu_option == 2)
        {
            generate_grades_input(group, size, capacity);
            break;
        }
        else if(menu_option == 3)
        {
            generate_names_input(group, size, capacity);
            break;
        }
        else if(menu_option == 4)
        {
            cout << "Išeinama iš programos...\n";
            return 0;
        }
        else
        {
            cout << "Nėra tokio pasirinkimo!\n";
            cout << "Įveskite:\n\t'1' jei norite ranka suvesti pažymius\n\t'2' jei norite, kad pažymiai būtų sugeneruoti\n\t'3' jei norite, kad būtų sugeneruoti studentų vardai\n\t'4' jei norite išeiti iš programos\n\n";
        }
    }
    output(group, size);

    for(int i = 0; i < size; i++)
        delete[] group[i].grade;  // free each student's grade array
    delete[] group;

}

// Collect student data interactively from the user.
// Loop until the user enters the sentinel character (';') as a name.
void manual_input(Students*& group, int& size, int& capacity) 
{
    while(true)
    {
    Students student;
    string input;
    int sum = 0;
    cout << "Jei norite, kad rezultatai būtų išspausdinami, įveskite ';'" << endl;
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

    cout << "Įveskite kiek semestro įvertinimų bus. ";
        int grade_count = get_int(1,INT_MAX);
        student.grade = new int[grade_count];
        student.grade_count = grade_count;



        print_line();


        for (int i = 0; i < grade_count; i++)  //type in all the grades the student got
        {
            cout << "Įveskite " << i + 1 << " pažymį iš " << grade_count << ":";
            student.grade[i] = get_int(0,10);
            sum += student.grade[i];
        }
        print_line();
        cout << "Įveskite egzamino pažymį: "; 
        student.exam = get_int(0,10);
        
        student.result = calc_result(sum, grade_count, student.exam);

    student.median = calc_median(student.exam, student.grade, student.grade_count);

        if(size == capacity)
        {
            resize_group(group, capacity);
        }
        group[size++] = student;
        print_line();
    // galima priskirti grupej, kai turime A.rez; pushbackinam studento pavadinima
    }
}

// Generate random grades for students entered manually (keeps names entered by user)
// Useful for quick testing without typing many grades.
void generate_grades_input(Students*& group, int& size, int& capacity)
{
    while(true)
    {

        Students student;
        
    //name input as usual
    cout << "Jei norite, kad rezultatai būtų išspausdinami, įveskite ';'" << endl;
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
        student.grade = new int[grade_count];
        student.grade_count = grade_count;
        int sum = 0;
        for(int i = 0; i<grade_count; i++)
        {
            int temp = rand() % 10;
            student.grade[i] = temp;
            sum += temp;
            cout << '\t' << i+1 << " pažymys iš " << grade_count << ": " << temp << endl;
        }
        student.exam = rand() % 10 + 1;
        cout << "\tEgzamino pažymys: " << student.exam << endl << endl;

        student.result = calc_result(sum, grade_count, student.exam);

        student.median = calc_median(student.exam, student.grade, student.grade_count);
        if(size == capacity)
        {
            resize_group(group, capacity);
        }
        group[size++] = student;
    }
}

// Generate random full names (first + last) using the files under vardai/
// Then prompt the user for each generated student to input grades/exam.
void generate_names_input(Students*& group, int& size, int& capacity)
{
    //TODO
    while(true)
    {
    Students student;
    std::string* full_name = random_name_generator();
    student.first_name = full_name[0];
    student.last_name = full_name[1];
    delete[] full_name;
        string input;
        int grade_count, sum = 0;

    cout << endl << "Studento vardas ir pavardė: " << student.first_name << " " << student.last_name << endl;
    cout << "Jei norite, kad rezultatai būtų išvedami, įveskite ';'" << endl;
    cout << endl << "Įveskite semestro įvertinimus. Kiek jų bus? ";
    grade_count = get_int(1,INT_MAX);
    if(grade_count == -1) return; //vistiek reik kazkaip su ; isspausdint
        student.grade = new int[grade_count];
        student.grade_count = grade_count;

        print_line();

        //ivedimas pazymiu
        for (int i = 0; i < grade_count; i++) 
        {
            cout << "Įveskite " << i + 1 << " pažymį iš " << grade_count << ":";
            student.grade[i] = get_int(0,10);
            sum += student.grade[i];
        }
        print_line();
        cout << "Įveskite egzamino pažymį: "; 
        student.exam = get_int(0,10);
        print_line();

        student.result = calc_result(sum, grade_count, student.exam);

    student.median = calc_median(student.exam, student.grade, student.grade_count);

        if(size == capacity)
        {
            resize_group(group, capacity);
        }
        group[size++] = student;
    }
}

// Read first and last name files and return a randomly selected [first, last]
// Expects files under the relative folder "vardai/"
string* random_name_generator()
{
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

    // Count lines in each file to allocate arrays
    std::ifstream f1(first_name_file);
    std::ifstream f2(last_name_file);
    if(!f1 || !f2)
    {
        std::cerr << "Error opening name files" << endl;
        // return empty names array
        std::string* empty = new std::string[2];
        empty[0] = ""; empty[1] = "";
        return empty;
    }

    int count1 = 0;
    while(std::getline(f1, line)) ++count1;
    int count2 = 0;
    while(std::getline(f2, line)) ++count2;
    f1.clear(); f1.seekg(0);
    f2.clear(); f2.seekg(0);

    std::string* first_names = new std::string[count1 > 0 ? count1 : 1];
    std::string* last_names = new std::string[count2 > 0 ? count2 : 1];

    int idx = 0;
    while(std::getline(f1, line)) { first_names[idx++] = line; }
    idx = 0;
    while(std::getline(f2, line)) { last_names[idx++] = line; }

    int rand_index1 = (count1>0) ? rand() % count1 : 0;
    int rand_index2 = (count2>0) ? rand() % count2 : 0;

    std::string* full_name = new std::string[2];
    full_name[0] = first_names[rand_index1];
    full_name[1] = last_names[rand_index2];

    delete[] first_names;
    delete[] last_names;
    return full_name;
}

// Print the results table. User chooses whether to show averages (v) or medians (m).
void output(Students* group, int size) 
{
    // this func is for printing all names and result average OR median
    char print_option;
    while(true) // reprompt user for wrong input
    {
        cout << endl;
        cout << "Iveskite 'v', jei norite vidurkio rezultatus pamatyti." << endl << "Iveskite 'm', jei norite medianos rezultatus pamatyti." << endl;
        cin >> print_option;
        print_option = static_cast<char>(std::tolower(static_cast<unsigned char>(print_option)));

        if(print_option == 'v' || print_option == 'm') break;
        cout << "Tokio išvesties pasirinkimo nėra!" << endl;
    }

    switch (print_option)
    {
    case 'v':
        cout << endl;
        cout << left << setw(10) << "Vardas" << left << setw(20) << "Pavardė";
        cout << setw(12) << "Galutinis (Vid.)" << endl;
        print_line();
        for (int i = 0; i < size; ++i)
        {
            Students &student = group[i];
            cout << left << setw(10) << student.first_name << left << setw(20) << student.last_name;
            cout << right << std::fixed << std::setprecision(2) << setw(12) << student.result << endl;
        }
        break;

    case 'm':
        cout << endl;
        cout << left << setw(10) << "Vardas" << left << setw(20) << "Pavardė";
        cout << setw(12) << "Galutinis (Med.)" << endl;
        print_line();
        for (int i = 0; i < size; ++i)
        {
            Students &student = group[i];
            cout << left << setw(10) << student.first_name << left << setw(20) << student.last_name;
            cout << right << std::fixed << std::setprecision(2) << setw(12) << student.median << endl;
        }
        break;
    }
}

// Compute weighted average result: 40% homework average + 60% exam
double calc_result(int sum, int n, int exam)
{
    return sum * 1.0 / (n * 1.0) * 0.4 + exam * 0.6;
}

// Compute median including the exam score. Returns a double.
// The function copies the homework grades into a new vector, appends the exam
// score, sorts and returns the median value (average of two middle values when even count).
double calc_median(int exam, int* grade, int count)
{
    
    int total = count + 1;
    int* arr = new int[total];


    double median;

    for(int i = 0; i < count; i++)
    {
        arr[i] = grade[i];
    }
    arr[count] = exam;

   
    std::sort(arr, arr + total);
    // choose median depending on odd/even size
    if(total % 2 == 1) // odd
    {
        median = arr[total/2];
    
    }
    else // even
    {
        median = (arr[total/2 - 1] + arr[total/2]) / 2.0;
    }
    delete[] arr;
    return median;
}


// Read a positive integer from stdin. Returns 0 if the sentinel ';' is entered.
// Keeps prompting until a valid positive integer is entered.
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

// Read a single grade in the range [0..10] from stdin. Keeps prompting until valid.


// Small helper to print a visual separator line in output
void print_line()
{
    cout << endl << "-----------------------------------------------" << endl;
}

void resize_group(Students*& group, int &capacity)
{
    int new_capacity = capacity * 2;
    Students* temp = new Students[new_capacity]; //allocatinam daugiau memory

    for(int i = 0; i < capacity; i++) //atkopijuojam studentus i temp array
        temp[i] = group[i];

    delete[] group; //atlaisvinam sena array

    group = temp;
    capacity = new_capacity;
}