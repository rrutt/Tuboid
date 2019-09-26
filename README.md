# Tuboid - Vacuum Tube Guitar Amp Effect Plug-In for Digital Audio Workstation Software

## Introduction

**Tuboid** emulates the non-linear _soft limiting_ distortion sound of a vacuum tube guitar amplifier.

**Tuboid** is implemented as a VST 3 plug-in for use with various Digital Audio Workstation (DAW) software products running on Microsoft Windows.

## Summary

The **Tuboid** plug-in is a software implementation of an _Over-Threshold Power Function_ (OTPF) feedback  distortion synthesizer.
**_Nonlinear distortion synthesizer using over-threshold power-function feedback_** is the title of US Patent 4,710,727 (December 1, 1987, Inventor Thomas E. Rutt, now abandoned), available in the **doc** sub-folder of this repository as **[USPatent-4710727-abandoned.pdf](./doc/USPatent-4710727-abandoned.pdf)**

OTPF feedback closely emulates the soft limiting input/output response characteristics of vacuum tube triode grid limit distortion, as described in **_Vacuum Tube Triode Nonlinearity as Part of The Electric Guitar Sound_**, T. E. Rutt, Presented at the 76th Convention of Audio Engineering Society  October 8-11, 1984, New York (Preprint 2141 F-5), available in the **doc** sub-folder of this repository as **[AESPaper-1.pdf](./doc/AESPaper-1.pdf)**

A summary of the findings of that paper are included as an appendix to the  user guide for the original DirectX version of the Tuboid plug-in, available in the **doc** sub-folder of this repository as **[TuboidPlugin-Beta1-UserGuide.pdf](./doc/TuboidPlugin-Beta1-UserGuide.pdf)**

The name **_Tuboid_** connotes an intelligent device which emulates the  distortion characteristics of a vacuum tube.

## Copyrights and Licenses

Copyright © 2019 Rick Rutt, licensed under the **[GNU General Public License, Version 3](https://www.gnu.org/licenses/gpl-3.0.html)**
 
Tuboid Algorithm Copyright © 2008 Tom Rutt

**[WDL IPlug](https://github.com/olilarkin/wdl-ol)** Portions Copyright © 2005 and later Cockos Incorporated

**[VST 3 SDK](https://github.com/steinbergmedia/vst3sdk)** Portions Copyright © 2019, Steinberg Media Technologies GmbH, All Rights Reserved

## Using the Tuboid Plugin

### Deployment

- Download the **[Tuboid-setup.zip](./Tuboid-setup.zip)** file from this GitHub project.
- Open the folder where you saved the ZIP in Windows file Explorer.
- Right-click the **Tuboid-setup.zip** file and select **Extract All...** from the pop-up menu.  Be sure to enable **Show extracted files when complete**.
- Open the additional **Tuboid-setup** sub-folder in Windows file Explorer.
- Right-click the **Install-Tuboid-VST3.bat** file and select **Run as administrator** from the pop-up menu.
- When the Windows Command Processor prompts **Do you want to allow this app to make changes to your device?** select **Yes**.
- While the setup script runs, it will periodically prompt **Press any key to continue . . .**  Press the Space bar to proceed to the next step in the script, or else close the Command Prompt window to abort the script.
- The setup script copies the **Tuboid.vst3** plug-in file to the standard system folder for VST 3 plug-ins.

### Compatible audit editing software: REAPER

The REAPER digital audio workstation product is able to host VST 3 plug-ins, as well as VST 2 plug-ins.

This product can be downloaded for free and allows a 60 day free trial.
A personal-use license can be purchased for $60.
Pending receipt of the license key, the software fully functions, but with a license warning notice.

Download the REAPER software from here: **<https://www.reaper.fm/>**

### Using the Tuboid plug-in within REAPER

Upon running the REAPER software you will be presented with an empty project.

![REAPER empty project](img/REAPER-empty-project.png?raw=true "REAPER empty project")

Use the **Options | Preferences** menu item to confirm the configuration of your VST plug-in folder locations:

![REAPER VST preferences](img/REAPER-VST-preferences.png?raw=true "REAPER VST preferences")

Open a Windows file Explorer window to a folder containing WAV audio files and _drag-and-drop_ a WAV file into the light-gray area to the upper right of the REAPER project window.
(Position your mouse pointer at the left edge of the light-gray area before releasing the mouse button to _drop_ the file.)

![REAPER wav file added](img/REAPER-wav-file-added.png?raw=true "REAPER wav file added")

Use the REAPER "play" buttons to listen to the audio track, and to pause, stop, or rewind the track.

![REAPER play buttons](img/REAPER-play-buttons.png?raw=true "REAPER play buttons")

Click the little **FX** button in the audio track control to open the **Add FX** dialog.

![REAPER FX button](img/REAPER-FX-button.png?raw=true "REAPER FX button")

Select **VST3** in the left area of the dialog, then select the **Tuboid** plug-in and click **OK**.

![REAPER Add FX](img/REAPER-Add-FX.png?raw=true "REAPER Add FX")

The Tuboid user-interace appears:

![REAPER Tuboid UI](img/REAPER-Tuboid-UI.png?raw=true "REAPER Tuboid UI")

You can drag the Tuboid user-interface window around to avoid covering the REAPER window controls.

Rewind and play the audio clip to hear the Tuboid effect as applied to the audio clip.

You can _toggle_ the Tuboid effect on and off while the audio clip is playing by using the check-box at the upper-left of the Tuboid user-interface dialog:

![REAPER FX disable](img/REAPER-FX-disable.png?raw=true "REAPER FX disable")

You can also adjust the Tuboid user-interface controls while the audio clip is playing to hear the differences in sound produced using various parameter settings.

The following are the default Tuboid parameter settings that provide a "warm" guitar distortion:

- Squash Positive = 1.00
- Threshold Positive = 0.50
- Gain = 5.00
- Threshold Negative = 0.70
- Squash Negative = 1.00

Here are alternate settings that provide a "cool" guitar distortion:

- Squash Positive = 3.00
- Threshold Positive = 0.30
- Gain = 2.00
- Threshold Negative = 0.70
- Squash Negative = 1.00

![Tuboid settings cool](img/Tuboid-settings-cool.png?raw=true "Tuboid settings cool")

#### Explanation of Tuboid Configuration Parameters

Tuboid emulates the following vacuum tube circuit found in the pre-amplifier stage of many vintage guitar amplifiers:

![Triode cathode follower circuit](img/Triode-cathode-follower-circuit.png?raw=true "Triode cathode follower circuit")

The triode vacuum tube to the lower left of the diagram is the primary amplification element.

The triode vacumm tube to the upper right of the diagram provides _negative feedback_ to the input signal when the primary amplifier tube is reaching its voltage saturation level.

This negative feedback partially reduces the input signal to prevent the output signal from being _hard limited_ (clipped).
This effected is known as _soft limiting_.

The effect of this negative feedback voltage is typically stronger for the positive voltage side of the input audio signal than for the negative voltage side.

Analysis of this positive vs. negative asymmetry reveals a distortion effect that contains more _even harmonics_ (overtones) than _odd harmonics_ which would occur with a symmetric feedback circuit.
Even harmonics provide a more pleasing audio effect than odd harmonics.

The Tuboid configuration parameters relate to the feedback aspects of this circuit as follows:

- **Gain**: This parameter controls how much of the output from the primary amplification triode feeds into the secondary feedback triode (the _cathode follower_).  Set it to 0.0 to suppress all negative feedback effect.
- **Threshold**: These two parameters control what voltage level from the primary amplification triode must be exceeded in order to trigger the secondary feedback triode to provide a reduction in the input voltage.  The values can be set separately for the positive vs. the negative voltage portions of the audio waveform.
- **Squash**: These two parameters allow for control of the degree of negative feedback voltage from the secondary feedback triode used to reduce the input signal voltage into the primary amplifier triode.  The values can be set separately for the positive vs. the negative voltage portions of the audio waveform.


#### Test audio clips

The **clips** sub-folder in this GitHub project contains some WAV file audio files containing some guitar licks played on a Fender Stratocaster.
Load one of these files into REAPER to use as a signal source for experimenting with the Tuboid plug-in:

- **Strat3.wav**
- **Strat4.wav**
- **Strat5.wav**
- **Strat6.wav**

The **clips** folder also contains some triangular waveform audio files that can be used to more abstractly evaluate the Tuboid effect:

- **100tri.wav** contains a simple triangular waveform.
- **tri100-1100.wav** contains a triangular waveform with a high-frequency sine-wave modulation signal.  By using a _soft limiting_ approach, rather than a _hard limiting_ (clipping) approach to high audio input levels, the Tuboid effect is able to preserve the sine-wave modulation present in the input signal and pass it through to the output signal.
- **tru100-1100.wav** contain a low-frequency triangular waveform in the left channel and a high-frequency triangular waveform in the right channel.

![Triangular Waveform Signals](img/Triangular-waveform-signals.png?raw=true "Triangular Waveform Signals")


#### Various free instrument plug-ins

The following web sites provide some VST instrument plug-ins that can be used with REAPER to experiment with Tuboid effects.

This can be used, in conjunction with MIDI input files, as an alternative to WAV audio files as the signal source.

**<http://www.vst4free.com/index.php?plug-ins=Guitar/Bass&l=0>**

**<https://www.dskmusic.com/dsk-harmonica/>**

**<http://freevst.org/instruments/harmonica/>**

**<http://files.freevst.org/DSK_Harmonica.zip>**


#### Free MIDI files

This web site contains some MIDI files that can be used in conjunction with the VST instrument plug-ins to create some audio tracks:

**<https://cymatics.fm/blogs/production/midi-files>**


## Other guitar amp simulation software

Here are some other approaches to emulation or simulation of vacuum tube guitar amplifiers:

**<https://www.youtube.com/watch?v=GQvfVaHyHeE>**

**<https://www.guitarworld.com/gear/guitar-amp-simulators-better-real-amps>**

**<https://www.musicianonamission.com/guitar-amp-simulators-vs-real/>**

**<https://theproaudiofiles.com/best-amp-simulator-plugins/>**

**<https://www.soundshockaudio.com/amp-simulator/>**

**<https://www.guitarfella.com/free-and-paid-guitar-amp-simulators/>**


## Development Enviromment

- Windows 10
- Microsoft Visual Studio 2019 Community Edition
  - Workload: **Desktop development with C++**
  - Include Optional: **C++ MFC for v142 build tools (x86 & x64)**

### IPlug Implementation Notes

Thus tutorial was used to create the Visual Studio solution framework for the **Tuboid** project.

**<http://www.martin-finke.de/blog/articles/audio-plugins-001-introduction/>**

**_Note:_** When following this tutorial for creation of a VST 3 plug-in, a minor change needs to be performed to match the current version of the VST 3 SDK.
Add the following file reference to the **MyFirstPlugin-vst3.vcsproj** project within Visual Studio at the **vst3\VST3_SDK\public.sdk\source\common** folder location in the Solution Explorer:

    ..\wdl-ol\VST3_SDK\public.sdk\source\common\commoniids.cpp

### Building Tuboid from the Source Code

The Visual Studio solution file resides in the **src** sub-folder as **Tuboid.sln**
This solution file contains a **Tuboid-app** sub-project and the **Tuboid-vst3** sub-project.

The **Tuboid-app** sub-project acts as a standalone host for the Tuboid plug-in.
Run this project within Visual Studio to debug the startup logic for the Tuboid plug-in and to test or debug the logic that reacts to changes in the parameter sliders.

The post-build steps for the **Tuboid-vst** sub-project include copying the resulting DLL file (named as **Tuboid.vst3**) to the standard system folder **C:\\Program Files (x86)\\Common Files\\VST3**

Since this is a protected folder tree, this step only succeeds if you start Visual Studio via the **Run as administrator** option by right-clicking on the Visual Studio Start menu item (or desktop icon). 

#### VST 2 support

A separate solution file **Tuboid-with-vst2.sln** also includes a **Tuboid-vst2** sub-project.
This solution allows you to build a VST 2 version of the plug-in, provided you obtained a VST 2 SDK license from Steinberg Media Technologies GmbH prior to October, 2018.
(Steinberg is retiring the VST 2 technology and no longer licenses development and VST 2 plug-in distribution except for developers that obtained licenses as of that date.)

If you have an existing license for the VST 2 SDK you can use this **Tuboid-with-vst2.sln** solution file after copying the following two files from the VST2 SDK to the **src\\VST_SDK** sub-folder:

- **aeffect.h**
- **aeffectx.h**



## Additional Documentation

### Tuboid references

**<http://www.aes.org/e-lib/browse.cfm?elib=15455&feature>**

**<http://freeverb3vst.osdn.jp/doc/JAES_V58_5_PG420.pdf>**

**<http://thaihdbox.net/audioxpress/2010/02audioXpress_February2010.pdf>**

### Free Online Book on Digital Signal Processing

**[The Scientist and Engineer's Guide to Digital Signal Processing](http://www.dspguide.com/pdfbook.htm)**
by Steven W. Smith, Ph.D.

## The Original Creator of Tuboid

My oldest brother, Thomas E. Rutt, passed away in September, 2015.

![Tom Rutt on bass](img/TomOnBass.jpg?raw=true "Tom Rutt on bass")

Tom was an electrical engineer and amateur musician.

He combined those interests to research how to create the sound of vacuum tube guitar amplifiers in the transistor age, and then the digital signal processing era.
The result of that research is this **Tuboid** software.

### Tom Rutt memorials from Object Management Group colleagues

Tom also served on standards committees for the Object Management Group.
Here are some memorials from several of his colleges from OMG:

<https://www.omg.org/tom-rutt.htm>

<https://www.omg.org/tomrutt/>
