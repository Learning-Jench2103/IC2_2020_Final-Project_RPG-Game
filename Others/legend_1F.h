#ifndef LEGEND_1F_H
#define LEGEND_1F_H

class legend_1F
{
private:
	void setColor(unsigned int color = 7) const;
	void setCursor(int x, int y) const;

public: 
	legend_1F();
	void display();
};

#endif