@echo off

@REM Сменяме директорията на тази в която се намира този скрипт.
cd %~dp0

@REM Компилираме изискваните файлове за библиотеката
g++ -c ../Task1/point.cpp ../Task1/triangle.cpp ../Task1/quadrilateral.cpp
@REM Създаваме динамично свързана библиотека от обектните файлове
g++ -shared -o geometry.dll *.o -Wl,--out-implib,ligeometry.a

@REM Компилирам финалният изпълним файл като добавя и библиотеката в него
g++ main.cpp -o main.exe -L. -lgeometry
@REM Изпълняваме програмата
main.exe

@REM Изтривам ненужните файлове
del *.o
del main.exe