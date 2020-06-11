#ifndef WELCOME_1F_H
#define WELCOME_1F_H

class Welcome_1F
{
private:
	void setCursor(int x, int y) const;
	void setColor(unsigned int color = 7) const;
public:
	Welcome_1F();
	void run();
};



#endif



