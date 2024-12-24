#include <iostream>
#include <cmath>  // For pow() function
#include <string> // For string handling

int binaryToDecimal(const std::string& binary) {
    int decimal = 0;
    int length = binary.length();
    
    for (int i = 0; i < length; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, length - 1 - i);  // Calculate the corresponding power of 2
        }
    }

    return decimal;
}

int main() {
    std::string binary = "00000000001011";  // Binary input as string
    int decimal = binaryToDecimal(binary);
    std::cout << "Decimal equivalent: " << decimal << std::endl;
    return 0;
}
