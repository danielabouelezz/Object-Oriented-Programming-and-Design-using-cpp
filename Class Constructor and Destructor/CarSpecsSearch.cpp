/* This code is working well
   However, it is badly designed. Why?

Note: The original code is at the end.
*/

#include <bits/stdc++.h>

class CarSpecs{
private:
    std::string trim;
    std::string engineType;
    std::pair<int, int> horsepower;
    std::string steeringRatio;

public:

    std::string& GetEngineType()
    {
        return engineType;
    }
    void SetEngineType(std::string& engineType)
    {
        this->engineType = engineType;
    }
    std::pair<int, int> GetHorsepower()
    {
        return horsepower;
    }

    void SetHorsepower(std::pair<int, int> horsepower)
    {
        this->horsepower = horsepower;
    }
    std::string GetSteeringRatio()
    {
        return steeringRatio;
    }
    void SetSteeringRatio(std::string& steeringRatio)
    {
        this->steeringRatio = steeringRatio;
    }
    std::string& GetTrim()
    {
        return trim;
    }
    void SetTrim(std::string& trim)
    {
        this->trim = trim;
    }

    bool isEqual(CarSpecs &others) const
    {
        return others.GetEngineType() == engineType &&
                others.GetHorsepower() == horsepower &&
                others.GetSteeringRatio() == steeringRatio &&
                others.GetTrim() == trim;
    }

    /*
    bool isEqual(CarSpecs &others) const
    {
        return others.GetEngineType() == GetEngineType() &&
                others.GetHorsepower() == GetHorsepower() &&
                others.GetSteeringRatio() == GetSteeringRatio() &&
                others.GetTrim() == GetTrim();
    }
    */
};

class AutoTrader{
private:
    std::vector<CarSpecs> currentCarVec;
public:
    void LoadDatabase()
    {
        //Fill currentCarVec;
    }

    bool search_match(CarSpecs &queryCar)
    {
        for(auto availableCar : currentCarVec)
        {
            if(availableCar.isEqual(queryCar))
                return true;
        }
        return false;
    }
};

/*

1- The original code violates encapsulation concept by forcing others to think how
    to compare to objects.
   The right way, CarSpecs class should provide is_equal functionality

2- Also from code change perspective, every time we change the data members
    in CarSpecs (e.g. details of exterior shape)
   We will have to change AutoTrader class (2 classes changed).
   If CarSpecs provides is_equal functionality, other users won't need to do/care
   about the changes as they are still handled

3- On the other side, the code did not follow this nice tip:
    “Don’t ask for the information you need to do the work; ask the object that has the information to do the work for you.” Allen Holub

	We asked for all the gets to do the comparison! This should be the class responsibility
 */


int main()
{
    return 0;
}


/*
class CarSpecs{
private:
    std::string trim;
    std::string engineType;
    std::pair<int, int> horsepower;
    std::string steeringRatio;

public:

    std::string& GetEngineType()
    {

    }
    void SetEngineType(std::string& engineType)
    {

    }
    std::pair<int, int> GetHorsepower()
    {

    }

    void SetHorsepower(std::pair<int, int> horsepower)
    {

    }
    std::string GetSteeringRatio()
    {

    }
    void SetSteeringRatio(std::string& steeringRatio)
    {

    }
    std::string& GetTrim()
    {

    }
    void SetTrim(std::string& trim)
    {

    }
};

class AutoTrader{
private:
    std::vector<CarSpecs> currentCarVec;
public:
    void LoadDatabase()
    {
        //Fill currentCarVec;
    }

    bool search_match(CarSpecs &queryCar)
    {
        for(auto availableCar : currentCarVec)
        {
            if(availableCar.GetEngineType() == queryCar.GetEngineType() &&
               availableCar.GetHorsepower() == queryCar.GetHorsepower() &&
               availableCar.GetSteeringRatio() == queryCar.GetSteeringRatio() &&
               availableCar.GetTrim() == queryCar.GetTrim()){ return true;}
        }
        return false;
    }
};
*/
