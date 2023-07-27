#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "cell.h"
#include "residential.h"
#include "commercial.h"
#include "industrial.h"
#include "powerline.h"
#include "road.h"
using namespace std;

class Region{
    private:
    //Declaring data variables
    vector<vector<string> > region; //Cell* when implemented
    int timestep;
    int workers;
    int goods;
    int refRate;
    int timeLimit;

    public:
    Region(){
        timestep = 0;
        timeLimit = 0;
        workers = 0;
        goods = 0;
        refRate = 0;
    }
    //Setters and Getters to transfer data outside of cpp file
    int getTimestep(){
        return timestep;
    }
    void setWorkers(int w){
        workers = w;
    }
    int getWorkers(){
        return workers;
    }
    void setGoods(int g){
        goods = g;
    }
    int getGoods(){
        return goods;
    }
    void setRefRate(int rr){
        refRate = rr;
    }
    void setTimeLimit(int tl) {
        timeLimit = tl;
    }

    //void Simulate()
    //void findRegion()
//Sets the region based on information from csv file
    void setRegion(string regionFile){
        // Read in the data and store chars in data
        vector<string> row; // change to Cell*
        string line, word;

        fstream regionlay (regionFile, ios::in);
        if(regionlay.is_open())
        {
            int y = 0;
            while (getline(regionlay, line))
            {
                row.clear();
                stringstream str(line);
                Cell* temp=nullptr;
                int x = 0;
                while(getline(str, word, ',')){
                    if(word=="R")
                        temp=new ResidentialCell(x, y);
                    else if (word=="I")
                        temp=new IndustrialCell(x, y);
                    else if (word=="C")
                        temp=new CommercialCell(x, y);
                    else if (word=="#"||word=="T"||word=="P") // treat powerplant and powerline as same
                        temp=new Powerline(x, y, word);
                    else if (word=="-")
                        temp=new Road(x, y);
                    row.push_back(temp);
                    x++;
                }
                region.push_back(row);
                y++;
            }
        }
        else
        {
            cout<<"Could not open file\n";
        }
    }
    //Prints out region state based on refresh rate
    void print(){
        cout<<"Region Map:"<<endl;
        for(int i=0;i<region.size();i++)
        {
            for(int j=0;j<region[i].size();j++)
            {
                cout<<region[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"Timestep: "<<timestep<<endl;
        cout<<"Number of Available Workers: "<<workers<<endl;
        cout<<"Number of Available Goods: "<<goods<<endl;
    }
    void zoom(){
        int x1, x2, y1, y2;
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
            return;
        }
        if (y1<0||y2>region[0].size()||y1>y2){
            cout<<"Out of bounds."<<endl;
            return;
        }
        for(int x=x1;x<=x2;x++){
            for(int y=y1;y<=y2;y++){
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
    }
};
