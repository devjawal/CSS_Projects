#include<iostream>
using namespace std;

// Function to perform XOR operation
string xor_operation(string dividend, string divisor) {
    int len = divisor.length();
    string result = "";
    for (int i = 0; i < len; i++) {
        if (dividend[i] == divisor[i]) {
            result += '0';
        } else {
            result += '1';
        }
    }
    return result;
}

// Function to perform CRC division
string crc_division(string dividend, string divisor) {
    int pick = divisor.length();
    string temp = dividend.substr(0, pick);
    int n = dividend.length();
    
    // Loop to continue the division process
    while (pick < n) {
        // Perform XOR if the leading bit is 1
        if (temp[0] == '1') {
            temp = xor_operation(temp, divisor) + dividend[pick];
        } else {
            // Else, XOR with a string of zeros
            temp = xor_operation(temp, string(divisor.length(), '0')) + dividend[pick];
        }
        pick++;
        
        // Keep only the relevant portion of `temp`
        temp = temp.substr(1); // Remove the first bit
    }

    // Perform the last XOR for the remaining bits
    if (temp[0] == '1') {
        temp = xor_operation(temp, divisor);
    } else {
        temp = xor_operation(temp, string(divisor.length(), '0'));
    }

    return temp.substr(1); // Remove leading bit and return remainder
}

// Function to encode data using CRC
string encoded_data(string data, string divisor) {
    int n = divisor.length();
    
    // Append n-1 zeros to the data
    string appended = data + string(n - 1, '0');
    
    // Perform division to get the remainder
    string remainder = crc_division(appended, divisor);
    
    // Return the data concatenated with the remainder (CRC)
    return data + remainder;
}

// Function to check if received data is error-free
bool check(string received, string divisor) {
    string remainder = crc_division(received, divisor);
    
    // Check if the remainder is all zeros
    for (char c : remainder) {
        if (c != '0') {
            return false; // Error detected
        }
    }
    return true; // No error
}

int main() {
    string data, divisor, received;
    
    // Input data and divisor
    cout << "Enter the data: " << endl;
    cin >> data;
    cout << "Enter the divisor: " << endl;
    cin >> divisor;
    
    // Encode the data
    string encoded = encoded_data(data, divisor);
    cout << "Encoded string: " << encoded << endl;
    
    // Simulate the received message
    cout << "Enter received message: " << endl;
    cin >> received;
    
    // Check if the received message has an error
    bool t = check(received, divisor);
    cout << "Boolean: " << t << endl;
    
    return 0;
}
