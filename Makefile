test:  thread.o  exe.o
gcc -o test  exe.o thread.o -L. -lmysqlclient -lpthread

exe : exe.o
gcc -c exe.c 
    
thread : thread.o
gcc -c thread.c 

clean :
rm *.o test