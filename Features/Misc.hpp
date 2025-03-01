#pragma once
#include <iostream>
#include <string>
#include <unistd.h>
#include <atomic>
#include <vector>
#include <chrono>
#include <thread>
#include <GLFW/glfw3.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/XInput2.h>
#include "../Core/Player.hpp"
#include "../Core/LocalPlayer.hpp"
#include "../Core/Offsets.hpp"
#include "../Core/Level.hpp"

#include "../Math/Vector2D.hpp"
#include "../Math/Vector3D.hpp"
#include "../Math/QAngle.hpp"
#include "../Math/Resolver.hpp"

#include "../Utils/Memory.hpp"
#include "../Utils/XDisplay.hpp"
#include "../Utils/Conversion.hpp"
#include "../Utils/Config.hpp"
#include "../Utils/HitboxType.hpp"
#include "../Utils/InputManager.hpp"
#include "../Utils/InputTypes.hpp"
#include "../Utils/Weapons.hpp"

// UI //
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"

struct Misc {
    bool TeamGamemode = true;
    bool Superglide = false;
    bool SkinChanger = false;
    bool TestSkinChanger = false;
    
    bool ChangeP2020 = false;
    int Skin1P2020 = 1;
    
    //Weapon IDs
    //Light
    int SkinP2020 = 1;
    int SkinRE45 = 1;
    int SkinALTERNATOR = 1;
    int SkinR99 = 1;
    int SkinR301 = 1;
    int SkinSPITFIRE = 1;
    int SkinG7 = 1;
    
    //Heavy
    int SkinFLATLINE = 1;
    int SkinHEMLOCK = 1;
    int SkinREPEATER = 1;
    int SkinRAMPAGE = 1;
    int SkinCAR = 1;
    
    //Energy
    int SkinHAVOC = 1;
    int SkinDEVOTION = 1;
    int SkinLSTAR = 1;
    int SkinTRIPLETAKE = 1;
    int SkinVOLT = 1;
    int SkinNEMESIS = 1;
    
    //Shotgun
    int SkinMOZAMBIQUE = 1;
    int SkinEVA8 = 1;
    int SkinPEACEKEEPER = 1;
    int SkinMASTIFF = 1;
    
    //Snipers
    int SkinLONGBOW = 1;
    int SkinCHARGE_RIFLE = 1;
    int SkinSENTINEL = 1; 
    
    //Legendary
    int SkinWINGMAN = 1;
    int SkinPROWLER = 1;
    int SkinBOCEK = 1;
    int SkinKRABER = 1;

    XDisplay* X11Display;
    Level* Map;
    LocalPlayer* Myself;
    std::vector<Player*>* Players;

    Misc(XDisplay* X11Display, Level* Map, LocalPlayer* Myself, std::vector<Player*>* GamePlayers) {
        this->X11Display = X11Display;
        this->Map = Map;
        this->Myself = Myself;
        this->Players = GamePlayers;
    }

    void RenderUI() {
        if (ImGui::BeginTabItem("Misc", nullptr, ImGuiTabItemFlags_NoCloseWithMiddleMouseButton | ImGuiTabItemFlags_NoReorder)) {
            ImGui::Checkbox("Team Check", &TeamGamemode);
            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                ImGui::SetTooltip("Enable if playing BR, Gun Run or Training\nDisable if playing Control or TDM");
            
            /*ImGui::Checkbox("Auto Superglide [!!!]", &Superglide);
            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                ImGui::SetTooltip("Hold space whilst climbing over an object to gain extra speed!\n[!!!] It works but breaks the overlay, so I do not recommend using this until I find a fix.");*/
            ImGui::Separator();
            ImGui::Checkbox("Skin Changer", &SkinChanger);
            if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
                ImGui::SetTooltip("Change's weapon skins ONLY. May also change legend skin?\nMay be glitchy at first.\nNot all skins are avaliable.");

            //Select Weapons
            ImGui::Text("Weapons");
            if (ImGui::CollapsingHeader("Light", nullptr)) {
            	ImGui::SliderInt("P2020", &SkinP2020, 0, 10);
            	ImGui::SliderInt("RE-45 Auto", &SkinRE45, 0, 16);
            	ImGui::SliderInt("Alternator SMG", &SkinALTERNATOR, 0, 16);
            	ImGui::SliderInt("R-99 SMG", &SkinR99, 0, 16);
            	ImGui::SliderInt("R-301 Carbine", &SkinR301, 0, 18);
            	ImGui::SliderInt("M600 Spitfire", &SkinSPITFIRE, 0, 16);
            	ImGui::SliderInt("G7 Scout", &SkinG7, 0, 21);
            }
            
            if (ImGui::CollapsingHeader("Heavy", nullptr)) {
            	ImGui::SliderInt("VK-47 Flatline", &SkinFLATLINE, 0, 20);
            	ImGui::SliderInt("Hemlock Burst AR", &SkinHEMLOCK, 0, 18);
            	ImGui::SliderInt("30-30 Repeater", &SkinREPEATER, 0, 11);
            	ImGui::SliderInt("Rampage LMG", &SkinRAMPAGE, 0, 11);
            	ImGui::SliderInt("C.A.R SMG", &SkinCAR, 0, 11);
            }
            
            if (ImGui::CollapsingHeader("Energy", nullptr)) {
            	ImGui::SliderInt("Havoc Rifle", &SkinHAVOC, 0, 14);
            	ImGui::SliderInt("Devotion LMG", &SkinDEVOTION, 0, 11);
            	ImGui::SliderInt("L-Star EMG", &SkinLSTAR, 0, 11);
            	ImGui::SliderInt("Triple-Take", &SkinTRIPLETAKE, 0, 11);
            	ImGui::SliderInt("Volt", &SkinVOLT, 0, 14);
            	ImGui::SliderInt("Nemesis Burst AR", &SkinNEMESIS, 0, 9);
            }
            
            if (ImGui::CollapsingHeader("Shotguns", nullptr)) {
            	ImGui::SliderInt("Mozambique", &SkinMOZAMBIQUE, 0, 11);
            	ImGui::SliderInt("EVA-8 Auto", &SkinEVA8, 0, 11);
            	ImGui::SliderInt("Peacekeeper", &SkinPEACEKEEPER, 0, 16);
            	ImGui::SliderInt("Mastiff", &SkinMASTIFF, 0, 11);
            }
            
            if (ImGui::CollapsingHeader("Snipers", nullptr)) {
            	ImGui::SliderInt("Longbow DMR", &SkinLONGBOW, 0, 11);
            	ImGui::SliderInt("Charge Rifle", &SkinCHARGE_RIFLE, 0, 11);
            	ImGui::SliderInt("Sentinel", &SkinSENTINEL, 0, 11);
            }
            
            if (ImGui::CollapsingHeader("Legendary", nullptr)) {
            	ImGui::SliderInt("Wingman", &SkinWINGMAN, 0, 11);
            	ImGui::SliderInt("Prowler Burst SMG", &SkinPROWLER, 0, 11);
            	ImGui::SliderInt("Bocek Compound Bow", &SkinBOCEK, 0, 11);
            	ImGui::SliderInt("Kraber .50-CAL Sniper", &SkinKRABER, 0, 11);
            }
            
            ImGui::EndTabItem();
        }
    }

    bool Save() {
        try {
            Config::Misc::TeamGamemode = TeamGamemode;
            Config::Misc::Superglide = Superglide;
            Config::Misc::SkinChanger = SkinChanger;
	    //Weapon IDs
	    //Light
	     Config::Misc::SkinP2020 = SkinP2020;
	     Config::Misc::SkinRE45 = SkinRE45;
	     Config::Misc::SkinALTERNATOR = SkinALTERNATOR;
	     Config::Misc::SkinR99 = SkinR99;
	     Config::Misc::SkinR301 = SkinR301;
	     Config::Misc::SkinSPITFIRE = SkinSPITFIRE;
	     Config::Misc::SkinG7 = SkinG7;
	    
	    //Heavy
	     Config::Misc::SkinFLATLINE = SkinFLATLINE;
	     Config::Misc::SkinHEMLOCK = SkinHEMLOCK;
	     Config::Misc::SkinREPEATER = SkinREPEATER;
	     Config::Misc::SkinRAMPAGE = SkinRAMPAGE;
	     Config::Misc::SkinCAR = SkinCAR;
	    
	    //Energy
	     Config::Misc::SkinHAVOC = SkinHAVOC;
	     Config::Misc::SkinDEVOTION = SkinDEVOTION;
	     Config::Misc::SkinLSTAR = SkinLSTAR;
	     Config::Misc::SkinTRIPLETAKE = SkinTRIPLETAKE;
	     Config::Misc::SkinVOLT = SkinVOLT;
	     Config::Misc::SkinNEMESIS = SkinNEMESIS;
	    
	    //Shotgun
	     Config::Misc::SkinMOZAMBIQUE = SkinMOZAMBIQUE;
	     Config::Misc::SkinEVA8 = SkinEVA8;
	     Config::Misc::SkinPEACEKEEPER = SkinPEACEKEEPER;
	     Config::Misc::SkinMASTIFF = SkinMASTIFF;
	    
	    //Snipers
	     Config::Misc::SkinLONGBOW = SkinLONGBOW;
	     Config::Misc::SkinCHARGE_RIFLE = SkinCHARGE_RIFLE;
	     Config::Misc::SkinSENTINEL = SkinSENTINEL; 
	    
	    //Legendary
	     Config::Misc::SkinWINGMAN = SkinWINGMAN;
	     Config::Misc::SkinPROWLER = SkinPROWLER;
	     Config::Misc::SkinBOCEK = SkinBOCEK;
	     Config::Misc::SkinKRABER = SkinKRABER;
            return true;
        } catch (...) {
            return false;
        }
    }

    void Update() {
    	if (SkinChanger) {
		if(!Map->IsPlayable) return;
		if(Myself->IsDead) return;
		long wephandle = Memory::Read<long>(Myself->BasePointer + OFF_WEAPON_HANDLE);
		wephandle &= 0xffff;
		long wep_entity = Myself->WeaponEntity;
		std::map<int, std::vector<int>> weaponSkinMap;
		//Light ammo weapons
		weaponSkinMap[SkinChangerID::WEAPON_P2020] = { SkinP2020 };
		weaponSkinMap[SkinChangerID::WEAPON_RE45] = { SkinRE45 };
		weaponSkinMap[SkinChangerID::WEAPON_ALTERNATOR] = { SkinALTERNATOR };
		weaponSkinMap[SkinChangerID::WEAPON_R99] = { SkinR99 }; 
		weaponSkinMap[SkinChangerID::WEAPON_R301] = { SkinR301 };    
		weaponSkinMap[SkinChangerID::WEAPON_SPITFIRE] = { SkinSPITFIRE }; 
		weaponSkinMap[SkinChangerID::WEAPON_G7] = { SkinG7 };
		//Heavy ammo weapons
		weaponSkinMap[SkinChangerID::WEAPON_CAR] = { SkinCAR }; 
		weaponSkinMap[SkinChangerID::WEAPON_RAMPAGE] = { SkinRAMPAGE };  
		weaponSkinMap[SkinChangerID::WEAPON_REPEATER] = { SkinREPEATER };
		weaponSkinMap[SkinChangerID::WEAPON_HEMLOCK] = { SkinHEMLOCK }; 
		weaponSkinMap[SkinChangerID::WEAPON_FLATLINE] = { SkinFLATLINE }; 
		//Energy ammo weapons
		weaponSkinMap[SkinChangerID::WEAPON_NEMESIS] = { SkinNEMESIS };  
		weaponSkinMap[SkinChangerID::WEAPON_VOLT] = { SkinVOLT }; 
		weaponSkinMap[SkinChangerID::WEAPON_TRIPLETAKE] = { SkinTRIPLETAKE }; 
		weaponSkinMap[SkinChangerID::WEAPON_LSTAR] = { SkinLSTAR }; 
		weaponSkinMap[SkinChangerID::WEAPON_DEVOTION] = { SkinDEVOTION }; 
		weaponSkinMap[SkinChangerID::WEAPON_HAVOC] = { SkinHAVOC }; 
		//Sniper ammo weapons
		weaponSkinMap[SkinChangerID::WEAPON_SENTINEL] = { SkinSENTINEL };
		weaponSkinMap[SkinChangerID::WEAPON_CHARGE_RIFLE] = { SkinCHARGE_RIFLE };
		weaponSkinMap[SkinChangerID::WEAPON_LONGBOW] = { SkinLONGBOW };    
		//Shotgun ammo weapons
		weaponSkinMap[SkinChangerID::WEAPON_MOZAMBIQUE] = { SkinMOZAMBIQUE }; 
		weaponSkinMap[SkinChangerID::WEAPON_EVA8] = { SkinEVA8 }; 
		weaponSkinMap[SkinChangerID::WEAPON_PEACEKEEPER] = { SkinPEACEKEEPER }; 
		weaponSkinMap[SkinChangerID::WEAPON_MASTIFF] = { SkinMASTIFF }; 
		//Legendary ammo weapons
		weaponSkinMap[SkinChangerID::WEAPON_WINGMAN] = { SkinWINGMAN }; 
		weaponSkinMap[SkinChangerID::WEAPON_PROWLER] = { SkinPROWLER };
		weaponSkinMap[SkinChangerID::WEAPON_BOCEK] = { SkinBOCEK };
		weaponSkinMap[SkinChangerID::WEAPON_KRABER] = { SkinKRABER };

		if (SkinChanger){
		    int waponIndex = Memory::Read<int>(wep_entity + OFF_WEAPON_INDEX);
		    if (weaponSkinMap.count(waponIndex) == 0) return;
		    int skinID = weaponSkinMap[waponIndex][0];
		    //printf("Weapon: %s Activated Skin ID: %d \n", WeaponName(waponIndex).c_str(), skinID);  
		    Memory::Write<int>(wep_entity + OFF_SKIN, skinID);
		}
    	}
    	
    	if (Superglide) {
    	    while (X11Display->KeyDown(XK_space)) {
		    static float startjumpTime = 0;
		    static bool startSg = false;
		    static float traversalProgressTmp = 0.0;
	 
		    float worldtime = Memory::Read<float>(Myself->BasePointer + OFF_TIME_BASE); // Current time
		    float traversalStartTime = Memory::Read<float>(Myself->BasePointer + OFFSET_TRAVERSAL_START_TIME); // Time to start wall climbing
		    float traversalProgress = Memory::Read<float>(Myself->BasePointer + OFFSET_TRAVERSAL_PROGRESS); // Wall climbing, if > 0.87 it is almost over.
		    auto HangOnWall = -(traversalStartTime - worldtime);
	 
		    if (HangOnWall > 0.1 && HangOnWall < 0.12)
		    {
		        Memory::Write<int>(OFF_REGION + OFF_IN_JUMP + 0x8, 4);
		    }
		    if (traversalProgress > 0.87f && !startSg && HangOnWall > 0.1f && HangOnWall < 1.5f)
		    {
		        //start SG
		        startjumpTime = worldtime;
		        startSg = true;
		    }
		    if (startSg)
		    {
		        //printf ("sg Press jump\n");
		        Memory::Write<int>(OFF_REGION + OFF_IN_JUMP + 0x8, 5);
		        while (Memory::Read<float>(Myself->BasePointer + OFF_TIME_BASE) - startjumpTime < 0.011);
		        {
		            Memory::Write<float>(OFF_REGION + OFF_IN_DUCK + 0x8, 6);
		            std::this_thread::sleep_for(std::chrono::milliseconds(50));
		            Memory::Write<float>(OFF_REGION + OFF_IN_JUMP + 0x8, 4);
		            std::this_thread::sleep_for(std::chrono::milliseconds(600));
		        }
		        startSg = false;
		        break;
		    }
		}
	    }
    	}
};
