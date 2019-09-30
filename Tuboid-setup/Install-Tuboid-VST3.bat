@echo on

set VST3_FOLDER=C:\Program Files (x86)\Common Files\VST3

REM Navigate to the folder containing this "bat shell" file.
pushd %~dp0
pause

mkdir "%VST3_FOLDER%"

pause

copy .\Tuboid.vst3 "%VST3_FOLDER%\Tuboid.vst3"

popd

echo "Done!"
pause
