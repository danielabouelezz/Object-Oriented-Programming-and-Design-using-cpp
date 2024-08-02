/***
Your team asked to develop a configuration manager component
    -This one loads system default values and critical information
    -E.g. Some servers IPs, Databases paths(& usernames & passwords)
    -E.g. also loads some heavy files and cache for frequent requests

After you developed it, you noticed that some several of code create a seperate object
    -But is actually loading the same things. It also takes 30 minuted to load data from disk!
Your team lead suggested the following:
    -Changing the class to allow ONLY onw shared instance
    -This way the class forces any user to use the SAME object(The class itself!)
    -Change the next code to do such change
***/
//Original Code at the end

#include <bits/stdc++.h>

class ConfigurationManager{
private:
    static ConfigurationManager* instance;

    std::string configuration_path;
    std::vector<std::string> servers_ips;
    std::string aws_service_url;
    //Other heavy data;
    bool is_loaded;

    ConfigurationManager(std::string configuration_path):
        configuration_path(configuration_path){}
public:

    static ConfigurationManager* getInstance(const std::string& value)
    {
        if(instance == nullptr)
        {
            std::cout<<"Creating a new ConfigurationManager\n";
            instance = new ConfigurationManager(value);
        }
        return instance;
    }

    void Load()
    {
        if(is_loaded)
            return;
        // some heavy load
        std::cout<<"lazy Loading\n";
        servers_ips.push_back("10.20.30.40");
        servers_ips.push_back("10.20.30.41");
        servers_ips.push_back("10.20.30.42");
        aws_service_url = "https://dynamodb.us-west-2.amazonaws.com";
        is_loaded = true;
    }


    std::string GetAwsServiceUrl()
    {
        Load();
        return aws_service_url;
    }


    ~ConfigurationManager() {
		/// Note, you shouldn't try to destroy the conf_mgr here!!!
		/// The first object destroy it but others still use it (or will reload)!

		///FreeInstance();	// if you uncommented = infinite loop. WHY? Answer is belo very bottom

		/// Quote: Don’t create problems to solve a problem
	}

    static void FreeInstance() {
		if (ConfigurationManager::instance != nullptr) {
			std::cout << "Free the instance\n";
			delete ConfigurationManager::instance;
			ConfigurationManager::instance = nullptr;
		} else
			std::cout << "The instance freed already\n";
	}
};

ConfigurationManager* ConfigurationManager::instance = nullptr;


void f1()
{
    ConfigurationManager* mgr = ConfigurationManager::getInstance("/home/moustafa/conf_info.txt");
    std::cout<<mgr->GetAwsServiceUrl()<<"\n";
}

void f2()
{
    ConfigurationManager* mgr = ConfigurationManager::getInstance("/home/moustafa/conf_info.txt");
    std::cout<<mgr->GetAwsServiceUrl()<<"\n";
}

int main()
{
    f1();
    f2();

    //If we forget to free, it will be memory leak!
    //We need more elegant solutions!
    ConfigurationManager::FreeInstance();

    return 0;
}



/*
class ConfigurationManager{
private:
    std:;string configuration_path;
    std::vector<std::string> servers_ips;
    std::string aws_service_url;
    //Other heavy data;
    bool is_loaded = false;
public:
    ConfigurationManager(std::string configuration_path):
        configuration_path(configuration_path){}

    void Load()
    {
        if(is_loaded)
            return;
        // some heavy load
        std::cout<<"lazy Loading\n";
        servers_ips.push_back("10.20.30.40");
        servers_ips.push_back("10.20.30.41");
        servers_ips.push_back("10.20.30.42");
        aws_service_url = "https://dynamodb.us-west-2"
        is_loaded = true;
    }

    std::string GetAwsServiceUrl()
    {
        Load();
        return aws_service_url;
    }
};

void f1()
{
    ConfigurationManager mgr("/home/moustafa/conf_info.txt");
    std::cout<<mgr.GetAwsServiceUrl()<<"\n"
}

void f2()
{
    ConfigurationManager mgr("/home/moustafa/conf_info.txt");
    std::cout<<mgr.GetAwsServiceUrl()<<"\n";
}

int main()
{
    f1();
    f2();
    return 0;
}
*/
