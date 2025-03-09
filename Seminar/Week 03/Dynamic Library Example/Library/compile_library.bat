g++ -c test.cpp -o mylib.o
g++ -shared -o mylib.dll mylib.o -Wl,--out-implib,libmylib.a