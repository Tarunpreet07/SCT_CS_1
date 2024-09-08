#include<iostream>
#include<string>
using namespace std;

//Function to encyrpt message
string encrypt(string text,int shift) {
    string encryptedtext = "";

    for(char &ch : text){
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            encryptedtext += (ch - base + shift) % 26 + base;
        }
        else {
            encryptedtext += ch; //Non-alphabetic characters remained unchanged
        }
    }
    return encryptedtext;
}

//Function to decrypt message
string decrypt(string text,int shift) {
    string decryptedtext = "";

    for(char &ch : text){
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            decryptedtext += (ch - base - shift + 26) % 26 + base;
        }
        else{
            decryptedtext += ch; //Non-alphabetic characters remained unchanged
        }
    }
    return decryptedtext;
}

int main() {
    string message;
    int shift;
    char choice;

    cout << "Casear Cipher Encryption/Decryption\n";
    cout << "Enter 'E' for Encryption and 'D' for Decryption :";
    cin >> choice;
    cin.ignore(); //ignore newline after choice;

    if(choice != 'E' && choice != 'D'){
        cout << "Invalid choice! Please choose 'E' for encryption and 'D' for decryption.\n";
        return 1;
    }

    cout << "Enter Your Message: ";
    getline(cin, message);

    cout << "Enter shift value(number): ";
    cin >> shift;

    if(choice == 'E'){
        string encryptedMessage = encrypt(message, shift);
        cout << "Encrypted Message: " << encryptedMessage << endl;
    }
    else{
        if(choice == 'D'){
        string decryptedMessage = decrypt(message, shift);
        cout << "Decrypted Message: " << decryptedMessage << endl;
    }
    }
    return 0;
}