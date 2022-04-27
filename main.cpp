using namespace std; 
#include <iostream>
#include <fstream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <stdbool.h>  

#include "DMC.h"
#include "FAC.h"
#include "SAC.h"

#define LINE_SIZE 32

vector<string> stringToVector(string s){
    stringstream ss(s);
    string word;
    vector<string> stringVect; 
    while (ss >> word) {
        stringVect.push_back(word);
    }
    return stringVect;
}

int main(int argc, char *argv[]){
    string line;
    int total = 0; 
    DMC *dmc1 = new DMC(1024);
    DMC *dmc4 = new DMC(4096);
    DMC *dmc16 = new DMC(16384);
    DMC *dmc32 = new DMC(32768);
    SAC *sac2 = new SAC(16384, 2);
    SAC *sac4 = new SAC(16384, 4);
    SAC *sac8 = new SAC(16384, 8);
    SAC *sac16 = new SAC(16384, 16);
    FAC *facLRU = new FAC(16384); 
    FAC *facHC = new FAC(16384); 
    SAC *sacAWM2 = new SAC(16384, 2);
    SAC *sacAWM4 = new SAC(16384, 4);
    SAC *sacAWM8 = new SAC(16384, 8);
    SAC *sacAWM16 = new SAC(16384, 16);
    SAC *sacNP2 = new SAC(16384, 2);
    SAC *sacNP4 = new SAC(16384, 4);
    SAC *sacNP8 = new SAC(16384, 8);
    SAC *sacNP16 = new SAC(16384, 16);
    SAC *sacNPM2 = new SAC(16384, 2);
    SAC *sacNPM4 = new SAC(16384, 4);
    SAC *sacNPM8 = new SAC(16384, 8);
    SAC *sacNPM16 = new SAC(16384, 16);
    cout<<"Size: "<<sizeof((sacNPM16->table))<<endl;
    ifstream file(argv[1]);
      if (file.is_open()){
        int zero = 0; 
        int * accessTime = &zero; 
        while(getline(file, line)){
            vector<string> ln = stringToVector(line);
            const string add = ln.at(1);
            string flag  = ln.at(0); 
            unsigned long long l = strtoull(add.c_str(), NULL, 16);
            dmc1->process(l);
            dmc4->process(l);
            dmc16->process(l);
            dmc32->process(l);
            sac2->process(l, *accessTime);
            sac4->process(l, *accessTime);
            sac8->process(l, *accessTime);
            sac16->process(l, *accessTime);
            facLRU->processLRU(l, *accessTime);
            facHC->processHC(l);
            sacAWM2->processAWM(l, *accessTime);
            sacAWM4->processAWM(l, *accessTime);
            sacAWM8->processAWM(l, *accessTime);
            sacAWM16->processAWM(l, *accessTime);
            sacNP2->processNP(l, accessTime, LINE_SIZE);
            sacNP4->processNP(l, accessTime, LINE_SIZE);
            sacNP8->processNP(l, accessTime, LINE_SIZE);
            sacNP16->processNP(l, accessTime, LINE_SIZE);
            sacNPM2->processNPM(l, accessTime, LINE_SIZE);
            sacNPM4->processNPM(l, accessTime, LINE_SIZE);
            sacNPM8->processNPM(l, accessTime, LINE_SIZE);
            sacNPM16->processNPM(l, accessTime, LINE_SIZE);
            total++;
            *accessTime = *accessTime + 1;

        }
      }
    file.close();
    ofstream ofile;
    ofile.open(argv[2]);
    ofile << dmc1->getTotalHits() << "," << total << "; ";
    ofile << dmc4->getTotalHits() << "," << total << "; ";
    ofile << dmc16->getTotalHits() << "," << total << "; ";
    ofile << dmc32->getTotalHits() << "," << total << ";" << endl; 
    ofile << sac2->getTotalHits() << "," << total << "; ";
    ofile << sac4->getTotalHits() << "," << total << "; ";
    ofile << sac8->getTotalHits() << "," << total << "; ";
    ofile << sac16->getTotalHits() << "," << total << ";" << endl; 
    ofile << facLRU->getTotalHits() << "," << total << ";" << endl; 
    ofile << facHC->getTotalHits() << "," << total << ";" << endl; 
    ofile << sacAWM2->getTotalHits() << "," << total << "; ";
    ofile << sacAWM4->getTotalHits() << "," << total << "; ";
    ofile << sacAWM8->getTotalHits() << "," << total << "; ";
    ofile << sacAWM16->getTotalHits() << "," << total << ";" << endl; 
    ofile << sacNP2->getTotalHits() << "," << total << "; ";
    ofile << sacNP4->getTotalHits() << "," << total << "; ";
    ofile << sacNP8->getTotalHits() << "," << total << "; ";
    ofile << sacNP16->getTotalHits() << "," << total << ";" << endl; 
    ofile << sacNPM2->getTotalHits() << "," << total << "; ";
    ofile << sacNPM4->getTotalHits() << "," << total << "; ";
    ofile << sacNPM8->getTotalHits() << "," << total << "; ";
    ofile << sacNPM16->getTotalHits() << "," << total << ";" << endl; 
    ofile.close();

}
