/* COP 3502C Assignment 1
This program is written by: Kauan Lima*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 21

typedef struct Player {
    char *name; //Player name (dynamically allocated)
    int totalGoals; //Total goals scored by the player(needs to be counted based on the match)
}Player;

typedef struct Team {
    char *name; // Name of the team (dynamically allocated)
    Player **players; //An array of Player pointers where each pointer is pointing to a player
    int playerCount; // Number of players in the team
}Team;

typedef struct Goal {
    Player *scorer; // Pointer to the player who scored
    int time; // Time of the goal in minutes
}Goal;

typedef struct Match {
    Team *team1; // Pointer to Team 1
    Team *team2; // Pointer to Team 2
    Goal *goals; // Array of goals scored in the match
    int goalCount; // Total number of goals in the match
}Match;

//this is a special struct that should only be used to process a particular command (mentioned below in the function requirement)
typedef struct MatchWinnerTeam
{
    Team *winnerTeam; //pointer to the winner team if any.
    int isDraw; //set to 1 if it was a draw. In that case winnerTeam will be NULL
}MatchWinnerTeam;

// allocate space for Player struct
// allocate space for player name and copy passed name into the struct
// set goals to zero
// return Player*
Player* createPlayer(char *name)
{
    Player* p = (Player*)malloc(sizeof(Player));

    int Length = strlen(name) + 1;
    p->name = (char*)malloc(Length * sizeof(char));
    strcpy(p->name, name);

    p->totalGoals = 0;

    return p;
}

// free Player name and player struct
void freePlayer(Player* player)
{
    free(player->name);
    free(player);
}

// allocate space for Team struct
// allocate space for team name and copy passed name into the struct
// allocate space for the list of players
// initialize struct playerCount
// return Team*
Team* createTeam(char *name, int playerCount)
{
    Team* t = (Team*)malloc(sizeof(Team));

    int Length = strlen(name) + 1;
    t->name = (char*)malloc(Length * sizeof(char));
    strcpy(t->name, name);

    t->players = (Player**)malloc(playerCount * sizeof(Player*));
    t->playerCount = playerCount;

    return t;
}

// free Team name, player List, and struct
void freeTeam(Team* team)
{
    free(team->name);
    free(team->players);
    free(team);
}

// find player by their target name
// loop through each player in full playerList
// return Player* if found, return NULL if not
Player* getPlayerByName(char* name, Player** playerList, int numPlayers)
{
    for (int i = 0; i < numPlayers; i++)
    {
        if (strcmp(name, playerList[i]->name) != 0)
            continue;
        return playerList[i];
    }

    return NULL;
}

// find team by their target name
// loop through each team in full teamList
// return Team* if found, return NULL if not
Team* getTeamByTeamName(Team** teamList, int numTeams, char *tname)
{
    for (int i = 0; i < numTeams; i++)
    {
        if (strcmp(tname, teamList[i]->name) != 0)
            continue;
        return teamList[i];
    }

    return NULL;
}

// increment goalCount for each goal recorded
// allocate proper space for goals list
// find the scorer which exists in team1 or team2 and add to goals
// increment total goals on player
// initialize the time of the goal in the struct
void recordGoal(Match *match, Player *player, int time)
{
    match->goalCount++;

    match->goals = (Goal*)realloc(match->goals, sizeof(Goal) * (match->goalCount + 1));

    match->goals[match->goalCount - 1].scorer = getPlayerByName(player->name, match->team1->players, match->team1->playerCount);
    if (match->goals[match->goalCount - 1].scorer == NULL)
        match->goals[match->goalCount - 1].scorer = getPlayerByName(player->name, match->team2->players, match->team2->playerCount);

    player->totalGoals++;
    match->goals[match->goalCount - 1].time = time;
}

// find if player has scored more than 3 goals in a match
// print the match name, player name, and total goals in tournament
int printHatTrickPlayers(Match *match)
{
    // allocate memory to track players and goals for this function
    Player** pPtr = (Player**)calloc(match->goalCount, sizeof(Player*));
    int* gc = (int*)calloc(match->goalCount, sizeof(int));
    int uniquePlayers = 0;

    // loop through each goal
    for (int i = 0; i < match->goalCount; i++)
    {
        // for each player in pPtr, increment their goalCount for the match
        // if they are found and scored more than once
        int foundPlayer = 0;
        for (int j = 0; j < uniquePlayers; j++)
            if (pPtr[j] == match->goals[i].scorer)
            {
                gc[j]++;
                foundPlayer = 1;
                break;
            }

        // if a player isn't in pPtr, add them to the correct index
        // initialize their goalcount
        if (!foundPlayer)
        {
            pPtr[uniquePlayers] = match->goals[i].scorer;
            gc[uniquePlayers] = 1;
            uniquePlayers++;
        }
    }

    // find any index which has 3 or more goals
    // if index exists, declare that a hatrick exists in this match
    int trickExists = 0;
    for (int i = 0; i < uniquePlayers; i++)
        if (gc[i] >= 3)
        {
            if (!trickExists)
                printf("hat trick found in %s vs %s:\n", match->team1->name, match->team2->name);
            printf("%s %d\n", pPtr[i]->name, pPtr[i]->totalGoals);
            trickExists = 1;
        }

    // free the memory of the function specific arrays
    free(pPtr);
    free(gc);

    return trickExists;
}

// find the winner of a team between two matches and return MatchWinnerTeam*
// winning team stored as a pointer and also returns if the match was a draw
MatchWinnerTeam* getWinningTeam(Match *matches, int matchCount, char *team1Name, char *team2Name)
{
    // allocate space for mwt and initialize a tracker variable
    MatchWinnerTeam* mwt = (MatchWinnerTeam*)malloc(sizeof(MatchWinnerTeam));
    int isMatchFound = 0;

    // loop through each match
    for (int i = 0; i < matchCount; i++)
        // check if two teams played in the same match
        if (strcmp(matches[i].team1->name, team1Name) == 0 && strcmp(matches[i].team2->name, team2Name) == 0)
        {
            // goal trackers
            int team1GoalCount = 0, team2GoalCount = 0;
            isMatchFound = 1;

            // loop through each goal in the match
            for (int j = 0; j < matches[i].goalCount; j++)
            {
                // loop through each player in team 1 and find if scorer exists
                for (int k = 0; k < matches[i].team1->playerCount; k++)
                    if (matches[i].goals[j].scorer == matches[i].team1->players[k])
                    {
                        team1GoalCount++;
                        break;
                    }
    
                // loop through each player in team 2 and find if scorer exists
                for (int k = 0; k < matches[i].team2->playerCount; k++)
                    if (matches[i].goals[j].scorer == matches[i].team2->players[k])
                    {
                        team2GoalCount++;
                        break;
                    }
            }
            
            // decide the outcome
            if (team1GoalCount > team2GoalCount)
            {
                mwt->winnerTeam = matches[i].team1;
                mwt->isDraw = 0;
            }
            else if (team1GoalCount < team2GoalCount)
            {
                mwt->winnerTeam = matches[i].team2;
                mwt->isDraw = 0;
            }
            else
            {
                mwt->winnerTeam = NULL;
                mwt->isDraw = 1;
            }
            return mwt;
        }

    // free mwt and return null if no match found
    if (!isMatchFound)
    {
        free(mwt);
        return NULL;
    }
}

// tallies the wins, losses, and draws of each team in the tournament to find
// the highest score and return the Team* pointing to the champion team
Team* getChampion(Team **teamList, int teamCount, Match *matchList, int matchCount)
{
    // allocate points array to keep track of each team's points
    int* points = (int*)calloc(teamCount, sizeof(int));
    
    // loop through each team
    for (int i = 0; i < teamCount; i++)
        // loop through each team again
        // j = i+1 so that duplicated checks dont occur (1vs1), (2vs2), or (1vs2) and (2vs1)
        for (int j = i + 1; j < teamCount; j++)
        {
            // check for team1 and team2 name, sort them appropriately
            char team1[STRING_SIZE], team2[STRING_SIZE];
            if (strcmp(teamList[i]->name, teamList[j]->name) > 0)
            {
                strcpy(team1, teamList[j]->name);
                strcpy(team2, teamList[i]->name);
            }
            else
            {
                strcpy(team1, teamList[i]->name);
                strcpy(team2, teamList[j]->name);
            }
            
            MatchWinnerTeam* mwt = getWinningTeam(matchList, matchCount, team1, team2);

            // if no match found, iterate through loop again
            if (mwt == NULL)
                continue;

            // tally all points
            if (mwt->isDraw)
            {
                points[i]++;
                points[j]++;
            }
            else if (mwt->winnerTeam == teamList[i])
                points[i] += 3;
            else if (mwt->winnerTeam == teamList[j])
                points[j] += 3;
            free(mwt);
        }

    // find the team with the most points
    int maxPoints = -1;
    int maxIndex = 0;

    for (int i = 0; i < teamCount; i++)
        if (points[i] > maxPoints)
        {
            maxPoints = points[i];
            maxIndex = i;
        }

    // free points array
    free(points);
    
    return teamList[maxIndex];
}

// free all memory allocated in program
void freeAll(int numTeams, int numMatches, Team** teamList, Match* matchList, Player** playerList)
{
    // free each player and team and each team
    for (int i = 0; i < numTeams; i++)
    {
        for (int j = 0; j < teamList[i]->playerCount; j++)
            freePlayer(teamList[i]->players[j]);
        freeTeam(teamList[i]);
    }
    // free each goal array
    for (int i = 0; i < numMatches; i++)
        free(matchList[i].goals);

    //free any other declared lists
    free(matchList);
    free(playerList);
}

// main
int main(void)
{
    // initialize the lengths for each loop in the program
    int numTeams = 0, numMatches = 0, numCmd = 0;
    scanf("%d %d %d", &numTeams, &numMatches, &numCmd);

    // declare pointer arrays
    Team* teamList[numTeams];
    Player** playerList = NULL;

    // tracker variables
    int playerInTeamCount = 0, playerListCount = 0;

    // name variables
    char teamName[STRING_SIZE], playerName[STRING_SIZE];

    // loop that generates specified number of teams
    for (int i = 0; i < numTeams; i++)
    {
        scanf("%s %d", teamName, &playerInTeamCount);
        teamList[i] = createTeam(teamName, playerInTeamCount);

        playerListCount += playerInTeamCount;
        playerList = (Player**)realloc(playerList, playerListCount * sizeof(Player*));

        // loop that generates specified number of players per team
        for (int j = 0; j < playerInTeamCount; j++)
        {
            scanf("%s", playerName);

            playerList[playerListCount - playerInTeamCount + j] = createPlayer(playerName);
            teamList[i]->players[j] = playerList[playerListCount - playerInTeamCount + j];
        }
    }

    // initialize null match array
    Match* matchList = (Match*)malloc(numMatches * sizeof(Match));

    // loop to create each match
    for (int i = 0; i < numMatches; i++)
    {
        char team1[STRING_SIZE], team2[STRING_SIZE];
        scanf("%s %s", team1, team2);

        matchList[i].team1 = getTeamByTeamName(teamList, numTeams, team1);
        matchList[i].team2 = getTeamByTeamName(teamList, numTeams, team2);
        matchList[i].goals = NULL;
        matchList[i].goalCount = 0;

        // loop to create unspecified number of goals per match
        for (int j = 0; /* infinite loop */ ; j++)
        {
            char scorerName[STRING_SIZE];
            int time = 0;
            scanf("%s", scorerName);

            if (strcmp(scorerName, "end") == 0)
                break;

            scanf("%d", &time);

            Player* scorer = getPlayerByName(scorerName, playerList, playerListCount);

            recordGoal(&matchList[i], scorer, time);
        }
    }

    // declare necessary variables for commands
    char cmd[STRING_SIZE], team1winner[STRING_SIZE], team2winner[STRING_SIZE];
    int hasOccurred = 0;

    // loop to run each command
    for (int i = 0; i < numCmd; i++)
    {
        scanf("%s", cmd);

        // print the player with the most goals
        int exists = 0;
        if (strcmp(cmd, "max_goal_player") == 0)
        {
            int maxGoals = -1;
            int maxIndex = 0;

            for (int j = 0; j < playerListCount; j++)
                if (playerList[j]->totalGoals > maxGoals)
                {
                    maxGoals = playerList[j]->totalGoals;
                    maxIndex = j;
                }
            printf("player with max goal %s %d\n", playerList[maxIndex]->name, playerList[maxIndex]->totalGoals);
        }
        // print player with 3+ goals in a match and their total goal count
        else if (strcmp(cmd, "hattrick") == 0)
        {
            for (int j = 0; j < numMatches; j++)
            {
                exists = printHatTrickPlayers(&matchList[j]);
                if (exists == 1)
                    hasOccurred = 1;
            }
            if (!exists && !hasOccurred)
                printf("no hat trick found in the tournament\n");
        }
        // print the winner of two teams
        else if (strcmp(cmd, "winner") == 0)
        {
            scanf("%s %s", team1winner, team2winner);

            MatchWinnerTeam* mwt = getWinningTeam(matchList, numMatches, team1winner, team2winner);

            if (mwt == NULL)
                printf("no match between %s and %s\n", team1winner, team2winner);
            else if (mwt->isDraw)
                printf("%s vs %s match drawn\n", team1winner, team2winner);
            else
                printf("winner of %s vs %s is %s\n", team1winner, team2winner, mwt->winnerTeam->name);
            free(mwt);
        }
        // print the champion
        else if (strcmp(cmd, "champion") == 0)
        {
            Team* champ = getChampion(teamList, numTeams, matchList, numMatches);
            printf("champion is %s", champ->name);
        }
    }

    // free all memory
    freeAll(numTeams, numMatches, teamList, matchList, playerList);

    return 0;
}