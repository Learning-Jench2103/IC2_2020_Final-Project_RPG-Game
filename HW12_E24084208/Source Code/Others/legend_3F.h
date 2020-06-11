#ifndef LEGEND_3F_H
#define LEGEND_3F_H

class legend_3F
{
private:
	void setColor(unsigned int color = 7) const;
	void setCursor(int x, int y) const;

public:
	legend_3F();
	void display();
};

#endif