CXX = g++
CXXFLAGS = -Werror=vla -std=c++14 -MMD
OBJECTS = main.o basicboard.o blind.o block1.o block2.o board.o cell.o decorator.o dot.o force.o game.o heavy.o i.o interpreter.o j.o l.o Level.o Level1.o Level2.o Level3.o Level4.o NonRandom.o o.o Random.o row.o s.o stringGenerator.o subject.o t.o textDisplay.o z.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = biquadris
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}

.PHONY: clean
clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
