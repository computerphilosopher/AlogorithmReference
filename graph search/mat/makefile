main: fs_mat.o Queue.o
	gcc -o main fs_mat.o Queue.o
fs_mat.o: fs_mat.c fs_mat.h
	gcc -c fs_mat.c
Queue.o: Queue.c fs_mat.h
	gcc -c Queue.c
