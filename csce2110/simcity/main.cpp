#include <string>
#include "region.h"

int main(){
    //Take in the name of the file containing the configuration information
    string configname;
    cout<<"Enter the name of the file containing the simulation configuration information: ";
    cin>>configname;
    string regionFile;
    int timeLimit;
    int refRate;
    Region region;
    //Open the file named by the user
    fstream file (configname, ios::in);
    if(file.is_open())
    {
        string temp = "";
        getline(file, temp, ':');
        getline(file, regionFile);
        region.setRegion(regionFile);
        getline(file, temp, ':');
        getline(file, temp);
        timeLimit = stoi(temp);
        region.setTimeLimit(timeLimit);
        getline(file, temp, ':');
        getline(file, temp);
        refRate = stoi(temp);
        region.setRefRate(refRate);
    }
    file.close();
    //Print out the initial state
    region.print();
    region.zoom();

    return 0;
}
