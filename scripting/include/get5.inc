#if defined _trate_included
  #endinput
#endif
#define _trate_included

enum GameState {
    GameState_None,                          // no setup has taken place
    GameState_PreVeto,                       // warmup, waiting for the veto
    GameState_Veto,                          // warmup, doing the veto
    GameState_Warmup,                        // setup done, waiting for players to ready up
    GameState_KnifeRound,                    // in the knife round
    GameState_WaitingForKnifeRoundDecision,  // waiting for a .stay/.swap command after the knife round
    GameState_GoingLive,                     // in the lo3 process
    GameState_Live,                          // the match is live
    GameState_PostGame,                      // postgame screen + waiting for GOTV to finish broadcast
};

enum MatchTeam {
    MatchTeam_Team1,
    MatchTeam_Team2,
    MatchTeam_TeamSpec,
    MatchTeam_TeamNone,
    MatchTeam_Count,
};

// Returns the current pug gamestate.
native GameState Trate_GetGameState();

// Prints a plugin-formatted message to a client.
native void Trate_Message(int client, const char[] format, any:...);

// Prints a plugin-formatted message to all clients.
native void Trate_MessageToAll(const char[] format, any:...);

public SharedPlugin __pl_trate = {
    name = "trate",
    file = "trate.smx",
#if defined REQUIRE_PLUGIN
    required = 1,
#else
    required = 0,
#endif
};

#if !defined REQUIRE_PLUGIN
public __pl_trate_SetNTVOptional() {
    MarkNativeAsOptional("Trate_GetGameState");
    MarkNativeAsOptional("Trate_Message");
    MarkNativeAsOptional("Trate_MessageToAll");
}
#endif