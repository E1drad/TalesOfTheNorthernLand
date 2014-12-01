CC=g++
CFLAGS=-c -Wall -Wextra -std=c++11
LDFLAGS=
SOURCES=Item.cpp Armes.cpp Main.cpp Race.cpp Technique.cpp Classe.cpp Personnage.cpp Branche.cpp Posture.cpp Afficheur.cpp Marchand.cpp Instancieur.cpp CreateurPersonnage.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=TalesOfTheNorthernLand
all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm *.o	
