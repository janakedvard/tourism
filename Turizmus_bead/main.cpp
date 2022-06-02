#include <iostream>
#include "City.h"
#include <fstream>
using namespace std;

City* concheck(City* c){
    int cond=c->getCondition();

    if(c->type()=="Good"&& cond<67){
        c = c->decadence();

    }
    if((c->type() == "Avg") && (cond<34)){
        c = c->decadence();

    }
    if(c->type()=="Bad" && cond>34)
    {
        c = c->improve();
    }
    if(c->type()=="Avg"&& cond>=67)
    {
        c = c->improve();
    }



    c->setCondition(cond);
    return c;
}


City* createcity(int con){
    City* c;

    if(con>67){
        c = Good::instance();
    }else if(con>=34 && con<67){
        c = Average::instance();
    }else{
        c = Bad::instance();
    }
    c->setCondition(con);
    cout<<"CREATE:"<<c->getCondition()<<" "<<c->type()<<endl;
    return c;
}



City* simulation(const string &file){
    ifstream f(file);
    if(f.fail()){
        cout<<"Wrong file name"<<endl;
        exit(1);
    }
    int cond;
    f >> cond;
    City* cp;
    cp = createcity(cond);
    int years;
    f >> years;
    if(years>10)years=10;

    for(int i = 0; i<years; i++){
        cp->setIncome(0);
        int j;
        f >> j;
        Japanese* japan = new Japanese(j);

        int m;
        f >> m;
        Modern* modern = new Modern(m);

        int t;
        f >> t;
        Third* th = new Third(t);
        cout<<"Tervezett turistak: "<<endl;
        cout<<j<<" "<<m<<" "<<t<<endl;

        int a = cp->visit(japan);
        int b = cp->visit(modern);
        int c = cp->visit(th);



        cout<<"Valoban megerkezettek: "<<endl;
        cout<<cp->getJapnum()<<" "<<cp->getModnum()<<" "<<cp->getThirdnum()<<endl;

        cp->setIncome((cp->getJapnum()+cp->getModnum()+cp->getThirdnum())*100000);
        cout<<"Bevetel: "<<cp->getIncome()<<endl;
        cp->setCondition(cp->getCondition()-(a+b+c));
        int d;
        if(cp->getIncome()>1000000000){
        d = cp->getIncome()-1000000000;
        }else{d = 0;}
        cp->setCondition(cp->getCondition()+d/20000000);


        cp = concheck(cp);

        if(cp->getCondition()>100)cp->setCondition(100);
        else if(cp->getCondition()<1)cp->setCondition(1);
        cout<<cp->getCondition()<<" "<<cp->type()<<endl;

        cout<<i<<" menet vége"<<endl;


    }

    return cp;
}

#define NORMAL_MODE
#ifdef NORMAL_MODE
int main()
{

    simulation("input.txt");



    return 0;
}
#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("no turists", "input2.txt")
{
    City* p = simulation("input2.txt");

    CHECK(p->type()=="Avg");
    CHECK(p->getCondition()==50);

}
TEST_CASE("concheck, good to avg", "input3.txt")
{
    City* p = simulation("input3.txt");

    CHECK(p->type()=="Avg");
    CHECK(p->getCondition()==48);

}
TEST_CASE("concheck, avg to bad", "input4.txt")
{
    City* p = simulation("input4.txt");

    CHECK(p->type()=="Bad");
    CHECK(p->getCondition() == 16);
}
TEST_CASE("concheck, avg to good", "input5.txt")
{
    City* p = simulation("input5.txt");

    CHECK(p->type()=="Good");
    CHECK(p->getCondition()==69);
}
TEST_CASE("good to bad", "input6.txt")
{
    City* p = simulation("input6.txt");

    CHECK(p->type()=="Bad");
    CHECK(p->getCondition() == 17);
}
TEST_CASE("zero years", "input7.txt")
{
    City* p = simulation("input7.txt");

    CHECK(p->type()=="Avg");
    CHECK(p->getCondition()==50);

}
TEST_CASE("11 years", "input8.txt")
{
    City* p = simulation("input8.txt");

    CHECK(p->type()=="Bad");
    CHECK(p->getCondition() == 1);
}
#endif
