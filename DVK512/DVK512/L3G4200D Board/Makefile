main:main.o L3G4200D.o
	gcc -o main main.o L3G4200D.o -lbcm2835
mian.o:main.c L3G4200D.h
	gcc -c main.c -lbcm2835
L3G4200D.o:L3G4200D.c L3G4200D.h
	gcc -c L3G4200D.c -lbcm2835
