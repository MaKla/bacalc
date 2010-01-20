
#include <client.cpp>
#include <iostream>

using namespace std;

int main() {
	char* r = process("3+4", "127.0.0.1", 9375);

	cout << r << endl;

	return 0;
}
