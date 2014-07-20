set location=%cd%
cd C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\bin\x86_amd64
call "vcvarsx86_amd64"
cd %location%
qmake "CONFIG+=debug" myOpenGL.pro
jom