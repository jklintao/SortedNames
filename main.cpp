#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class alphabeticalOrder{
public:
    void Constructor(){
        names.clear();
        sortedNames.clear();
        notNames.clear();
        numNames = 0;
    };

    void fileInput(string filename){
        ifstream inFile;
        inFile.open(filename);
        if(inFile.fail()) {
            cout << "Error! File failed to open...";
        }
        string temp;
        while(inFile.good()){
            getline(inFile,temp);
            names.push_back(temp);
        }
    }

    void printNames(vector<string> x){
        for(int i = 0; i < x.size(); i++){
            cout << x[i] << endl;
        }
    }

    void sortAZ(){

    }

private:
    vector<string> names;
    vector<string> sortedNames;
    vector<string> notNames;
    int numNames;
};

