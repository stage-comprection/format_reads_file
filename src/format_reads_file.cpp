#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>


using namespace std;

void formatReadsFile(string& readsFilePath){

    ifstream readsFile;
    string originalreadsFile = readsFilePath + ".backup";
    readsFile.open(originalreadsFile.c_str());

    ofstream formattedReadsFile;
    formattedReadsFile.open(readsFilePath.c_str());

    string line, name, sequence;
    bool start = false;
    uint count = 0;

    while(getline(readsFile, line)){

        if(line[0] == '>'){

            if (!start){

                name = '>' + to_string(count) + '\n';
                start = true;

            } else {

                if (sequence.find("to_thrash") == string::npos){

                    formattedReadsFile<<name<<sequence;
                } else {

                    --count;
                }

                name = "\n>" + to_string(count) + '\n';
                sequence = "";

            }

            ++count;

        } else if (line.find("N") == string::npos){

            sequence += line;

        } else{

            sequence = "to_thrash";
        }
    }

    readsFile.close();
    formattedReadsFile.close();
}



int main(int argc, char *argv[]){

    if (argc < 2){
        cout<<"\nError : not enough arguments, exiting...\n";
        return -1;
    }

    string filePath = argv[1];
    string readsFilePath = filePath;
    formatReadsFile(readsFilePath);
    return 0;
}

