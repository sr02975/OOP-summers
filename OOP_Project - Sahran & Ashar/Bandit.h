#ifndef BANDIT_H
#define BANDIT_H
#include"Unit.h"


class Bandit:public Unit
{
    public:
        Bandit();
        ~Bandit();
        Bandit(LTexture*,float,float);
        void Render(long int&, SDL_Renderer*,bool);

    protected:
        enum ANIMATION_FRAMES {MAIN_OBJECT = 3};

    private:
};

#endif // BANDIT_H
