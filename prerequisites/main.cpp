#include <iostream>
#include <sstream>
#include "vector"
#include <algorithm>
using namespace std;

int main() {
    while (true){
        //Get the input
        string temp = {};
        getline(cin, temp);
        stringstream ss3 (temp);

        //Store it, if its "0" then exit
        int courses_count = 0, categories_count = 0;
        ss3 >> courses_count >> categories_count;

        if (courses_count == 0) break;

        //Store freddies courses
        vector <string> freddies_courses;
        getline(cin, temp);
        stringstream ss (temp);
        while (ss >> freddies_courses.emplace_back()){}

        //Check if freddie meets the requirements for each category
        bool meets_requirements = true;
        for (int i = 0; i < categories_count; ++i) {
            int courses_in_category = 0, required_courses = 0;
            getline(cin, temp);
            stringstream ss2 (temp);

            ss2 >> courses_in_category >> required_courses;
            string category_course;
            for (int j = 0; j < courses_in_category; ++j) {
                ss2 >> category_course;
                //Can we find this course in freddies courses?
                if (find(freddies_courses.begin(), freddies_courses.end(), category_course) != freddies_courses.end())
                {
                    required_courses--;
                }
            }

            //If we didn't meet the requirements for this category, we can't graduate
            if (required_courses > 0) meets_requirements = false;
        }

        if(meets_requirements){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}
