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

#include "Tuboid.h"
#include "IPlug_include_in_plug_src.h"
#include "IControl.h"
#include "resource.h"
#include <string>

const std::string kVersionText = "Version 1.0.1";

const double kLogarithmConstant = 588.0;

const int kNumPrograms = 7;  // Number of MakePreset calls.

const double kDefaultGain = 411.0;
const double kDefaultSquashPositive = 0.0;
const double kDefaultSquashNegative = 0.0;
const double kDefaultThresholdPositive = 0.496;
const double kDefaultThresholdNegative = 0.696;

enum EParams
{
  kGain = 0,
  kSquashPositive,
  kSquashNegative,
  kThresholdPositive,
  kThresholdNegative,
  kNumParams
};

enum ELayout
{
  kWidth = GUI_WIDTH,
  kHeight = GUI_HEIGHT,

  kGraphX = 380,
  kGraphY = 350,
  kGraphWidth = 200,
  kGraphHeight = 200,

  kVersionX = 300,
  kVersionY = 330,
  kVersionWidth = 200,
  kVersionHeight = 30,
  kVersionFontSize = 20,

  kFaderX = 73,
  kFaderYBase = 78,
  kFaderOffsetY = 110,
  kFaderLength = 275,

  kTextOffsetX = 150,
  kTextOffsetY = -40,
  KTextWidth = 100,
  kTextHeight = 25,
  kTextFontSize = 18,

  kSquashPositiveX = kFaderX,
  kSquashPositiveY = kFaderYBase,

  kThresholdPositiveX = kFaderX,
  kThresholdPositiveY = kSquashPositiveY + kFaderOffsetY,

  kGainX = kFaderX,
  kGainY = kThresholdPositiveY + kFaderOffsetY,

  kThresholdNegativeX = kFaderX,
  kThresholdNegativeY = kGainY + kFaderOffsetY,

  kSquashNegativeX = kFaderX,
  kSquashNegativeY = kThresholdNegativeY + kFaderOffsetY
};

Tuboid::Tuboid(IPlugInstanceInfo instanceInfo)
  :	IPLUG_CTOR(kNumParams, kNumPrograms, instanceInfo), mGain(1.0), mThresholdPositive(1.0)
{
  TRACE;

  //arguments are: name, defaultVal, minVal, maxVal, step, label
  //GetParam(kGain)->InitDouble("Gain", 0.0, 0.0, 1000.0, 1.0, "1 to 50");
  GetParam(kGain)->InitDouble("Gain", kDefaultGain, 0.0, 1000.0, 1.0, "1 to 50");
  GetParam(kGain)->SetShape(1.0);

  //GetParam(kSquashPositive)->InitDouble("Squash Positive", 0.0, 0.0, 1000.0, 1.0, "1 to 50");
  GetParam(kSquashPositive)->InitDouble("Squash Positive", kDefaultSquashPositive, 0.0, 1000.0, 1.0, "1 to 50");
  GetParam(kSquashPositive)->SetShape(1.0);

  //GetParam(kSquashNegative)->InitDouble("Squash Negative", 0.0, 0.0, 1000.0, 1.0, "1 to 50");
  GetParam(kSquashNegative)->InitDouble("Squash Negative", kDefaultSquashNegative, 0.0, 1000.0, 1.0, "1 to 50");
  GetParam(kSquashNegative)->SetShape(1.0);

  //GetParam(kThresholdPositive)->InitDouble("Threshold Positive", 1.0, 0.0, 1.0, 0.001, "0 to 1");
  GetParam(kThresholdPositive)->InitDouble("Threshold Positive", kDefaultThresholdPositive, 0.0, 1.0, 0.001, "0 to 1");
  GetParam(kThresholdPositive)->SetShape(1.0);

  //GetParam(kThresholdNegative)->InitDouble("Threshold Negative", 1.0, 0.0, 1.0, 0.001, "0 to 1");
  GetParam(kThresholdNegative)->InitDouble("Threshold Negative", kDefaultThresholdNegative, 0.0, 1.0, 0.001, "0 to 1");
  GetParam(kThresholdNegative)->SetShape(1.0);

  mpGraphics = MakeGraphics(this, kWidth, kHeight);
  //pGraphics->AttachPanelBackground(&COLOR_RED);
  mpGraphics->AttachBackground(PANEL_BACKGROUND_ID, PANEL_BACKGROUND_FN);

  mTextVersion =
	  new ITextControl(
		  this,
		  IRECT(
			  kVersionX, kVersionY,
			  kVersionX + kVersionWidth, kVersionY + kVersionHeight),
		  new IText(kVersionFontSize, 0, 0, IText::kStyleNormal, IText::kAlignFar),
		  kVersionText.c_str());
  mpGraphics->AttachControl(mTextVersion);

  IBitmap fader = mpGraphics->LoadIBitmap(IFADERCONTROL_HORIZ_ID, IFADERCONTROL_HORIZ_FN);

  mpGraphics->AttachControl(
	  new IFaderControl(
		  this, 
		  kGainX, kGainY, kFaderLength,
		  kGain, &fader, kHorizontal));
  mTextGain =
	  new ITextControl(
		  this,
		  IRECT(
			  kGainX + kTextOffsetX, kGainY + kTextOffsetY, 
			  kGainX + kTextOffsetX + KTextWidth, kGainY + kTextOffsetY + kTextHeight),
		  new IText(kTextFontSize, 0, 0, IText::kStyleNormal, IText::kAlignFar),
		  FormatDouble(mGain, "%4.2f").c_str());
  mpGraphics->AttachControl(mTextGain);

  mpGraphics->AttachControl(
	  new IFaderControl(
		  this,
		  kSquashPositiveX, kSquashPositiveY, kFaderLength,
		  kSquashPositive, &fader, kHorizontal));
  mTextSquashPositive =
	  new ITextControl(
		  this,
		  IRECT(
			  kSquashPositiveX + kTextOffsetX, kSquashPositiveY + kTextOffsetY,
			  kSquashPositiveX + kTextOffsetX + KTextWidth, kSquashPositiveY + kTextOffsetY + kTextHeight),
		  new IText(kTextFontSize, 0, 0, IText::kStyleNormal, IText::kAlignFar),
		  FormatDouble(mSquashPositive, "%4.2f").c_str());
  mpGraphics->AttachControl(mTextSquashPositive);

  mpGraphics->AttachControl(
	  new IFaderControl(
		  this,
		  kSquashNegativeX, kSquashNegativeY, kFaderLength,
		  kSquashNegative, &fader, kHorizontal));
  mTextSquashNegative =
	  new ITextControl(
		  this,
		  IRECT(
			  kSquashNegativeX + kTextOffsetX, kSquashNegativeY + kTextOffsetY,
			  kSquashNegativeX + kTextOffsetX + KTextWidth, kSquashNegativeY + kTextOffsetY + kTextHeight),
		  new IText(kTextFontSize, 0, 0, IText::kStyleNormal, IText::kAlignFar),
		  FormatDouble(mSquashNegative, "%4.2f").c_str());
  mpGraphics->AttachControl(mTextSquashNegative);

  mpGraphics->AttachControl(
	  new IFaderControl(
		  this, 
		  kThresholdPositiveX, kThresholdPositiveY, kFaderLength,
		  kThresholdPositive, &fader, kHorizontal));
  mTextThresholdPositive =
	  new ITextControl(
		  this,
		  IRECT(
			  kThresholdPositiveX + kTextOffsetX, kThresholdPositiveY + kTextOffsetY, 
			  kThresholdPositiveX + kTextOffsetX + KTextWidth, kThresholdPositiveY + kTextOffsetY + kTextHeight),
		  new IText(kTextFontSize, 0, 0, IText::kStyleNormal, IText::kAlignFar),
		  FormatDouble(mThresholdPositive, "%4.2f").c_str());
  mpGraphics->AttachControl(mTextThresholdPositive);

  mpGraphics->AttachControl(
	  new IFaderControl(
		  this,
		  kThresholdNegativeX, kThresholdNegativeY, kFaderLength,
		  kThresholdNegative, &fader, kHorizontal));
  mTextThresholdNegative =
	  new ITextControl(
		  this,
		  IRECT(
			  kThresholdNegativeX + kTextOffsetX, kThresholdNegativeY + kTextOffsetY,
			  kThresholdNegativeX + kTextOffsetX + KTextWidth, kThresholdNegativeY + kTextOffsetY + kTextHeight),
		  new IText(kTextFontSize, 0, 0, IText::kStyleNormal, IText::kAlignFar),
		  FormatDouble(mThresholdNegative, "%4.2f").c_str());
  mpGraphics->AttachControl(mTextThresholdNegative);

  AttachGraphics(mpGraphics);

  //MakeDefaultPreset((char *) "-", kNumPrograms);
  CreatePresets();
}

Tuboid::~Tuboid() {}

void Tuboid::CreatePresets() {
	MakePreset("warm", kDefaultGain, kDefaultSquashPositive, kDefaultSquashNegative, kDefaultThresholdPositive, kDefaultThresholdNegative);
	MakePreset("cool", 177.0, 280.5, 0.0, 0.301, 0.696);
	MakePreset("clean", 0.0, 0.0, 0.0, 1.0, 1.0);
	MakePreset("mild", 250.0, 500.0, 500.0, 0.5, 0.5);
	MakePreset("moderate", 500.0, 500.0, 500.0, 0.5, 0.5);
	MakePreset("heavy", 750.0, 500.0, 500.0, 0.5, 0.5);
	MakePreset("extreme", 1000.0, 500.0, 500.0, 0.5, 0.5);
}

void Tuboid::ProcessDoubleReplacing(
	double** inputs,
	double** outputs,
	int nFrames)
{
	// Mutex is already locked for us.

	int const channelCount = 2;

	for (int i = 0; i < channelCount; i++) {
		double* input = inputs[i];
		double* output = outputs[i];

		for (int s = 0; s < nFrames; ++s, ++input, ++output) {
			*output = MapAudioSample(*input);
		}
	}
}

double Tuboid::MapAudioSample(double input)
{
	double output;

	// Convert input signal sample from [-1.0, +1.0] double interval to expanded integer interval.
	long integerInput = (long)(input * INTEGER_SIGNAL_MAX);

	// Offset the integer value to an unsigned integer value;
	long offsetInput = integerInput + MAPOFFSET;

	// Separate the offset value into high bit and low bit portions;
	short highInput = offsetInput / (SUBMAPSIZE - 1);
	short lowInput = offsetInput - (highInput * (SUBMAPSIZE - 1));

	// Use the high bits as an index into the Tuboid map to retrieve the integer mapped output value.
	short mappedOutput = imap[highInput];

	// Use linear interpolation to correct the mapped output for the low bits of the input value.
	if (highInput < (SUBMAPSIZE - 1))
	{
		short nextMappedOutput = imap[highInput + 1];
		short interpolation = (short)(((nextMappedOutput - mappedOutput) * lowInput) / (SUBMAPSIZE - 1));
		mappedOutput += interpolation;
	}

	// Convert resulting output signal sample from expanded integer interval back to [-1.0, +1.0] double interval.
	output = ((double)mappedOutput) / INTEGER_SIGNAL_MAX;

	return output;
}

void Tuboid::Reset()
{
  TRACE;
  IMutexLock lock(this);
}

void Tuboid::OnParamChange(int paramIdx)
{
	IMutexLock lock(this);

	switch (paramIdx)
	{
	case kGain:
		// Get current value of Gain slider (0 to 1000) and unlog to Gain (1.0 to 50.0)
		mGain = pow(10.0, GetParam(kGain)->Value() / kLogarithmConstant);
		mTextGain->SetTextFromPlug((char*)FormatDouble(mGain, "%4.2f").c_str());
		break;

	case kSquashPositive:
		// Get current value of SquashPositive slider (0 to 1000) and update SquashPositive (1.0 to 50.0)
		mSquashPositive = pow(10.0, GetParam(kSquashPositive)->Value() / kLogarithmConstant);
		mTextSquashPositive->SetTextFromPlug((char*)FormatDouble(mSquashPositive, "%4.2f").c_str());
		break;

	case kSquashNegative:
		mSquashNegative = GetParam(kSquashNegative)->Value() / 100.;
		// Get current value of SquashNegative slider (0 to 1000) and update SquashPositive (1.0 to 50.0)
		mSquashNegative = pow(10.0, GetParam(kSquashNegative)->Value() / kLogarithmConstant);
		mTextSquashNegative->SetTextFromPlug((char*)FormatDouble(mSquashNegative, "%4.2f").c_str());
		break;

	case kThresholdPositive:
		mThresholdPositive = GetParam(kThresholdPositive)->Value();
		mTextThresholdPositive->SetTextFromPlug((char*)FormatDouble(mThresholdPositive, "%4.2f").c_str());
		break;

	case kThresholdNegative:
		mThresholdNegative = GetParam(kThresholdNegative)->Value();
		mTextThresholdNegative->SetTextFromPlug((char*)FormatDouble(mThresholdNegative, "%4.2f").c_str());
		break;

	default:
		break;
	}

	MakeMapUsingTuboidAlgorithm();
}

std::string Tuboid::FormatDouble(const double value, char* fmt)
{
	char buff[100];
	snprintf(buff, sizeof(buff), fmt, value);
	std::string buffAsStdStr = buff;
	return buffAsStdStr;
}

void Tuboid::MakeMapUsingTuboidAlgorithm()
{
	double gain, ftp, ftn, btp, btn;
	gain = mGain;
	ftp = mThresholdPositive;
	ftn = mThresholdNegative;
	btp = mSquashPositive;
	btn = mSquashNegative;
	long usi, usj, usk, usl, usm, lastinp;
	//long usn;
	double ktp, ktn, doubleTmp, sOutSig;
	short isigMax = 32767;
	short isigMin = -32768;
	short istp, istn;
	double stp, stn, sigMax, sigMin;
	double sInSig, sCap;
	short iInSig;
	long hsk, lasth;
	short topflag;

	topflag = 0;

	sigMax = (double)isigMax;
	sigMin = (double)isigMin;
	stp = sigMax * ftp;
	stn = sigMin * ftn;
	istp = (short)stp;
	istn = (short)stn;

	doubleTmp = 1. / (sigMax - stp);
	ktp = doubleTmp * sigMax * (gain - 1.) / gain;
	ktp *= doubleTmp;
	ktp *= doubleTmp;
	ktp *= btp;

	doubleTmp = 1. / (sigMin - stn);
	ktn = doubleTmp * sigMin * (gain - 1.) / gain;
	ktn *= doubleTmp;
	ktn *= doubleTmp;
	ktn *= btn;

	imap[256] = 0;
	sOutSig = 0.;
	usl = MAPOFFSET;
	lastinp = usl;
	lasth = 128;
	imap[lasth] = 0;

	/* compute the mapping array using the tuboid algorithm */
	// negative portion of map
	for (usi = usl - 1; lastinp > 0 && usi >= 0; usi--) { /* usi represents the output value */
		#pragma warning(disable:26451) // Arithmetic overflow
		sCap = (double)(usi - MAPOFFSET);
		sOutSig = 0.; /* feedback 0 if not overthreshold */
		if (sCap < stn)
		{
			doubleTmp = sCap - stn;
			sOutSig = doubleTmp * doubleTmp;
			sOutSig *= doubleTmp;
			sOutSig *= ktn;
		}
		// apply feedback 

		sInSig = sCap / gain + sOutSig;
		if (sInSig >= sigMax) iInSig = isigMax;
		else if (sInSig <= sigMin) {
			//printf("bot usi %ld, iInsig %ld, hsk %ld \n lastinp %ld, lasth %ld\n",
			//	usi, (long)sInSig, hsk, lastinp, lasth);
			iInSig = isigMin;
		}
		else iInSig = (short)sInSig;

		usk = iInSig + MAPOFFSET;
		//if (usi == 0) printf("usi %ld usk %ld lastinp %ld\n", usi, usk, lastinp);
		if (usk < 0) usk = 0;
		hsk = 128 + iInSig / 256;
		//hsk = usk/256;
		if (hsk < lasth) {
			for (usj = hsk; usj < lasth; usj++)
				imap[usj] = (short)(usi - MAPOFFSET);
			lastinp = usk; lasth = hsk;
		}

		//printf("usi %ld usj %ld usk %ld \n",usi, usj, usk);
		//for (usn = usj; usn<=usk; usn++) imap[usn] = (short) (usi-MAPOFFSET); 
		// usj = usn; 
		//if (usn >= usl) printf("negmidover usi %ld usj %ld usl %ld usn %ld usk %ld\n",usi,usj,usl,usn,usk);;
	}

	if (lasth > 0) for (usj = 0; usj < lasth; usj++) imap[usj] = isigMin;

	lasth = 128;
	imap[lasth] = 0;
	//printf("usi %ld usj %ld usl %ld usn %ld usk %ld\n",usi,usj,usl,usn, usk); 
	//positive portion of map 
	usm = MAPSIZE - 1;
	lastinp = usl;
	for (usi = usl + 1; lastinp < usm && usi < MAPSIZE; usi++) { /* usi represents the output value */
		sCap = (double)(usi - MAPOFFSET);
		sOutSig = 0.; /* feedback 0 if not overthreshold */
		if (sCap > stp)
		{
			doubleTmp = sCap - stp;
			sOutSig = doubleTmp * doubleTmp;
			sOutSig *= doubleTmp;
			sOutSig *= ktp;
		}
		// apply feedback 

		sInSig = sCap / gain + sOutSig;
		if (sInSig >= sigMax) {
			if (lasth == 255) {
				/*    	printf("top usi %ld, iInsig %ld, hsk %ld \n lastinp %ld, lasth %ld\n",
								usi,(long)sInSig,hsk,lastinp,lasth); */
				lasth = 256;
				imap[lasth] = (short)(usi - MAPOFFSET);
				break;
			}
			iInSig = isigMax;

		}
		else if (sInSig <= sigMin) iInSig = isigMin;
		else iInSig = (short)sInSig;

		usk = iInSig + MAPOFFSET;

		//if (usi == usm) printf("usm=usi %ld usk %ld lastinp %ld\n", usi, usk, lastinp);
		if (usk > usm) usk = usm;

		hsk = usk / 256;

		/*  if (usi > MAPSIZE-3) printf("usi %ld, usk %ld, hsk %ld,lasth %ld\n",usi,usk, hsk,lasth);
		*/
		if (hsk > lasth) {
			for (usj = hsk; usj > lasth; usj--)
				imap[usj] = (short)(usi - MAPOFFSET);
			lastinp = usk;  lasth = hsk;
		}

		/*  if (usi > MAPSIZE-3) printf("usi %ld, lastinp %ld, lasth %ld\n",usi,lastinp,lasth);
		*/
	}

	if (lasth < 256) for (usj = lasth + 1; usj <= 256; usj++) imap[usj] = isigMax;
}