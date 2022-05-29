@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

REM testing program to tell about invalid usage
%PROGRAM% > %OUT% && goto error
fc %OUT% %~dp0InvalidArguments.txt > nil || goto error

%PROGRAM% arg1 arg2 arg3 > %OUT% && goto error
fc %OUT% %~dp0InvalidArguments.txt > nil || goto error




echo All tests passed
exit /B 0

:error
echo Testing failed
exit /B 1