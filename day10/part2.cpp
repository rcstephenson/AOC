#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
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
    const int org_x = 20; // astriod of origin
    const int org_y = 21; // astriod of origin
    int x2,y2; // second position measurment
    float ang; // angle between current and second asteriod 
    char c2; // char at position  

    vector<string> data =  read_file(); // load input file


    // map of points to corresponding asteriod locations
    map<float, vector<pair<int,int>>> ast_los ;

    cout << "\nStarting..." << endl;


    for (int lm=0; lm<WIDTH*HEIGHT;lm++) {
        x2=lm%WIDTH;
        y2=lm/HEIGHT;  
        c2=data[y2][x2];

        ang=0;
        if (c2 == '#') {    
            if (abs(org_y - y2)== 0) {
                ang = ((org_x - x2) > 0) ? 90.0 : 270.0;
            }
            else if (abs(org_x-x2) == 0) {
                ang = ((org_y - y2) > 0) ? 0.0 : 180.0;
            } else { 
                ang =  -(atan2((float)(org_x-x2),(float)(org_y-y2)) * (57.29577951308));
                if (ang < 0) {
                    ang += 360.0;
                }
            }
            //cout << ang << endl;
            ast_los[ang].push_back(pair<int,int>(x2,y2));
        }
    }
         
     int maxV=0;
     int V=0;

    

   /*
    * Sorts through the asteriods at each angle relative to the 'origin' astriod  
    */
    for (auto angle_points : ast_los) {
        auto angle = angle_points.first;
        auto points = angle_points.second;
        sort(points.begin(),points.end(), 
                [org_x,org_y](pair<int,int> p1, pair<int,int> p2) -> bool {
                    bool xchk = (p1.first - org_x) > (p2.first - org_x);
                    bool ychk = (p1.second- org_y) > (p2.second- org_y);
                    bool result =  xchk | ychk;
                    return result;
                }        
        );
            if (1) {
            //point.pop_back();
            printf("θ=%0.2f°\n", angle);
            for (auto p : points) {
                printf("\t(%d,%d)\n",p.first,p.second);
            }
            }
    }

    int hit =0;
    pair<int,int> ans;
    for (auto angle_points : ast_los) {
        auto angle = angle_points.first;
        auto points = angle_points.second;
        if (hit == 200-1){
            ans = points.back();
            break;
        } else{
        points.pop_back();
        hit +=1;
        }
        
    }

    printf("200th Asteriod @ \t(%d,%d)\n",ans.first,ans.second); 
    cout << "ANS:" << ans.first*100 + ans.second << endl;
    cout << "EOF.\n";    
} // sol: 243 @ (21,22)
