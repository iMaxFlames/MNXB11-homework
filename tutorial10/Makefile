CXX:=g++
CXXWARNINGS:=-Wall -Wextra -Werror -Wno-stringop-truncation
CXXSTD:=-std=c++17
INCLUDES:=-I include/ -I external/include/ -I /opt/apps/root/include
CXXOPT:=-O3
CXXFLAGS:=$(CXXWARNINGS) $(CXXSTD) $(CXXOPT) $(INCLUDES)
LDFLAGS:=-lpthread -L/opt/apps/root/lib -lCore -lImt -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lROOTVecOps -lTree -lTreePlayer -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lMultiProc -lROOTDataFrame -Wl,-rpath,/opt/apps/root/lib -pthread -lm -ldl -rdynamic

all: main

src/%.o: src/%.cxx 
	$(CXX) $(CXXFLAGS) $^ -c -o $@

main: main.cxx src/Circle.o src/Rectangle.o src/GeometryIO.o src/parse_csv.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

clean:
	rm -r src/*.o
	rm main

.PHONY: all clean