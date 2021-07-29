#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;

vector<string> keyVec;
vector<int> numVec;
vector<string> infoVec;
map<string, vector<string> > dataMap;

// bool exist is for checking whether the keyword exist already
// int index is for inserting information for the existed keyword
void ImportData(string searchW, bool exist, int index);       

int main() {

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

    int num;
    //keyVec.push_back("");
    while (!myfile2.eof()) {                                          // keep reading until end-of-file
      string keyword;
      myfile2 >> keyword;
      myfile2 >> num;
      
      if(keyword != ""){
        keyVec.push_back(keyword);
        numVec.push_back(num);
      }
      else{
        break;
      }
    }

    string result;
    while (!myfile.eof()) {
      //cin.ignore();
      getline(myfile, result);
      infoVec.push_back(result);
    }
    int vecSize = keyVec.size();
  
    cout << "Welcome to GitfishYu's Search Engine" << endl;          // start search engine
    cout << "Please type the keyword you want to search:" << endl;   // type in keyword
    string searchW;
    cin >> searchW;

    for (int i = 0; i < vecSize; i++) {
      if(keyVec[i] == searchW) {
          int count = numVec[i];
          if(count == 1) {
            cout << "Here is " << count << " result:" << endl;
          }
          else{
            cout << "Here are " << count << " results:" << endl;
          }
          int sum = 0;               // sum of results before the result that match the keyword
          for(int j = 0; j < i; j++){
            sum += numVec[j];
          }
          for(int k = 1; k <= count; k++){
            cout << infoVec[sum+k] << endl;
          }
          numVec[i] = count + 1;
          ImportData(searchW, true, sum+count+1);
          break;
      }
      else if(keyVec[i] != searchW && i == vecSize -1){          // if keyword doesn't equal to searchW
                                                                 // and the for loop has reached end
          cout << "Could not find the result that match this keyword" << endl;
          ImportData(searchW, false, 0);
      } 
    }
    myfile.close();
    myfile2.close();
    return 0; 
}

void ImportData(string searchW, bool exist, int index){        
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
    cout << "Type into your information" << endl;
    string information;
    cin.ignore();
    getline(cin, information);                         // extract a whole of information
    if(!exist){                                        // if the exist is false, add information to the back
      keyVec.push_back(searchW);                       // put search word in the key vector
      numVec.push_back(1);                             // put number 1 (indicate search word only have 1 information) in the num vector
      infoVec.push_back(information);                  // put information in a vector
    }
    
    else{                                              // if the exist is true, 
      list<string> copy(infoVec.begin(), infoVec.end());
      list<string>::iterator it = copy.begin();
      for(int i = 0 ; i < index; i++){
        it++;
      }

      copy.insert(it, information);
      vector<string> copyVec(copy.begin(), copy.end());
      infoVec.clear();
      for(int i = 0; i < copyVec.size(); i++){
        infoVec.push_back(copyVec[i]);
      }
    }
    //dataMap.insert(make_pair(searchW, infoVec));     // map the search word to the information vector
    ofstream out("keyword.txt");                       // open keyword.txt
    ofstream out2("database.txt");                     // open database.txt
    for(int i = 0; i < keyVec.size(); i++){
      out << keyVec[i];
      out << " ";
      out << numVec[i];
      out << " ";
    }
    for(int i = 1; i < infoVec.size(); i++){   // directly at the back of database.txt
      out2 << endl;
      out2 << infoVec[i];
    }
  
    out.close();
    out2.close();
  }
  else if(answer == "N") {                   // terminate the program 
    cout << "Thank you for using GitfishYu Search Engine! Have a nice day!" << endl;
  } 
}