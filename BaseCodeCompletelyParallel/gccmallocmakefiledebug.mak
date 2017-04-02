all: PatternFinder


PatternFinder: main.o Forest.o Logger.o PListArchive.o FileReader.o StopWatch.o ChunkFactory.o ProcessorConfig.o
	g++ -g main.o Forest.o Logger.o PListArchive.o FileReader.o StopWatch.o ChunkFactory.o ProcessorConfig.o -o PatternFinder -pthread
main.o: main.cpp
	g++ -g -c -std=c++11 main.cpp -pthread
Forest.o: Forest.cpp
	g++ -g -c -std=c++11 Forest.cpp -pthread
Logger.o: Logger.cpp
	g++ -g -c -std=c++11 Logger.cpp -pthread
PListArchive.o: PListArchive.cpp
	g++ -g -c -std=c++11 PListArchive.cpp -pthread
FileReader.o: FileReader.cpp
	g++ -g -c -std=c++11 FileReader.cpp -pthread
StopWatch.o: StopWatch.cpp
	g++ -g -c -std=c++11 StopWatch.cpp -pthread
ChunkFactory.o: ChunkFactory.cpp
	g++ -g -c -std=c++11 ChunkFactory.cpp -pthread
ProcessorConfig.o: ProcessorConfig.cpp
	g++ -g -c -std=c++11 ProcessorConfig.cpp -pthread
clean:
	rm *o
#Clean command: make -f gccmallocmakefile.mak clean
#Release: g++ -std=c++11 -O3 -s -DNDEBUG main.cpp TreeNode.cpp -pthread -o Debug/PatternFinder
#./PatternFinder -f TaleOfTwoCities.txt -min 1 -max 1000000 -d -threads 5 -mem 40 -lev 1 -his 0 -v 1 -HD
