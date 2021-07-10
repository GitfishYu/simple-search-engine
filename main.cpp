#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    cout << "Welcome to GitfishYu's Search Engine" << endl;          // start search engine
    cout << "Please type the keyword you want to search:" << endl;   // type in keyword
    string keyword;
    cin >> keyword;
    ifstream myfile;                                                 // read file
    myfile.open("database.txt");                                     // open file
    if(!myfile) {                                                    // if file could not be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    while (!myfile.eof()) {                                          // keep reading until end-of-file
/*       cout << "The next number is " << num << endl;
      indata >> num; // sets EOF flag if no value found */
    }
  /*  indata.close();
   cout << "End-of-file reached.." << endl;
    ofstream myfile;
    myfile.open ("database.txt");
    myfile << "Writing this to a file.\n"; */
    myfile.close();
    return 0;
}