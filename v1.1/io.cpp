#include "menu.h"
#include "student.hpp"

//ivedame vardus, pavardes, pazymius, egzamina
void manual_input(vector<Students>& group) 
{
    while(true)
    {
        Students student;
        string first, last;
        int grade_count = 0;

        cout << "Jei norite, kad rezultatai butu išspausdinami, įveskite ';'" << endl;
        cout << "Įveskite vardą ir pavardę studento: ";

        cin >> first;
        if(first == ";") { cout << endl; return; }
        student.set_first_name(first);

        cin >> last;
        if(last == ";") { cout << endl; return; }
        student.set_last_name(last);

        print_line();

        while(true)
        {
            int temp;
            cout << "Jei norite pereit į kitą studentą, įveskite ';'\n";
            cout << "Įveskite " << grade_count + 1 << " pažymį:  ";
            temp = get_int(0, 10);
            if(temp == -1) break; //leave it since ';' returns -1 to exit
            student.add_grade(temp);
        }

        print_line();
        cout << "Įveskite egzamino pažymį: "; 
        int exam = get_int(0, 10);
        student.set_exam(exam);
        
        student.set_result();
        student.set_median();

        group.push_back(student);
        print_line();
    }
}

// Random-grade input mode (user supplies names)
void generate_grades_input(vector<Students>& group)
{
    while(true)
    {   
        Students student;
        string first, last;
        //name input as usual
        cout << "Jei norite, kad rezultatai butu išspausdinami, įveskite ';'" << endl;
        cout << "Įveskite vardą ir pavardę studento: ";
        
        cin >> first;
        if(first == ";") return;
        student.set_first_name(first);


        cin >> last;
        if(last == ";") return;
        student.set_last_name(last);

        //random grade generation 
        student.set_random_grades();
        //append the vector
        group.push_back(student);
    }
}


// Generate random names (from vardai/) then prompt for grades/exam
void generate_names_input(vector<Students>& group)
{
    while(true)
    {
        Students student;
        student.set_random_name();
        group.push_back(student);

        print_line();
        cout << "Jei norite, kad būtų, išvesti rezultatai, įveskite ';' " << endl;
        cout << "Jeigu norite pereiti prie kito studento, įveskite '1' ";
        int exit_option = get_int(1,1);
        if(exit_option == -1) return;
        print_line();
    }
}

void file_input(vector<Students>& group, const string& filename)
{
    ifstream file(filename); //open file
    if(!file) //check if file opened
    {
        throw runtime_error("Neišėjo atidaryti failo ");
        //cerr << "Neišėjo atidaryti failo " << filename <<endl;
        return;
    }

    string line;
    getline(file, line); //skip header

    while(getline(file, line))
    {
        stringstream ss(line);
        Students student(ss);
        group.push_back(student);
    }
    file.close();
}

// Print results table: user chooses average (v) or median (m)
void terminal_output(vector<Students>& group) 
{
    print_line();
    //this func is for printing all names and result average OR median
    char print_option;
    while(true) //repromt user for wrong input
    {
        cout << endl;
        cout << "Įveskite 'v', jei norite vidurkio rezultatus pamatyti." << endl << "Įveskite 'm', jei norite medianos rezultatus pamatyti." << endl;
        cin >> print_option;
        tolower(print_option);

        if(print_option == 'v' || print_option == 'm') break;
        cout << "Tokio išvesties pasirinkimo nėra!" << endl;
    }
    
    switch (print_option)
    {
    case 'v':
        cout << endl;
        cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavardė";
        cout << setw(20) << " Galutinis (Vid.)" << endl;
        print_line();
        for (auto student : group) 
        {
            cout << left << setw(20) << student.first_name() << left << setw(20) << student.last_name();

            cout << setw(20) << fixed << setprecision(2) << student.result() << endl;
        }
        break;
    
    case 'm':
        cout << endl;
        cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavardė";
        cout << setw(20) << " Galutinis (Med.)" << endl;
        print_line();
        for (auto student : group) 
        {
            cout << left << setw(20) << student.first_name() << left << setw(20) << student.last_name();

            cout << setw(20) << fixed << setprecision(2) << student.median() << endl;
        }
        break;
    }     
}

void file_output(vector<Students>& group, string filename)
{
    ofstream outFile(filename);

        if(!outFile)
        {
            cerr << "Klaida atidarinėjant failą įrašymui..." << endl;
            return;
        }

        outFile << left << setw(20) << "Vardas" << left << setw(20) << "Pavardė";
        outFile << setw(20) << " Galutinis (Vid.)";
        outFile << setw(20) << " Galutinis (Med.)" << endl;
        for(int i = 0; i<76; i++)
            outFile << "-";
        outFile << endl;

        for (auto student : group) 
        {
            outFile << left << setw(20) << student.first_name() << left << setw(20) << student.last_name();
            outFile << left << setw(20) << fixed << setprecision(2) << student.result();
            outFile << left << setw(20) << fixed << setprecision(2) << student.median() << endl;
        }
    
    
}

void temp_output(vector<Students>& group)
{
    print_line();
    cout << endl;
    cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavardė";
    cout << setw(20) << " Galutinis (Vid.)";
    cout << setw(20) << " Galutinis (Med.)";
    print_line();
    for (auto student : group) 
    {
        cout << left << setw(20) << student.first_name() << left << setw(20) << student.last_name();
        cout << left << setw(20) << fixed << setprecision(2) << student.result();
        cout << left << setw(20) << fixed << setprecision(2) << student.median() << endl;
    }

}



// Read integer in [start..end]; returns -1 if user enters ';'


void sort_output(vector<Students>& group, int sort_option)
{ 
    if(sort_option == 1)
    {
        //sort by first names
        sort(group.begin(), group.end(), 
        [](const Students&a, const Students&b){ 
            return a.first_name < b.first_name;
        });
        
    }
    else if(sort_option == 2)
    {
        //sort by last names
        sort(group.begin(), group.end(), 
        [](const Students&a, const Students&b){ 
            return a.last_name < b.last_name;
        });
    }
    else if(sort_option == 3)
    {
        //sort by grade avg
        sort(group.begin(), group.end(), 
        [](const Students&a, const Students&b){ 
            return a.result > b.result;
        });

    }
    else
    {
        //sort by median
    sort(group.begin(), group.end(), 
        [](const Students&a, const Students&b){ 
            return a.median > b.median;
        });
    }
}

void split_students_by_grades(vector<Students>& group, vector<Students>& below_five)
{
    while(group.back().get_result() < 5)
    {
        below_five.push_back(group.back());
        group.pop_back();
    }
}

string generate_raw_student_file(int student_amount, int grade_amount)
{
    ostringstream filename;
    filename << "../../studentInput/studentai_gen" << student_amount << ".txt";
    
    ofstream outFile(filename.str());
    
    if(!outFile)
    {
        cerr << "Klaida atidarinėjant failą įrašymui..." << endl;
        return ""; //return empty string for failure
    }
    outFile << left << setw(20) << "Vardas" << left << setw(20) << "Pavardė";

    for(int j = 0; j < grade_amount; j++)
    {
        outFile << left << setw(7) << ("ND" + to_string(j+1));
    }
    outFile << left <<setw(7) << "Egz" << endl;

    for(int i = 0; i<student_amount; i++)
    {
        outFile << left << setw(20) 
        << ("Vardas" + to_string(i+1)) 
        << left 
        << setw(20) << ("Pavarde" + to_string(i+1));

        for(int i = 0; i<grade_amount+1; i++)
        {
            int grade = rand() % 10 + 1;
            outFile << left << setw(7) << grade;
        }
        outFile << endl;
    }
    //nereikia outFile.close() nes kai ofstream iseina is scope, automatiskai destructorius pacall'intas
    return filename.str(); //reiks file_input(filename)
}



// Read integer in [start..end]; returns -1 if user enters ';'
int get_int(int start, int end)
{
    while(true) //check if input is for grade count is int{
        try //check if input is for grade count is int
        {
            string input;
            int temp = 0;
            bool is_number = true;
            cin >> input;
            if(input == ";") return -1;
            for(auto i : input)
            {
                if(!isdigit(static_cast<unsigned char>(i)))
                {
                    if(end==INT_MAX) throw invalid_argument("Įveskite naturalų skaičių nuo");
                    else
                    {
                        throw invalid_argument("Įveskite naturalų skaičių nuo " +
                        to_string(start) + " iki " + to_string(end) + "!");
                        //cout << "Įveskite naturalų skaičių nuo " << start << " iki " << end << "! "; perasiau su throw exception
                    }
                    is_number = false;
                    break;
                }
            }
            
            if(is_number)
                temp = stoi(input);
            if(temp < start  && is_number)
            {
                throw invalid_argument("Įveskite naturalų skaičių daugiau už " + to_string(start-1) + "!");
                //cout << "Įveskite naturalų skaičių daugiau už " << start - 1  << " ! " ;
            }
            else if(temp > end && is_number) 
            {
                throw invalid_argument("Įveskite naturalų skaičių mažesnį už " + to_string(end+1) + "!");
                //cout << "Įveskite naturalų skaičių mažesnį už " << end + 1 << " ! ";
            }
            else if(temp <= end && temp >= start && is_number) return temp; //if conditions correct
        }
    
        catch(const invalid_argument& e)
        {
            cerr << "Įvedimo klaida: " << e.what() << endl;
            cout << "Bandykite dar kartą: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
}


void print_line()
{
    cout << endl << "----------------------------------------------------------------------------" << endl;
}

