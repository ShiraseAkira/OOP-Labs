@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

REM testing invalid argument count
%PROGRAM% > %OUT% && goto error
fc %OUT% %~dp0InvalidArguments.txt > NUL || goto error

%PROGRAM% arg1 arg2 arg3 > %OUT% && goto error
fc %OUT% %~dp0InvalidArguments.txt > NUL || goto error

REM testing file open fail
%PROGRAM% NonExistingFile.txt "some string" > %OUT% && goto error
fc %OUT% %~dp0FileOpenFail.txt > NUL|| goto error


echo All tests passed
exit /B 0

:error
echo Testing failed
exit /B 1