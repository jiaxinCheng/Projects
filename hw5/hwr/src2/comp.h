#include <string>
#include <utility>
using namespace std;
struct NameCompD {  //comparators that used to decreasingly sort all the names
    bool operator()(const std::pair<string, int> &a, const std::pair<string, int> &b) 
    { 
      return a.first > b.first; 
    }
  };

struct NameCompI{ //comparators that used to increasingly sort all the names
  bool operator()(const std::pair<string, int> &a, const std::pair<string,int> &b){
    return a.first < b.first;
  }
};

struct NumCompD{ //sort numbers decreasingly
  bool operator()(const std::pair<string,int> &a, const std::pair<string,int> &b){
    return a.second > b.second;
  }
};

struct NumCompI{ // sort numbers increasingly
  bool operator()(const std::pair<string, int> &a, const std::pair<string, int> &b){
    return a.second < b.second;
  }
};