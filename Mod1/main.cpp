#include <iostream>
#include <fstream>
#include <limits>
#include <cctype>
using namespace std;

//return type - function name - parameter
//& - function recieves memory addresses and changes origional variables
void displaymenu(int&); //uses passby refrence to update user selection
void selectIO(char&, char&); // returns two seperate characters
int getInput(char&, double&, double&, ifstream&);//reads data from file and returns status indicator
double calculate(int&, char&, double&, double&);// returns as a double while updating 4 other variables
int sendOutput(char&, double&, char&, double&, double&, ofstream&); //logs reports to a file

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



int main(int argc, const char * argv[]) {

    int choiceType, size; // Use int for menu choice
    double num1 = 0, num2 = 0, result = 0;
    char repeat = 'y';
    

    const int MAX_SIZE = 100; // The physical limit of the array
    double list[MAX_SIZE]; // Create the array with enough spaces
    int count;



    do {
        cout << "--Calculator menu--" << endl;
        cout << "choose function type: \n (1) basic \n (2) statistical \n (3) exit " << endl;
        cin >> choiceType;

        if(choiceType == 3) {
            cout << "thanks, bye!" << endl;
            break;
        }

        if(choiceType == 1) {
           
            cout << "Choose an operation: " << endl;
            cout << " 1. add \n 2. subtract \n 3. multiply \n 4. divide \n 5. exit" << endl;
            //cout << " 5. sum \n 6. mean \n 7. median \n 8. min \n 9. max \n 10. exit." << endl;
            cin >> choiceType;
            //exits program if user selects 10
            if(choiceType == 5) {
                cout << "Have a good day!" << endl;
                break;
            }
            // basic math
            if (choiceType >= 1 && choiceType <= 4) {
                cout << "Enter two numbers separated by a space: ";
                cin >> num1 >> num2;

                switch(choiceType) {
                case 1:
                    result = add(num1, num2);
                    break;
                case 2:
                    result = subtract(num1, num2);
                    break;
                case 3:
                    result = multiply(num1, num2);
                    break;
                case 4:
                    if (num2 != 0) result = divide(num1, num2);
                    else {
                        cout << "Divide by zero error!" << endl;
                result = 0;
                        cout << "would you like to preform another calculation?" << endl;
                        
                        //                    break;
                        
                    }
                }
            }
            cout << "Result = " << result << endl;
        }while(choiceType == 1);
    } while(choiceType >= 1 && choiceType <=4);


    // stactistical math
    do {
    if (choiceType == 2) {
        cout << "How many numbers? ";
        cin >> size;

        if(size > MAX_SIZE) size = MAX_SIZE;

        cout << "Enter the list of numbers seperated by a space: " << endl;
        for (int i = 0; i < size; i++) {
            cin >> list[i]; // Fills the array index by index
        }

        switch(choiceType) {
        case 5:
            result = sum(list, size);
            break;
        case 6:
            result = mean(list, size);
            break;
        case 7:
            result = median(list, size);
            break;
        case 8:
            result = min(list, size);
            break;
        case 9:
            result = max(list, size);
            break;

        default:
            cout << "Invalid input, please choose a number 5-10" << endl;

        }
        
    } while(choiceType == 2);

        break;
    do {
        cout << "Would you like to perform another calculation? (y/n): ";
        cin >> repeat;
        break;
    } while (tolower(repeat) == 'y');
    

    cout << "thanks, bye!" << endl;

}while(tolower(repeat) == 'y');

return 0;
}

// Basic Function Definitions
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

//Statistical Function Definitions
double sum(const double arr[], int size) {
    double total = 0; // Initialize sum at 0
    for (int i = 0; i < size; i++) {
        total += arr[i]; // Add current element to total
    }
    return total;
}

double mean(const double list[], int size) {
    return 0;
} // mean
double median(double list[], int size) {
    return 0;
} // median
double min(const double list[], int size) {
    return 0;
} // min
double max(const double list[], int size) {
    return 0;
} // max


