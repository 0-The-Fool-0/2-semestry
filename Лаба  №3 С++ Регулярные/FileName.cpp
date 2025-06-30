#include <iostream>
#include <fstream>
#include <regex>
#include <string>
using namespace std;
bool isValidGUID(const string& guid) {
    // –егул€рное выражение дл€ проверки GUID
    regex guidRegex(R"(^\{?([0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12})\}?$)");
    return regex_match(guid, guidRegex);
}


int main() {
  
    ifstream inputFile("input1.txt");  
  ofstream outputFile("output.txt"); 
    string line;

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    int testCount = 0;

    while (getline(inputFile, line)) {
        testCount++;
       
        if (isValidGUID(line)) {
          
            outputFile << line << " - correct" << endl;
            cout << "correct  ";
        }
        else {
            
            outputFile << line << " - incorrect" << endl;
            cout << "incorrect  ";
        }
        cout << line << endl;
    }
 

    inputFile.close();
    outputFile.close();

    cout << "Test lines checked:" << testCount << endl;
    return 0;
}