@echo off
setlocal

REM �������� ��� �������� ���� � �����������
set REPO_DIR=

REM ������� � ���������� �����������
cd /d "%REPO_DIR%"
if errorlevel 1 (
    echo Failed to navigate to repository directory.
    exit /b 1
)

REM ���������� �����������
git checkout main
git pull origin main

REM ����� ���� ������������ ��� ������ ������ �������
for /r %%D in (.) do (
    if exist "%%Dtests.c" (
        echo Found solution file: %%D*.sln
        echo Building solution: %%D*.sln...
        msbuild "%%Dtests.c" /p:Configuration=Release
        if errorlevel 1 (
            echo Failed to build project in %%D
            exit /b 1
        )
    ) else (
        echo No solution files found in %%D
    )
)

echo Build completed successfully.
endlocal
exit /b 0