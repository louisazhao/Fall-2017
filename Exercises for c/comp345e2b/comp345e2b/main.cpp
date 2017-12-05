//  XOR encryption using a string as key.
//  main.cpp
//  comp345e2b
//
//  Created by Zhao Rui on 2017-09-19.
//  Copyright © 2017 Zhao Rui. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string encryption(const string&,const string&);

int main() {
    ofstream inputFile("textfile.txt",fstream::trunc|fstream::out);
    if(!inputFile)
    {
        cout<<"Input file cannot be opend."<<endl;
        exit(EXIT_FAILURE);
    }
    
    string sentence;
    cout<<"Enter the sentence you want to encrypt:"<<endl;
    getline(cin, sentence);
    inputFile<<sentence<<endl;
    inputFile.close();
    
    ifstream originalFile("textfile.txt");
    
    if(!originalFile)
    {
        cout<<"Original file cannot be opend."<<endl;
        exit(EXIT_FAILURE);
    }
    
    cout<<"Enter the name for the output file."<<endl;
    string name;
    cin>>name;
    ofstream outputFile(name.c_str());
    
    if(!outputFile)
    {
        cout<<"Output file cannot be opend."<<endl;
        exit(EXIT_FAILURE);
    }

    string key;
    cout<<"Enter a string as your key:"<<endl;
    cin>>key;
    
    string line;
    int total1=0;
    while(getline(originalFile,line))
    {
        for(int temp=0;temp<line.size();temp++)
        {
            line[temp]^=key[temp%key.length()];
            total1++;
        }
        outputFile<<noskipws<<line<<endl;
    }
    cout<<"Encryption done, "<<total1<<" char have been encrypted."<<endl;
    
    originalFile.close();
    outputFile.close();
    
    ifstream encrypted("encryption.txt");
    
    if (!encrypted)
    {
        cout<<"Encrypted file cannot be opend"<<endl;
        exit(EXIT_FAILURE);
    }
    
    ofstream unencrypted("result.txt");
    if (!unencrypted)
    {
        cout<<"result file cannot be opend"<<endl;
        exit(EXIT_FAILURE);
    }
    
    string line1;
    int total2=0;
    while(getline(encrypted,line1))
    {
        for(int temp=0;temp<line1.size();temp++)
        {
            line1[temp]^=key[temp%key.length()];
            total2++;
        }
        unencrypted<<noskipws<<line1<<endl;
    }
    cout<<"unencryption done, "<<total2<<" char have been unencrypted."<<endl;
    
    encrypted.close();
    unencrypted.close();
}


