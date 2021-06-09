#include <iostream>
#include"sorted_list.h"
#include <string>
using namespace std;

int main()
{
    SortedList<int> my_favorite_numbers;
    SortedList<string> my_favorite_names;

    my_favorite_numbers.Add(13);
    my_favorite_numbers.Add(42);
    my_favorite_numbers.Add(23);
    my_favorite_numbers.Add(2);
    my_favorite_numbers.Add(1);
    my_favorite_numbers.Print();
    my_favorite_numbers.Sort();
    my_favorite_numbers.Print();


    my_favorite_names.Add("landon");
    my_favorite_names.Add("Alex");
    my_favorite_names.Add("Nikhil");
    my_favorite_names.Add("sidra");
    my_favorite_names.Print();
    my_favorite_names.Sort();
    my_favorite_names.Print();


}


