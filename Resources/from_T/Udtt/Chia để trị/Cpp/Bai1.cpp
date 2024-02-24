#include <bits/stdc++.h>
using namespace std;

struct Student
{
    string name;
    string surname;
    int yearOfBirth;
    string address;

    void output()
    {
        cout << name << std::setw(20) << surname << std::setw(20) << yearOfBirth << std::setw(20) << address << endl;
    }
};

void merge(Student list[], int l, int m, int r)
{
    vector<Student> x(list + l, list + m + 1);
    vector<Student> y(list + m + 1, list + r + 1);
    int i = 0, j = 0;

    while (i < x.size() && j < y.size())
    {
        if (x[i].name.compare(y[j].name) <= 0)
        {
            list[l] = x[i];
            i++;
            l++;
        }
        else
        {
            list[l] = y[j];
            j++;
            l++;
        }
    }
    while (i < x.size())
    {
        list[l] = x[i];
        i++;
        l++;
    }
    while (j < y.size())
    {
        list[l] = y[j];
        j++;
        l++;
    }
}

void mergeSort(Student list[], int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    mergeSort(list, l, m);
    mergeSort(list, m + 1, r);
    merge(list, l, m, r);
}

int findStudentByName(Student list[], int l, int r, string name)
{
    if (l > r)
        return -1;
    int m = (l + r) / 2;
    if (list[m].name == name)
    {
        int next = findStudentByName(list, l, m - 1, name);
        return next == -1 ? m : next;
    }
    else if (list[m].name > name)
    {
        return findStudentByName(list, l, m - 1, name);
    }
    return findStudentByName(list, m + 1, r, name);
}

int main()
{
    Student list[6];
    list[0] = {"Thanh", "Nguyen Van", 2003, "Ha Noi"};
    list[1] = {"Hoa", "Nguyen Thi", 2001, "Bac Ninh"};
    list[2] = {"Mai", "Tran Thanh", 2004, "Ha Noi"};
    list[3] = {"Mai", "Do Thi", 2008, "Hai Phong"};
    list[4] = {"Hong", "Nguyen Manh", 2003, "Ha Nam"};
    list[5] = {"Tham", "Vu Van", 1999, "Ha Tay"};

    mergeSort(list, 0, 5);

    for (auto x : list)
    {
        x.output();
    }
    cout << "Nhap ten can tim: ";
    string name;
    cin >> name;
    cout << findStudentByName(list, 0, 5, name) << endl;

    return 0;
}