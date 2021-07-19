#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    cout << "Welcome to GitfishYu's Search Engine" << endl;          // start search engine
    cout << "Please type the keyword you want to search:" << endl;   // type in keyword
    string searchW;
    cin >> searchW;
    ifstream myfile;                                                 // read file
    ifstream myfile2;
    myfile.open("database.txt");                                     // open file
    myfile2.open("keyword.txt");
    if(!myfile) {                                                    // if file could not be opened
        cerr << "Error: database.txt could not be opened" << endl;
        exit(1);
    }
    if(!myfile2) {                                                    // if file could not be opened
        cerr << "Error: keyword.txt could not be opened" << endl;
        exit(1);
    }

    vector<string> keyVec;
    vector<int> numVec;
    map<string, vector<string> > dataMap;
    string keyword;
    int num;
    while (!myfile2.eof()) {                                          // keep reading until end-of-file
      myfile2 >> keyword;
      myfile2 >> num;
      keyVec.push_back(keyword);
      numVec.push_back(num);
    }
    int vecSize = keyVec.size();
    for (int i = 0; i < vecSize; i++) {
      if(keyword == searchW) {
          break;
      }
      else if(keyword != searchW && i == vecSize -1){
          cout << "Could not find the result that match this keyword" << endl;
          cout << "Do you want to provide some information about this keyword?" << endl;
          cout << "Yes (Y) or No (N) " << endl;
          string answer;
          cin >> answer;
          while (answer != "Y" && answer != "N"){
            cout << "Sorry, I don't understand" << endl;
            cout << "Try again" << endl;
            cin >> answer;
          }
          if(answer == "Y") {                        // provide result that match the keyword and import to the file
            keyVec.push_back(searchW);                       // put search word in the key vector
            numVec.push_back(1);                             // put number 1 (indicate search word only have 1 information) in the num vector
              
            cout << "Type into your information" << endl;
            string information;
            cin.ignore();
            getline(cin, information);                       // extract a whole of information
            vector<string> infoVec;
            infoVec.push_back(information);                  // put information in a vector
            dataMap.insert(make_pair(searchW, infoVec));     // map the search word to the information vector
            ofstream out("keyword.txt");                     // open keyword.txt
            ofstream out2("database.txt");                   // open database.txt
            for(int i = 1; i < keyVec.size(); i++){
              out << keyVec[i];
              out << " ";
              out << numVec[i];
              out << " ";
            }
            for(int i = 0; i < infoVec.size(); i++){
              out2 << infoVec[i];
            }
            out.close();
            out2.close();
          }
          else if(answer == "N") {                   // terminate the program 
            cout << "Thank you for using GitfishYu Search Engine! Have a nice day!" << endl;
          } 
      }
    } 
  /*  indata.close();
   cout << "End-of-file reached.." << endl;
    ofstream myfile;
    myfile.open ("database.txt");
    myfile << "Writing this to a file.\n"; */
    myfile.close();
    myfile2.close();
    return 0;
}