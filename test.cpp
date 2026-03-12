#include "v0.4/io.h"

int main()
try{
    std::cout << std::endl << "1k: " << std::endl; 
    test_data_processing("studentInput/studentai_gen1000.txt");

    std::cout << std::endl <<  "10k: " << std::endl; 
    test_data_processing("studentInput/studentai_gen10000.txt");

    std::cout << std::endl <<  "100k: " << std::endl; 
    test_data_processing("studentInput/studentai_gen100000.txt");

    std::cout << std::endl <<  "1mil: " << std::endl; 
    test_data_processing("studentInput/studentai_gen1000000.txt");
    
    std::cout << std::endl <<  "10mil: " << std::endl; 
    test_data_processing("studentInput/studentai_gen10000000.txt");
    return 0;
}

catch(const std::exception& e)
{
    std::cerr << "Nenumatyta klaida: " << e.what() << std::endl;
}