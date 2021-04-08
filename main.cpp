#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class alphabeticalOrder{
public:
    void openFile(string filename){
        ifstream inFile;
        inFile.open(filename);
        if(inFile.fail()){
            cout << "Error! File not found...";
        }
    }

private:
    vector<string> names;
    vector<string> sortedNames;
    vector<string> notNames;
    int numNames;
};
