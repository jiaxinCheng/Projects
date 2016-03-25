#include <string>
#include <utility>
using namespace std;
struct NameCompD {  
    bool operator()(const std::pair<string, int> &a, const std::pair<string, int> &b) 
    { 
      return a.first > b.first; 
    }
  };

struct NameCompI{
  bool operator()(const std::pair<string, int> &a, const std::pair<string,int> &b){
    return a.first < b.first;
  }
};

struct NumCompD{
  bool operator()(const std::pair<string,int> &a, const std::pair<string,int> &b){
    return a.second > b.second;
  }
};

struct NumCompI{
  bool operator()(const std::pair<string, int> &a, const std::pair<string, int> &b){
    return a.second < b.second;
  }
};