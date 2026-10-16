#include <iostream>
#include <string>

namespace school
{
    class Student
    {
    public:
        Student(int n, const std::string& nm)
        {
            id = n;
            name = nm;
        }

        void show() const
        {
            std::cout << "school::Student: "
                      << id
                      << " "
                      << name
                      << std::endl;
        }

    private:
        int id;
        std::string name;
    };
}

namespace lab
{
    class Student
    {
    public:
        Student(int n, const std::string& topic)
        {
            id = n;
            researchTopic = topic;
        }

        void show() const
        {
            std::cout << "lab::Student: "
                      << id
                      << " "
                      << researchTopic
                      << std::endl;
        }

    private:
        int id;
        std::string researchTopic;
    };
}

int main()
{
    school::Student a(1001, "Tom");
    lab::Student b(2001, "OCTA");

    a.show();
    b.show();

    std::cout << std::endl;
    std::cout << "Two classes have the same name,"
              << " but they belong to different namespaces."
              << std::endl;

    return 0;
}
