#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class Team{
private:
    std::string Name;
    int Att;
    int Def;
public:
    Team() : Name(""), Att(0), Def(0) {}
    Team(const std::string& name, int att, int def)
        : Name(name), Att(att), Def(def) {}
    std::string getName() const{
        return Name;
    } 
    int getAtt() const{
        return Att;
    }
    int getDef() const{
        return Def;
    }
};

class ChampionsLeague{
private:
    std::vector<Team> round16;
    std::vector<Team> round8;
    std::vector<Team> semi_final;
    std::vector<Team> final;
    Team winner;

    void roundOf16(){
        std::cout << "ROUND OF 16: " << std::endl;
        for (const Team& t : round16){
            std::cout << t.getName() << std::endl;
        }
        while (!round16.empty()){
            int team1_index = rand() % round16.size();
            Team team1 = round16[team1_index];
            round16.erase(round16.begin() + team1_index);
            int team2_index = rand() % round16.size();
            Team team2 = round16[team2_index];
            round16.erase(round16.begin() + team2_index);

            if (team1.getAtt() >= team2.getDef() && team1.getDef() >= team2.getAtt()){
                round8.push_back(team1);
            }
            else if (team1.getAtt() >= team2.getDef() && team1.getDef() <= team2.getAtt()){
                int rnd = rand() % 2;
                if (rnd == 0){
                    round8.push_back(team1);
                }
                else{
                    round8.push_back(team2);
                }
            }
            else if (team1.getAtt() <= team2.getDef() && team1.getDef() >= team2.getAtt()){
                int rnd = rand() % 2;
                if (rnd == 0){
                    round8.push_back(team1);
                }
                else{
                    round8.push_back(team2);
                }
            }
            else{
                round8.push_back(team2);
            }
        }
    }
    void roundOf8(){
        std::cout << "ROUND OF 8: " << std::endl;
        for (const Team& t : round8){
            std::cout << t.getName() << std::endl;
        }
        while (!round8.empty()){
            int team1_index = rand() % round8.size();
            Team team1 = round8[team1_index];
            round8.erase(round8.begin() + team1_index);
            int team2_index = rand() % round8.size();
            Team team2 = round8[team2_index];
            round8.erase(round8.begin() + team2_index);

            if (team1.getAtt() >= team2.getDef() && team1.getDef() >= team2.getAtt()){
                semi_final.push_back(team1);
            }
            else if (team1.getAtt() >= team2.getDef() && team1.getDef() <= team2.getAtt()){
                int rnd = rand() % 2;
                if (rnd == 0){
                    semi_final.push_back(team1);
                }
                else{
                    semi_final.push_back(team2);
                }
            }
            else if (team1.getAtt() <= team2.getDef() && team1.getDef() >= team2.getAtt()){
                int rnd = rand() % 2;
                if (rnd == 0){
                    semi_final.push_back(team1);
                }
                else{
                    semi_final.push_back(team2);
                }
            }
            else{
                semi_final.push_back(team2);
            }
            
        }
    }
    void semiFinals(){
        std::cout << "SEMI FINALS: " << std::endl;
        for (const Team& t : semi_final){
            std::cout << t.getName() << std::endl;
        }
        while (!semi_final.empty()){
            int team1_index = rand() % semi_final.size();
            Team team1 = semi_final[team1_index];
            semi_final.erase(semi_final.begin() + team1_index);
            int team2_index = rand() % semi_final.size();
            Team team2 = semi_final[team2_index];
            semi_final.erase(semi_final.begin() + team2_index);

            if (team1.getAtt() >= team2.getDef() && team1.getDef() >= team2.getAtt()){
                final.push_back(team1);
            }
            else if (team1.getAtt() >= team2.getDef() && team1.getDef() <= team2.getAtt()){
                int rnd = rand() % 2;
                if (rnd == 0){
                    final.push_back(team1);
                }
                else{
                    final.push_back(team2);
                }
            }
            else if (team1.getAtt() <= team2.getDef() && team1.getDef() >= team2.getAtt()){
                int rnd = rand() % 2;
                if (rnd == 0){
                    final.push_back(team1);
                }
                else{
                    final.push_back(team2);
                }
            }
            else{
                final.push_back(team2);
            }
        }
    }
    void finals(){
        std::cout << "FINALS: " << std::endl;
        for (const Team& t : final){
            std::cout << t.getName() << std::endl;
        }
        while (!final.empty()){
            int team1_index = rand() % final.size();
            Team team1 = final[team1_index];
            final.erase(final.begin() + team1_index);
            int team2_index = rand() % final.size();
            Team team2 = final[team2_index];
            final.erase(final.begin() + team2_index);

            if (team1.getAtt() >= team2.getDef() && team1.getDef() >= team2.getAtt()){
                winner = team1;
            }
            else if (team1.getAtt() >= team2.getDef() && team1.getDef() <= team2.getAtt()){
                int rnd = rand() % 2;
                if (rnd == 0){
                    winner = team1;
                }
                else{
                    winner = team2;
                }
            }
            else if (team1.getAtt() <= team2.getDef() && team1.getDef() >= team2.getAtt()){
                int rnd = rand() % 2;
                if (rnd == 0){
                    winner = team1;
                }
                else{
                    winner = team2;
                }
            }
            else{
                winner = team2;
            }
        }
        std::cout << "CHAMPIONS LEAGUE WINNER: " << winner.getName() << std::endl;
    }
    public:
        ChampionsLeague(){
            round16 = {
                Team("Real Madrid", 94, 86),
                Team("Bayern", 86, 85),
                Team("Manchester City", 90, 85),
                Team("PSG", 88, 84),
                Team("Barcelona", 92, 86),
                Team("Liverpool", 90, 88),
                Team("Inter Milan", 88, 87),
                Team("AC Milan", 86, 83),
                Team("Juventus", 85, 85),
                Team("Arsenal", 87, 88),
                Team("Manchester United", 0, 0),
                Team("Chelsea", 82, 80),
                Team("Napoli", 84, 82),
                Team("Tottenham", 84, 84),
                Team("Dortmund", 83, 85),
                Team("Leverkusen", 82, 83)
            };
            std::srand(std::time(nullptr));
        }
        void start(){
            std::cout << "****************************************" << std::endl;
            std::cout << "WELCOME TO THE CHAMPIONS LEAGUE" << std::endl;
            std::cout << "****************************************" << std::endl;
            roundOf16();
            roundOf8();
            semiFinals();
            finals();
        }
};

int main()
{
    ChampionsLeague tournament;
    tournament.start();

    return 0;
}