#include<iostream>
using namespace std;

class vowels{
    private:
    string input;
    public:
    vowels(string str){
        input=str;
    }

    private:
    bool isvowel(char ch){
        ch=isupper(ch);
        return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');

    }
    public:
    int countvowels(){
        int count=0;
        for(int i=0;i<input.length();i++){
            if(isvowel(input[i])){
                count++;
            }


        }
        cout<<count;
    }

};
int main(){
    string input_str="AeIoU";
    vowels word;
    
}