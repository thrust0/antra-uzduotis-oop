#include "menu.h"
#include "student.hpp"

/**
 * @brief Interactive manual input mode.
 *
 * Prompts the user for a student's first/last name, homework grades and exam
 * grade. The constructed Students object is appended to the provided group.
 * Entering a single semicolon (';') in the name input will stop input mode.
 * @param group Vector to append created Students objects to.
 */
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
            if(temp == -1) break; ///< ';' returns -1 to indicate end of grades
            student.add_grade(temp);
        }

        print_line();
        cout << "Įveskite egzamino pažymį: "; 
        int exam = get_int(0, 10);
        student.set_exam(exam);
        
        // ensure derived cached values are computed
        student.set_result();
        student.set_median();

        group.push_back(std::move(student));
        print_line();
    }
}

/**
 * @brief Random grade generator for an entered student name.
 *
 * The user supplies a name; homework grades are generated randomly and
 * appended to the group.
 */
void generate_grades_input(vector<Students>& group)
{
    while(true)
    {   
        Students student;
        string first, last;
    // name input as usual
        cout << "Jei norite, kad rezultatai butu išspausdinami, įveskite ';'" << endl;
        cout << "Įveskite vardą ir pavardę studento: ";
        
        cin >> first;
        if(first == ";") return;
        student.set_first_name(first);


        cin >> last;
        if(last == ";") return;
        student.set_last_name(last);

        // random grade generation
        student.set_random_grades();
        // append the vector
        group.push_back(student);
    }
}
/**
 * @brief Generate random student names (from name files) and prompt for
 * grades/exam as in interactive mode.
 */
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

/**
 * @brief Read students from a text file and append them to group.
 *
 * The file is expected to contain one student record per line compatible
 * with Students::read_students(). The first line is treated as a header
 * and skipped.
 * @param group Vector to append parsed students to.
 * @param filename Input file path.
 * @throws runtime_error if the file cannot be opened.
 */
void file_input(vector<Students>& group, const string& filename)
{
    ifstream file(filename); ///< open file
    if(!file) ///< check if file opened
    {
        throw runtime_error("Neišėjo atidaryti failo ");
        return;
    }

    string line;
    getline(file, line); // skip header

    Students student;
    while(file >> student)
    {
        group.push_back(std::move(student));
    }
}

/**
 * @brief Print students to the terminal, letting the user choose average or median.
 * @param group Students to display.
 */
void terminal_output(vector<Students>& group)
{
    print_line();
    // this func is for printing all names and result average OR median
    char print_option;
    while(true) // reprompt user for wrong input
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

/**
 * @brief Write students to a formatted file using Students::operator<<.
 * @param group Students to write.
 * @param filename Destination file path.
 */
void file_output(const vector<Students>& group, const string filename)
{
    ofstream outFile(filename);

    if(!outFile) { cerr << "Klaida įrašyme..." << endl; return;}

    // header
    outFile << left << setw(20) << "Vardas" << left << setw(20) << "Pavardė";
    outFile << setw(20) << " Galutinis (Vid.)";
    outFile << setw(20) << " Galutinis (Med.)" << endl;
    for(int i = 0; i<76; i++)
        outFile << "-";
    outFile << endl;

    for (const auto& student : group)
        outFile << student;
}

/**
 * @brief Print both average and median table to terminal.
 */
void temp_output(vector<Students>& group)
{
    print_line();
    cout << endl;
    cout << left << setw(20) << "Vardas" << left << setw(20) << "Pavardė";
    cout << setw(20) << " Galutinis (Vid.)";
    cout << setw(20) << " Galutinis (Med.)";
    print_line();
    for (auto student : group)
        student.print();
}

/**
 * @brief Sort the group according to sort_option.
 * @param group Vector to sort in-place.
 * @param sort_option 1=first name, 2=last name, 3=result, otherwise median
 */
void sort_output(vector<Students>& group, int sort_option)
{ 
    if(sort_option == 1)
    {
        // sort by first names
        sort(group.begin(), group.end(), compare_by_first_name);
    }
    else if(sort_option == 2)
    {
        // sort by last names
        sort(group.begin(), group.end(), compare_by_last_name);
    }
    else if(sort_option == 3)
    {
        // sort by grade avg
        sort(group.begin(), group.end(), compare_by_result);

    }
    else
    {
        // sort by median
        sort(group.begin(), group.end(), compare_by_median);
    }
}

/**
 * @brief Move students into above_five or below_five according to result().
 */
void split_students_by_grades(vector<Students>& group,vector<Students>& above_five, vector<Students>& below_five)
{
    for(auto& student : group) // avoid copying with reference
    {
        if(student.result() < 5)
            below_five.push_back(std::move(student)); // move to avoid copy
        else
            above_five.push_back(std::move(student));
    }
    group.clear(); // source container is emptied but retains capacity
}

/**
 * @brief Strategy two for splitting: assume group is sorted by result and pop back
 * until remaining element has result() >= 5.
 */
void split_strategy_two(vector<Students>& group, vector<Students>& below_five)
{
    while(group.back().result() < 5)
    {
        below_five.push_back(group.back());
        group.pop_back();
    }
}

/**
 * @brief Partition-based split: moves students with result()<5 to below_five.
 */
void split_strategy_three(vector<Students> & group, vector<Students>& below_five)
{
    // std::partition groups elements with predicate true first
    auto it = std::partition(group.begin(), group.end(),
        [](const Students& s) {return s.result() >= 5; });

    // copy poor-performing students to below_five and erase them from group
    below_five.assign(it, group.end());

    group.erase(it, group.end());
}


/**
 * @brief Generate a synthetic student input file with randomized grades.
 * @param student_amount Number of student rows to produce.
 * @param grade_amount Number of homework grades per student (exam added automatically).
 * @return The path to the created file or empty string on failure.
 */
string generate_raw_student_file(int student_amount, int grade_amount)
{
    ostringstream filename;
    filename << "../studentInput/studentai_gen" << student_amount << ".txt";
    
    ofstream outFile(filename.str());
    
    if(!outFile)
    {
        cerr << "Klaida atidarinėjant failą įrašymui..." << endl;
        return ""; // return empty string for failure
    }
    outFile << left << setw(20) << "Vardas" << left << setw(20) << "Pavardė";

    for(int j = 0; j < grade_amount; j++)
    {
        outFile << left << setw(7) << ("ND" + to_string(j+1));
    }
    outFile << left << setw(7) << "Egz" << endl;

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
    // no explicit close required — destructor will flush the file
    return filename.str(); // usable with file_input(filename)
}



/**
 * @brief Read an integer in [start..end] from stdin; returns -1 on ';'.
 *
 * This helper validates user input and provides friendly error messages.
 */
int get_int(int start, int end)
{
    while(true) // check if input is for grade count is int
        try // check if input is for grade count is int
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
            }
            else if(temp > end && is_number) 
            {
                throw invalid_argument("Įveskite naturalų skaičių mažesnį už " + to_string(end+1) + "!");
            }
            else if(temp <= end && temp >= start && is_number) return temp; // if conditions correct
        }
    
        catch(const invalid_argument& e)
        {
            cerr << "Įvedimo klaida: " << e.what() << endl;
            cout << "Bandykite dar kartą: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
}


/** @brief Print a decorative separator line. */
void print_line()
{
    cout << endl << "----------------------------------------------------------------------------" << endl;
}

