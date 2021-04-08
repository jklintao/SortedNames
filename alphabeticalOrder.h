//                                                     alphabeticalOrder
// Created by kylel on 4/8/2021.
// This program will sort a list of names in a text file in either ascending or descending order. It will print the list
// for display to the user, or export the sorted list to a file.

#ifndef PA5_ALPHABETICALORDER_H
#define PA5_ALPHABETICALORDER_H

#endif //PA5_ALPHABETICALORDER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class alphabeticalOrder{
public:
    void Constructor(){
        names.clear();
        AZsortedNames.clear();
        ZAsortedNames.clear();
        numNames = 0;
    };

    void fileInput(){
        string filename;
        cout << "Enter filename: ";
        cin >> filename;
        ifstream inFile(filename);
        string temp;
        if(inFile.is_open()) {
            while(getline(inFile,temp)) {
                names.push_back(temp);
            }
            numNames = names.size();
        }
        else{
            cout << "Error! File failed to open...";
        }
        inFile.close();
    };

    void printOrExport(){
        cout << endl;
        int x;
        cout << "Would you like to (1)print or (2)export?";
        cin >> x;
        cout << endl << endl;
        switch (x) {
            case 1:
                printNames();
                break;
            case 2:
                fileExport();
                break;
            default:
                cout << "Invalid Choice... Try Again" << endl;
                printOrExport();
                break;
        }
    };

    void printNames(){
        menu();
        int x;
        cout << "How would you like to sort?  ";
        cin >> x;
        switch (x) {
            case 1:
                cout << endl << "Number of names: " << numNames << endl;
                for(int i = 0; i < names.size(); i++){
                    cout << names[i] << endl;
                }
                break;
            case 2:
                sortAZ(names);
                cout << endl << "Number of names: " << numNames << endl << endl;
                for(int i = 0; i < AZsortedNames.size(); i++){
                    cout << AZsortedNames[i] << endl;
                }
                break;
            case 3:
                sortZA(names);
                cout << endl << "Number of names: " << numNames << endl << endl;
                for(int i = 0; i < ZAsortedNames.size(); i++){
                    cout << ZAsortedNames[i] << endl;
                }
                break;
            default:
                cout << "Invalid choice... Try again" << endl;
                printNames();
        }
    };

    void fileExport(){
        string filename;
        cout << "Enter filename: ";
        cin >> filename;
        cout << endl;
        menu();
        ofstream outFile(filename);
        int x;
        cout << "How would you like to sort?  ";
        cin >> x;
        switch (x) {
            case 1:
                for(int i = 0; i < names.size(); i++){
                    outFile << names[i] << endl;
                }
                outFile.close();
                break;
            case 2:
                sortAZ(names);
                for(int i = 0; i < AZsortedNames.size(); i++){
                    outFile << AZsortedNames[i] << endl;
                }
                outFile.close();
                break;
            case 3:
                sortZA(names);
                for(int i = 0; i < ZAsortedNames.size(); i++){
                    outFile << ZAsortedNames[i] << endl;
                }
                outFile.close();
                break;
            default:
                cout << "Invalid choice...Try Again" << endl;
                fileExport();
                break;
        }
    };

    static void menu(){
        cout << "1: Unsorted Names" << endl;
        cout << "2: Descending" << endl;
        cout << "3: Ascending" << endl;
    };

private:

    static bool ZtoA(const string& a,const string& b){
        return a>b;
    };

    void sortZA(vector<string> nameList){
        numNames = nameList.size();
        sort(nameList.begin(), nameList.end(),ZtoA);
        for(int i = 0; i < nameList.size(); i++){
            ZAsortedNames.push_back(nameList[i]);
        }
    };

    static bool AtoZ(const string& a, const string& b){
        return a<b;
    };

    void sortAZ(vector<string> nameList){
        numNames = nameList.size();
        sort(nameList.begin(), nameList.end(),AtoZ);
        for(int i = 0; i < nameList.size(); i++){
            AZsortedNames.push_back(nameList[i]);
        }
    };

    vector<string> names;
    vector<string> AZsortedNames;
    vector<string> ZAsortedNames;
    int numNames{};
};
