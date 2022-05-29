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

REM testing file that contain string we are looking for
%PROGRAM% %~dp0fileWithString.txt "And the mome raths outgrabe." > %OUT% || goto error
fc %OUT% %~dp0fileWithString-output.txt > NUL || goto error

REM testing file that contain MULTIPLE strings we are looking for
%PROGRAM% %~dp0fileWithMultipleStrings.txt "And the mome raths outgrabe." > %OUT% || goto error
fc %OUT% %~dp0fileWithMultipleStrings-output.txt > NUL || goto error

REM testing file that DOES NOT containt string we are looking for
%PROGRAM% %~dp0fileWithMultipleStrings.txt "Some string that does not exist" > %OUT% && goto error
fc %OUT% %~dp0stringNotFound.txt > NUL || goto error

REM testing file that contain string in with characters in different case
%PROGRAM% %~dp0fileWithMultipleStrings.txt "AND THE mome raths outgrabe." > %OUT% && goto error
fc %OUT% %~dp0stringNotFound.txt > NUL || goto error


echo All tests passed
exit /B 0

:error
echo Testing failed
exit /B 1