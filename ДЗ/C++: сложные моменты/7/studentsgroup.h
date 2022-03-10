#pragma once

#include <vector>
#include <algorithm>
#include <tuple>
#include <sstream>
#include <fstream>

#include "gb7.pb.h"

class IRepository {
    virtual void Open() = 0; // бинарная десериализация в файл
    virtual void Save() = 0; // бинарная сериализация в файл
};

class IMethods {
    virtual double GetAverageScore(const gb7_proto::FullName& name) = 0;
    virtual std::string GetAllInfo(const gb7_proto::FullName& name) = 0;
    virtual std::string GetAllInfo() = 0;
};

class StudentsGroup : public IRepository, IMethods
{
public:
    StudentsGroup()= default;
    virtual ~StudentsGroup() = default;

    double GetAverageScore(const gb7_proto::FullName &name) override;
    std::string GetAllInfo(const gb7_proto::FullName &name) override;
    std::string GetAllInfo() override;

    void Open() override;
    void Save() override;

    gb7_proto::StudentsGroup &students();

private:
    gb7_proto::StudentsGroup _students;
};

