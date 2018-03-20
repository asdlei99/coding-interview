CXX = g++
AR  = ar

MAIN =  main.o
OBJ  =  CandidateCountingAlgo3.o


CXXFLAGS = -c -O2 -Wall -std=c++11

###########################
#     Make target         #
#     TODO unit test      #
###########################
.PHONY: all clean CandidateCountingAlgo3

all: build_start CandidateCountingAlgo3

%.o : %.cpp
	@echo "   CXX   $@"
	@$(CXX) $(CXXFLAGS) -o $@ $<

build_start:
	@echo "  Build Start"


CandidateCountingAlgo3: $(OBJ) $(MAIN)
	@$(CXX) $(OBJ) $(MAIN) -o $@
	@echo "  STRIP $@"
	@strip $@
	@chmod +x $@
	@echo " Build CandidateCountingAlgo3 done."

clean:
	@echo "  Clean"
	@find . -name '*.o' | xargs rm -rf
	@rm CandidateCountingAlgo3 -rf
