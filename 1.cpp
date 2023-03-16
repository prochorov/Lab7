#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <crypt.h>
#include <iomanip>
#include <fstream>
using namespace std;
void findPass(string pass, const string& hash)
{
crypt_data *pCryptData = new crypt_data;
size_t pos = hash.find_last_of('$');
string hashHead = hash.substr(0,pos);
do {
string
newHash(crypt_r(pass.data(),hashHead.data(),pCryptData));
if (newHash == hash) {
cout<<"Hash: "<<hash<<endl<<"Pass: "<<pass<<endl;
break;
}
} while ( next_permutation( pass.begin(), pass.end() ) );
delete pCryptData;
}
int main()
{
int i = 0, j = 0;
ifstream f("/home/user/Downloads/hashs");
f.seekg(0, ios::end);
int fsize = f.tellg();
f.seekg(0, ios::beg);
char *b = new char [fsize];
char *s = new char[60];
f.read(b, fsize);
for (i = 0; i < fsize; i++) {
if (b[i] == '\n' || i == (fsize-1)) {
s[j] = '\0';
findPass("123456789", s);
delete[] s;
s = new char[60];
j = 0;
} else {
s[j] = b[i];
++j;
}
}
return 0;
}
