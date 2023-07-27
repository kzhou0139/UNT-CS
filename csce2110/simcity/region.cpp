#include "region.h"

void Region::print(){
    cout<<"Region Map:"<<endl;
    for(int i=0;i<region.size();i++)
    {
        for(int j=0;j<region[i].size();j++)
        {
            cout<<region[i][j]<<" ";
        }
        cout<<endl;
    }
}
