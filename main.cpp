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
void rational();



int conversion(long double number) //This function converts decimals to integers
{
    string stringDouble = to_string(number);
    cout << "As a string: " << stringDouble << endl; 
    int decimal = stringDouble.find(".");
    int length = stringDouble.length();
    length = length - decimal;
    int exponent = pow(10, length);
    int wholeNumber =  number * exponent;
    //remove unnnecessary 0's

    //coversion issues

    return wholeNumber;

}

void rational(double number2)
{
   int numberTest = conversion(number2);
   int primeTest = conversion(M_PI);
   cout << "PI converted too: " << primeTest <<endl;
   int test = numberTest % primeTest;
   cout << "The test results were: " << test << endl;

}

int fPrime(int number3) //This function calculates finalPrime
{   
    string stringDouble = to_string(number3);
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
    vector <long double> y2; 
    vector <long double> y;
    vector <long double> x;
    double start;
    double step = 0.1; //will be precions
    double stoppingValue;
    cout << "What is the starting value of x (double 0.0)/ STARTING RANGE" << endl;
    cin >> start;
    cout << "To what value of x would you want to find the rational points to ?\n This is a double (0.0)/ ENDING RANGE" <<endl;
    cin >> stoppingValue;

    for(double x_run = 0.0; x_run < stoppingValue; x_run+=step)
    {
       long double y2_run =  pow(x_run, 3) + a * x_run + b;
       long double y_run = sqrt(y2_run);
        y.push_back(y_run);
        y2.push_back(y2_run);
        x.push_back(x_run);
        // cout << "The value of y^2 is " << y2_run << endl;
        // cout << "The value of y is " << y_run << endl;
        // cout << "For the value of x " << x_run << endl;
    }
   


    for(int i = 0; i < y.size(); i++)
    {
        int convertedY = conversion(y[i]);
        int lengthY = lengthOf(convertedY);
        int finalPrimeY = fPrime(convertedY/30);
        int k;
        cout << "y is " << y[i] <<endl;
        cout << "The length of the y value is " << lengthY << endl;
        cout << "y converted to an equivalent whole number " << convertedY << endl;
        cout << "Therefore the final prime to test too is " << finalPrimeY <<endl;

        for(int k = 0; k < 2; k++)
        {  
            cout << "loop";
            if(convertedY % primes(finalPrimeY, k) == 0){
                cout << "\n\nRATIONAL POINT!!!\n";
                cout << "The point y is :" << y[i] <<endl;
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