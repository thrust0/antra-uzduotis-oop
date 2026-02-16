#include <iomanip>
#include <vector>
#include <iostream>
#include <string>
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


struct Students 
{
    string first_name = "A", last_name = "BB";
    //int *paz jei dinaminis masyvas
    vector <int> grade;
    int exam;
    double result, median;
};

constexpr char print_result = ';';
constexpr char print_median = ':';

void manual_input(vector<Students>& group);
void generate_grades_input(vector<Students>& group);
void generate_names_input(vector<Students>& group);
vector <string> random_name_generator();
void output(vector<Students>& group);
double calc_result(int sum, int n, int exam);
double calc_median(int exam, vector<int>& grade);
int get_positive_int();

int main() 
{
    srand(time(0));
    for(int i = 0; i<6; i++) cout << endl;
    vector<Students>group;

    //intro vartotojui
    cout << "\tSveiki, čia yra vidurkio ir medianos iš pažymių skaičiuoklė" << endl << endl;
    cout << "Iveskite:\n\t'1' jei norite ranka suvesti pazymius\n\t'2' jei norite, kad pazymiai butu sugeneruoti\n\t'3' jei norite, kad butu sugeneruoti studentu vardai\n\t'4' jei norite iseiti is programos\n\n";

    int menu_option;

    while(true)
    {
        cin >> menu_option;

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
            cout << "Iseinama is programos...\n";
            return 0;
        }
        else
        {
            cout << "Nera tokio pasirinkimo\n";
            return 1;
        }
    }
    output(group);

}

void manual_input(vector<Students>& group) 
{
    while(true)
    {
        Students student;
        string input;
        int sum = 0;
        cout << "Jei norite, kad rezultatai butu isspausdinami, iveskite ';'" << endl;
        cout << "Iveskite varda ir pavarde studento: ";
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

        cout << "Iveskite semestro ivertinimus. Kiek ju bus? ";
        int grade_count = get_positive_int();

        for (int i = 0; i < grade_count; i++)  //type in all the grades the student got
        {
            int temp;
            cout << "Iveskite " << i + 1 << " pazymi is " << grade_count << ":";
            cin >> temp;
            student.grade.push_back(temp);
            sum += temp;
        }
        cout << "Iveskite egzamina: "; 
        cin >> student.exam;
        
        student.result = calc_result(sum, grade_count, student.exam);

        student.median = calc_median(student.exam, student.grade);

        group.push_back(student);
        student.grade.clear();
    // galima priskirti grupej, kai turime A.rez; pushbackinam studento pavadinima
    }
}

void generate_grades_input(vector<Students>& group)
{
//TODO
    while(true)
    {

        Students student;
        
        //name input as usual
        cout << "Jei norite, kad rezultatai butu isspausdinami, iveskite ';'" << endl;
        cout << "Iveskite varda ir pavarde studento: ";
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
            int temp = rand() % 10 + 1;
            student.grade.push_back(temp);
            sum += temp;
            cout << '\t' << i+1 << " pazymys is " << grade_count << ": " << temp << endl;
        }
        student.exam = rand() % 10 + 1;
        cout << "\tEgzamino pazymys: " << student.exam << endl << endl;

        student.result = calc_result(sum, grade_count, student.exam);

        student.median = calc_median(student.exam, student.grade);

        group.push_back(student);
        student.grade.clear();
    }
}

void generate_names_input(vector<Students>& group)
{
    //TODO
    while(true)
    {
        Students student;
        vector<string> full_name = random_name_generator();
        student.first_name = full_name[0];
        student.last_name = full_name[1];
        string input;
        int grade_count, sum = 0;

        cout << endl << "Studento vardas ir pavarde: " << student.first_name << " " << student.last_name << endl;
        cout << "Jei norite, kad rezultatai butu isvedami, iveskite ';'" << endl;
        cout << endl << "Iveskite semestro ivertinimus. Kiek ju bus? ";
        grade_count = get_positive_int();
        if(grade_count == 0) return; //vistiek reik kazkaip su ; isspausdint


        //ivedimas pazymiu
        for (int i = 0; i < grade_count; i++) 
        {
            int temp;
            cout << "Iveskite " << i + 1 << " pazymi is " << grade_count << ":";
            cin >> temp;
            student.grade.push_back(temp);
            sum += temp;
        }
        cout << "Iveskite egzamina: "; 
        cin >> student.exam;
        
        student.result = calc_result(sum, grade_count, student.exam);

        student.median = calc_median(student.exam, student.grade);

        group.push_back(student);
        student.grade.clear();
    }
}

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

void output(vector<Students>& group) 
{
    //this func is for printing all names and result average OR median
    char print_option;
    while(true) //repromt user for wrong input
    {
        cout << endl;
        cout << "Iveskite 'v', jei norite vidurkio rezultatus pamatyti." << endl << "Iveskite 'm', jei norite medianos rezultatus pamatyti." << endl;
        cin >> print_option;
        std::tolower(print_option);

        if(print_option == 'v' || print_option == 'm') break;
        cout << "Tokio išvesties pasirinkimo nėra!" << endl;
    }
    
    switch (print_option)
    {
    case 'v':
        cout << left << setw(10) << "Vardas" << left << setw(20) << "Pavardė";
        cout << setw(10) << " Galutinis (Vid.)" << endl;
        cout << "-----------------------------------------------" << endl;
        for (auto student : group) 
        {
            cout << left << setw(10) << student.first_name << left << setw(20) << student.last_name;

            cout << setw(10) << std::setprecision(3) << student.result << endl;
        }
        break;
    
    case 'm':
        cout << left << setw(10) << "Vardas" << left << setw(20) << "Pavardė";
        cout << setw(10) << " Galutinis (Med.)" << endl;
        cout << "---------------------------------------------------------------" << endl;
        for (auto student : group) 
        {
            cout << left << setw(10) << student.first_name << left << setw(20) << student.last_name;

            cout << setw(10) << std::setprecision(3) <<" " << student.median << endl;
        }
        break;
    }     
}

double calc_result(int sum, int n, int exam)
{
    return sum * 1.0 / (n * 1.0) * 0.4 + exam * 0.6;
}

double calc_median(int exam, vector<int>& grade)
{
    //sukuriam nauja vectoriu nes isrusiuosim jo values rast meadiana
    vector <int> v;
    double median;

    for(int x : grade) 
    {
        v.push_back(x);
        //cout << x << endl;
    }
    
    v.push_back(exam);
    sort(v.begin(), v.end());
    //du skirtingi budai rast mediana, priklauso ar medianos elementu skaicius lyginis ar nelyginis
    if(v.size() % 2 == 1) //jeigu nelyginis
    {
        median = v[v.size()/2]; 
        return median;
    }
    else //jeigu lyginis
    {
        median = (v[(v.size()-1)/2] + v[(v.size()/2)]);
        return median/2;
    }
}


int get_positive_int()
{
    string input;
    int grade_count = 0;
     while(true) //check if input is for grade count is int and more than 0
        {
            bool check = true;
            cin >> input;
            if(input == ";") return 0;
            for(auto i : input)
            {
                if(!std::isdigit(i))
                {
                    cout << "Iveskite sveikaji skaiciu! ";
                    check = false;
                    break;
                }
            }
            
            if(check)
                grade_count = stoi(input);
            if(grade_count <= 0 && check)
            {
                cout << "Iveskite sveikaji skaiciu daugiau uz 0! " ;
            }
            else if(grade_count > 0 && check) break;
        }
    return grade_count;
}