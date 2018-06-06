#include <boost/ptr_container/ptr_vector.hpp>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
using namespace boost;


struct Animal
{
    string name;
    int legs;
    bool has_tail;
    Animal(string n,int l,bool t=true)
    {
        name = n;
        legs = l;
        has_tail = t;
    }
};

bool compare(Animal a,Animal b)
{
    return a.legs<b.legs;
}

int main()
{
  boost::ptr_vector<Animal> v;
  Animal tiger("tiger",4);
  Animal pig("pig",8);
  Animal chicken("chicken",2);

  v.push_back(&tiger);

  v.push_back(&pig);

  v.push_back(&chicken);

  v.sort(v.begin(),v.end(),compare);

  for(Animal ani: v)
  {
      cout<<"name: "<<ani.name<<"\tlegs: "<<ani.legs<<"\thasTail: "<<ani.has_tail<<endl;

  }
 free(v);
}
