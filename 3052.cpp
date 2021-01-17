#include <iostream>
#include <vector>

using namespace std;

int main() {	
	vector<int> rest;

	for (int i = 0; i < 10; i++) {
		int temp;
		cin >> temp;
		
		if (rest.size() == 0)
			rest.push_back(temp % 42);
		else {
			bool is_exist = false;
			for (int j = 0; j < rest.size(); j++) {
				if ((temp % 42) == rest[j]) {
					is_exist = true;
					break;
				}
			}
			if (is_exist == false)
				rest.push_back(temp % 42);
		}
	}

	cout << rest.size() << endl;

	return 0;
}
