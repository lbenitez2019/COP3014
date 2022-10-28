// iostream_cerr.cpp
// compile with: /EHsc
#include <iostream>
#include <fstream>

using namespace std;

void TestWide()
{
	int i = 0;
	wcout << L"Enter a number: ";
	wcin >> i;
	wcerr << L"test for wcerr" << endl;
	wclog << L"test for wclog" << endl;
}

int main()
{
	int i = 0;
	cout << "Enter a number: ";
	cin >> i;
	cerr << "test for cerr" << endl;
	clog << "test for clog" << endl;
	TestWide();
}