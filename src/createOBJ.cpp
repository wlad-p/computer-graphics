#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

bool checkVerticesFormat(string str){

    // separate by space
    string s;
    stringstream ss(str);
    vector<string> valuesString;
    while(getline(ss, s, ' ')){
        valuesString.push_back(s);
    }

    // Check if there are 3 values for x,y,z
    if(valuesString.size() != 3){
        cout << "There have to be 3 values for x,y,z." << endl;
        return false;
    }

    // convert string to float
    vector<float> values;
    for (int i = 0; i < valuesString.size(); i++){
        
        // Check if float values were provided
        try{
            values.push_back(std::stof(valuesString[i]));
        }
        catch(...){
            cout << "No float values were provided." << endl;
            return false;
        }
    }

    // Check if values are between 0.0 and 1.0
    for(int i=0; i < values.size(); i++){
        if(values[i] < 0.0 || values[i] > 1.0){
            cout << "Values have to be between 0.0 and 1.0" << endl;
            return false;
        }
    }

    return true;
}

bool checkFacesFormat(string str, int numberOfVertices){

    // separate by space
    string s;
    stringstream ss(str);
    vector<string> valuesString;
    while(getline(ss, s, ' ')){
        valuesString.push_back(s);
    }

    // convert string to int
    vector<int> values;
    for (int i = 0; i < valuesString.size(); i++){
        
        // Check if int values were provided
        try{
            values.push_back(std::stof(valuesString[i]));
        }
        catch(...){
            cout << "No int values were provided." << endl;
            return false;
        }
    }

    //Check if values match the number of vertices
    for(int i=0; i < values.size(); i++){
        if(values[i] < 0 || values[i] > (numberOfVertices - 1)){
            cout << "values don't match the number of vertices" << endl;
            return false;
        }
    }

    return true;
}

int main(){

    int verticesCounter = 0;
    ofstream objFile ("file.obj");
    cout << "Creating .obj file. Enter vertices values between 0.0 and 1.0 as float numbers. Separate values by space. Enter 'n' to finish. " << endl;

    // Create vertices
    while(true){
        cout << "Enter coordinate: " << endl;
        string line;
        getline( cin, line);

        if(checkVerticesFormat(line)){
            objFile << "v " << line << endl;
            verticesCounter++;
        }
        else if(line == "n"){
            cout << "vertices added" << endl;
            break;
        }
        else{
            cout << "Wrong format. Please provide exactly 3 float numbers between 0.0 and 1.0 separated by space. For example:\n 0.5 0.8 0.0" << endl;
        }
    }

    //Create faces
    cout << "Successfully added vertices. Enter face values. Enter 'n' to finish." << endl;
    while(true){
        cout << "Enter face values: " << endl;
        string line;
        getline( cin, line);

        if(checkFacesFormat(line, verticesCounter)){
            objFile << "f " << line << endl;
            
        }
        else if(line == "n"){
            cout << "faces added" << endl;
            break;
        }
        else{
            cout << "Wrong format. Please provide integer values separated by space. For example:\n 0 1 2" << endl;
        }
    }

    return 0;
}