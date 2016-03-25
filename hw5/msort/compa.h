#include <string>
#include <utility>
using namespace std;
struct StringCom {  
    bool operator()(const string &a, const string &b){
      return a < b;
    }
};

struct PairCom{
  bool operator()(const std::pair<string, int> &a, const std::pair<string,int> &b){
    return a.first < b.first;
  }
};

struct PairCom1{
  bool operator()(const std::pair<string, int> &a, const std::pair<string,int> &b){
    return a.second > b.second;
  }
};

