@echo off
chcp 65001 >nul

echo Dang bien dich chuong trinh...
gcc main.c hospital.c dynamic_array.c max_heap.c -o HospitalManager.exe

if errorlevel 1 (
    echo Bien dich that bai.
    pause
    exit /b 1
)

echo Bien dich thanh cong. Chay file HospitalManager.exe
pause
