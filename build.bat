@echo off

IF "%~1" == "" GOTO PrintHelp
IF "%~1" == "compile" GOTO Compile

vendor\Premake\premake5.exe %1
GOTO Done

:PrintHelp
echo.
echo Enter 'build.bat action' where action is one of the following:
echo.
echo   compile           Will generate make file then compile using the make file.
echo   clean             Remove all binaries and intermediate binaries and project files.
echo   codelite          Generate CodeLite project files
echo   gmake             Generate GNU makefiles for Linux
echo   vs2005            Generate Visual Studio 2005 project files
echo   vs2008            Generate Visual Studio 2008 project files
echo   vs2010            Generate Visual Studio 2010 project files
echo   vs2012            Generate Visual Studio 2012 project files
echo   vs2013            Generate Visual Studio 2013 project files
echo   vs2015            Generate Visual Studio 2015 project files
echo   vs2017            Generate Visual Studio 2017 project files
echo   vs2019            Generate Visual Studio 2019 project files
echo   vs2022            Generate Visual Studio 2022 project files
echo   xcode4            Generate Apple Xcode 4 project files

GOTO Done

:Compile

GOTO Done

vendor\Premake\premake5.exe vs2022

if not defined DevEnvDir
(
	Call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\VsDevCmd.bat"
)

set solutionFile="EasyS.sln"
msbuild /t:Build /p:Configuration=Debug /p:Platform=x64 %solutionFile%

:Done