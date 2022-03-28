#pragma once

class Command
{
public:
    Command() = default;
    virtual ~Command() = default;

    virtual void Execute() = 0;
};
