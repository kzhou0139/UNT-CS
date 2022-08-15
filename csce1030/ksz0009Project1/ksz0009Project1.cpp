#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    cout << "+--------------------------------------------------+" << endl;
    cout << "          Computer Science and Engineering          " << endl;
    cout << "           CSCE 1030 - Computer Science I           " << endl;
    cout << "       Kelly Zhou ksz0009 kellyzhou@my.unt.edu      " << endl;
    cout << "+--------------------------------------------------+" << endl;

    //initialize constants
    const int ACCOUNT_LENGTH = 6;
    enum propertyType {
        Commercial = 1, Residential = 2
    };

    //prints out numbers with 2 decimal places
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //user enters name, check to see if name is valid
    string name;
    bool nameVal = false;
    while (!nameVal) {
        cout << "Enter the name on your account: ";
        getline(cin, name);
        for (int i = 0; i < name.length(); i++) {
            if (!(isalpha(name.at(i)) || name.at(i) == ' ')) {
                nameVal = false;
                cout<<"Error: the name you entered is not valid. Please enter again."<<endl;
                break;
            }
            else
                nameVal = true;
        }
    }

    //convert initials to uppercase
    name.at(0) = toupper(name.at(0));
    for (int i = 1; i < name.length(); i++) {
        if(name.at(i - 1) == ' ')
            name.at(i) = toupper(name.at(i));
    }

    //user enters account numbers, check if account number is valid
    string accountNum = "";
    bool accountVal = false;
    while (!accountVal) {
        cout<<"Enter your account number: ";
        cin>>accountNum;
        if (accountNum.length() != 6) {
            accountVal = false;
            cout<<"Your account number must have 6 alphanumeric characters. Please enter again."<<endl;
        }
        else {
            for (int i = 0; i < accountNum.length(); i++) {
                if (isalpha(accountNum.at(i)) || isdigit(accountNum.at(i)))
                    accountVal = true;
                else {
                    accountVal = false;
                    cout<<"Your account number must have only alphabets or numbers. Please enter again."<<endl;
                    break;
                }
            }
        }
    }

    //get number of properties, make sure number of properties is valid
    int propertyNum = 0;
    bool propertyVal = false;
    while (!propertyVal) {
        cout<<"How many properties do you want to process?: ";
        cin>>propertyNum;
        if (propertyNum < 0) {
            propertyVal = false;
            cout<<"The number of properties must be positive. Please enter again."<<endl;
        }
        else
            propertyVal = true;
    }

    //ask for the type of property, calculate tax for each property
    propertyType prop;
    int userProp = 0;
    int propVal = 0;
    double tax = 0;
    double totalTax = 0;
    for (int i = 1; i <= propertyNum; i++) {
        cout<<"Processing property #"<<i<<endl;
        cout<<"1. Commercial"<<endl;
        cout<<"2. Residential"<<endl;
        bool propValid = false;
        while (!propValid) {
            cout<<"Enter property type: ";
            cin>>userProp;
            prop = (propertyType)userProp;
            cout<<"Enter property value: ";
            cin>>propVal;
            switch (prop) {
                case 1:
                    if (propVal < 1000000)
                        tax = propVal * 0.035;
                    else {
                        tax = 1000000 * 0.035;
                        int over = propVal - 1000000;
                        tax += over * 0.05;
                    }
                    propValid = true;
                    break;
                case 2:
                    if (propVal < 100000)
                        tax = 0;
                    else {
                        int over = propVal - 100000;
                        tax = over * 0.035;
                    }
                    if (propertyNum == 1) {
                        srand(time(NULL));
                        int rand = (rand%1001) + 1000;
                        if (rand > tax)
                            tax = 0;
                        else
                            tax -= rand;
                        cout<<"Your tax for this property was reduced by $"<<rand<<"."<<endl;
                    }
                    propValid = true;
                    break;
                default:
                    cout<<"The value that you entered is invalid."<<endl;
                    propValid = false;
                    break;
            }
            if (propValid == true)
                cout<<"Tax owed for property #"<<i<<" $"<<tax<<endl;
        }
        totalTax += tax;
    }

    //print out user information
    cout<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Account Number: "<<accountNum<<endl;
    cout<<"Your total taxes are: $"<<totalTax<<endl;

    return 0;
}