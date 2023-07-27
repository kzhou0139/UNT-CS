/**
 * @file main.cpp
 * @author Rhea Pookulangara
 * @brief This is the main file, and it is the only file that directly takes in user input
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <string>
#include "region.h"
#include "residential.h"
#include "commercial.h"
#include "industrial.h"
#include "powerline.h"
#include "road.h"

/**
 * @brief Create a new region object to store the new regions
 *
 */
Region* regionObj = new Region();

/**
 * @brief Create a Region object
 *
 * @param regionFile
 */
void createRegion(string regionFile){
    vector<vector<Cell*> > region;
    vector<Cell*> row;
    string line, word;

    /**
     * @brief Open the file and use the data to create cells for each variable
     *
     * @return fstream
     */
    fstream regionlay (regionFile, ios::in); //Opening the file
    if(regionlay.is_open())
    {
        int y = 0;
        while (getline(regionlay, line))
        {
            row.clear();
            stringstream str(line);
            Cell* temp=nullptr;
            int x = 0;
            while(getline(str, word, ',')){ //Setting each variable to a cell as defined in the project
                if(word=="R"){
                    temp=new ResidentialCell(x, y, regionObj);
                } else if (word=="I") {
                    temp=new Industrial(x, y, regionObj);
                } else if (word=="C") {
                    temp=new Commercial(x, y, regionObj);
                } else if (word=="#"||word=="T"||word=="P") { //Treat powerplant and powerline as the same
                    temp = new Powerline(x, y, word);
                } else{ //Consider a space a "road"
                    temp=new Road(x, y, word);
                }
                row.push_back(temp);
                x++;
            }
            region.push_back(row);
            y++;
        }
    } else {
        cout<<"Could not open file\n";//If file is invalid
    }
    regionObj->setRegion(region);
}

/**
 * @brief The main function allowing the user to input a file name with the configuration information and bounds to zoom in on a specific region
 *
 * @return int
 */
int main(){
    //Take in the name of the file containing the configuration information
    string configname;
    cout<<"Enter the name of the file containing the simulation configuration information: ";
    cin>>configname;
    string regionFile;
    int timeLimit;
    int refRate;
    /**
     * @brief Open the file containing the configuration information
     *
     * @return fstream
     */
    //Open the file named by the user
    fstream file (configname, ios::in);
    if(file.is_open())
    {
        string temp = "";
        getline(file, temp, ':');
        getline(file, regionFile);
        createRegion(regionFile);
        getline(file, temp, ':');
        getline(file, temp);
        timeLimit = stoi(temp);
        regionObj->setTimeLimit(timeLimit);
        getline(file, temp, ':');
        getline(file, temp);
        refRate = stoi(temp);
        regionObj->setRefRate(refRate);
    }
    file.close();
    //Print out the initial state, simulate, print the final output with added information, and allow users to zoom in if they would like
    regionObj->print();
    regionObj->simulate();
    regionObj->finalOutput();
    regionObj->zoom();

    return 0;
}
