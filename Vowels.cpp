#include <iostream>
#include<vector>
using namespace std;

class vowel {
    public:
    vowel(vector<string> &list){
        list_of_words=list;
    }
    bool isvowel(char ch){
        ch=toupper(ch);
        return(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U');
    }
    
    int countvowels(string str){
        int length=str.length();
        int count=0;

        for(int i=0;i<length;i++){
            if(isvowel(str[i])){
                count++;
            }
            return count;

        }
        count=0;   
    }
    
    void countstringvect(){
        vector<int>vowel_sizes;
        int size;

        for(int i=0;i<list_of_words.size();i++){
            size=countvowels(list_of_words.at(i));
            vowel_sizes.push_back(size);


        }
        for(int i=0;i<vowel_sizes.size();i++){
            cout<<vowel_sizes.at(i)<<',';
        }

    }
    
    vector<string>list_of_words;

    int main(){

        vector<string>lis={"apple","grapes","lemon"};
        vowel words(lis);
        words.countstringvect();
    }
    
    
    
    
    
   
    
    
    
    
    
    
    


};