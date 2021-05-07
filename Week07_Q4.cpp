#include<iostream>
#include<string>//allows use of string variable
using namespace std;
//function prototypes
int getNumAccidents(string region);
void findLowest(int& north, int& south, int& east, int& west, int& central, string& regOne, string& regTwo, 
string& regThree, string& regFour, string& regFive);

int main()
{
    string regionOne = "north", regionTwo = "south", regionThree = "east", regionFour = "west",
    regionFive = "central";//declaring and assigning value to string variables
    int northAccidents, southAccidents, eastAccidents, westAccidents, centralAccidents;//declaring variables for 
    //user input
    cout << "This program will find the safest region of your city for driving by determining which region ";
    cout << endl << "had the least number of automobile accidents last year." << endl << endl;//explaining program
    //calling function getNumAccidents and assigning returned value to a new variable every time it is called
    //passing name of region as argument so that it can be displayed and let the user know what input to enter
    northAccidents = getNumAccidents(regionOne);
    southAccidents = getNumAccidents(regionTwo);
    eastAccidents = getNumAccidents(regionThree);
    westAccidents = getNumAccidents(regionFour);
    centralAccidents = getNumAccidents(regionFive);
    cout << endl;
    findLowest(northAccidents, southAccidents, eastAccidents, westAccidents, centralAccidents, regionOne, regionTwo,
    regionThree, regionFour, regionFive);//function to find lowest value and print results
    cout << endl << endl;
    return 0;
}

int getNumAccidents(string region)//function to get user input
{
    int accidents;
    cout << "Please enter the number of accidents in the " << region << " region of your city last year: ";
    cin >> accidents;
    while (accidents < 0)//input validation not allowing input lower than 0
    {
        cout << "You must enter at least 0." << endl << endl;
        cout << "Please enter the number of accidents in the " << region << " region of your city last year: ";
        cin >> accidents;
    }
    return accidents;
}

void findLowest(int& north, int& south, int& east, int& west, int& central, string& regOne, string& regTwo, 
string& regThree, string& regFour, string& regFive)//function to find lowest value and print results
{
    int min;
    string minRegion;
    if (north < 10000000)//starting with a number high enough to be larger than any real input
    {
        min = north;
        minRegion = regOne;
    }
    if (south < min)
    {
        min = south;
        minRegion = regTwo;
    }
    if (east < min)
    {
        min = east;
        minRegion = regThree;
    }
    if (west < min)
    {
        min = west;
        minRegion = regFour;
    }
    if (central < min)
    {
        min = central;
        minRegion = regFive;
    }
    cout << "The " << minRegion << " region appears to be the safest place to drive, with only " << min;
    cout << " accidents last year.";//printing results and name of region corresponding with results
}