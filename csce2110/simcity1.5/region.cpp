/**
 * @file region.cpp
 * @author Rhea Pookulangara
 * @brief This is the function definition file with information for every type of cell in every region
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "region.h"

/**
 * @brief Construct a new Region:: Region object
 *
 * @param timestep
 * @param timeLimit
 * @param workers
 * @param goods
 * @param refRate
 *
 */
Region::Region(){
    timestep = 0;
    timeLimit = 0;
    workers = 0;
    goods = 0;
    refRate = 0;
}
/**
 * @brief Get the timestep in the region class
 *
 * @return int
 */
//Setters and Getters to transfer data outside of the cpp file itself
/**
 * @brief Get the timestep in the region class
 *
 * @return int
 */
int Region::getTimestep(){
    return timestep;
}
/**
 * @brief Set the number of workers
 *
 * @param w
 */
void Region::setWorkers(int w){
    workers = w;
}
/**
 * @brief Get the number of workers
 *
 * @return int
 */
int Region::getWorkers(){
    return workers;
}
/**
 * @brief Get worker list
 *
 * @return vector
 */
vector<Worker*> Region::getWorkerList() {
  return workerList;
}
/**
 * @brief Set the number of goods
 *
 * @param g
 */
void Region::setGoods(int g){
    goods = g;
}
/**
 * @brief Get the number of goods
 *
 * @return int
 */
int Region::getGoods(){
    return goods;
}
/**
 * @brief Set the refresh rate
 *
 * @param rr
 */
void Region::setRefRate(int rr){
    refRate = rr;
}
/**
 * @brief Get the time limit
 *
 * @param tl
 */
void Region::setTimeLimit(int tl) {
    timeLimit = tl;
}
/**
 * @brief Set the number of cats
 *
 * @param c
 */
void Region::setCats(int c){
    cats = c;
}
/**
 * @brief Set the income of each household
 *
 * @param n
 */
void Region::setIncome(int n){
    income = n;
}
/**
 * @brief Get the number of cats
 *
 * @return int
 */
int Region::getCats(){
    return cats;
}
/**
 * @brief Get the income per household
 *
 * @return int
 */
int Region::getIncome(){
    return income;
}

/**
 * @brief Set the region based on the type of variable
 *
 * @param r
 */
void Region::setRegion(vector<vector<Cell*> > &r) {
    region = r;
    for (int x = 0; x < region.size(); x++) {
        for (int y=0; y<region[0].size();y++) {
            if (region[x][y]->getType() == "#" || region[x][y]->getType() == "P" || region[x][y]->getType() == "T") {
                setPowerAccess(x, y);
            }
        }
    }
    //Set the adjacency list for cells to be used for pollution and the other functions like population
    for (int x = 0; x < region.size(); x++) {
        for (int y=0; y<region[0].size();y++) {
            region[x][y]->adj();
        }
    }
}

/**
 * @brief Simulate the region based on the number of timesteps and location of each variable
 *
 */
void Region::simulate() {
    for (int i=0; i<timeLimit; i++) {
        timestep++;

        //Simulate all of the commercial cells
        for(int x=0;x<region.size();x++)
        {
            for(int y=0;y<region[x].size();y++)
            {
                if (region[x][y]->getType() == "C") {
                    region[x][y]->simulate();
                }
            }
        }

        // Simulate all of the industrial cells
        for(int x=0;x<region.size();x++)
        {
            for(int y=0;y<region[x].size();y++)
            {
                if (region[x][y]->getType() == "I") {
                    region[x][y]->simulate();
                }
            }
        }

        //Simulate all of the residential cells
        for(int x=0;x<region.size();x++)
        {
            for(int y=0;y<region[x].size();y++)
            {
                if (region[x][y]->getType() == "R") {
                    region[x][y]->simulate();
                }
            }
        }

        //Update the population of all of the cells
        for(int x=0;x<region.size();x++)
        {
            for(int y=0;y<region[x].size();y++)
            {
                region[x][y]->updatePop();
            }
        }

        if (timestep%refRate==0) {
            print();
        }
    }
}

//Prints out each region state based on the refresh rate given in the user config.txt file
void Region::print(){
    cout<<"Region Map:"<<endl;
    for(int i=0;i<region.size();i++)
    {
        for(int j=0;j<region[i].size();j++)
        {
            if (region[i][j]->getPopulation()>0){
                cout<<region[i][j]->getPopulation();
            }
            else{
                cout<<region[i][j]->getType();
            }
            cout << " ";
        }
        cout<<endl;
    }
    cout<<"Timestep: "<<timestep<<endl;
    cout<<"Number of Available Workers: "<<workers<<endl;
    cout<<"Number of Available Goods: "<<goods<<endl<<endl;
}

/**
 * @brief Allows the user to "zoom in" on a specific part of the region map based on two sets of x & y coordinates
 *
 */
void Region::zoom(){
    bool inBounds = false;
    int x1, x2, y1, y2;
    while (!inBounds){
        cout<<"Enter the first x-coordinate of the region you would like to analyze: ";
        cin>>x1;
        cout<<"Enter the first y-coordinate of the region you would like to analyze: ";
        cin>>y1;
        cout<<"Enter the second x-coordinate of the region you would like to analyze: ";
        cin>>x2;
        cout<<"Enter the second y-coordinate of the region you would like to analyze: ";
        cin>>y2;
        if (x1<0||x2>region.size()||x1>x2){
            cout<<"Out of bounds."<<endl;
        } else if (y1<0||y2>region[0].size()||y1>y2){
            cout<<"Out of bounds."<<endl;
        } else {
            inBounds = true;
        }
    }
    int pop = 0;
    int pol = 0;
    cout<<"Region Map of this Area:"<<endl;
    for(int x=x1;x<=x2;x++){
        for(int y=y1;y<=y2;y++){
            pop+=region[x][y]->getPopulation();
            pol+=region[x][y]->getPollution();
            if(region[x][y]->getPopulation()>0){
                cout<<region[x][y]->getPopulation();
            }
            else{
                cout<<region[x][y]->getType();
            }
            cout<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Population in this Area: "<<pop<<endl;
    cout<<"Pollution in this Area: "<<pol<<endl;
}
/**
 * @brief Determines the power for a region
 *
 * @param x
 * @param y
 */
void Region::setPowerAccess(int x, int y) {
    for(int x1=x-1; x1<x+1; x1++) {
        if (x1<0 || x1>=region.size())
            continue;
        for (int y1=y-1; y1<y+1; y1++) {
            if (y1<0 || y1>=region[0].size())
                continue;
            if (x1==x && y1==y)
                continue;
            region[x1][y1]->setPower(true);
        }
    }
}
/**
 * @brief Set the cats
 *
 * @param c
 */
void Region::setCats(int c){
    cats = c;
}
/**
 * @brief Set the income
 *
 * @param n
 */
void Region::setIncome(int n){
    income = n;
}
/**
 * @brief Get the number of cats
 *
 * @return int
 */
int Region::getCats(){
    return cats;
}
/**
 * @brief Get the income
 *
 * @return int
 */
int Region::getIncome(){
    return income;
}
/**
 * @brief This the final output with the added information relating to population and pollution of each region
 *
 */
void Region::finalOutput() {
    int resPop = 0;
    int comPop = 0;
    int indPop = 0;
    int totPollution = 0;
    int cats = 0;
    int income = 0;

    for(int i=0;i<region.size();i++)
    {
        for(int j=0;j<region[i].size();j++)
        {
            if (region[i][j]->getType() == "R") {
                resPop += region[i][j]->getPopulation();
                cats = region[i][j]->getCats();
                income = region[i][j]->getIncome();
            }
            else if (region[i][j]->getType() == "C") {
                comPop += region[i][j]->getPopulation();
            }
            else if (region[i][j]->getType() == "I") {
                indPop += region[i][j]->getPopulation();
            }
            totPollution += region[i][j]->getPollution();
        }
    }
    // Output each parameter, new ones include income and cats
    cout<<"Residential Population: "<<resPop<<endl;
    cout<<"Industrial Population: "<<indPop<<endl;
    cout<<"Commercial Population: "<<comPop<<endl;
    cout<<"Total Pollution: "<<totPollution<<endl;
    cout<<"Final Pollution Map:"<<endl;
    cout<<"Total Income: "<<income<<endl;
    cout<<"Total Cats: "<<cats<<endl;
    for(int i=0;i<region.size();i++)
    {
        for(int j=0;j<region[i].size();j++)
        {
            if (region[i][j]->getPollution()>0){
                cout<<region[i][j]->getPollution();
            }
            else{
                cout<<region[i][j]->getType();
            }
            cout << " ";
        }
        cout<<endl;
    }
}
