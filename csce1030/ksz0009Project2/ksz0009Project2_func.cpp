#include "ksz0009Project2_header.h"

/*
Function: add_Student
Parameters: none
Return: include information in the output file
Description: This function adds a student to the student.dat file. The informtation for the new student is gotten by asking the user for the values. 
*/
void add_Student() {
    ofstream out;   //create output file, check that the output file opens properly
    out.open("student.dat", ios::app);
    if (out.fail()) {
        cout<<"Error: could not open file.";
        exit(EXIT_FAILURE);
    }

    Student stuAdd; //create object from the student struct
    string ln = "";
    string fn = "";
    cout<<"Enter last name of the student: ";   //obtain information about the new student from the user
    cin>>ln;
    cout<<"Enter the first name of the student: ";
    cin>>fn;
    stuAdd.name = ln + "," + fn + ",";
    cout<<"Enter student ID: ";
    cin>>stuAdd.id;
    cout<<"How many test did this student take?: ";
    cin>>stuAdd.numTestsTaken;
    for(int i = 0; i < stuAdd.numTestsTaken; i++) {
      cout<<"Enter score #"<<i+1<<": ";
      cin>>stuAdd.testScores[i];
    }  
    out<<"\n";
    out<<stuAdd.name; //put the information for the new student into the output file
    out<<stuAdd.id<<",";
    out<<stuAdd.numTestsTaken<<",";
    for (int i = 0; i < stuAdd.numTestsTaken; i++) 
        out<<stuAdd.testScores[i]<<",";

    out.close();
}

/*
Function: remove_Student
Parameters: an int variable representing the ID of the student that the user wants to remove
Return: writes information to the ofstream file
Description: This function goes through each student in the student.dat file then stores the information in their corresponding variables. 
If the student ID from the file doesn't match the stuID parameter, the student's information is written to the output file. If the student ID 
from the file matches the stuID parameter, the student's information is not written to the output file. If no student ID from the file matches 
the stuID parameter, the user is informed.
*/
void remove_Student(int stuID) {
    int numStudents = getNumber();
    Student *stuRemove = new Student[numStudents];
    bool match = false;
    int mCount;

    ifstream in;    //open input file, check that the file opens properly
    in.open("student.dat");
    if (in.fail()) {
        cout<<"Error: could not open this file."<<endl;
        exit(EXIT_FAILURE);
    }

    string fname[numStudents];
    string lname[numStudents];
    for (int i = 0; i < numStudents; i++) { //read student information from student.dat, store information in their corresponding variables
        Student *stu = new Student;
        string str;
        getline(in , str);
        istringstream inS(str);
        getline(inS, lname[i], ',');
        getline(inS, fname[i], ',');
        stu->name = lname[i] + "," + fname[i];
        string idS = "";
        getline(inS, idS, ',');
        stu->id = stoi(idS);
        if (stu->id == stuID) { //if the student ID from the file matches stuID, leave a boolean flag 
            match = true;
            mCount = i;
        }
        string testS = "";
        getline(inS, testS, ',');
        stu->numTestsTaken = stoi(testS);
        for (int i = 0; i < stu->numTestsTaken; i++) {
            string s = "";
            getline(inS, s, ',');
            *(stu->testScores+i) = stoi(s);
        }
        stuRemove[i] = *stu;
        delete stu;
    }
    in.close();

    if(match) { 
        ofstream out; //open output file, check that file opens properly
        out.open("student.dat");
        if (out.fail()) {
            cout<<"Error: could not open this file."<<endl;
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < numStudents; i++) { 
            if (i != mCount) {  //write student information to the output file if the student ID doesn't match stuID
                out<<lname[i]<<"," << fname[i] << ",";
                out<<stuRemove[i].id<<",";
                out<<stuRemove[i].numTestsTaken<<",";
                for (int j = 0; j < stuRemove[i].numTestsTaken; j++)
                    out<<stuRemove[i].testScores[j]<<",";
                if(i != numStudents-1)
                    out<<endl;
            }  
        }
        out.close();
    }
    else    //if there are no matches let user know
        cout<<"Error: This student ID does not exist."<<endl;
}

/*
Function: display
Parameters: none
Return: outputs information to terminal
Description: This function goes through each student in the student.dat file then stores the information in their corresponding variables. 
Additionally, the function displays the information obtained from the student.dat file in the terminal.
*/
void display() {
    ifstream in;    //create input file, check if file opened properly 
    in.open("student.dat");
    if (in.fail()) {
        cout<<"Error: could not open this file."<<endl;
        exit(EXIT_FAILURE);
    }
    int numStudents = getNumber();
    Student *stuDisplay = new Student[numStudents];
    for (int i = 0; i < numStudents; i++) { //obtain information from the student.dat file, assign information to their corresponding variables
        string str;
        getline(in , str);
        istringstream inS(str);
        string ln = "";
        string fn = "";
        getline(inS, ln, ',');
        getline(inS, fn, ',');
        string name = ln + ", " + fn;
        cout<<setw(30)<<name;
        string idS = "";
        getline(inS, idS, ',');
        cout<<setw(15)<<idS;
        string testS = "";
        getline(inS, testS, ',');
        stuDisplay[i].numTestsTaken = stoi(testS);
        for (int j = 0; j < stuDisplay[i].numTestsTaken; j++) {
            string s;
            getline(inS, s, ',');
            cout<<setw(5)<<s;
        }
        cout << endl;
    }
    in.close();
}

/*
Function: search
Parameters: an int variable representing the ID of the student that the user wants to remove
Return: outputs information in the terminal
Description: This function goes through each student in the student.dat file then stores the information in their corresponding variables. 
If the student ID of a student from the file matches stuID, the student's information is output into the terminal. If no student from the 
input file has an ID that matches stuID, the function lets the user know.
*/
void search(int stuID) {
    ifstream in;    //create input file, check if input file opened properly
    in.open("student.dat");
    if (in.fail()) {
        cout<<"Error: could not open this file."<<endl;
        exit(EXIT_FAILURE);
    }
    bool match = false;
    while (!in.eof()) { //obtain information from the student.dat file, assign information to their corresponding variables
        string str;
        getline(in , str);
        istringstream inS(str);
        Student *stu = new Student();
        string ln = "";
        string fn = "";
        getline(inS, ln, ',');
        getline(inS, fn, ',');
        stu->name = ln + "," + fn;
        string idS = "";
        getline(inS , idS, ',');
        stu->id = stoi(idS);
        string testS = "";
        getline(inS, testS, ',');
        stu->numTestsTaken = stoi(testS);
        for (int i = 0; i < stu->numTestsTaken; i++) {
            string s = "";
            getline(inS, s, ',');
            *(stu->testScores+i) = stoi(s);
        }
        if (stu->id == stuID) { //is the student's ID matches stuID, their information is printed to the terminal
            match = true;
            cout.setf(ios::right);
            cout<<setw(30)<<stu->name;
            cout<<setw(15)<<stu->id;
            for (int i = 0; i < stu->numTestsTaken; i++)
                cout<<setw(5)<<*(stu->testScores+i);
            cout<<endl;
        }
        delete stu;
    }
    if (match == false) //if no student's ID matches stuID, the user is informed
            cout<<"Error: There was no match for this student ID."<<endl;
    in.close();
}

/*
Function: exportResults
Parameters: none
Return: writes information to the output file
Description: This function goes through each student in the student.dat file then stores the information in their corresponding variables. 
Additionally, the function calls the findMinimum() function to find the lowest score scored by a student. Then, the function calculates the 
average scored earned by the student and writes the information to an output file. 
*/
void exportResults() {
    ofstream out;   //creates output file, checks to see if file opened properly
    out.open("average.dat");
    if (out.fail()) {
        cout<<"Error: could not open this file."<<endl;
        exit(EXIT_FAILURE);
    }
    ifstream in;    //creates input file, checks to see if file opened properly
    in.open("student.dat");
    if (in.fail()) {
        cout<<"Error: could not open this file."<<endl;
        exit(EXIT_FAILURE);
    }

    int numStudents = getNumber();
    Student *stuExport = new Student[numStudents];
    for (int i = 0; i < numStudents; i++) { //obtain information from the student.dat file, assign information to their corresponding variables
        Student *stu = new Student;
        string str;
        getline(in, str);
        istringstream inS(str);
        string ln = "";
        string fn = "";
        getline(inS, ln, ',');
        getline(inS, fn, ',');
        stu->name = ln + "," + fn;
        string idS = "";
        getline(inS, idS, ',');
        stu->id = stoi(idS);
        string testS = "";
        getline(inS, testS, ',');
        stu->numTestsTaken = stoi(testS);
        for (int i = 0; i < stu->numTestsTaken; i++) {
            string s = "";
            getline(inS, s, ',');
            *(stu->testScores+i) = stoi(s);
        }
        stuExport[i] = *stu;
        delete stu;
    }

    for (int i = 0; i < numStudents; i++) { //go through list of students and find the average score for each student
        int sum = 0;
        for (int j = 0; j < stuExport[i].numTestsTaken; j++) 
            sum += stuExport[i].testScores[j];
        int min = findMinimum(stuExport[i].testScores, stuExport[i].numTestsTaken);
        sum -= min;
        int divide = 0;
        if (stuExport[i].numTestsTaken == 5)
            divide = stuExport[i].numTestsTaken - 1;
        else
            divide = stuExport[i].numTestsTaken;
        double avg = sum/divide;
        out.setf(ios::fixed);
        out.setf(ios::showpoint);
        out.precision(1);
        out<<stuExport[i].name<<"   "<<avg<<endl;
    }
    cout << "Results exported to file."<< endl;

    delete [] stuExport;
    out.close();
    in.close();
}

/*
Function: findMinimum
Parameters: an int array representing the grades of the student, an int variable representing the size of the array (the number of tests the student took)
Return: an int representing the lowest score scored by the student
Description: This function finds the lowest score scored by the student. If the student took less than five tests, the minimum grade is set to 0. If the student
took five tests, the function loops through the grades array and finds the lowest value.
*/
int findMinimum(int grades[], int size) {
    int min = 100;
    if (size < 5)
        min = 0;
    else {
        for (int i = 0; i < size; i++) {
            if (grades[i] < min)    //checks to see if the current index has a grade lower than the minimum grade 
                min = grades[i];    //if so, the minimum is assigned the value of the current index
        }
    }
    return min;
}
