@echo off
echo Compiling the program...
g++ Main.cpp Graphic.cpp Menu.cpp Setup.cpp User.cpp Board.cpp Check.cpp Game.cpp -o main.exe -lwinmm
if %errorlevel% neq 0 (
    echo Error occurred while compiling the program. Exiting...
    pause
    exit /b 1
)
echo Compilation successful.
pause
start main.exe