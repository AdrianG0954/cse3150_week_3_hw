
#include <iostream>
#include <cstring> // for strlen, strcpy

// TODO: function prototypes

// TODO: implement addStudent
void addStudent(char *name, double gpa, char *names[], double gpas[], int &size, int capacity)
{
    if (size == capacity)
    {
        throw std::string("List full");
    }
    names[size] = name;
    gpas[size] = gpa;
    size++;
}

// TODO: implement updateGPA
void updateGPA(double *gpaPtr, double newGpa)
{
    if (gpaPtr != nullptr)
    {
        *gpaPtr = newGpa;
    }
}

// TODO: implement printStudent
void printStudent(const char *name, const double &gpa)
{
    std::cout << name << ": " << gpa << std::endl;
}

// TODO: implement averageGPA
double averageGPA(const double gpas[], int size)
{
    if (size == 0)
    {
        throw std::string("No students");
    }

    double sum = 0.0;
    for (int i = 0; i < size; ++i)
    {
        sum += gpas[i];
    }
    return sum / size;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char *names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do
    {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // TODO: implement menu logic
            char buff[100];
            double gpa;
            std::cout << "Enter new student and gpa: " << std::endl;
            std::cin >> buff >> gpa;

            char *student = new char[strlen(buff) + 1];
            strcpy(student, buff);
            try
            {
                addStudent(student, gpa, names, gpas, size, capacity);
            }
            catch (const std::string& e)
            {
                std::cout << e << std::endl;
            }
            break;
        }
        case 2:
        {
            // TODO: implement menu logic
            int idx;
            double newGpa;
            std::cout << "Enter idx and new gpa: " << std::endl;
            std::cin >> idx >> newGpa;

            if (idx < 0 || idx >= size)
            {
                throw std::string("index out of bounds");
            }

            updateGPA(&gpas[idx], newGpa);
            break;
        }
        case 3:
        {
            // TODO: implement menu logic
            for (int i = 0; i < size; i++)
            {
                printStudent(names[i], gpas[i]);
            }
            break;
        }
        case 4:
        {
            // TODO: implement menu logic
            try
            {
                std::cout << "Average GPA: " << averageGPA(gpas, size) << std::endl;
            }
            catch (const std::string e)
            {
                std::cout << e << std::endl;
            }
            break;
        }
        case 5:
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        default:
        {
            std::cout << "Invalid choice" << std::endl;
        }
        }
    } while (choice != 5);

    // TODO: free memory
    for (int i = 0; i < size; ++i)
    {
        delete[] names[i];
    }

    return 0;
}
