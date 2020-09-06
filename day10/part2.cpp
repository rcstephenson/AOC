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

   /*
    * For part 2 solution can be found by iterating through a list for points sorted by their angle
    * step to some angle and increment if a value found was found at the current angle, then step to the next angle
    * stop at 200th increment.
    */

   // make a new scan for case (X,Y)

int main() {
    int org_x = 21;
    int org_y = 22;
    int x2,y2; // second position measurment
    float ang; // angle between current and second asteriod 
    char c,c2; // char at position  

    vector<string> data =  read_file(); // load input file


    // make a hash table of ast_los[ang] = {astriod @ (x,y)} 
    // i.e. ast_los= {'0': {(0,1),(0,2),...}, '90': {...}, ..., '359.*': {...} };

    // vector<vector<vector<float>>> ast_los; // asteriod's line of sight: f(x,y)={angles}
    // vector<vector<float>> w_zeros;
    // vector<float> e = {}; 
    // for (int i=0; i<WIDTH;i++) w_zeros.push_back(e);   
    // for (int j=0;j<HEIGHT;j++) ast_los.push_back(w_zeros);

    cout << "\nStarting..." << endl;


            for (int lm=0; lm<WIDTH*HEIGHT;lm++) {
                x2=lm%WIDTH;
                y2=lm/HEIGHT;  
                c2=data[y2][x2];

                ang=0;
                if (c2 == '#') {    
                    if (abs(org_y - y2)== 0) {
                        ang = ((org_x - x2) < 0) ? 90 : 270;
                    }
                    else if (abs(org_x-x2) == 0) {
                        ang = ((org_y - y2) < 0) ? 0 : 180;
                    } else { 
                        ang =  (atan2((float)(org_x-x2),(float)(org_y-y2)) * (57.29577951308));
                        if (ang < 0) {
                            ang += 360.0;
                        }
                    }
                    // ast_los[y2][x2].insert(ang);

                    
                }
            }
         
    int maxV=0;
    int V=0;
    int ind_x,ind_y = 1;
    for(ind_x; ind_x<=WIDTH;ind_x++){
        printf("%-4d",ind_x);
    }
    cout << endl;
    for (auto it : ast_los) {
        // cout << ind_y << " ";
        printf("%-2d",ind_y);
        ind_y+=1;
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
