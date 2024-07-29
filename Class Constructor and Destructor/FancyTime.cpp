//Change the class to allow consecutive function calls in the main.

#include <bits/stdc++.h>

class Time{
private:
    // Put on separate lines for code clarity
    int hours;
    int minutes;
    int seconds;

    void valueValidation(int& value, int maxValue = 59)
    {
        if(value < 0)
            value = 0;
        else if(value > maxValue)
            value = maxValue;
    }

public:
    Time(int hours, int minutes, int seconds){
        //There is mimber function doing the same task
        //Avoid code duplications
        setTime(hours, minutes, seconds);
    }

    void setTime(int hours, int minutes, int seconds)
    {
        //Put on separate lines for code clarity
        //Still there is a missing point here.
        //We better use setters as the validate/change input
        valueValidation(hours, 23);
        valueValidation(minutes);
        valueValidation(seconds);
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    int getTotalSeconds()
    {
        return hours*60*60 + minutes*60 + seconds;
    }

    int getTotalMinutes()
    {
        return hours*60 + minutes;
    }

    void PrintHHMMSS()
    {
        //Code duplicate
        std::cout<<ToString(":")<<"\n";
    }

    std::string ToString(std::string separator = "-")
    {
        std::ostringstream oss;
        oss<<hours<<separator<<minutes<<separator<<seconds;
        return oss.str();
    }

    int getHours()
    {
        return hours;
    }
    Time& setHours(int hours)
    {
        //Be careful from missing verification. This is important for "data-integrity"
        if(hours < 0)
            hours = 0;
        this->hours = hours;

        return *this;
    }
    int getMinutes()
    {
        return minutes;
    }
    Time& setMinutes(int minutes)
    {
        if(minutes < 0)
            minutes = 0;
        this->minutes = minutes;

        return *this;
    }
    int getSeconds()
    {
        return seconds;
    }
    Time& setSeconds(int seconds)
    {
        if(seconds < 0)
            seconds = 0;
        this->seconds = seconds;

        return *this;
    }
};

/*
what does it mean to do
	1) t.SetHours(5).Something?
	.Something is a function, then it needs object
	then t.SetHours(5) must return object of type time NOT void

	So we need to return object from these setters

	2) Now each object has pointer to itself this
		*this is the object
		We can return this but there is a problem
		It will be a copy, so NOT same
		This means we are modifying some temporary object NOT t itself!

	To solve that, return the object by reference: Time&T

	So overall
	Time& SomeSetter
		return *this
*/

int main()
{
    Time t(3, 1, 2);
    t.PrintHHMMSS();

    t.setHours(5).setMinutes(45).setSeconds(13);
    t.PrintHHMMSS();

    return 0;
}
