@echo on

set VST3_FOLDER=C:\Program Files\Common Files\VST3

REM Navigate to the folder containing this "bat shell" file.
pushd %~dp0
pause

mkdir "%VST3_FOLDER%"

pause

copy .\Tuboid64.vst3 "%VST3_FOLDER%\Tuboid64.vst3"

popd

echo "Done!"
pause
