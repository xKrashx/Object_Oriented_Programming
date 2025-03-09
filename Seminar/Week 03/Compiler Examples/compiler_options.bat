g++ -E main.cpp > main.ii @REM Preprocessing only. This expands all directives like define, include, etc.
g++ -S main.cpp @REM Compile only without assembling and linking. Gives an assembly file main.s
g++ -c main.cpp @REM Compile and assemble without linking. Gives an object file main.o
g++ main.o -o main.exe @REM Link the object files and create an output executable.
g++ main.cpp -o main.exe @REM Preprocess, compile, assemble and link to create main.exe