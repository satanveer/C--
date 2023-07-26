#include <iostream>
using namespace std;

class Song {
  
 

  private:
    string artist;
    string title;
    string album;
    int play_count = 0;
    const double pay_rate = 0.001;
    double money_earned = 0;
    
    void UpdatePlayCount() {
      play_count++;
    }
  
    void UpdateMoneyEarned() {
      money_earned = play_count * pay_rate;
    }

    public:
    Song(string art,string tit,string alb){
      artist=art;
      title=tit;
      album=alb;
    }

    void Play(int n){
      for(int i=0;i<=n-1;i++){
        UpdatePlayCount();
        UpdateMoneyEarned();
      }

    }
    void Stats(){
      cout<<artist<<endl;
      cout<<title<<endl;
      cout<<album<<endl;
      cout<<play_count<<endl;
      cout<<pay_rate<<endl;
      cout<<money_earned;
    
    }

    string GetArtist(){
      return artist;

    }
    string GetAlbum(){
      return album;
    }
    int GetPlayCount(){
      return play_count;
    }
    string GetTitle(){
      return title;
    }
    double GetPayRate(){
      return pay_rate;
    }
    double GetMoneyEarned(){
      return money_earned;
    }

    string SetAlbum(string albumx){
      album=albumx;
    }
    string SetTitle(string titlex){
      title=titlex;
    }
    string SetArtist(string artistx){
      artist=artistx;
    }
};

int main() {

  Song my_song("Led Zeppelin", "Ten Years Gone", "Physical Graffiti");
  cout << my_song.GetArtist() << endl;
  cout << my_song.GetTitle() << endl;
  cout << my_song.GetAlbum() << endl;
  cout << my_song.GetPlayCount() << endl;
  cout << my_song.GetPayRate() << endl;
  cout << my_song.GetMoneyEarned() << endl;
  my_song.SetArtist("Michael Jackson");
  my_song.SetTitle("Beat It");
  my_song.SetAlbum("Thriller");
  my_song.Play(1000000);
  my_song.Stats();
  
  return 0;
  
}

//DO NOT EDIT CODE ABOVE THIS LINE