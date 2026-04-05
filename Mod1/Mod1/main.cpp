#include <fstream>
#include <iostream>
#include <limits>
#include <cctype>
#include <string>     // For filenames and opName
#include <iomanip>    // For setprecision
#include <stdexcept>  // For runtime_error
#include <algorithm>  // For std::sort() and std::swap()
#include <list>
#include <string>
#include <numeric>

void displaymenu(int&); //uses passby refrence to update user selection
void selectIO(char&, char&); // returns two seperate characters
int getInput(char&, double&, double&, std::fstream&);//reads data from file and returns status indicator
double calculate(int&, char&, double&, double&);// returns as a double while updating 4 other variables
int sendOutput(char&, double&, char&, double&, double&, std::fstream&); //logs reports to a file

//calculation fcns
//return type - function(parameters)
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);

double sum(const double list[], int size);
double mean(const double list[], int size);
double median(double list[], int size); // Requires data to be sorted in place or copied.
double min(const double list[], int size);
double max(const double list[], int size);


using namespace std;

int main() {
    int choiceType, size = 0; // Use int for menu choice
    double num1 = 0, num2 = 0, result = 0;
    char repeat = 'y';
    
    const int MAX_SIZE = 100; // The physical limit of the array
    double list[MAX_SIZE]; // Create the array with enough spaces
    //int count;
    
    const int colWidth = 15; // Width for each column
    
    do {
        cout << "===============================================" << endl;
        cout << "            C++ ALGORITHM TOOLKIT              " << endl;
        cout << "===============================================" << endl;
        
        // Header Row
        cout << left << setw(colWidth) << "  [ BASIC ]"
        << setw(colWidth) << "[ STATS ]"
        << setw(colWidth) << "[ SORT/SEARCH ]" << endl;
        
        // Menu Options
        cout << left << setw(colWidth) << "  1. Add"      << setw(colWidth) << "6. Sum"     << setw(colWidth) << "11. Bubble" << endl;
        cout << left << setw(colWidth) << "  2. Sub"      << setw(colWidth) << "7. Mean"    << setw(colWidth) << "12. Select" << endl;
        cout << left << setw(colWidth) << "  3. Mult"     << setw(colWidth) << "8. Median"  << setw(colWidth) << "13. Linear" << endl;
        cout << left << setw(colWidth) << "  4. Div"      << setw(colWidth) << "9. Min"     << setw(colWidth) << "14. Binary" << endl;
        cout << left << setw(colWidth) << "  5. Max"      << setw(colWidth) << "10. Exit"   << endl;
        
        cout << "-----------------------------------------------" << endl;
        cin >> choiceType;
        // TODO: display user choice - cout << string << endl; ??
        if (choiceType == 10) {
            cout << endl << "Thank you for using the Simple Calculator!" << endl;
            cout << "\n----------------------------------------" << endl;
            break;
        }
        
        if (choiceType >= 1 && choiceType <= 4){
            cout << "Enter two numbers separated by a space: ";
            cin >> num1 >> num2;
            
            //Basic
            switch(choiceType) {
                case 1: result = add(num1, num2); break;
                case 2: result = subtract(num1, num2); break;
                case 3: result = multiply(num1, num2); break;
                case 4:
                    if (num2 != 0) result = divide(num1, num2);
                    else {
                        cout << "Divide by zero error!" << endl;
                    }
            }
        }
        
        //Stats
            if (choiceType >= 4 && choiceType <= 9) {
            cout << "How many numbers? ";
            cin >> size;
            
            if(size > MAX_SIZE) size = MAX_SIZE;
            cout << "Enter the list of numbers seperated by a space: " << endl;
            for (int i = 0; i < size; i++) {
                cin >> list[i]; // Fills the array index by index
            }
            switch(choiceType){
                case 5: result = max(list, size); break;
                case 6: result = sum(list, size); break;
                case 7: result = mean(list, size); break;
                case 8: result = median(list, size); break;
                case 9: result = min(list, size); break;
            }
             
            cout << "Result = " << result << endl;
            cout << "would you like to preform another calculation?" << endl;
            cin >> repeat;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear Buffer
            
                if (tolower(repeat) == 'n') {
                    choiceType = 10;
                }
            }
        } while (choiceType != 10);
        
        
        cout << "\n========================================" << endl;
        cout << "  Goodbye!" << endl;
        cout << "========================================" << endl;
        
        return 0;
    }


//Basic
double add(double a, double b) {
    return a + b;
}
double subtract(double a, double b) {
    return a - b;
}
double multiply(double a, double b) {
    return a * b;
}
    double divide(double a, double b) {
        return a / b;
}
    //Stats
double sum(const double arr[], int size) {
        double total = 0; // Initialize sum at 0
        for (int i = 0; i < size; i++) {
            total += arr[i]; // Add current element to total
        }
        return total;
    }

double mean(const double list[], int size) {
    if (size == 0) return 0; // Prevent division by zero
    return sum(list, size) / size;
    } // mean

double median(double list[], int size) {
    std::sort(list, list + size);
    if (size % 2 != 0) // Odd
        return list[size / 2];
    else // Even
        return (list[(size - 1) / 2] + list[size / 2]) / 2.0;
}
double min(const double list[], int size) {
    double small = list[0];
    for (int i = 1; i < size; i++) {
        if (list[i] < small) small = list[i];
    }
    return small;
}

double max(const double list[], int size) {
    double large = list[0];
    for (int i = 1; i < size; i++) {
        if (list[i] > large) large = list[i];
    }
    return large;
}
