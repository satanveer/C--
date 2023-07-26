#include <iostream>
#include <vector>
using namespace std;

class vowels{
    
    private:
    vector<string> input_word;
    
    public:
    
    vowels(vector<string> str){
        input_word=str;
    }

    void countstrings(){
        int counter;
        vector<int>vowelsize;

        for(int i=0;i<input_word.size();i++){
            counter=countvowel(input_word.at(i));
            vowelsize.push_back(counter);         

        }
        for(int i=0;i<vowelsize.size();i++){
            cout<<vowelsize.at(i)<<endl;
        }
    }


    private:
    

    bool isvowel(char ch){
        ch = toupper(ch);
        return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');

    }
    int countvowel(string input){
         int count;
        for(int i=0;i<input.length();){
            if(isvowel(input[i])){
                count++;
            }
            
        }
        return count;

    }


};
int main(){
    vector<string>rubb={"abcde","eeiao",'fan'};
    vowels words(rubb);
    words.countstrings();

}