#CST43 Lu Jiarui / Ma Qiang / Wang Wei
all: UI.exe

UI.exe: UI.cpp Word.cpp Word.h WordCollection.cpp WordCollection.h WordCollectionFactory.h WordSearch.h WordSearch.cpp WordTest.h WordExtraction.h WordExtraction.cpp
	g++ -o UI.exe UI.cpp Word.cpp WordCollection.cpp WordSearch.cpp WordExtraction.cpp