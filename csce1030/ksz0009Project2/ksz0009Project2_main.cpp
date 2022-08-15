#include "ksz0009Project2_header.h"

int main() {
    cout << "+--------------------------------------------------+" << endl;
    cout << "          Computer Science and Engineering          " << endl;
    cout << "           CSCE 1030 - Computer Science I           " << endl;
    cout << "       Kelly Zhou ksz0009 kellyzhou@my.unt.edu      " << endl;
    cout << "+--------------------------------------------------+" << endl;

    bool cont = true;
    while (cont) {  //loop continues until 'Quit' case
        int choice = 0;
        cout << "1. Add" << endl;   //print out options
        cout << "2. Remove" << endl;
        cout << "3. Display" << endl;
        cout << "4. Search" << endl;
        cout << "5. Results" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        CHOICES c = static_cast<CHOICES>(choice);   //cast choice (int) into c (enum)
        switch (c) {
            case Add:   //if user enters '1', this code runs
                add_Student();
                break;
            case Remove:    //if user enters '2', this code runs
                int idRemove;
                cout << "Enter the ID of the student you want to remove: ";
                cin >> idRemove;
                remove_Student(idRemove);
                break;
            case Display:   //if user enters '3', this code runs
                display();
                break;
            case Search:    //if user enters '4', this code runs
                int idSearch;
                cout << "Enter the ID of the student you are searching for: ";
                cin >> idSearch;
                search(idSearch);
                break;
            case Results:   //if user enters '5', this code runs
                exportResults();
                break;
            case Quit:  //if user enters '6', this code runs
                cout << "Program terminated."<<endl;
                cont = false;
                break;
            default:    //if user enters a value other than 1-6. this code runs
                cout << "Incorrect choice. Please enter again";
                break;
        }
    }

    return 0;
}
