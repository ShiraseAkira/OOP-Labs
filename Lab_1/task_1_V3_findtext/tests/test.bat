@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

%PROGRAM% > %OUT% || goto error

echo All tests passed
exit /B 0

:error
echo Testing failed
exit /B 1