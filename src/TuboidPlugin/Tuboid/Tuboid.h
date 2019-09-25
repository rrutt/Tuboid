/*
	Copyright © 2019 Rick Rutt
	Tuboid Algorithm Copyright © 2008 Tom Rutt

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

#ifndef __TUBOID__
#define __TUBOID__

#include "IPlug_include_in_plug_hdr.h"
#include <string>

// The following three defines are from Wavecomp vintage.
#define MAPOFFSET 32768
#define MAPSIZE 65536 
#define SUBMAPSIZE 257 

// These constants are used to convert an input signal sample from [-1.0, +1.0] double interval to [-32768, +32767] integer interval.
#define INTEGER_SIGNAL_MIN (-32768)
#define INTEGER_SIGNAL_MAX 32767

class Tuboid : public IPlug
{
public:
  Tuboid(IPlugInstanceInfo instanceInfo);
  ~Tuboid();

  void Reset();
  void OnParamChange(int paramIdx);
  void ProcessDoubleReplacing(double** inputs, double** outputs, int nFrames);

private:
  double mGain;
  double mSquashPositive;
  double mSquashNegative;
  double mThresholdPositive;
  double mThresholdNegative;

  ITextControl* mTextGain;
  ITextControl* mTextSquashPositive;
  ITextControl* mTextSquashNegative;
  ITextControl* mTextThresholdPositive;
  ITextControl* mTextThresholdNegative;

  short imap[SUBMAPSIZE];

  IGraphics* mpGraphics;

  void CreatePresets();

  void MakeMapUsingTuboidAlgorithm();

  std::string FormatDouble(const double value, char* fmt);

  double MapAudioSample(double input);
};

#endif
