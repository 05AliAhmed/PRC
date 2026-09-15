@echo off
setlocal

echo ============================================
echo  PRC - fresh_start.bat
echo  Cleans stale UE5 intermediate files so
echo  the project rebuilds from a clean state.
echo ============================================
echo.
echo WARNING: Close Unreal Engine BEFORE running this.
echo This will delete: Binaries, Intermediate,
echo DerivedDataCache, Saved\Cooked, Saved\StagedBuilds
echo.
echo Your source files and Content folder are NOT touched.
echo.
pause

echo.
echo Cleaning...

if exist ".vs"                  rmdir /s /q ".vs"                  && echo   Deleted: .vs
if exist "Binaries"             rmdir /s /q "Binaries"             && echo   Deleted: Binaries
if exist "Intermediate"         rmdir /s /q "Intermediate"         && echo   Deleted: Intermediate
if exist "DerivedDataCache"     rmdir /s /q "DerivedDataCache"     && echo   Deleted: DerivedDataCache
if exist "Saved\Cooked"         rmdir /s /q "Saved\Cooked"         && echo   Deleted: Saved\Cooked
if exist "Saved\StagedBuilds"   rmdir /s /q "Saved\StagedBuilds"   && echo   Deleted: Saved\StagedBuilds

echo.
echo Done. Next steps:
echo  1. Right-click your .uproject file
echo  2. Select "Generate Visual Studio project files"
echo  3. Open UE5 - it will rebuild shaders on first launch
echo.
pause
endlocal
