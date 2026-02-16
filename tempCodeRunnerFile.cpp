int get_grade()
{
    string input;
    int grade = 0;

    while(true)
    {
        bool is_number = true;
        cin >> input;
        for(auto i : input)
        {
            if(!std::isdigit(i))
                {
                    cout << "Iveskite sveikaji skaiciu! ";
                    is_number = false;
                    break;
                }
        }
        if(is_number)
            grade = stoi(input);
        if((grade > 10 || grade < 0) && is_number)
            cout << "Iveskite skaiciu tarp 0 iki 10! ";
        else if(grade <= 10 && grade >= 0 && is_number) break;
    }
    return grade;
}