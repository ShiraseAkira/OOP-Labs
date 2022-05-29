@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

REM testing invalid argument count
%PROGRAM% > %OUT% && goto error
fc %OUT% %~dp0InvalidArguments.txt > NUL || goto error

%PROGRAM% arg1 arg2 > %OUT% && goto error
fc %OUT% %~dp0InvalidArguments.txt > NUL || goto error

echo Test 1 passed

REM testing invalid argument type
%PROGRAM% arg1 > %OUT% && goto error
fc %OUT% %~dp0InvalidArgumentType.txt > NUL || goto error
echo Test 2 passed

REM testing invalid argument value
%PROGRAM% -1 > %OUT% && goto error
fc %OUT% %~dp0InvalidArgumentValue.txt > NUL || goto error
%PROGRAM% 256 > %OUT% && goto error
fc %OUT% %~dp0InvalidArgumentValue.txt > NUL || goto error

echo Test 3 passed

REM testing some values
%PROGRAM% 0 > %OUT% || goto error
fc %OUT% %~dp00.txt > NUL || goto error

%PROGRAM% 255 > %OUT% || goto error
fc %OUT% %~dp0255.txt > NUL || goto error

%PROGRAM% 128 > %OUT% || goto error
fc %OUT% %~dp0128.txt > NUL || goto error

%PROGRAM% 6 > %OUT% || goto error
fc %OUT% %~dp06.txt > NUL || goto error

echo All tests passed
exit /B 0

:error
echo Testing failed
exit /B 1