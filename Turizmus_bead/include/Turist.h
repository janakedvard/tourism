#ifndef TURIST_H
#define TURIST_H


class Turist
{
    public:
        Turist();
        virtual ~Turist();
    virtual int getHarm() const = 0;
    virtual int getTurists() const =0;

    protected:

    private:

};

class Japanese : public Turist
{
    public:
        Japanese(int a) : numOfTurists(a){};
        int getHarm() const override {return harm;}
        int getTurists() const override {return numOfTurists;}

    protected:

    private:
        int numOfTurists;
        int harm = 0;
};

class Modern : public Turist
{
    public:
        Modern(int a): numOfTurists(a){};
        int getHarm() const override {return harm;}
        int getTurists() const override {return numOfTurists;}

    protected:

    private:
        int numOfTurists;
        int harm = 100;
};

class Third : public Turist
{
    public:
        Third(int a): numOfTurists(a){};
        int getHarm() const override {return harm;}
        int getTurists() const override {return numOfTurists;}

    protected:

    private:
        int numOfTurists;
        int harm = 50;
};


#endif // TURIST_H
