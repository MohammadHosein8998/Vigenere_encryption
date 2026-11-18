#include <iostream>

using namespace std;

// this funstion recieved text and shift 
// return the encrypted text
string encrypt(string text, int s) {
	string result = "";

	// traverse text
	for (int i = 0;  i < text.length(); i++){
		// apply transformation to each character 
		// Encrypt UpperCase  letters
		if (isupper(text[i]))
			result += char(int(text[i] + s - 65)) % 26 + 65;
		else
			result += char(int(text[i] + s - 97)) % 26 + 97;
	}
	return result;

}


// Driver program to test the above function
int main() {
	string text = "MY NAME IS MOHHAMD HOSEIN";
	int s = 4;

	cout << "Text : " << text << endl;
	cout << "\nShift : " << s << endl;
	cout << "\Chiper : " << encrypt(text , s) << endl;

	return 0;
}