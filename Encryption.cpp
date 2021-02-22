//SIMPLE THREE WAY MESSAGE ENCRYPTION PROGRAMM BY DIMITRIOS PAPOULIAS

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string phrase;
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string encryption {"ZXCVBNMASDFGHJKLPOQWEIUYRTzxcvbnmasdfghjklpoqweiuyrt"};
    cout << "Type the message you want to send : ";
    getline(cin, phrase);
//FIRST LAYER ENCRYPTION
    cout <<"\n\nMESSENGE ENCRYPTION.....\n\n";
    string encrypted_phrase;
    for(int i = 0; i < phrase.length(); i++){
        size_t position = alphabet.find(phrase[i]);
        if(position != string::npos){
            encrypted_phrase += encryption[position];
        }else{
            encrypted_phrase += phrase[i];
        }
    }
    /*cout <<"The first layer encrypted message is : " << encrypted_phrase;
    cout <<"\n=========================================================================";*/
//SECOND LAYER ENCRYPTION
    vector <int> second_encryption;
    int z;
    for(int i = 0; i < encrypted_phrase.size(); i++){
        if(encrypted_phrase[i] == ' '){
            second_encryption.push_back(0);
        }else{
            z = int(encrypted_phrase[i]);
            second_encryption.push_back(z);
        }
    }
    /*cout << "\nThe second layer encrypted message is : ";
    for(int i = 0; i < encrypted_phrase.size(); i++){
        cout << second_encryption[i];
    }
    cout << "\n========================================================================";*/
//THIRD LAYER OF ENCRYPTION
    string encryption_stage_iii {"$P%B#WERQ!LJKTY*&-DA_F=/GU^p@b`werq+ljkty;:<da>f.~gu"};
    string third_encryption;
    for(int i = 0; i < second_encryption.size(); i++){
        int posision = -1;
        int j = 0, found = 0;
        do{
            if(char(second_encryption[i]) == encryption[j]){
                found = 1;
                posision = j;
            }else{
                j++;
            }
        }while(found == 0 && j < encryption.size());
        if(posision != -1){
            third_encryption += encryption_stage_iii[posision];
        }else{
            third_encryption += second_encryption[i];
        }
    }
    //cout << "\nThe third layer encrypted message is : " << third_encryption;
    //cout <<"\n=========================================================================";
    
    cout << "\nThe message is : " << third_encryption << "\n";
    cout << "\n\n\n\n";
    return 0;
}

//FIRST LAYER DECRYPTION
    /*cout << "\n\nMESSEGE DECRYPTION\n\n";
    for(int i = 0; i <= phrase.length(); i++){
        size_t position = encryption.find(encrypted_phrase[i]);
        if(position != string::npos){
            encrypted_phrase[i] = alphabet[position];
        }else{
            encrypted_phrase[i] = phrase[i];
        }
    }
    cout << "The dencrypted message is : " << encrypted_phrase << endl << endl << endl;*/