#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string s1, string s2) {
    int carry = 0;
    string result = "";
    int i = s1.size() - 1;  
    int j = s2.size() - 1;  
    
    while (i >= 0 || j >= 0 || carry != 0) { 
        int sum = carry; 

        if (i >= 0) { 
            sum += s1[i] - '0';
            i--;
        }
        
        if (j >= 0) { 
            sum += s2[j] - '0';
            j--;
        }
        
        result += (sum % 2) + '0'; 
        carry = sum / 2; 
            }
    
    reverse(result.begin(), result.end());

    size_t pos = result.find_first_not_of('0');
    if (pos != string::npos) {
        result = result.substr(pos);
    } else {
        result = "0"; // If the result is all zeros
    }

    return result;
}

int main() {
    string binary1 = "0000001001001";
    string binary2 = "0110101";

    string sum = addBinary(binary1, binary2);
    cout << "Sum: " << sum << endl;

    return 0;
}
