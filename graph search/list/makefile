main: fs_list_dynamic.o Queue.o
	gcc -o main fs_list_dynamic.o Queue.o
fs_list_dynamic.o: fs_list_dynamic.c fs_list.h
	gcc -c fs_list_dynamic.c
Queue.o: Queue.c fs_list.h
	gcc -c Queue.c
