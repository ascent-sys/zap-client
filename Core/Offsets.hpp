#pragma once

// Core    
constexpr long OFF_REGION = 0x140000000;                      //[Static]->Region
constexpr long OFF_LEVEL = 0x16d6ab0;                         //[Miscellaneous]->LevelName
constexpr long OFF_LOCAL_PLAYER = 0x21615d8;                  //[Miscellaneous]->LocalPlayer
constexpr long OFF_ENTITY_LIST = 0x1db2ed8;                   //[Miscellaneous]->cl_entitylist
constexpr long OFF_NAME_LIST = 0xc5ea050;                     //[Miscellaneous]->NameList
constexpr long OFF_NAME_INDEX = 0x38;                           //nameIndex (same)

// HUD
constexpr long OFF_VIEWRENDER = 0x73cc460;                    //[Miscellaneous]->ViewRenderer
constexpr long OFF_VIEWMATRIX = 0x11a350;                     //[Miscellaneous]->ViewMatrix

// Buttons
constexpr long OFF_INATTACK = 0x073cd740;                     //[Buttons]->in_attack
constexpr long OFF_IN_JUMP = 0x073cd828;                       //[Buttons]->in_jump
constexpr long OFF_IN_DUCK = 0x073cd920;                       //[Buttons]->in_duck
constexpr long OFFSET_IN_FORWARD = 0x073cd670;                       //[Buttons]->in_forward
constexpr long OFFSET_TRAVERSAL_START_TIME = 0x2ac0;             //[RecvTable.DT_LocalPlayerExclusive]->m_traversalStartTime
constexpr long OFFSET_TRAVERSAL_PROGRESS = 0x2abc;             //[RecvTable.DT_LocalPlayerExclusive]->m_traversalProgress
constexpr long OFFSET_WALL_RUN_START_TIME = 0x3524;           //[RecvTable.DT_LocalPlayerExclusive]->m_wallRunStartTime
constexpr long OFFSET_WALL_RUN_CLEAR_TIME = 0x3528;             //[RecvTable.DT_LocalPlayerExclusive]->m_wallRunClearTime

// Player
constexpr long OFF_HEALTH = 0x02fc;                           //[RecvTable.DT_Player]->m_iHealth
constexpr long OFF_MAXHEALTH = 0x0438;                        //[RecvTable.DT_Player]->m_iMaxHealth
constexpr long OFF_SHIELD = 0x01a0;                           //[RecvTable.DT_TitanSoul]->m_shieldHealth
constexpr long OFF_MAXSHIELD = 0x01a4;                        //[RecvTable.DT_TitanSoul]->m_shieldHealthMax
constexpr long OFF_CAMERAORIGIN = 0x1e90;                     //[Miscellaneous]->CPlayer!camera_origin
constexpr long OFF_STUDIOHDR = 0xfb0;                        //[Miscellaneous]->CBaseAnimating!m_pStudioHdr
constexpr long OFF_BONES = 0x0d60 + 0x48;                     //m_nForceBone
constexpr long OFF_LOCAL_ORIGIN = 0x017c;                     //[DataMap.C_BaseEntity]->m_vecAbsOrigin
constexpr long OFF_ABSVELOCITY = 0x0170;                      //[DataMap.C_BaseEntity]->m_vecAbsVelocity
constexpr long OFF_ZOOMING = 0x1b91;                          //[RecvTable.DT_Player]->m_bZooming
constexpr long OFF_TEAM_NUMBER = 0x030c;                      //[RecvTable.DT_BaseEntity]->m_iTeamNum
constexpr long OFF_NAME = 0x0449;                             //[RecvTable.DT_BaseEntity]->m_iName
constexpr long OFF_LIFE_STATE = 0x0658;                       //[RecvTable.DT_Player]->m_lifeState
constexpr long OFF_BLEEDOUT_STATE = 0x26a0;                   //[RecvTable.DT_Player]->m_bleedoutState  
constexpr long OFF_LAST_VISIBLE_TIME = 0x194d + 0x3;          //[RecvTable.DT_BaseCombatCharacter]->m_hudInfo_visibilityTestAlwaysPasses + 0x3
constexpr long OFF_LAST_AIMEDAT_TIME = 0x194d + 0x3 + 0x8;    //[RecvTable.DT_BaseCombatCharacter]->m_hudInfo_visibilityTestAlwaysPasses + 0x3 + 0x8
constexpr long OFF_VIEW_ANGLES = 0x24f4 - 0x14;               //[DataMap.C_Player]-> m_ammoPoolCapacity - 0x14
constexpr long OFF_PUNCH_ANGLES = 0x23f8;                     //[DataMap.C_Player]->m_currentFrameLocalPlayer.m_vecPunchWeapon_Angle
constexpr long OFF_YAW = 0x21fc - 0x8;                        //m_currentFramePlayer.m_ammoPoolCount - 0x8
constexpr long LOCAL_ORIGIN = 0x0188;                         // [DataMap.CBaseViewModel] -> m_localOrigin

// Weapon 
constexpr long OFF_WEAPON_HANDLE = 0x18f4;                    //[RecvTable.DT_Player]->m_latestPrimaryWeapons
constexpr long OFF_WEAPON_INDEX = 0x1738;                     //[RecvTable.DT_WeaponX]->m_weaponNameIndex
constexpr long OFF_PROJECTILESCALE = 0x04ec + 0x1978;         //projectile_gravity_scale + [WeaponSettingsMeta]base
constexpr long OFF_PROJECTILESPEED = 0x04e4 + 0x1978;         //projectile_launch_speed + [WeaponSettingsMeta]base
constexpr long OFF_OFFHAND_WEAPON = 0x1904;                   //m_latestNonOffhandWeapons
constexpr long OFF_CURRENTZOOMFOV = 0x1590 + 0x00b8;          //m_playerData + m_curZoomFOV
constexpr long OFF_TARGETZOOMFOV = 0x1590 + 0x00bc;           //m_playerData + m_targetZoomFOV
constexpr long OFF_SKIN = 0x0d18;                             //m_nSkin
constexpr long OFF_TIME_BASE = 0x2048;                     //m_currentFramePlayer.timeBase
constexpr long OFF_WEAPON_DISCARDED = 0x1559;                 //[RecvTable.DT_WeaponX]->m_discarded

//glow
constexpr long OFF_HIGHLIGHT_TYPE_SIZE = 0x34;
constexpr long OFF_GLOW_ENABLE = 0x26c;                       //[DT_HighlightSettings].?
constexpr long OFF_GLOW_THROUGH_WALL = 0x28c;                 //[DT_HighlightSettings].?
constexpr long OFF_GLOW_FIX = 0x268;
constexpr long OFF_GLOW_HIGHLIGHT_ID = 0x28C;                 //[DT_HighlightSettings].m_highlightServerActiveStates
constexpr long OFF_GLOW_HIGHLIGHTS = 0xB93E050;
