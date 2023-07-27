#ifndef CELL_H
#define CELL_H

using namespace std;
#include <string>

class Cell{
    public:
    //Virtual so other functions can inherit it and override it
    virtual void simulate()=0;
    //Get and set population and pollution
    int getPopulation(){
        return population;
    }
    void setPopulation(int p){
        population = p;
    }
    int getPollution(){
        return pollution;
    }
    void setPollution(int pl){
        pollution = pl;
    }
    bool getPower(){
        return hasPower;
    }
    void setPower(bool po){
        hasPower = po;
    }
    void setType(string t){
        type = t;
    }
    string getType(){
        return type;
    }
    protected:
    int population;
    int pollution;
    int x, y;
    bool hasPower;
    string type;
};

#endif
