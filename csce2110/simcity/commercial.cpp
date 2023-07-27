#include "commercial.h"

Commercial::Commercial(int xVal, int yVal){
    this->x = xVal;
    this->y = yVal;
}

Commercial::adjIndex(vector<vector<cell>> &region, int adjSearch[], int i, int j){
    if (i==0){
        adjSearch[0] = 0;
        adjSearch[1] = 1;
    }
    else if (i==region.size()){
        adjSearch[0] = i-1;
        adjSearch[1] = i;
    }
    else {
        adjSearch[0] = i-1;
        adjSearch[1] = i+1;
    }
    if (j==0) {
        adjSearch[2] = j;
        adjSearch[3] = j+1;
    }
    else if (j==region[0].size()){
        adjSearch[2] = j-1;
        adjSearch[3] = j;
    }
    else {
        adjSearch[2] = j-1;
        adjSearch[3] = j+1;
    }
    return adjSearch;
}

Commercial:CommercialUpdate (vector<vector<cell>> &region, int adjSearch[], int workers, int goods){
    for (int i = 0; i < region.size(); i++){
        for (int j = 0; j < region[0].size; j++){
            int adjSearch[4];
            if ((region[i][j] == 'R' || region[i][j] == 'I' || region [i][j] == 'C') && workers >=1 && goods >=1){
                adjIndex(region, adjSearch, i, j);
                int count = 0;
                for (int a = adjSearch[0]; i <= adjSearch[1]; i++){
                    for (int b = adjSearch[2]; b <= adjSearch[3]; b++){
                        if (region[a][b] == 'T' || region[a][b] == '#')  {
                            count++;
                        }
                    }
                    if (count >=1){
                        region([i][j])++;
                    }
                }
            }
            else if ((region[i][j] == 'R' || region[i][j] == 'I' || region [i][j] == 'C') && workers >=1 && goods >=1){
                adjIndex(region, adjSearch, i, j);
                int count = 0;
                for (int a = adjSearch[0]; i <= adjSearch[1]; i++){
                    for (int b = adjSearch[2]; b <= adjSearch[3]; b++){
                        if (region[a][b] >= 1)  {
                            count++;
                        }
                    }
                    if (count >=1){
                        region([i][j])++;
                    }
                }
            }
            else if ((region[i][j] == 1) && workers >=1 && goods >=1){
                adjIndex(region, adjSearch, i, j);
                int count = 0;
                for (int a = adjSearch[0]; i <= adjSearch[1]; i++){
                    for (int b = adjSearch[2]; b <= adjSearch[3]; b++){
                        if (region[a][b] >= 1)  {
                            count++;
                        }
                    }
                    if (count >=2){
                        region([i][j])++;
                    }
                }
            }
        }
    }
}
