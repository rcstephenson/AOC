#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <vector>

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
    int dp,dy; // differential position measurment
    cout << "\nStarting..." << endl;
    vector<string> data =  read_file();
    string c;
    cout << data[0][1] << endl;
    for (int ij=0; ij<WIDTH*HEIGHT;ij++){
        x=ij%WIDTH;
        y=ij/HEIGHT;
        c=data[y][x];
        for (int lm=0; lm<WIDTH*HEIGHT;lm++){
        
        }
    } 
    cout << "\nEOF.\n";    
}
