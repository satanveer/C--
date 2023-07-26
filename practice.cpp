#include <iostream>
using namespace std;

class vowels{
    private:
    string input;
    public:
    vowels(string str){
        input=str;
    }

    bool isvowel(char ch){
        ch = toupper(ch);
        return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }

    int countvowel(){
        int len=input.length();
        int count=0;

        for(int i=0;i<len;i++){
            if(isvowel(input[i])){
                count++;
            }
        }
        return count;
    }
    void printv(){
        int print=countvowel();
        cout<<print;

    }

};
int main(){
    string input_str="aeiou";
    vowels word("aeiou");
    word.printv();
    return 0;
}