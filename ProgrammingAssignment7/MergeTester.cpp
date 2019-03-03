/* Authors: Amy Dixon
* Date: 02.14.2019
* Purpose: This program in MergeTester.cpp
*				 uses the STL algorithm, 'merge,' to merge two ordered lists 
*				 of strings into a single ordered list of strings. 
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> theBigMerge(vector<string>& ventus, vector<string>& roxas);
void display(vector<string> v);

int main() {
	// Declare variables
	vector<string> tl1{ "abba", "acdc", "UB40" };
	vector<string> tl2{ "dbs", "emf", "zz top" };
	vector<string> tl3{ "zz top" };
	vector<string> tl4{ };
	vector<string> tl5{ "dbs", "emf", "zz top" };

#pragma region TestCases
	// Hard-coded test cases
	cout << "Test 1: " << endl; // Test case 1
	cout << "list 1 = ";
	display(tl1);
	cout << "list 2 = ";
	display(tl2);
	cout << "Result = ";
	display(theBigMerge(tl1, tl2));
	cout << endl;

	cout << "Test 2: " << endl; // Test case 2
	cout << "list 1 = ";
	display(tl1);
	cout << "list 2 = ";
	display(tl3);
	cout << "Result = ";
	display(theBigMerge(tl1, tl3));
	cout << endl;

	cout << "Test 3: " << endl; // Test case 3
	cout << "list 1 = ";
	display(tl1);
	cout << "list 2 = ";
	display(tl4);
	cout << "Result = ";
	display(theBigMerge(tl1, tl4));
	cout << endl;

	cout << "Test 4: " << endl; // Test case 4
	cout << "list 1 = ";
	display(tl5);
	cout << "list 2 = ";
	display(tl1);
	cout << "Result = ";
	display(theBigMerge(tl5, tl1));
	cout << endl;
#pragma endregion

	// Keep window open
	system("pause");

	// Exit
	return EXIT_SUCCESS;
}

void display(vector<string> v) {
	cout << "{ ";

	for (string word : v) {
		cout << "'" << word <<"'" << " ";
	}

	cout << "}" << endl;
}

vector<string> theBigMerge(vector<string>& ventus, vector<string>& roxas) {
	// Make copies since 'merge' doesn't like const
	vector<string> ven = ventus;
	vector<string> rox = roxas;

	// Declare variables
	vector<string> sora(ventus.size() + roxas.size());
	auto venBegin = ven.begin();
	auto venEnd = ven.end();
	auto roxBegin = rox.begin();
	auto roxEnd = rox.end();

	// Sort
	sort(venBegin, venEnd);
	sort(roxBegin, roxEnd);

	// Meerrrrgggggeeeeeee
	merge(venBegin, venEnd, roxBegin, roxEnd, sora.begin());

	return sora;
}
