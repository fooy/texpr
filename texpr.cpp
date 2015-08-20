#include <stdio.h>
#include "TExpr.tab.hh"
using namespace std;
int main(int argc, const char *argv[])
{
    ExprValuePtr f1=ExprValuePtr(new ExprValue);
    ExprValuePtr f2=ExprValuePtr(new ExprValue);
    ExprValuePtr f3=ExprValuePtr(new ExprValue);
    ExprValuePtr f4=ExprValuePtr(new ExprValue);
    ExprValuePtr f5=ExprValuePtr(new ExprValue);

    f1->setInt(123);
    f2->setStr("456");
    f3->setInt(789);
    f4->setStr("123sdfjk1232142342354");

    f5->setImage((void*)"hello",5);



    ExprValTable st;
    st.setField("int1",f1);
    st.setField("str2",f2);
    st.setField("this.is.array#1",f3);
    st.setField("INM_ORG_TELLER_ID",f4);
    st.setField("img",f5);

    ExprValuePtr ev = ExprValuePtr(new ExprValue);

    string msg;

    if(int res= SDExprEval( st, ev , argv[1] ,msg ) ){
        cerr<< "error :"<<  msg << endl;
    }else{
        //cout << "expr = " << ev->getStr().c_str() <<endl;
        cout << "ret : " << ev->getPrintStr() <<endl;
    }
    return 0;
}
