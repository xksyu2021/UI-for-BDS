#pragma once

void Submit(HWND hWnd1);
void Update(HWND hWnd1, int id, int id1);

extern HWND hGamemode, hDifficulty, hPermission;
extern WORD wmId, wmEvent;

#define CONF_ServerName 51010
#define CONF_GameMode 51020
#define CONF_ForceGameMode 51021
#define CONF_GameDifficuty 51030
#define CONF_Cheat 51040
#define CONF_Cheat_NOEDIT 51041
#define CONF_DeflautPermission 51050
#define CONF_LevelName 51060
#define CONF_LevelSeed 51070
#define CONF_MaxPlayer 51080
#define CONF_Idle 51190

#define CONF_OnlineMode 51090
#define CONF_LanVisible 51100
#define CONF_Whitelist 51120
#define CONF_OnlineMode_NOEDIT 51091
#define CONF_LanVisible_NOEDIT 51101
#define CONF_Whitelist_NOEDIT 51121

#define CONF_FroceTexture 51130
#define CONF_BanSkin 51140
#define CONF_Mute 51150
#define CONF_FroceTexture_NOEDIT 51131
#define CONF_BanSkin_NOEDIT 51141
#define CONF_Mute_NOEDIT 51151

#define CONF_AntiCheat_NOEDIT 51161
#define CONF_AntiCheat 51162

#define CONF_OPENCONFIG 51170
#define CONF_OK 51180