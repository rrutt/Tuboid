/*
	Copyright � 2019 Rick Rutt
	Tuboid Algorithm Copyright � 2008 Tom Rutt

	This file is part of Tuboid.

	Tuboid is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Tuboid is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Tuboid.  If not, see <https://www.gnu.org/licenses/>.
*/

#define PLUG_MFR "Rick Rutt"
#define PLUG_NAME "Tuboid"

#define PLUG_CLASS_NAME Tuboid

#define BUNDLE_MFR "Rick Rutt"
#define BUNDLE_NAME "Tuboid"

#define PLUG_ENTRY Tuboid_Entry
#define PLUG_FACTORY Tuboid_Factory
#define PLUG_VIEW_ENTRY Tuboid_ViewEntry

#define PLUG_ENTRY_STR "Tuboid_Entry"
#define PLUG_VIEW_ENTRY_STR "Tuboid_ViewEntry"

#define VIEW_CLASS Tuboid_View
#define VIEW_CLASS_STR "Tuboid_View"

// Format        0xMAJR.MN.BG - in HEX! so version 10.1.5 would be 0x000A0105
#define PLUG_VER 0x00010000
#define VST3_VER_STR "1.0.0"

#define PLUG_COPYRIGHT  "Copyright � 2019 Rick Rutt"

// http://service.steinberg.de/databases/plugin.nsf/plugIn?openForm
// 4 chars, single quotes. At least one capital letter
#define PLUG_UNIQUE_ID 'Tubd'
// make sure this is not the same as BUNDLE_MFR
#define PLUG_MFR_ID 'RER'

// ProTools stuff

#if (defined(AAX_API) || defined(RTAS_API)) && !defined(_PIDS_)
  #define _PIDS_
  const int PLUG_TYPE_IDS[2] = {'EFN1', 'EFN2'};
  const int PLUG_TYPE_IDS_AS[2] = {'EFA1', 'EFA2'}; // AudioSuite
#endif

#define PLUG_MFR_PT "Rick Rutt\nRick Rutt\nRER"
#define PLUG_NAME_PT "Tuboid\nTubd"
#define PLUG_TYPE_PT "Effect"
#define PLUG_DOES_AUDIOSUITE 1

/* PLUG_TYPE_PT can be "None", "EQ", "Dynamics", "PitchShift", "Reverb", "Delay", "Modulation", 
"Harmonic" "NoiseReduction" "Dither" "SoundField" "Effect" 
instrument determined by PLUG _IS _INST
*/

#define PLUG_CHANNEL_IO "1-1 2-2"

#define PLUG_LATENCY 0
#define PLUG_IS_INST 0

// if this is 0 RTAS can't get tempo info
#define PLUG_DOES_MIDI 0

#define PLUG_DOES_STATE_CHUNKS 0

// Unique IDs for each image resource.
#define IFADERCONTROL_HORIZ_ID 101
#define PANEL_BACKGROUND_ID 102

// Image resource locations for this plug.
#define IFADERCONTROL_HORIZ_FN "resources/img/IFaderControl_Horiz.png"
#define PANEL_BACKGROUND_FN "resources/img/TuboidPanel.png"

// GUI default dimensions
#define GUI_WIDTH 800
#define GUI_HEIGHT 600

// on MSVC, you must define SA_API in the resource editor preprocessor macros as well as the c++ ones
#if defined(SA_API)
#include "app_wrapper/app_resource.h"
#endif

// vst3 stuff
#define MFR_URL "www.olilarkin.co.uk"
#define MFR_EMAIL "spam@me.com"
#define EFFECT_TYPE_VST3 "Fx"

/* "Fx|Analyzer"", "Fx|Delay", "Fx|Distortion", "Fx|Dynamics", "Fx|EQ", "Fx|Filter",
"Fx", "Fx|Instrument", "Fx|InstrumentExternal", "Fx|Spatial", "Fx|Generator",
"Fx|Mastering", "Fx|Modulation", "Fx|PitchShift", "Fx|Restoration", "Fx|Reverb",
"Fx|Surround", "Fx|Tools", "Instrument", "Instrument|Drum", "Instrument|Sampler",
"Instrument|Synth", "Instrument|Synth|Sampler", "Instrument|External", "Spatial",
"Spatial|Fx", "OnlyRT", "OnlyOfflineProcess", "Mono", "Stereo",
"Surround"
*/
