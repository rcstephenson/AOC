#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

#define WIDTH 24
#define HEIGHT 24

vector<string> read_file() {
    string line;
    std::vector<string> result;
    ifstream myfile ("input.txt"); // opening file
   
    if(myfile.is_open()) {
        cout << "Getting input...\n\n";
        while(getline(myfile,line)) {
            result.push_back(line);
        } 
    myfile.close(); // closing file
    } else {
        cout << "Failed to Read File.";
    }
    return result;
}


int main() {
    int x,y; // current position measurment 
    int dx,dy; // differential position measurment
    float slope,ang;
    cout << "\nStarting..." << endl;
    vector<string> data =  read_file();
    // map init
    vector<vector<set<int>>> ast_los;
    vector<set<int>> w_zeros;
    set<int> e = {}; 
    for (int i=0; i<WIDTH;i++)    
            w_zeros.push_back(e);   
    for (int j=0;j<HEIGHT;j++) 
        ast_los.push_back(w_zeros);
    // -- 

    char c, c2;    
    
    for (int ij=0; ij<WIDTH*HEIGHT;ij++){
        x=ij%WIDTH;
        y=ij/HEIGHT;
        c=data[y][x];
        
        dx=0;
        dy=0;
        if (c == '#')
        {
            
            for (int lm=0; lm<WIDTH*HEIGHT;lm++){
                dx=lm%WIDTH;
                dy=lm/HEIGHT;  
                c2=data[dy][dx];
                ang=0;
                slope=0;
                if (c2 == '#') {    
                    if (abs(y - dy)== 0){
                        slope = (x - dx) > 0 ? 90 : 270;
                    }
                    else if (abs(x-dx) == 0) {
                        slope = (y - dy) > 0 ? 0 : 180;
                    } else { 
                        slope =  (atan2((float)(y-dy),(float)(x-dx)) * (float)(180.0 / 3.14159265));
                    }
                    if (ast_los[y][x].end() == ast_los[y][x].find(slope))  {
                        ast_los[y][x].insert(slope);
                    }
                }
            }
        }
    } 
    int maxV=0;
    int V=0;
    for (auto it : ast_los) {
        for (auto ij : it) {
            V= ij.size();
            (V == 0) ? printf("%4c",'.') : printf("%4d",V); // why use if statements if you just found out what a ternary is !?
            //printf("%4d",V);
            if (V > maxV) 
                maxV = V;
        }
        cout << endl;
    }
    cout << endl << "Max: " << maxV << endl; 
    cout << "EOF.\n";    
}
