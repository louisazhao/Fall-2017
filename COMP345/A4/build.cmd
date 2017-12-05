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
g++ -Wall -g -std=c++11  -c /nfs/home/t/ta_li/git/COMP345A4/source/implementation/AbstractTokenizer.cpp -o obj/Debug/source/implementation/AbstractTokenizer.o
g++ -Wall -g -std=c++11  -c /nfs/home/t/ta_li/git/COMP345A4/source/implementation/Document.cpp -o obj/Debug/source/implementation/Document.o
g++ -Wall -g -std=c++11  -c /nfs/home/t/ta_li/git/COMP345A4/source/implementation/DocumentIndexer.cpp -o obj/Debug/source/implementation/DocumentIndexer.o
g++ -Wall -g -std=c++11  -c /nfs/home/t/ta_li/git/COMP345A4/source/implementation/Indexer.cpp -o obj/Debug/source/implementation/Indexer.o
g++ -Wall -g -std=c++11  -c /nfs/home/t/ta_li/git/COMP345A4/source/implementation/IndexItem.cpp -o obj/Debug/source/implementation/IndexItem.o
g++ -Wall -g -std=c++11  -c /nfs/home/t/ta_li/git/COMP345A4/source/implementation/Movie.cpp -o obj/Debug/source/implementation/Movie.o
g++ -Wall -g -std=c++11  -c /nfs/home/t/ta_li/git/COMP345A4/source/implementation/QueryResult.cpp -o obj/Debug/source/implementation/QueryResult.o
g++ -Wall -g -std=c++11  -c /nfs/home/t/ta_li/git/COMP345A4/source/implementation/Sentence.cpp -o obj/Debug/source/implementation/Sentence.o
g++ -Wall -g -std=c++11  -c /nfs/home/t/ta_li/git/COMP345A4/source/implementation/SentenceIndexer.cpp -o obj/Debug/source/implementation/SentenceIndexer.o
g++ -Wall -g -std=c++11  -c /nfs/home/t/ta_li/git/COMP345A4/source/implementation/SentenceTokenizer.cpp -o obj/Debug/source/implementation/SentenceTokenizer.o
g++ -Wall -g -std=c++11  -c /nfs/home/t/ta_li/git/COMP345A4/source/implementation/Stopword.cpp -o obj/Debug/source/implementation/Stopword.o
g++ -Wall -g -std=c++11  -c /nfs/home/t/ta_li/git/COMP345A4/source/implementation/WordTokenizer.cpp -o obj/Debug/source/implementation/WordTokenizer.o
g++ -Wall -g -std=c++11  -c /nfs/home/t/ta_li/git/COMP345A4/source/Indexing.cpp -o obj/Debug/source/Indexing.o
g++  -o bin/Debug/A1 obj/Debug/source/implementation/AbstractTokenizer.o obj/Debug/source/implementation/Document.o obj/Debug/source/implementation/DocumentIndexer.o obj/Debug/source/implementation/Indexer.o obj/Debug/source/implementation/IndexItem.o obj/Debug/source/implementation/Movie.o obj/Debug/source/implementation/QueryResult.o obj/Debug/source/implementation/Sentence.o obj/Debug/source/implementation/SentenceIndexer.o obj/Debug/source/implementation/SentenceTokenizer.o obj/Debug/source/implementation/Stopword.o obj/Debug/source/implementation/WordTokenizer.o obj/Debug/source/Indexing.o  -pthread


//googler
g++ -Wall -g -std=c++11  -c /nfs/home/t/ta_li/git/COMP345A4/source/Googler.cpp -o obj/Debug/source/Googler.o
g++  -o bin/Debug/A2 obj/Debug/source/Googler.o obj/Debug/source/implementation/AbstractTokenizer.o obj/Debug/source/implementation/Document.o obj/Debug/source/implementation/DocumentIndexer.o obj/Debug/source/implementation/Indexer.o obj/Debug/source/implementation/IndexItem.o obj/Debug/source/implementation/Movie.o obj/Debug/source/implementation/QueryResult.o obj/Debug/source/implementation/Sentence.o obj/Debug/source/implementation/SentenceIndexer.o obj/Debug/source/implementation/SentenceTokenizer.o obj/Debug/source/implementation/Stopword.o obj/Debug/source/implementation/WordTokenizer.o  -pthread

//essay
g++ -Wall -g -std=c++11  -c /nfs/home/t/ta_li/git/COMP345A4/source/Summarizer.cpp -o obj/Debug/source/Summarizer.o
g++  -o bin/Debug/A3 obj/Debug/source/implementation/AbstractTokenizer.o obj/Debug/source/implementation/Document.o obj/Debug/source/implementation/DocumentIndexer.o obj/Debug/source/implementation/Indexer.o obj/Debug/source/implementation/IndexItem.o obj/Debug/source/implementation/Movie.o obj/Debug/source/implementation/QueryResult.o obj/Debug/source/implementation/Sentence.o obj/Debug/source/implementation/SentenceIndexer.o obj/Debug/source/implementation/SentenceTokenizer.o obj/Debug/source/implementation/Stopword.o obj/Debug/source/implementation/WordTokenizer.o obj/Debug/source/Summarizer.o  -pthread

//movie
g++ -Wall -g -std=c++11  -c /nfs/home/t/ta_li/git/COMP345A4/source/MovieRecommender.cpp -o obj/Debug/source/MovieRecommender.o
g++  -o bin/Debug/A4 obj/Debug/source/implementation/AbstractTokenizer.o obj/Debug/source/implementation/Document.o obj/Debug/source/implementation/DocumentIndexer.o obj/Debug/source/implementation/Indexer.o obj/Debug/source/implementation/IndexItem.o obj/Debug/source/implementation/Movie.o obj/Debug/source/implementation/QueryResult.o obj/Debug/source/implementation/Sentence.o obj/Debug/source/implementation/SentenceIndexer.o obj/Debug/source/implementation/SentenceTokenizer.o obj/Debug/source/implementation/Stopword.o obj/Debug/source/implementation/WordTokenizer.o obj/Debug/source/MovieRecommender.o  -pthread 
