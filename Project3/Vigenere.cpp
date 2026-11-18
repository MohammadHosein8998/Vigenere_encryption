
#include <iostream>
#include <String>
using namespace std;


class Vigenere {
public:
	// ** represent key
	string key;
	// ** constructore of the  class 
	//	**  the chosen key 
	Vigenere(string chosenKey) {
		for (int i = 0; i < chosenKey.size(); i++) {
			if (chosenKey[i] >= 'A' && chosenKey[i] <= 'Z')
				this->key += chosenKey[i];
			else
				this->key += chosenKey[i];
		}
	}
	string encrypt(string t) {
		string encryptedOutPut;
		for (int i = 0, j = 0; i < t.length(); ++i) {
			char c = t[i];
			if (c >= 'a' && c <= 'z')
				c += 'A' - 'a';
			else if (c < 'A' || c > 'Z')
				continue;
			// added 'A' to bring it in range 
			// of Ascii alphabet [ 65-90 | A-z]
			encryptedOutPut += (c + key[j] - 26) % 26 + 'A';
			j = (j + 1) % key.length();

		}
		return encryptedOutPut;
	}

	string decrypt(string t) {
		string decryptedOutput;

		for (int i = 0, j = 0; i < t.length(); i++) {
			char c = t[i];
			if (c >= 'a' && c <= 'z') 
				c += 'A' - 'a';
			else if (c < 'A' || c > 'Z')
				continue;
			// added 'A' to bring it in range 
			// of Ascii alphabet [ 65-90 | A-z]
			decryptedOutput += (c - key[j] + 26) % 26 + 'A';
			j = (j + 1) % key.length();
		}
		return decryptedOutput;
	}
};



int main() {
	Vigenere my_vienere("APRESS WELCOM!");
	string originalMessage = "this is an example of vigenere cipher for apress";

	string enc = my_vienere.encrypt(originalMessage);
	string dec = my_vienere.decrypt(enc);

	cout << "orginal message : " << originalMessage << endl;
	cout << "encrypted message : " << enc << endl;
	cout << "decryptes message : " << dec << endl;


	return 0;
}


