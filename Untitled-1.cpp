#include <iostream>
using namespace std;

class Game{
    public:
    string jenis = "moba";
};

class Genre : public Game{
    public:
    string nama = "mobile legend";
};

int main(){
    Genre myGame;
    cout << myGame.jenis << " " << myGame.nama;
    return 0;
}