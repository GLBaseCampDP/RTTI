#include <iostream>
#include <typeindex>
#include <vector>
#include <string>
#define MK make_pair
using namespace std;

class d {};

int main() {
  cout << type_index(typeid(double)).name()
   << endl <<
   type_index(typeid(d)).name() << endl <<
   type_index(typeid(int)).name() << endl;

 vector< pair<type_index, string> > names;

 auto p =
 MK(type_index(typeid(double)),"double");
 names.push_back(p);
 p = MK(type_index(typeid(d)),"class d");
 names.push_back(p);
 p = MK(type_index(typeid(int)), "int");
 names.push_back(p);

 for (unsigned i = 0; i< names.size();
   cout << names[i].second << endl, i++);
}
