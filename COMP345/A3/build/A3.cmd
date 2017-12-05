//doxygen
doxygen -g

#RECURSIVE              = YES

doxygen Doxyfile


//program
mkdir -p obj/Debug
mkdir -p bin/Debug


//copy test files
cp -r test/* bin/Debug


//indexing
g++ -Wall -g -std=c++11  -c src/implementation/AbstractTokenizer.cpp -o obj/Debug/src/implementation/AbstractTokenizer.o
g++ -Wall -g -std=c++11  -c src/implementation/Document.cpp -o obj/Debug/src/implementation/Document.o
g++ -Wall -g -std=c++11  -c src/implementation/DocumentIndexer.cpp -o obj/Debug/src/implementation/DocumentIndexer.o
g++ -Wall -g -std=c++11  -c src/implementation/Indexer.cpp -o obj/Debug/src/implementation/Indexer.o
g++ -Wall -g -std=c++11  -c src/implementation/IndexItem.cpp -o obj/Debug/src/implementation/IndexItem.o
g++ -Wall -g -std=c++11  -c src/implementation/QueryResult.cpp -o obj/Debug/src/implementation/QueryResult.o
g++ -Wall -g -std=c++11  -c src/implementation/Sentence.cpp -o obj/Debug/src/implementation/Sentence.o
g++ -Wall -g -std=c++11  -c src/implementation/SentenceIndexer.cpp -o obj/Debug/src/implementation/SentenceIndexer.o
g++ -Wall -g -std=c++11  -c src/implementation/SentenceTokenizer.cpp -o obj/Debug/src/implementation/SentenceTokenizer.o
g++ -Wall -g -std=c++11  -c src/implementation/Stopword.cpp -o obj/Debug/src/implementation/Stopword.o
g++ -Wall -g -std=c++11  -c src/implementation/WordTokenizer.cpp -o obj/Debug/src/implementation/WordTokenizer.o
g++ -Wall -g -std=c++11  -c src/Indexing.cpp -o obj/Debug/src/Indexing.o
g++  -o bin/Debug/A1 obj/Debug/src/implementation/AbstractTokenizer.o obj/Debug/src/implementation/Document.o obj/Debug/src/implementation/DocumentIndexer.o obj/Debug/src/implementation/Indexer.o obj/Debug/src/implementation/IndexItem.o obj/Debug/src/implementation/QueryResult.o obj/Debug/src/implementation/Sentence.o obj/Debug/src/implementation/SentenceIndexer.o obj/Debug/src/implementation/SentenceTokenizer.o obj/Debug/src/implementation/Stopword.o obj/Debug/src/implementation/WordTokenizer.o obj/Debug/src/Indexing.o   


//googler
g++ -Wall -g -std=c++11  -c src/Googler.cpp -o obj/Debug/src/Googler.o
g++  -o bin/Debug/A2 obj/Debug/src/implementation/AbstractTokenizer.o obj/Debug/src/implementation/Document.o obj/Debug/src/implementation/DocumentIndexer.o obj/Debug/src/implementation/Indexer.o obj/Debug/src/implementation/IndexItem.o obj/Debug/src/implementation/QueryResult.o obj/Debug/src/implementation/Sentence.o obj/Debug/src/implementation/SentenceIndexer.o obj/Debug/src/implementation/SentenceTokenizer.o obj/Debug/src/implementation/Stopword.o obj/Debug/src/implementation/WordTokenizer.o obj/Debug/src/Googler.o   


//summarizer
g++ -Wall -g -std=c++11  -c src/Summarizer.cpp -o obj/Debug/src/Summarizer.o
g++  -o bin/Debug/A3 obj/Debug/src/implementation/AbstractTokenizer.o obj/Debug/src/implementation/Document.o obj/Debug/src/implementation/DocumentIndexer.o obj/Debug/src/implementation/Indexer.o obj/Debug/src/implementation/IndexItem.o obj/Debug/src/implementation/QueryResult.o obj/Debug/src/implementation/Sentence.o obj/Debug/src/implementation/SentenceIndexer.o obj/Debug/src/implementation/SentenceTokenizer.o obj/Debug/src/implementation/Stopword.o obj/Debug/src/implementation/WordTokenizer.o obj/Debug/src/Summarizer.o  

