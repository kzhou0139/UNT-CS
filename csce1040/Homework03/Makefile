output: main.o Book.o Books.o Loan.o Loans.o Patron.o Patrons.o
	g++ main.o Book.o Books.o Loan.o Loans.o Patron.o Patrons.o -o output

main.o: main.cpp
	g++ -c main.cpp

Book.o: Book.cpp Book.h
	g++ -c Book.cpp Book.h

Books.o: Books.cpp Books.h
	g++ -c Books.cpp Books.h

Loan.o: Loan.cpp Loan.h
	g++ -c Loan.cpp Loan.h

Loans.o: Loans.cpp Loans.h
	g++ -c Loans.cpp Loans.h

Patron.o: Patron.cpp Patron.h
	g++ -c Patron.cpp Patron.h

Patrons.o: Patrons.cpp Patrons.h
	g++ -c Patrons.cpp Patrons.h

clean:
	rm *.o output
