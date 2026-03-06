#include "uzduotis-headers.h"


void manual_input(std::vector<Students>& group) 
{
    while(true)
    {
        Students student;
        std::string input;
        int sum = 0;
        int grade_count = 0;

        std::cout << "Jei norite, kad rezultatai butu išspausdinami, įveskite ';'" << std::endl;
        std::cout << "Įveskite vardą ir pavardę studento: ";
        std::cin >> student.first_name;

        if(student.first_name == ";") //chekinam ar nenori iseit is programos
        {
            std::cout << std::endl; return;
        }
        std::cin >> student.last_name;

        if(student.last_name == ";") //just in case apsiprende
        {
            std::cout << std::endl; return;
        }

        //std::cout << "Įveskite kiek semestro įvertinimų bus. ";
        //int grade_count = get_int(1, INT_MAX);
        //if(grade_count == -1)
        //    return;
        
        print_line();

        while(true)
        {
            int temp;
            std::cout << "Jei norite pereit į kitą studentą, įveskite ';'\n";
            std::cout << "Įveskite " << grade_count + 1 << " pažymį:  ";
            temp = get_int(0, 10);
            if(temp == -1) break;
            student.grade.push_back(temp);
            sum += temp;
            grade_count++;
        }

        print_line();
        std::cout << "Įveskite egzamino pažymį: "; 
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
void generate_grades_input(std::vector<Students>& group)
{
    while(true)
    {

        Students student;
        
        //name input as usual
        std::cout << "Jei norite, kad rezultatai butu išspausdinami, įveskite ';'" << std::endl;
        std::cout << "Įveskite vardą ir pavardę studento: ";
        std::cin >> student.first_name;
        std::cout << std::endl; 
        if(student.first_name == ";") //chekinam ar nenori iseit is programos
        {
            return;
        }
        std::cin >> student.last_name;

        if(student.last_name == ";") //just in case apsiprende
        {
            return;
        }

        //random grade generation 
        random_grades_generator(student);
        //append the vector
        group.push_back(student);
        student.grade.clear();
    }
}


// Generate random names (from vardai/) then prompt for grades/exam
void generate_names_input(std::vector<Students>& group)

{
    while(true)
    {
        Students student;
        std::vector<std::string> full_name = random_name_generator();
        student.first_name = full_name[0];
        student.last_name = full_name[1];
        std::string input;
        int sum = 0;
        int grade_count = 0;

        std::cout << std::endl << "Studento vardas ir pavarde: " << student.first_name << " " << student.last_name << std::endl;
        print_line();

        random_grades_generator(student);

        group.push_back(student);
        student.grade.clear();

        std::cout << "Jei norite, kad būtų, išvesti rezultatai, įveskite ';' " << std::endl;
        std::cout << "Jeigu norite pereiti prie kito studento, įveskite '1' ";
        int exit_option = get_int(1,1);
        if(exit_option == -1) return;
        print_line();
    }
}

void file_input(std::vector<Students>& group, const std::string& filename)
{
    std::ifstream file(filename); //open file

    if(!file) //check if file opened
    {
        std::cerr << "Neišėjo atidaryti failo " << filename <<std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); //skip header

    while(std::getline(file, line))
    {
        std::stringstream ss(line); //stringstream
        Students student;
        ss >> student.first_name >> student.last_name; 
        
        //idedam i streama kiekviena grade
        int grade;
        int sum = 0;
        int grade_count = 0;
        while (ss >> grade)
        {
            sum += grade;
            student.grade.push_back(grade);
            grade_count++;
        }

        if(!student.grade.empty())//pachekinam kad turetu grade kad nebutu runtime error, nes negalim poppint tuscio vector element
        {
            student.exam = student.grade.back();//last elemnt of grades is put into exam grade
            student.grade.pop_back();//the element from vector grade is taken out since its exam
        }
        grade_count--;
        sum = sum - student.exam;
        student.result = calc_result(sum, grade_count, student.exam);
        student.median = calc_median(student.exam, student.grade);

        group.push_back(student);
    }
    file.close();
}

void random_grades_generator(Students& student)
{
    int grade_count = rand() % 10 + 1; //kad butu nuo 1-10 o ne 0-11
    int sum = 0;
    for(int i = 0; i<grade_count; i++)
    {
        int temp = rand() % 10;
        student.grade.push_back(temp);
        sum += temp;
        std::cout << '\t' << i+1 << " pažymys iš " << grade_count << ": " << temp << std::endl;
    }

    student.exam = rand() % 10;
    std::cout << "\tEgzamino pažymys: " << student.exam << std::endl << std::endl;

    student.result = calc_result(sum, grade_count, student.exam);

    student.median = calc_median(student.exam, student.grade);
}

// Read name lists from files under vardai/ and return a random first+last
std::vector<std::string> random_name_generator()
{
    std::vector<std::string> v_first_names;
    std::vector<std::string> v_last_names;
    std::vector<std::string> full_name;
    std::string first_name_file;
    std::string last_name_file;
    std::string line;
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

    
    std::ifstream file_first_names(first_name_file);
    std::ifstream file_last_names(last_name_file);

    if(!file_first_names)
    {
        std::cerr << "Error opening the male first names file" << std::endl;
        return {};
    }
    if(!file_last_names)
    {
        std::cerr << "Error opening the male last names file" << std::endl;
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
void output(std::vector<Students>& group) 
{
    print_line();
    //this func is for printing all names and result average OR median
    char print_option;
    while(true) //repromt user for wrong input
    {
        std::cout << std::endl;
        std::cout << "Įveskite 'v', jei norite vidurkio rezultatus pamatyti." << std::endl << "Įveskite 'm', jei norite medianos rezultatus pamatyti." << std::endl;
        std::cin >> print_option;
        std::tolower(print_option);

        if(print_option == 'v' || print_option == 'm') break;
        std::cout << "Tokio išvesties pasirinkimo nėra!" << std::endl;
    }
    
    switch (print_option)
    {
    case 'v':
        std::cout << std::endl;
        std::cout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavardė";
        std::cout << std::setw(20) << " Galutinis (Vid.)" << std::endl;
        print_line();
        for (auto student : group) 
        {
            std::cout << std::left << std::setw(20) << student.first_name << std::left << std::setw(20) << student.last_name;

            std::cout << std::setw(20) << std::fixed << std::setprecision(2) << student.result << std::endl;
        }
        break;
    
    case 'm':
        std::cout << std::endl;
        std::cout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavardė";
        std::cout << std::setw(20) << " Galutinis (Med.)" << std::endl;
        print_line();
        for (auto student : group) 
        {
            std::cout << std::left << std::setw(20) << student.first_name << std::left << std::setw(20) << student.last_name;

            std::cout << std::setw(20) << std::fixed << std::setprecision(2) << student.median << std::endl;
        }
        break;
    }     
}

void file_output(std::vector<Students>& group)
{
    std::ofstream outFile("StudentOuput.txt");

    if(!outFile)
    {
        std::cerr << "Klaida atidarinėjant failą įrašymui..." << std::endl;
        return;
    }

    outFile << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavardė";
    outFile << std::setw(20) << " Galutinis (Vid.)";
    outFile << std::setw(20) << " Galutinis (Med.)" << std::endl;
    for(int i = 0; i<76; i++)
        outFile << "-";
    outFile << std::endl;

    for (auto student : group) 
    {
        outFile << std::left << std::setw(20) << student.first_name << std::left << std::setw(20) << student.last_name;
        outFile << std::left << std::setw(20) << std::fixed << std::setprecision(2) << student.result;
        outFile << std::left << std::setw(20) << std::fixed << std::setprecision(2) << student.median << std::endl;
    }
    
}

void temp_output(std::vector<Students>& group)
{
    print_line();
    std::cout << std::endl;
    std::cout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavardė";
    std::cout << std::setw(20) << " Galutinis (Vid.)";
    std::cout << std::setw(20) << " Galutinis (Med.)";
    print_line();
    for (auto student : group) 
    {
        std::cout << std::left << std::setw(20) << student.first_name << std::left << std::setw(20) << student.last_name;
        std::cout << std::left << std::setw(20) << std::fixed << std::setprecision(2) << student.result;
        std::cout << std::left << std::setw(20) << std::fixed << std::setprecision(2) << student.median << std::endl;
    }

}

// Compute weighted average: 40% homework + 60% exam
double calc_result(int sum, int n, int exam)
{
    return sum * 1.0 / (n * 1.0) * 0.4 + exam * 0.6;
}

// Compute median including exam (returns double)
double calc_median(int exam, std::vector<int>& grade)
{
    // create a copy that we can sort without modifying the caller's data
    std::vector <int> v;
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
    std::string input;
    int temp;

     while(true) //check if input is for grade count is int
        {
            bool is_number = true;
            std::cin >> input;
            if(input == ";") return -1;
            for(auto i : input)
            {
                if(!std::isdigit(static_cast<unsigned char>(i)))
                {
                    if(end==INT_MAX) throw std::invalid_argument("Įveskite naturalų skaičių nuo");
                    else
                    {
                        throw std::invalid_argument("Įveskite naturalų skaičių nuo " +
                        std::to_string(start) + "iki " + std::to_string(end) + "!");
                        //std::cout << "Įveskite naturalų skaičių nuo " << start << " iki " << end << "! "; perasiau su throw exception
                    }
                    is_number = false;
                    break;
                }
            }
            
            if(is_number)
                temp = stoi(input);
            if(temp < start  && is_number)
            {
                throw std::invalid_argument("Įveskite naturalų skaičių daugiau už " + std::to_string(start-1) + "!");
                //std::cout << "Įveskite naturalų skaičių daugiau už " << start - 1  << " ! " ;
            }
            else if(temp > end && is_number) 
            {
                throw std::invalid_argument("Įveskite naturalų skaičių mažesnį už " + std::to_string(end+1) + "!");
                //std::cout << "Įveskite naturalų skaičių mažesnį už " << end + 1 << " ! ";
            }
            else if(temp <= end && temp >= start && is_number) break; //if conditions correct

        }
    return temp;
}

// get_int handles grade input; sentinel ';' returns -1

// Print a separator line
void print_line()
{
    std::cout << std::endl << "----------------------------------------------------------------------------" << std::endl;
}

void sort_output(std::vector<Students>& group, int sort_option)
{ 
    if(sort_option == 1)
    {
        //sort by first names
        std::sort(group.begin(), group.end(), 
        [](const Students&a, const Students&b){ 
            return a.first_name < b.first_name;
        });
        
    }
    else if(sort_option == 2)
    {
        //sort by last names
        std::sort(group.begin(), group.end(), 
        [](const Students&a, const Students&b){ 
            return a.last_name < b.last_name;
        });
    }
    else if(sort_option == 3)
    {
        //sort by grade avg
        std::sort(group.begin(), group.end(), 
        [](const Students&a, const Students&b){ 
            return a.result > b.result;
        });

    }
    else
    {
        //sort by median
    std::sort(group.begin(), group.end(), 
        [](const Students&a, const Students&b){ 
            return a.median > b.median;
        });
    }
}