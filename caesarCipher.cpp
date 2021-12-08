//https://www.khanacademy.org/computing/computer-science/cryptography/crypt/v/caesar-cipher
//https://www.youtube.com/watch?v=-SiPu1iW3dU

#include<iostream>
using namespace std;

int main() {
    cout << "----------------- Ceaser Chiper ----------------------" << endl;
    cout << "fsbox4@gmail.com, Paul" << endl;
    cout << "This is Ceaser's Chiper algorithm." << endl;
    cout << "It will change your message to secret sentence." << endl;
    cout << "Only you and the other person can read." << endl;

    int offset = 0;
    int isEven = true;
    while(isEven) { //<-
        cout << "Type the offset (-10 ~ 10) : ";
        cin >> offset;
        cin.ignore();

        if(offset >= -10 && offset <= 10) {
            isEven = false;
        } else {
            cout << "offset is invalid" << endl;
        }
    }

    string secretMassage = "";
    string shiftedWord = ""; //"N qtaj H++ BTB >_< !";

    cout << "Secret Message: ";
    getline(cin, secretMassage);

    if(offset >= 0) {
        for(int i = 0; i < secretMassage.size(); i++) {
            int addOffset = secretMassage[i] + offset; // valueName shiftedChar

            if(offset == 0) {
                shiftedWord += secretMassage[i];
            } else if(secretMassage[i] >= 'A' && addOffset <= 'Z') { // word[i] + offset <= 90의 공식으로 + offset으로 알파벳 구간을 벗어나는 WOW가 다음 if문으로 넘어감
                shiftedWord += addOffset;
            } else if(secretMassage[i] >= 'a' && addOffset <= 'z') { // word[i] + offset <= 122의 공식으로 + offset으로 알파벳 구간을 벗어나는 v가 다음 if문으로 넘어감
                shiftedWord += addOffset;
            } else if(addOffset > 'Z' && addOffset < 'a') { // 91 ~ 96
                shiftedWord += addOffset - 26;
            } else if(addOffset >= 'z') { // 127 ~
                shiftedWord += addOffset - 26;
            } else {
                shiftedWord += secretMassage[i];
            }
        }
    } else {
        for(int i = 0; i < secretMassage.size(); i++) {

            int addOffset = secretMassage[i] + offset;

            if(secretMassage[i] < 'A' || secretMassage[i] > 'z') { // 알파벳이 아닌 문자처리
                shiftedWord += secretMassage[i];
            } else if(addOffset >= 'A' && secretMassage[i] <= 'Z') {
                shiftedWord += addOffset;
            } else if(addOffset >= 'a' && secretMassage[i] <= 'z') {
                shiftedWord += addOffset;
            } else if(addOffset > 'Z' && addOffset < 'a') {
                shiftedWord += addOffset + 26;
            } else if(addOffset < 'A') {
                shiftedWord += addOffset + 26;
            } else {
                shiftedWord += secretMassage[i];
            }
        }
    }

    cout << "Encrypted message: " << shiftedWord << endl;

    return 0;
}

 //WOW I am so excited >_< !! haha