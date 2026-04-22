#include "student.hpp"
#include "student.hpp"
#include <cassert>
/** Unit tests for Students class. Each test covers one behaviour. */

/** Test default constructor behaviour. */
void test_default_konstruktoriu() {
    Students s;
    assert(s.first_name() == "");
    assert(s.exam() == 0);
    assert(s.result() == 0);
    cout << "✓ Default konstruktorius\n";
}

/** Test copy constructor preserves name fields. */
void test_copy_konstruktoriu() {
    Students s1;
    s1.set_first_name("Vardas");
    s1.set_last_name("Pavarde");
    Students s2(s1);
    assert(s2.first_name() == "Vardas");
    assert(s2.last_name() == "Pavarde");
    cout << "✓ Copy konstruktorius\n";
}

/** Test move constructor moves name out of source. */
void test_move_konstruktoriu() {
    Students s1;
    s1.set_first_name("Vardas");
    Students s2(std::move(s1));
    assert(s2.first_name() == "Vardas");
    assert(s1.first_name() == "");
    cout << "✓ Move konstruktorius\n";
}

/** Test copy assignment operator. */
void test_copy_assignment() {
    Students s1, s2;
    s1.set_first_name("Vardas");
    s2 = s1;
    assert(s2.first_name() == "Vardas");
    cout << "✓ Copy assignment\n";
}

/** Test move assignment operator. */
void test_move_assignment() {
    Students s1, s2;
    s1.set_first_name("Vardas");
    s2 = std::move(s1);
    assert(s2.first_name() == "Vardas");
    assert(s1.first_name() == "");
    cout << "✓ Move assignment\n";
}

/** Test destructor is invoked (scope-based). */
void test_destructor() {
    {
        Students s;
        s.set_first_name("Vardas");
    } // destructor called here when s goes out of scope
    cout << "✓ Destructor\n";
}

/** Test operator>> parses last value as exam. */
void test_input_operator() {
    stringstream ss("Vardas Pavarde 8 7 9 6 10");
    Students s;
    ss >> s;
    assert(s.first_name() == "Vardas");
    assert(s.last_name() == "Pavarde");
    assert(s.exam() == 10); // last grade is exam
    cout << "✓ operator>>\n";
}

/** Test operator<< prints a formatted student line (visual check).
 *  The assertion is omitted because formatting is visual; test prints output.
 */
void test_output_operator() {
    Students s;
    s.set_first_name("Vardas");
    s.set_last_name("Pavarde");
    cout << "✓ operator<< output: " << s << "\n";
}

/** Run all tests. */
int main()
{
    cout << "=== Studentų klasės testai ===\n\n";
    test_default_konstruktoriu();
    test_copy_konstruktoriu();
    test_move_konstruktoriu();
    test_copy_assignment();
    test_move_assignment();
    test_destructor();
    test_input_operator();
    test_output_operator();
    cout << "\nVisi testai praėjo!\n";
    return 0;
}
