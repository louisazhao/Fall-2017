//doxygen
doxygen -g
doxygen Doxyfile



//program
mkdir obj
mkdir bin

cp test/* bin

//index
g++ -Wall -g -std=c++11  -c Dictionary.cpp -o obj/Dictionary.o
g++ -Wall -g -std=c++11  -c Document.cpp -o obj/Document.o
g++ -Wall -g -std=c++11  -c index.cpp -o obj/index.o
g++ -Wall -g -std=c++11  -c Indexer.cpp -o obj/Indexer.o
g++ -Wall -g -std=c++11  -c QueryResult.cpp -o obj/QueryResult.o
g++ -Wall -g -std=c++11  -c Stopword.cpp -o obj/Stopword.o
g++ -Wall -g -std=c++11  -c Tokenizer.cpp -o obj/Tokenizer.o
g++  -o bin/index obj/Dictionary.o obj/Document.o obj/index.o obj/Indexer.o obj/QueryResult.o obj/Stopword.o obj/Tokenizer.o   



//google
g++ -Wall -g -std=c++11  -c Dictionary.cpp -o obj/Dictionary.o
g++ -Wall -g -std=c++11  -c Document.cpp -o obj/Document.o
g++ -Wall -g -std=c++11  -c googler.cpp -o obj/googler.o
g++ -Wall -g -std=c++11  -c Indexer.cpp -o obj/Indexer.o
g++ -Wall -g -std=c++11  -c QueryResult.cpp -o obj/QueryResult.o
g++ -Wall -g -std=c++11  -c Stopword.cpp -o obj/Stopword.o
g++ -Wall -g -std=c++11  -c Tokenizer.cpp -o obj/Tokenizer.o
g++  -o bin/google obj/Dictionary.o obj/Document.o obj/googler.o obj/Indexer.o obj/QueryResult.o obj/Stopword.o obj/Tokenizer.o
