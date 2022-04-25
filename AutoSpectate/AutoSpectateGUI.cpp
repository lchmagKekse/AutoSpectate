#include "pch.h"
#include "AutoSpectate.h"

/* Plugin Settings Window code here
std::string AutoSpectate::GetPluginName() {
	return "AutoSpectate";
}

void AutoSpectate::SetImGuiContext(uintptr_t ctx) {
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

// Render the plugin settings here
// This will show up in bakkesmod when the plugin is loaded at
//  f2 -> plugins -> AutoSpectate
void AutoSpectate::RenderSettings() {
	ImGui::TextUnformatted("AutoSpectate plugin settings");
}
*/

/*
// Do ImGui rendering here
void AutoSpectate::Render()
{
	if (!ImGui::Begin(menuTitle_.c_str(), &isWindowOpen_, ImGuiWindowFlags_None))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}

	ImGui::End();

	if (!isWindowOpen_)
	{
		cvarManager->executeCommand("togglemenu " + GetMenuName());
	}
}

// Name of the menu that is used to toggle the window.
std::string AutoSpectate::GetMenuName()
{
	return "autospectate";
}

// Title to give the menu
std::string AutoSpectate::GetMenuTitle()
{
	return menuTitle_;
}

// Don't call this yourself, BM will call this function with a pointer to the current ImGui context
void AutoSpectate::SetImGuiContext(uintptr_t ctx)
{
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
}

// Should events such as mouse clicks/key inputs be blocked so they won't reach the game
bool AutoSpectate::ShouldBlockInput()
{
	return ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantCaptureKeyboard;
}

// Return true if window should be interactive
bool AutoSpectate::IsActiveOverlay()
{
	return true;
}

// Called when window is opened
void AutoSpectate::OnOpen()
{
	isWindowOpen_ = true;
}

// Called when window is closed
void AutoSpectate::OnClose()
{
	isWindowOpen_ = false;
}
*/
