#include <iomanip>
#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include <random>
#include <ctime>


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
void random_name_generator();
void output(vector<Students>& group);

double calc_result(int sum, int n, int exam);
double calc_median(int exam, vector<int>& grade);

int main() 
{
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
        }
    }
    output(group);

}

void manual_input(vector<Students>& group) 
{
    while(true)
    {
        Students student;
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
        int grade_count, sum = 0;
        cin >> grade_count;

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
        srand(time(0));
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
        random_name_generator();
    }
}

void random_name_generator()
{

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