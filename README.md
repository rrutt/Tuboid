# Tuboid

## Introduction

The **Tuboid** plug-in is a VST 3 audio filter plug-in, which is a software implementation of an _Over-Threshold Power Function_ (OTPF) feedback  distortion synthesizer.
**_Nonlinear distortion synthesizer using over-threshold power-function feedback_** is the title of US Patent 4,710,727 (December 1, 1987, Inventor Thomas E. Rutt, now abandoned), available in the **doc** sub-folder of this repository as **USPatent-4710727 (abandoned).pdf**

OTPF feedback closely emulates the soft limiting input/output response characteristics of vacuum tube triode grid limit distortion, as described in **_Vacuum Tube Triode Nonlinearity as Part of The Electric Guitar Sound_**, T. E. Rutt, Presented at the 76th Convention of Audio Engineering Society  October 8-11, 1984, New York (Preprint 2141 F-5), available in the **doc** sub-folder of this repository as **AESPaper-1.pdf**

A summary of the findings of that paper are included as an appendix to the  user guide for the original DirectX version of the Tuboid plug-in, available in the **doc** sub-folder of this repository as **TuboidPlugin-Beta1-UserGuide.pdf**

The name **_Tuboid_** connotes an intelligent device which emulates the  distortion characteristics of a vacuum tube.

## Copyrights and Licenses

Copyright © 2019 Rick Rutt, licensed under the **[GNU General Public License, Version 3](https://www.gnu.org/licenses/gpl-3.0.html)**
 
Tuboid Algorithm Copyright © 2008 Tom Rutt

**[WDL IPlug](https://github.com/olilarkin/wdl-ol)** Portions Copyright © 2005 and later Cockos Incorporated

**[VST 3 SDK](https://github.com/steinbergmedia/vst3sdk)** Portions Copyright © 2019, Steinberg Media Technologies GmbH, All Rights Reserved

## Using the Plugin

### Deployment

_(To be added: Document deployment of VST 3 plug-in.)

### Compatible audit editing software: Reaper

This product is able to host VST 3 plug-ins, as well as VST 2 plug-ins.

This product can be downloaded for free and allows a 60 day free trial.
A personal-use license can be purchased for $60.
Pending receipt of the license key, the software fully functions, but with a license warning notice.

**<https://www.reaper.fm/>**

### Using the Tuboid plug-in within Reaper

_(to be added)_


### Free harmonica instrument plug-in

<https://www.dskmusic.com/dsk-harmonica/>

<http://freevst.org/instruments/harmonica/>

<http://files.freevst.org/DSK_Harmonica.zip>


### Various free instrument plug-ins

<http://www.vst4free.com/index.php?plug-ins=Guitar/Bass&l=0>


## Free MIDI files

<https://cymatics.fm/blogs/production/midi-files>


## Other guitar amp simulation software

<https://www.musicianonamission.com/guitar-amp-simulators-vs-real/>

<https://theproaudiofiles.com/best-amp-simulator-plugins/>

<https://www.soundshockaudio.com/amp-simulator/>

**<https://www.guitarworld.com/gear/guitar-amp-simulators-better-real-amps>
<https://www.youtube.com/watch?v=GQvfVaHyHeE>**

<https://www.guitarfella.com/free-and-paid-guitar-amp-simulators/>


## Development Enviromment

- Windows 10
- Microsoft Visual Studio 2019 Community Edition
  - Workload: **Desktop development with C++**
  - Include Optional: **C++ MFC for v142 build tools (x86 & x64)**

### IPlug Implementation Notes

<http://www.martin-finke.de/blog/articles/audio-plugins-001-introduction/>

**_Note:_** When following this tutorial for creation of a VST 3 plug-in, a minor change needs to be performed to match the current version of the VST 3 SDK.
Add the following file reference to the **MyFirstPlugin-vst3.vcsproj** project within Visual Studio at the **vst3\VST3_SDK\public.sdk\source\common** folder location in the Solution Explorer:

    ..\wdl-ol\VST3_SDK\public.sdk\source\common\commoniids.cpp

### Installing and Using the VST 3 Test Host

_(to be added)_

## Additional Documentation

### Tuboid references

**<http://www.aes.org/e-lib/browse.cfm?elib=15455&feature>**

**<http://freeverb3vst.osdn.jp/doc/JAES_V58_5_PG420.pdf>**

**<http://thaihdbox.net/audioxpress/2010/02audioXpress_February2010.pdf>**

### Free Online Book on Digital Signal Processing

[The Scientist and Engineer's Guide to Digital Signal Processing](http://www.dspguide.com/pdfbook.htm)
by Steven W. Smith, Ph.D.

## Tom Rutt memorials from Object Management Group colleagues

<https://www.omg.org/tom-rutt.htm>

<https://www.omg.org/tomrutt/>
