@echo off
setlocal

echo ============================================
echo  PRC - rebuild.bat
echo  Regenerates Visual Studio project files
echo  for the UE5 C++ project.
echo ============================================
echo.

:: Find the .uproject file in the current directory
set UPROJECT=
for %%f in (*.uproject) do set UPROJECT=%%f

if "%UPROJECT%"=="" (
    echo ERROR: No .uproject file found.
    echo Run this script from your UE5 project root folder
    echo (the folder that contains your .uproject file).
    echo.
    pause
    exit /b 1
)

echo Found project: %UPROJECT%
echo.

:: Try UnrealVersionSelector first (handles version detection automatically)
set SELECTOR="C:\Program Files (x86)\Epic Games\Launcher\Engine\Binaries\Win64\UnrealVersionSelector.exe"

if exist %SELECTOR% (
    echo Generating project files via UnrealVersionSelector...
    %SELECTOR% /projectfiles "%CD%\%UPROJECT%"
    if %errorlevel%==0 (
        echo.
        echo Done. Open the .sln file in Visual Studio.
    ) else (
        echo Generation failed. Try right-clicking the .uproject file instead.
    )
    pause
    exit /b 0
)

:: Fallback: try common UE5 install paths
echo UnrealVersionSelector not found at default path.
echo Trying common UE5 install locations...
echo.

set UBT=
for %%v in (5.7 5.6 5.5 5.4 5.3) do (
    if exist "C:\Program Files\Epic Games\UE_%%v\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe" (
        set UBT="C:\Program Files\Epic Games\UE_%%v\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.exe"
        echo Found UE %%v
        goto :found_ubt
    )
)

:not_found
echo Could not find UE5 automatically.
echo.
echo Manual fix:
echo  1. Right-click %UPROJECT%
echo  2. Select "Generate Visual Studio project files"
echo.
pause
exit /b 1

:found_ubt
echo Generating project files...
%UBT% -ProjectFiles -project="%CD%\%UPROJECT%" -game -rocket -progress
if %errorlevel%==0 (
    echo.
    echo Done. Open the .sln file in Visual Studio.
) else (
    echo Generation failed. Try right-clicking the .uproject file instead.
)
echo.
pause
endlocal
