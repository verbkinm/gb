#include <numeric>

#include "gb7.pb.h"
#include "studentsgroup.h"

using namespace std;

int main()
{
    StudentsGroup studentGroup;

    auto st1 = studentGroup.students().add_students();
    auto st2 = studentGroup.students().add_students();

    gb7_proto::FullName *fl1 = new gb7_proto::FullName;
    gb7_proto::FullName *fl2 = new gb7_proto::FullName;

    fl1->set_name("Вася");
    fl1->set_surname("Пупкин");
    fl1->set_patronymic("Иванович");

    fl2->set_name("Donald");
    fl2->set_surname("Trump");

    st1->set_allocated_fullname(fl1);

    st1->add_valuation(5);
    st1->add_valuation(4);
    st1->add_valuation(3);

    st1->set_avrval(accumulate(st1->valuation().begin(), st1->valuation().end(), 0) / st1->valuation_size());

    st2->set_allocated_fullname(fl2);

    st2->add_valuation(2);
    st2->add_valuation(4);
    st2->add_valuation(3);

    st2->set_avrval(accumulate(st2->valuation().begin(), st2->valuation().end(), 0) / st2->valuation_size());

    studentGroup.Save();
    studentGroup.Open();

    cout << studentGroup.GetAllInfo();

    return 0;
}
