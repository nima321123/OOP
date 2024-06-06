#include <iostream>
#include <vector>
using namespace std;

class Player{
    private:
        string name;
        int num;
    public:
        Player(string name, int num):name(name), num(num){}
        void describe(){
            cout << "Player name: " << name << endl;
            cout << "Player number: " << num << endl;
        }
        ~Player(){
            cout << "Player destructor called."<< endl;
        }
};

class Team{
    private:
        string name;
        vector<Player*> players; // This team has multiple players
    public:
        Team(string name, vector<Player*> teamPlayers):name(name), players(teamPlayers){}
        ~Team(){
            cout << "Team destructor called" << endl;
        }
        void describe(){
            cout <<"Team name: " << name << endl;
            cout <<"Players info*** " << endl;
            for (Player* player:players){
                player->describe();
            }
        }
};

int main(){
    Player* player1 = new Player("John", 1);
    Player* player2 = new Player("Anna", 2);
    vector<Player*> players = {player1, player2};
    Team team("Eagle", players);
    team.describe();
    
    delete player1;
    delete player2;

    
}