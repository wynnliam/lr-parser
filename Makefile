CMP=gcc
FLG=-g -Wall
SRC=./src/*.c
OUT=./bin/a.out

.phony: clean

all: $(SRC)
	-mkdir bin
	$(CMP) $(FLG) $(SRC) -o $(OUT)

clean:
	-rm -rf ./bin/
