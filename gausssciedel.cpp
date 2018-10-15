#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

int main(){

    double x , y , z ;
    double x1, y1, z1;
    x = y = z =0;

    for( int i =0; i < 8; i++){

            cout<<i+1<<endl<<"x: "<<x<<endl<<"y: "<<y<<endl<<"z: "<<z<<endl;

        x = (0.795 + 0.05*y + 0.10*z)/1.02;
        z = (1.398 + 0.11*x + 0.12*y)/(1.04);
        y = (0.849 + 0.11*x + 0.05*z)/(1.03);

        double mx =floor(x*1000);
        double mz =floor(z*1000);
        double my =floor(y*1000);
        double mx1 = floor(x1*1000);
        double my1 = floor(y1*1000);
        double mz1 = floor(z1*1000);


          if(my1 == my && i > 2 && mx1 == mx && mz1 == mz){
        //    break;
        }


        x1 = x; y1 = y; z1 = z;





    }




}
