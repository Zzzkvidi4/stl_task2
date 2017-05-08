#pragma once
class Command
{
private:
    std::string title;
public:
    Command(std::string title);
    virtual void Execute() = 0;
    std::string GetTitle();
    ~Command();
};

