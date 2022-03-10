#include "studentsgroup.h"

double StudentsGroup::GetAverageScore(const gb7_proto::FullName &name)
{
    auto it = std::find_if(_students.students().begin(), _students.students().end(), [&name](const gb7_proto::Student &student){
        return std::tie(student.fullname().name(), student.fullname().surname(), student.fullname().patronymic())
                == std::tie(name.name(), name.surname(), name.patronymic());
    });

    if(it == _students.students().end())
        return 0.0;

    return it->avrval();
}

std::string StudentsGroup::GetAllInfo(const gb7_proto::FullName &name)
{
    auto it = std::find_if(_students.students().begin(), _students.students().end(), [&name](const gb7_proto::Student &student){
        return std::tie(student.fullname().name(), student.fullname().surname(), student.fullname().patronymic())
                == std::tie(name.name(), name.surname(), name.patronymic());
    });

    if(it == _students.students().end())
        return "name not found";

    std::stringstream stream;
    stream << "Info:\n";

    stream << "\t" << it->fullname().surname() << ' ' << it->fullname().name() << ' ' << it->fullname().patronymic() << '\n';

    stream << "\t";
    for(auto const &el : it->valuation())
        stream << el << ' ';

    stream << '\n';
    stream << '\t' << it->avrval();

    return stream.str();
}

std::string StudentsGroup::GetAllInfo()
{
    std::stringstream stream;
    for(auto const &el : _students.students())
        stream << GetAllInfo(el.fullname()) << '\n';

    return stream.str();
}

void StudentsGroup::Open()
{
    std::ifstream in("students.bin", std::ios_base::binary);

    if (_students.ParseFromIstream(&in))
        std::cout << "ParseFromIstream OK" << std::endl;
    else
        std::cout << "Error ParseFromIstream" << std::endl;
}

void StudentsGroup::Save()
{
    std::ofstream out("students.bin", std::ios_base::binary);
    _students.SerializeToOstream(&out);
}

gb7_proto::StudentsGroup &StudentsGroup::students()
{
    return _students;
}
