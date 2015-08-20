all : texpr
BISON=/usr/local/Cellar/bison/3.0.4/bin/bison

CXXFLAGS=-stdlib=libstdc++
TExpr.tab.cc:TExpr.y
	$(BISON) TExpr.y

TExpr.lex.cc:TExpr.l
	flex TExpr.l

texpr:TExpr.tab.o TExpr.lex.o ExprValue.o ExprValTable.o ExprFn.o texpr.o 
	$(CXX) $(CXXFLAGS) \
	  TExpr.tab.o TExpr.lex.o ExprValue.o ExprValTable.o ExprFn.o texpr.o -o $@

clean:
	- rm *.o texpr

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<
.cc.o:
	$(CXX) -c $(CXXFLAGS) $<
