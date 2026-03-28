#include "menu.h"

void menu(){
    srand(time(0));
    vector<Students>group;
    vector<Students> above_five;
    vector<Students> below_five;

    int menu_option = 0;
    int sort_option = 0;
    int output_option = 0;
    int split_option = 0;

    //empty lines to creat up the terminal lil bit
    for(int i = 0; i<6; i++) cout << endl;

    intro_text();
    input_method(group, menu_option);
    if(menu_option == 6) return; //exit program

    print_line();

    //choose how to sort the students
    sort_method(group, sort_option);
    print_line();

    //choose where to ouput 1 terminal 2 txt file 3 two txt files
    output_method(group,above_five, below_five, menu_option, output_option, split_option, sort_option);
}

void intro_text()
{
    cout << "\tSveiki, čia yra vidurkio ir medianos iš pažymių skaičiuoklė" <<
    endl << endl;
    cout << "Įveskite:\n\t'1' jei norite ranka suvesti pažymius\n\t'2' jei norite, kad pažymiai būtu sugeneruoti\n\t'3' jei norite, kad būtu sugeneruoti studentų vardai ir pažymiai\n\t" 
            <<"'4' jei norite nuskaityti duomenis iš failo\n\t'5' jei norite sugeneruoti faile duomenis \n\t'6' jei norite išeiti iš programos\nĮveskite pasirinkimą:";
}


void input_method(vector<Students>& group, int& menu_option)
{
    while(true)
    {
        menu_option = get_int(1, 6);

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
            print_line();

            cout << "Pasirinkite is kurio failo nuskaityti:\n"
            "\t'1' iš kursiokai.txt\n"
            "\t'2' iš studentai10000.txt\n"
            "\t'3' iš studentai100000.txt\n"
            "\t'4' iš studentai1000000.txt\n"
            "\t'5' iš studentai_gen1000.txt\n"
            "\t'6' iš studentai_gen10000.txt\n"
            "\t'7' iš studentai_gen100000.txt\n"
            "\t'8' iš studentai_gen1000000.txt\n"
            "\t'9' iš studentai_gen10000000.txt\n"
            "Įveskite pasirinkimą: ";            
            int file_option = get_int(1,9);
            file_input(group, FILE_PATHS[file_option - 1]);
            break;
        }
        else if(menu_option == 5) //generavimas studentu faile
        {
            cout << "Pasirinkite kiek norite studentu sugeneruoti: \n"
            << "\t'1' 1 000\n"
            << "\t'2' 10 000\n"
            << "\t'3' 100 000\n"
            << "\t'4' 1 000 000\n"
            << "\t'5' 10 000 000\n"
            << "Įveskite pasirinkimą: ";
            
            int amount_option = get_int(1, 5);
            int student_amount = STUDENT_COUNTS[amount_option - 1];
            
            //creating the file
            string filename = generate_raw_student_file(student_amount, 7);
            //string filename = test_generate_raw_student_file(student_amount, 7);
            file_input(group, filename);
            break;
        } //exit program option 
        else if(menu_option == 6)
        {
            cout << "Išeinama is programos...\n";
            return;
        }
        else
        {
            cout << "Nėra tokio pasirinkimo!\n";
            intro_text();
        }
    }
}

void sort_method(vector<Students>& group, int& sort_option)
{
    cout << "Pasirinkite kaip norite, kad studentai būtu išrušiuoti:\n\t'1'Pagal vardą\n\t'2'Pagal pavardę\n\t'3'Pagal vidurkį\n\t'4'Pagal medianą\n";
    cout << "Įveskite pasirinkimą: ";

    sort_option = get_int(1,4);
    sort_output(group, sort_option);
}

void output_method(vector<Students>& group, vector<Students>& above_five, vector<Students>& below_five, int& menu_option,int& output_option, int& split_option, int& sort_option)
{
    cout << "Pasirinkite kur norite, kad duomenys būtu išvesti:\n\t'1'Terminale\n\t'2'Teksto faile\n\t'3'Į du atskirus failus\nĮveskite pasirinkimą: ";
    output_option = get_int(1,3);
    
    if(output_option == 1 && menu_option == 4)
    {
        temp_output(group); //temp output displays median and result avg. since normal output only displays either one
        return;
    }
    else if(output_option == 1)
    {
        terminal_output(group);
        return;
    }
    else if(output_option == 2) //v0.2 versijos paprastas file output
    {
        file_output(group, "../studentOutput/StudentOutput.txt");
        return;
    }
    else//v0.4 i 2 atskirus filus output
    {
        split_method(group, above_five, below_five, split_option, sort_option);
        if(split_option == 1)
        {
            file_output(above_five, "../studentOutput/kietiakai.txt");
            file_output(below_five, "../studentOutput/vargsiukai.txt");
        }
        else
        {
            file_output(group, "../studentOutput/kietiakai.txt");
            file_output(below_five, "../studentOutput/vargsiukai.txt");
        }

        return;
    }
}

void split_method(vector<Students>& group, vector<Students>& above_five, vector<Students>& below_five, int& split_option, int& sort_option)
{
    cout << "Pasirinkite, su kokia strategija norite atskirti studentus: "
    << "\n\t1. Pirma strategija"
    << "\n\t2. Antra strategija"
    << "\n\t3. Trečia strategija\n"
    << "Įveskite pasirinkimą: ";
    split_option = get_int(1, 3);

    if(split_option == 1)
        split_students_by_grades(group, above_five, below_five);
    else if (split_option == 2)
    {
        sort_output(group, 3);
        split_strategy_two(group, below_five);
        sort_output(group, sort_option);
        sort_output(below_five, sort_option);
    }
    else
    {
        split_strategy_three(group, below_five);
        sort_output(group, sort_option);
        sort_output(below_five, sort_option);
    }
}