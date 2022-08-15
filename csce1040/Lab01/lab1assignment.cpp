#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {

	struct Employee {
		int id;
		string name;
	};

	struct Customer {
		int id;
		string name;
		double balance;
	};

	ofstream out;
	out.open("lab1.out");
	if (out.fail()) {
		cout<<"Output file failed to open"<<endl;
		exit(EXIT_FAILURE);
	}
	out << "123456789012345678901234567890123456789012345678901234567890" << endl;

	vector<Employee> empList;
	vector<Customer> cusList;
	int empID[50];
	int cusID[50];
	int empCount = 0;
	int cusCount = 0;

	while (!cin.eof()) {
	    char ch; cin >> ch;

		if (ch == 'e') {
			Employee emp;
			cin >> emp.id;
			cin >> emp.name;
      		empID[empCount] = emp.id;
			empList.push_back(emp);
			empCount++;
		}

		if (ch == 'c') {
			Customer cus;
			cin >> cus.id;
			cin >> cus.name;
			cin >> cus.balance;
      		cusID[cusCount] = cus.id;
			cusList.push_back(cus); 
			cusCount++;
		}

		if (ch == 't') {
			int cusNum; cin >> cusNum;
			int empNum; cin >> empNum;
			char wd; cin >> wd;
			double amount; cin >> amount;

			int cusIndex = 0;
			for (int i = 0; i < cusCount; i++) {
				if (cusID[i] == cusNum)
					cusIndex = i;
			}

			int empIndex = 0;
			for (int i = 0; i < empCount; i++) {
				if (empID[i] == empNum)
					empIndex = i;
			}

			char posNeg;
			if (wd == 'w') {
		    	posNeg = '-';
		        cusList.at(cusIndex).balance -= amount;
		    }
			else {
		        posNeg = '+';
		        cusList.at(cusIndex).balance += amount;
		    }

		    out.setf(ios::fixed);
		    out.setf(ios::showpoint);
		    out.precision(2);
			out << right << setw(10) << cusList.at(cusIndex).name << "\t" << right << setw(10) << empList.at(empIndex).name << " " << posNeg << "$" << right << setw(7) << amount << " $" << right << setw(9) << cusList.at(cusIndex).balance << endl;
		}
	}
	
	out.close();
	
	return 0;
}



