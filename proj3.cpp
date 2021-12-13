#include "Manager.h"
#include <iostream>
using namespace std;

int main (int argc, char* argv[]) {
  if (argc < 2)
    {
      cout << "You are missing a data file." << endl;
      cout << "Expected usage ./proj3 proj3_schedule1.txt" << endl;
      cout << "File 1 should be a file with a schedule" << endl;
    }
  else
    {
      cout << endl << "***Manager***" << endl << endl;
      Manager S = Manager(argv[1]);
    }
  return 0;
}
