#include "pch.h"
#include "AutoSpectate.h"


BAKKESMOD_PLUGIN(AutoSpectate, "AutoSpectate", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void AutoSpectate::onLoad()
{
	_globalCvarManager = cvarManager;

	cvarManager->registerCvar("AutoSpectate_enable", "0", "Enable Plugin", false, true, 0, true, 1).addOnValueChanged([this](std::string oldValue, CVarWrapper cvar) { Plugin_enabled = cvar.getBoolValue(); });
	cvarManager->registerCvar("SpectatorIsAdmin", "0", "Spectator is Admin", false, true, 0, true, 1).addOnValueChanged([this](std::string oldValue, CVarWrapper cvar) { SpectatorIsAdmin = cvar.getBoolValue(); });

	cvarManager->registerCvar("spectatorDelay", "1.8", "spectatorDelay", false, true, 0, true, 100, true).addOnValueChanged([this](std::string oldValue, CVarWrapper cvar) { spectatorDelay = cvar.getFloatValue(); });
	cvarManager->registerCvar("guiDelay", "1.0", "guiDelay", false, true, 0, true, 100, true).addOnValueChanged([this](std::string oldValue, CVarWrapper cvar) { guiDelay = cvar.getFloatValue(); });

	gameWrapper->HookEventPost("Function TAGame.MatchType_TA.AutoSpectate", [this](std::string eventName) { if(Plugin_enabled) enterSpectator(); });
	gameWrapper->HookEventPost("Function TAGame.PRI_TA.Spectate", [this](std::string eventName) { if(Plugin_enabled) removeGUI(); });


}

void AutoSpectate::onUnload()
{
}

void AutoSpectate::sendKey(int index) {

	INPUT ip;

	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0;
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	ip.ki.wVk = index;
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
}

void AutoSpectate::enterSpectator() {

	if (SpectatorIsAdmin) {
		auto pc = gameWrapper->GetPlayerController();
		if (pc.IsNull()) return;

		pc.Spectate();
		return;
	}

	gameWrapper->SetTimeout([this](GameWrapper* gw) { sendKey(0x28); sendKey(0x28); sendKey(0x0D); }, spectatorDelay);
}

void AutoSpectate::removeGUI() {

	gameWrapper->SetTimeout([this](GameWrapper* gw) { cvarManager->executeCommand("replay_gui hud 0; replay_gui matchinfo 0"); }, guiDelay);

}