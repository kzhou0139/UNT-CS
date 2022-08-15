/* 
Author: Kelly Zhou (kellyzhou@my.unt.edu)
Date:   23 September 2021        
Instructor: Poli Nemkova and Solomon Ubani
Description: Switch-Case - recieve user input for which season it is then output a statement in regards to the season through switch cases.
*/

#include <iostream>
using namespace std;

int main() {
    enum Season {Summer = 'S', Fall = 'F', Winter = 'W', Spring = 'G'};
    char val;
    cout<<"Please enter season ('S' = Summer, 'F' = Fall, 'W' = Winter, 'G' = Spring): ";
    cin>>val;

    switch (toupper(val)) {
        case Summer:
            cout<<"It is rather hot outside."<<endl;
            break;
        case Fall:
            cout<<"The weather looks good."<<endl;
            break;
        case Winter:
            cout<<"It is rather cold outside."<<endl;
            break;
        case Spring:
            cout<<"The flowers are blooming."<<endl;
            break;
        default:
            cout<<"Wrong choice"<<endl;
            break;
    }

    return 0;
}
