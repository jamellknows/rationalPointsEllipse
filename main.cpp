#include <iostream>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
int primes();
int conversion();
void curve();


int conversion(double number) //This function converts decimals to integers
{
    string stringDouble = to_string(number);
    int length = stringDouble.length();
    int wholeNumber =  number * pow(10, length);

    return wholeNumber;

}

int fPrime(int number) //This function calculates finalPrime
{   
    string stringDouble = to_string(number);
    int length = stringDouble.length();
    char firstchar = stringDouble[0];
    int  firstNum = atoi(&firstchar);
    int finalPrime = (firstNum + 1) * pow(10, length);

    return finalPrime;

}

int lengthOf(int number)
{
    string stringDouble = to_string(number);
    int length = stringDouble.length();
    return length;
}

int primes(int testLength, int primechoice){

    int number = testLength;
    vector <long double> arr1;
    vector <long double> arr2;
    vector <long double> prime1;
    vector <long double> prime2;
    long double theta = M_PI / 3;

    for( int i = 0; i < number ; i++)
    {
        double y_1 = theta * (1 + 6 * i);
        y_1 = sqrt(pow(y_1/theta, 2) - 0.25);
        arr1.push_back(y_1);
        double y_2 = 5 * theta * (1 + ((6 / 5) * i));
        y_2 = sqrt(pow(y_2/theta, 2) - 0.25); 
        arr1.push_back(y_2);
      


    }
    int lArr1 = arr1.size();

    sort(arr1.begin(), arr1.begin() + lArr1);
    for (int k = 0; k < lArr1; k++){
        if(((k + 1) % 4) == 0){
                arr1[k] = arr1[k] + 1;
       
        }
        prime1.push_back(floor(arr1[k]) - 1);
        prime1.push_back(floor(arr1[k]) + 1);
    }
    return prime1[primechoice];
}


void curve(double a, double b)
{   
    // cout << "To what precision do you want to plot the curve? integer value " << endl;
    // int precision; 
    // cin >> precision;
    vector <double> y2; 
    vector <double> y;
    vector <double> x;
    double step = 0.1; //will be precions
    double stoppingValue;
    cout << "To what value of x would you want to find the rational points to ?\n This is a double (0.0)" <<endl;
    cin >> stoppingValue;

    for(double x_run = 0.0; x_run < stoppingValue; x_run+=step)
    {
        double y2_run =  pow(x_run, 3) + a * x_run + b;
        double y_run = sqrt(y2_run);
        y.push_back(y_run);
        y2.push_back(y2_run);
        x.push_back(x_run);
        // cout << "The value of y^2 is " << y2_run << endl;
        // cout << "The value of y is " << y_run << endl;
        // cout << "For the value of x " << x_run << endl;
    }
    cout << "output of y vector" <<endl;
    for(int i =0; i < y.size(); i++)
    {
        cout << y[i] <<endl;
    }


    for(int i = 0; i < y.size(); i++)
    {
        int convertedY = conversion(y[i]);
        int lengthY = lengthOf(convertedY);
        int finalPrimeY = fPrime(convertedY);
        int k;
        cout << "y is " << y[i] <<endl;
        cout << "y converted is " << convertedY << endl;
        cout << "length of y point " << lengthY << endl;
        cout << "the final prime to test to is " << finalPrimeY <<endl;
        for(int k = 0; k < (convertedY / 2); k ++)
        {  
            if(convertedY % primes(convertedY, k) == 0){
                cout << "\n\nRATIONAL POINT!!!\n";
                cout << "The point y is : " << y[i] <<endl;
                cout << "The point x is :" << x[i] <<endl;
            
            }
         
            
         }


        
    }



}

int main()
{
    double a, b;
    double root = sqrt(2);
    double x, y;
    int testLength = 50;
    double step = 0.1;
    double start;
    double stop = 2 * M_PI;

    //y^2 = x^3 + ax + b
    //draw the curve 
    //input a input b 
    //find y 

    //find the points
    //find rational points
    cout << "\n\n\tWELCOME TO THE RATIONAL POINTS ON A CURVE FINDER!!!\n\n";
    cout << "What value of a and b do you want to use?\n";
    cout << "The fomula for a curve is y^2 = x^3 + ax + b\n";
    cout << "Enter a\n"; cin>>a;
    cout << "Enter b\n"; cin>>b;
    curve(a,b);
    




    // for(double thetaM = start; thetaM <= stop ; thetaM+=step)
    // {
    //     x = cos(thetaM);
    //     cout << "The point x is " << x << endl;
    //     y = root/x;
    //     int z = conversion(y);

    //     for(int i; i < testLength; i++){
    //         if(z % primes(testLength, i) == 0 ){
    //             cout << "Rational point"<<endl;
    //             cout << "The point y is " << y << endl;
    //             cout << z << endl;
    //         }
    //     }
        
    // }
   
    
    //cool we can find rational points
    
    return 0;
}