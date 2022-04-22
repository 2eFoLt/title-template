#include <cstring>
#include <cstdio>
using namespace std;
int main() {
	char* strToChr = new char[9];
	strcpy(strToChr, "0101 0101");
	printf("Size of char array is %d", sizeof(strToChr));
	delete[] strToChr;
	return 0;
}