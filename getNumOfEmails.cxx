#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

string stripEmailAddr(string str) {
	string ret = "";
	for(char c: str) {
		if(c=='.') continue;//skip dot char
		if(c=='@' || c=='+') break; //ignore after @ or +
		ret += c;//otherwise concatenate char into return string
	}
	return ret;
}

int getNumOfUniqueEmails(vector<string>& emailaddrs) {
	unordered_set<string> set;
	for(string email: emailaddrs) {
		if(!email.empty())
			set.insert(stripEmailAddr(email));
	}
	return set.size();
}

int main() {
  vector<string> inputStr = {"test.email@gmail.com", "test.email+spam@gmail.com","testemail@gmail.com"};
  cout << getNumOfUniqueEmails(inputStr) << endl;
  return 0;
}
