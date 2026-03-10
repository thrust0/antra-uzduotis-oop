#include "menu.h"

void menu(){
    srand(time(0));
    for(int i = 0; i<6; i++) std::cout << std::endl;
    std::vector<Students>group;

    //intro vartotojui
    std::cout << "\tSveiki, čia yra vidurkio ir medianos iš pažymių skaičiuoklė" << std::endl << std::endl;
    std::cout << "Įveskite:\n\t'1' jei norite ranka suvesti pažymius\n\t'2' jei norite, kad pažymiai būtu sugeneruoti\n\t'3' jei norite, kad būtu sugeneruoti studentų vardai ir pažymiai\n\t" 
                <<"'4' jei norite nuskaityti duomenis iš failo\n\t'5' jei norite sugeneruoti faile duomenis \n\t'6' jei norite išeiti iš programos\n\n";

    int menu_option = 0;
    int sort_option = 0;
    int output_option = 0;

    /*
    generate_raw_student_file(1000, 15);
    generate_raw_student_file(10000, 15);
    generate_raw_student_file(100000, 10);
    generate_raw_student_file(1000000, 5);
    generate_raw_student_file(10000000, 3);
    */
    
    // validate menu input via get_int
    //repromt for how user wants to input the students
    while(true)
    {
        menu_option = get_int(1, 5);

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
            std::cout << "Pasirinkite is kurio failo nuskaityti:\n\t'1' iš kursiokai.txt\n\t'2' iš studentai10000\n\t'3' iš studentai100000\n\t'4' iš studentai1000000\nĮveskite pasirinkimą: ";
            int file_option = get_int(1,4);
            switch (file_option)
            {
            case 1:
                file_input(group, "../studentInput/kursiokai.txt");
                break;
            case 2:
                file_input(group, "../studentInput/studentai10000.txt");
                break;
            case 3:
                file_input(group, "../studentInput/studentai100000.txt");
                break;
            case 4:
                file_input(group, "../studentInput/studentai1000000.txt");
                break;
            default:
                break;
            }
            break;
        }
        else if(menu_option == 5) //generavimas studentu faile
        {
            std::cout << "Pasirinkite kiek norite studentu sugeneruoti: \n"
            << "\t'1' 1 000\n"
            << "\t'2' 10 000\n"
            << "\t'3' 100 000\n"
            << "\t'4' 1 000 000\n"
            << "\t'5' 10 000 000\n"
            << "Įveskite pasirinkimą: ";
            
            int amount_option = get_int(1, 5);
            int student_amount = 0;
            switch (amount_option)
            {
            case 1:
                student_amount = 1000;
                break;
            case 2:
                student_amount = 10000;
                break;
            case 3:
                student_amount = 100000;
                break;
            case 4:
                student_amount = 1000000;
                break;
            case 5:
                student_amount = 10000000;
                break;
            default:
                break;
            }
            
            //creating the file
            std::string filename = generate_raw_student_file(student_amount, 7);
            //std::string filename = test_generate_raw_student_file(student_amount, 7);
            file_input(group, filename);
            break;
        } //exit program option 
        else if(menu_option == 6)
        {
            std::cout << "Išeinama is programos...\n";
            return;
        }
        else
        {
            std::cout << "Nėra tokio pasirinkimo!\n";
            std::cout << "Įveskite:\n\t'1' jei norite ranka suvesti pažymius\n\t'2' jei norite, kad pažymiai būtu sugeneruoti\n\t'3' jei norite, kad būtu sugeneruoti studentų vardai ir pažymiai\n\t'4' jei norite nuskaityti duomenis iš failo\n\t'5' jei norite išeiti iš programos\n\n";
        }
    }

    print_line();
    //choose how to sort the students
    std::cout << "Pasirinkite kaip norite, kad studentai būtu išrušiuoti:\n\t'1'Pagal vardą\n\t'2'Pagal pavardę\n\t'3'Pagal vidurkį\n\t'4'Pagal medianą\n";
    std::cout << "Įveskite pasirinkimą: ";
    sort_option = get_int(1,4);
    print_line();

    //choose where to ouput 1 terminal 2 txt file 3 two txt files
    std::cout << "Pasirinkite kur norite, kad duomenys būtu išvesti:\n\t'1'Terminale\n\t'2'Teksto faile\n\t'3'Į du atskirus failus\nĮveskite pasirinkimą: ";
    output_option = get_int(1,3);
    
    sort_output(group, sort_option);
    if(output_option == 1 && menu_option == 4)
    {
        temp_output(group); //temp output displays median and result avg. since normal output only displays either one
        return;
    }
    else if(output_option == 1)
    {
        output(group);
        return;
    }
    else if(output_option == 2) //v0.2 versijos paprastas file output
    {
        file_output(group, "../studentOutput/StudentOutput.txt");
        return;
    }
    else //v0.4 i 2 atskirus filus output
    {
        std::vector<Students>above_five_students;
        std::vector<Students>below_five_students;

        split_students_by_grades(group, above_five_students, below_five_students);

        file_output(above_five_students, "../studentOutput/kietiakai.txt");
        file_output(below_five_students, "../studentOutput/vargsiukai.txt");
        return;
    }
}