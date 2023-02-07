#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

int solve(int N, int M, int S, vector<string> required_skills_list, vector<vector<tuple<string, int>>> players)
{
    // SCRIVI QUA IL TUO CODICE
    return 0;
}

int testcase()
{
    int N, M, S;
    cin >> N >> M >> S;

    vector<string> required_skills_list(M);
    vector<vector<tuple<string, int>>> players(N, vector<tuple<string, int>>(S));

    for (int i = 0; i < M; i++)
        cin >> required_skills_list[i];

    for (int i = 0; i < N; i++)
    {
        int id;
        cin >> id;
        for (int j = 0; j < S; j++)
            cin >> get<0>(players[i][j]) >> get<1>(players[i][j]);
    }

    return solve(N, M, S, required_skills_list, players);
}

int main()
{

    // freopen("input.txt", "r", stdin); // DECOMMENTA QUA SE VUOI LEGGERE DA FILE
    // freopen("output.txt", "w", stdout); // DECOMMENTA QUA SE VUOI SCRIVERE DA FILE

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
        cout << testcase() << "\n";

    return 0;
}