#include <math.h>
#include <iostream>
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
    int   x,y; // current position measurment 
    int x2,y2; // second position measurment
    float ang; // angle between current and second asteriod 
    char c,c2; // char at position  

    vector<string> data =  read_file(); // load input file

    vector<vector<set<float>>> ast_los; // asteriod's line of sight: f(x,y)={angles}
    vector<set<float>> w_zeros;
    set<float> e = {}; 
    for (int i=0; i<WIDTH;i++) w_zeros.push_back(e);   
    for (int j=0;j<HEIGHT;j++) ast_los.push_back(w_zeros);

    cout << "\nStarting..." << endl;

    for (int ij=0; ij<WIDTH*HEIGHT;ij++){
        x=ij%WIDTH;
        y=ij/HEIGHT;
        c=data[y][x];
        
        x2=0;
        y2=0;
        if (c == '#')
        {
            
            for (int lm=0; lm<WIDTH*HEIGHT;lm++){
                x2=lm%WIDTH;
                y2=lm/HEIGHT;  
                c2=data[y2][x2];

                ang=0;
                if (c2 == '#') {    
                    if (abs(y - y2)== 0) {
                        ang = ((x - x2) < 0) ? 90 : 270;
                    }
                    else if (abs(x-x2) == 0) {
                        ang = ((y - y2) < 0) ? 0 : 180;
                    } else { 
                        ang =  (atan2((float)(x-x2),(float)(y-y2)) * (57.29577951308));
                        if (ang < 0) {
                            ang += 360.0;
                        }
                    }
                    if (ast_los[y][x].end() == ast_los[y][x].find(ang))  {
                        ast_los[y][x].insert(ang);

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
} // sol: 243 @ (21,22)
