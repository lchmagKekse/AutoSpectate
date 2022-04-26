#include "pch.h"
#include "AutoSpectate.h"


std::string AutoSpectate::GetPluginName() {
	return "AutoSpectate";
}

void AutoSpectate::SetImGuiContext(uintptr_t ctx) {
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

void AutoSpectate::RenderSettings() {

	CVarWrapper enableCvar = cvarManager->getCvar("AutoSpectate_enable");
	if (!enableCvar) return;
	bool enabled = enableCvar.getBoolValue();
	if (ImGui::Checkbox("Enable plugin", &enabled))
		enableCvar.setValue(enabled);

	ImGui::SameLine();

	ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 0.6f), "(?)");
	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("Enables the plugin. Duh");
	}


	CVarWrapper AdminCvar = cvarManager->getCvar("SpectatorIsAdmin");
	if (!AdminCvar) return;
	bool Adminenabled = AdminCvar.getBoolValue();
	if (ImGui::Checkbox("Spectator is Admin", &Adminenabled))
		AdminCvar.setValue(Adminenabled);

	ImGui::SameLine();
	ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 0.6f), "(?)");
	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("Enable this when the Spectator is the admin of the match.\nThe Spectator Delay will be ignored and the player instantly gets put into spectator upon joining the game.");
	}


	float step = 0.01f;
	if (ImGui::InputScalar("Spectator Delay", ImGuiDataType_Float, &spectatorDelay, true ? &step : NULL))
		cvarManager->getCvar("spectatorDelay").setValue(spectatorDelay);
	if (spectatorDelay < 0)
		cvarManager->getCvar("spectatorDelay").setValue(0);

	ImGui::SameLine();
	ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 0.6f), "(?)");
	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("The delay in seconds when the player enters spectator.\nPlay around with this until you find the perfect timing. Depends on how fast/slow your PC is.");
	}


	if (ImGui::InputScalar("GUI Delay", ImGuiDataType_Float, &guiDelay, true ? &step : NULL))
		cvarManager->getCvar("guiDelay").setValue(guiDelay);
	if (guiDelay < 0)
		cvarManager->getCvar("guiDelay").setValue(0);

	ImGui::SameLine();
	ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 0.6f), "(?)");
	if (ImGui::IsItemHovered()) {
		ImGui::SetTooltip("The delay in seconds when the GUI gets removed after entering spectator mode.\nPlay around with this until you find the perfect timing. Depends on how many players join the game and fast/slow your PC is.");
	}

	ImGui::TextColored(ImVec4(1.0f, 1.0f, 1.0f, 0.6f), "Hover over the question marks for help");

	ImGui::NewLine();
	ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.4f, 0.5f), "Made by LchmagKekse");
}