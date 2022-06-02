#ifndef CITY_H
#define CITY_H
#include "Turist.h"
#include <string>
#include <iostream>

class City
{
    public:
        City();
        virtual ~City(){};
        virtual City* improve() const = 0;
        virtual City* decadence () const = 0;
        virtual int visit(Japanese* jap) = 0;
        virtual int visit(Modern* mod) = 0;
        virtual int visit(Third* third) = 0;
        virtual std::string type() const = 0;
        virtual int getJapnum() const = 0;
        virtual int getModnum() const = 0;
        virtual int getThirdnum() const = 0;
        virtual int getIncome() {return income;}
        virtual void setIncome(int n){income=n;}
        virtual int getCondition(){return condition;}
        virtual void setCondition(int c){condition=c;}




    protected:

    private:
        int condition=0;
        int income=0;
        int japnum;
        int modnum;
        int thirdnum;
};
class Good : public City
{
    public:
        static Good* instance();
        City* improve() const override;
        City* decadence() const override;
        int visit(Japanese* jap) override;
        int visit(Modern* mod) override;
        int visit(Third* third) override;
        std::string type() const override {return "Good";}
        int getJapnum() const override {return japnum;}
        int getModnum() const override {return modnum;}
        int getThirdnum() const override {return thirdnum;}

    protected:

    private:
        int condition=0;
        int income=0;
        static Good* _instance;
        int japnum;
        int modnum;
        int thirdnum;

};

class Average : public City
{
    public:
        static Average* instance();
        City* improve() const override;
        City* decadence() const override;
        int visit(Japanese* jap) override;
        int visit(Modern* mod) override;
        int visit(Third* third) override;
        std::string type() const override {return "Avg";}
        int getJapnum() const override {return japnum;}
        int getModnum() const override {return modnum;}
        int getThirdnum() const override {return thirdnum;}



    protected:

    private:
        int condition=0;
        int income=0;
        static Average* _instance;
        int japnum;
        int modnum;
        int thirdnum;

};
class Bad : public City
{
    public:
        static Bad* instance();
        City* improve() const override;
        City* decadence() const override;
        int visit(Japanese* jap) override;
        int visit(Modern* mod) override;
        int visit(Third* third) override;
        std::string type() const override {return "Bad";}
        int getJapnum() const override {return japnum;}
        int getModnum() const override {return modnum;}
        int getThirdnum() const override {return thirdnum;}

    protected:

    private:
        int condition=0;
        int income=0;
        static Bad* _instance;
        int japnum;
        int modnum;
        int thirdnum;

};
#endif // CITY_H
