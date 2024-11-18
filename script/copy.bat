
set dirToCopy=%~1
set targetDir=%~2

echo Copying

echo %dirToCopy%
echo %targetDir%

cd "%targetDir%"
mkdir "res"
xcopy /y /s /e "%dirToCopy%" "%targetDir%\res"

pause
REM cd "$(OutDir)"
REM mkdir "assets"
REM xcopy /s /e /y "$(SolutionDir)assets" "$(OutDir)assets"