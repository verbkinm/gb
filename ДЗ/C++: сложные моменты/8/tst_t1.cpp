#include "1/phonebook.h"

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

std::ifstream file("PhoneBook.txt"); // путь к файлу PhoneBook.txt
PhoneBook book(file);

TEST(gb_test, openFile)
{
    std::ifstream file("PhoneBook.txt");
    ASSERT_TRUE(file.is_open());
}

TEST(gb_test, SortByPhone)
{
    book.SortByPhone();

    std::stringstream stream;
    stream << book._db.front().second;

    ASSERT_EQ("+4(940)2556793", stream.str());

    stream.str(std::string());
    stream << book._db.back().second;
    ASSERT_EQ("+493(7637)6114861", stream.str());
}

TEST(gb_test, SortByName)
{
    book.SortByName();

    std::stringstream stream;
    stream << book._db.front().first;

    ASSERT_EQ("        Aleksei        Dubinin   Mikhailovich", stream.str());

    stream.str(std::string());
    stream << book._db.back().first;
    ASSERT_EQ("         Zakhar        Zaitsev     Artemovich", stream.str());
}

TEST(gb_test, GetPhoneNumber)
{
    auto answer = book.GetPhoneNumber("Ivanov");
    ASSERT_EQ("", get<0>(answer));
    answer = book.GetPhoneNumber("Petrov");
    ASSERT_EQ("not found", get<0>(answer));
}

TEST(gb_test, ChangePhoneNumber)
{
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{7, 123, "15344458", std::nullopt});
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber{ 16, 465, "9155448", 13 });

    std::stringstream stream;
    stream << book._db.at(17).second;

    ASSERT_EQ("+7(123)15344458", stream.str());

    stream.str(std::string());
    stream << book._db.at(11).second;
    ASSERT_EQ("+7(273)5699819 5542", stream.str());
}
