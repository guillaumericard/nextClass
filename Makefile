CC = g++
CFLAGS = -g -Wall --std=c++11

main: main.o Cours.o lectureFichier.o
	$(CC) $(CFLAGS) -o main main.o Cours.o lectureFichier.o

main.o: main.cpp Cours.h lectureFichier.h
	$(CC) $(FLAGS) -c main.cpp

Cours.o: Cours.h

lectureFichier.o: lectureFichier.h
