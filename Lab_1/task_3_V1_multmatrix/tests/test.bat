@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

REM testing invalid argument count
%PROGRAM% > %OUT% && goto error
fc %OUT% %~dp0InvalidArguments.txt > NUL|| goto error

%PROGRAM% arg1 > %OUT% && goto error
fc %OUT% %~dp0InvalidArguments.txt > NUL || goto error

%PROGRAM% arg1 arg2 arg3 > %OUT% && goto error
fc %OUT% %~dp0InvalidArguments.txt > NUL || goto error

echo test 1 passed

REM testing files can be open
%PROGRAM% NonExistingFile.txt %~dp0matrix_1_1.txt > %OUT% && goto error
fc %OUT% %~dp0FileOpenFail.txt > NUL || goto error

%PROGRAM% %~dp0matrix_1_1.txt NonExistingFile.txt > %OUT% && goto error
fc %OUT% %~dp0FileOpenFail.txt > NUL || goto error

echo test 2 passed

REM testing files being multiplied correctly
%PROGRAM% %~dp0matrix_1_1.txt %~dp0matrix_1_2.txt > %OUT% || goto error
fc %OUT% %~dp0result_1.txt > NUL|| goto error

%PROGRAM% %~dp0matrix_2_1.txt %~dp0matrix_1_2.txt > %OUT% || goto error
fc %OUT% %~dp0result_2.txt > NUL|| goto error

%PROGRAM% %~dp0matrix_3_1.txt %~dp0matrix_1_2.txt > %OUT% || goto error
fc %OUT% %~dp0result_3.txt > NUL || goto error

echo test 3 passed

echo All tests passed
exit /B 0

:error
echo Testing failed
exit /B 1