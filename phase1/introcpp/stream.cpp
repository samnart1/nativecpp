#include <iostream>
using namespace std;

int main() {
    
    int sum = 0, num = 0, sum2 = 0;

    while (num <= 10)
    {
        sum += num;
        num++;
    }

    cout << "Sum or number from 0 to 10 is: " << sum << endl;

    for (int i = 0; i <= 10; i++) {
        sum2 += i;
    }

    cout << "Sum2 is: " << sum2 << endl;
    

    return 0;
}