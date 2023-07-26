#include<iostream>
using namespace std;

class vowels{
    
    private:
    string input_string;


    public:
  
    vowels(string str){
        input_string=str;

    }
    bool isVowel(char s){
        s=toupper(s);

        return(s=='A'||s=='E'||s=='I'||s=='O'||s=='U');



    }
    int countvowels(){
        int count;
        int length=input_string.length();
        for(int i=0;i<length;i++){
            
            if(isVowel(input_string[i])){
                count++;

            }
            
        }
    

    
    }
    void printvowels(){
        int novowels=countvowels();
        cout<<novowels;
    }
};
    int main(){
        string input_string="string";
        vowels word(input_string);
        word.printvowels();
    }
