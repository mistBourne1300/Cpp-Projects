#include <iostream>
#include <vector>
#include <string>
using namespace std;


int hashme(string param, int tablesize) {
    unsigned char *ptr = (unsigned char *)param.c_str();
    int sum = 0;
    for(int i = 0; i < param.size(); i++) {
        sum += ptr[i];
    }
    int hashval = sum%tablesize;
    cout << "Size = "<<sizeof(param)<<" Sum = "<<sum<<" hash "<<hashval<<endl;
    return hashval;
}
int main()
{
    const int tablesize = 11;
    vector<string> strvec;
    string foo("Hello");
    cout << "Hash of Hello "<<hashme(foo, tablesize)<<endl;
    string foo2("Hello");
    cout << "Hash2 of Hello "<<hashme(foo2, tablesize)<<endl;
    }