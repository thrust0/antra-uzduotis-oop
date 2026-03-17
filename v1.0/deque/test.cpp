#include "menu.h"

void test_strategy_one(string filename);

int main()
{
    string file1k = "../../studentInput/studentai_gen1000.txt";
    string file10k = "../../studentInput/studentai_gen10000.txt";
    string file100k = "../../studentInput/studentai_gen100000.txt";
    string file1m = "../../studentInput/studentai_gen1000000.txt";
    string file10m = "../../studentInput/studentai_gen10000000.txt";

    test_strategy_one(file1k);
    test_strategy_one(file10k);
    test_strategy_one(file100k);
    test_strategy_one(file1m);
    test_strategy_one(file10m);
}

void test_strategy_one(string filename)
{
    deque<Students> group;
    deque<Students> above_five;
    deque<Students> below_five;

    //input
    auto start_input = std::chrono::high_resolution_clock::now();
    file_input(group, filename);
    auto end_input = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed_input = end_input - start_input;
    cout << "Nuskaitymas " << filename << ": " << elapsed_input.count() << "ms\n";

    //sort
    auto start_sort = std::chrono::high_resolution_clock::now();
    sort_output(group, 3);
    auto end_sort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed_sort = end_sort - start_sort;
    cout << "Rūšiavimas " << filename << ": " << elapsed_sort.count() << "ms\n";

    //split
    auto start_split = std::chrono::high_resolution_clock::now();
    split_students_by_grades(group, above_five, below_five);
    auto end_split = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed_split = end_split - start_split;
    cout << "Skaidymas " << filename << ": " << elapsed_split.count() << "ms\n";
}