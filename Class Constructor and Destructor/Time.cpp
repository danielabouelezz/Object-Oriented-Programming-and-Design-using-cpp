/*Identify 2 changes for code clarity.
  Identify a bug.
  Identify 2 code duplications.
  Identify missing inputs verifications(user mistakes).

Note : You will find the initial code at the end.
*/

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
    void setHours(int hours)
    {
        //Be careful from missing verification. This is important for "data-integrity"
        if(hours < 0)
            hours = 0;
        this->hours = hours;
    }
    int getMinutes()
    {
        return minutes;
    }
    void setMinutes(int minutes)
    {
        if(minutes < 0)
            minutes = 0;
        this->minutes = minutes;
    }
    int getSeconds()
    {
        return seconds;
    }
    void setSeconds(int seconds)
    {
        if(seconds < 0)
            seconds = 0;
        this->seconds = seconds;
    }
};

int main()
{
    Time t(0, 120, 120);
    t.PrintHHMMSS();
    return 0;
}
/*
class Time{
private:
    int hours, minutes, seconds;

public:
    Time(int hours, int minutes, int seconds):
        hours(hours), minutes(minutes), seconds(seconds){}

    void setTime(int hours, int minutes, int seconds)
    {
        this->hours = hours,this->minutes = minutes,this->seconds = seconds;
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
        std::cout<<hours<<":"<<minutes<<":"<<seconds<<"\n";
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
    void setHours(int hours)
    {
        this->hours = hours;
    }
    int getMinutes()
    {
        return minutes;
    }
    void setMinutes(int minutes)
    {
        this->minutes = minutes;
    }
    int getSeconds()
    {
        return seconds;
    }
    void setSeconds(int seconds)
    {
        this->seconds = seconds;
    }
};
*/
