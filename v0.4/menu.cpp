#include "menu.h"

void menu(){
    srand(time(0));
    for(int i = 0; i<6; i++) std::cout << std::endl;
    std::vector<Students>group;

    //intro vartotojui
    std::cout << "\tSveiki, čia yra vidurkio ir medianos iš pažymių skaičiuoklė" << std::endl << std::endl;
    std::cout << "Įveskite:\n\t'1' jei norite ranka suvesti pažymius\n\t'2' jei norite, kad pažymiai būtu sugeneruoti\n\t'3' jei norite, kad būtu sugeneruoti studentų vardai ir pažymiai\n\t'4' jei norite nuskaityti duomenis iš failo\n\t'5' jei norite išeiti iš programos\n\n";

    int menu_option = 0;
    int sort_option = 0;
    int output_option = 0;

    
    generate_raw_student_file(1000, 15);
    generate_raw_student_file(10000, 15);
    generate_raw_student_file(100000, 10);
    generate_raw_student_file(1000000, 5);
    generate_raw_student_file(10000000, 3);
    
    
    // validate menu input via get_int
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
                file_input(group, "../studentai/kursiokai.txt");
                break;
            case 2:
                file_input(group, "../studentai/studentai10000.txt");
                break;
            case 3:
                file_input(group, "../studentai/studentai100000.txt");
                break;
            case 4:
                file_input(group, "../studentai/studentai1000000.txt");
                break;
            default:
                break;
            }
            break;
        }
        else if(menu_option == 5)
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
    std::cout << "Pasirinkite kaip norite, kad studentai būtu išrušiuoti:\n\t'1'Pagal vardą\n\t'2'Pagal pavardę\n\t'3'Pagal vidurkį\n\t'4'Pagal medianą\n";
    std::cout << "Įveskite pasirinkimą: ";
    sort_option = get_int(1,4);
    print_line();

    std::cout << "Pasirinkite kur norite, kad duomenys būtu išvesti:\n\t'1'Terminale\n\t'2'Teksto faile\nĮveskite pasirinkimą: ";
    output_option = get_int(1,2);
    
    sort_output(group, sort_option);
    if(output_option == 1 && menu_option == 4)
    {
        temp_output(group);
        return;
    }
    else if(output_option == 1)
    {
        output(group);
        return;
    }
    else
    {
        file_output(group);
        return;
    }
}