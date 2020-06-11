#ifndef LEGEND_2F_H
#define LEGEND_2F_H

class legend_2F
{
private:
	void setColor(unsigned int color = 7) const;
	void setCursor(int x, int y) const;

public:
	legend_2F();
	void display();
};

#endif