#include <iostream>
#include <string.h>
#include<sstream>
#include "Quash.h"

#include <iostream>
#include <string.h>
#include<sstream>
#include "Quash.h"

using namespace std;

int main(int argc, char *argv[])
{
    Quash q;
  std::string input = argv[1];
    std::istringstream ss(input);
    std::string token;
    size_t pos=-1;
    string command;
    while(ss>>token) {
      while ((pos=token.rfind(',')) != std::string::npos) {
        token.erase(pos, 1);
      }
    
      int i;
      if(command == "insert"){

          int i = stoi(token);
          int numToInsert = i;
          q.insert(i);
          q.print();
          
                command = "";
      }
      if(token == "insert"){
      command = "insert";

      }
     
    }
    return 0;
}