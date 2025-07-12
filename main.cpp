#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <cassert>
#include <cstdlib>


using namespace std;
vector<string> code_; //code
vector<string> name_; //name
vector<string> age_; //age
vector<string> gender_;// gender
vector<double> chem_;
vector<double> draw_;
vector<double> comp_;
vector<double> math_;
vector<double> phy_;
string chem_g[9];
string draw_g[9];
string comp_g[9];
string math_g[9];
string phy_g[9];
string code, name, gender, age;
string math, comp, draw, chem, phy;
string c;

class student
{
private:
    vector<string> code_; //code
    vector<string> name_; //name
    vector<string> age_; //age
    vector<string> gender_;// gender
public:
    void Open_File()
    {
        ifstream myfile("studentsData.csv");

        if (myfile.is_open())
        {
            cout << "the file is successfully open and it contains\n" << endl;
        }
        string line;
        getline(myfile, line);
        while (!myfile.eof())
        {

            getline(myfile, code, ',');
            code_.push_back(code);
            getline(myfile, name, ',');
            name_.push_back(name);
            getline(myfile, age, ',');
            age_.push_back(age);
            getline(myfile, gender, '\n');
            gender_.push_back(gender);
        }

        cout << "CODE" << "\t" << "NAME" << "\t" << "        age" << "  \t" << "gender\n" << endl;
        for (int j = 0; j < 9; j++) { cout << code_[j] << "\t" << name_[j] << "\t" << age_[j] << "\t" << gender_[j] << "\n" << endl; }

        myfile.close();
    }
    void Open_Grades()
    {
        ifstream myotherfile("studentsGrade.csv");
        if (myotherfile.is_open())
        {
            cout << "the file is successfully open and it contains\n" << endl;
        }
        string line;
        getline(myotherfile, line);

        while (!myotherfile.eof())
        {
            getline(myotherfile, code, ',');
            code_.push_back(code);
            getline(myotherfile, math, ',');
            math_.push_back(stoi(math));
            getline(myotherfile, phy, ',');
            phy_.push_back(stoi(phy));
            getline(myotherfile, draw, ',');
            draw_.push_back(stoi(draw));
            getline(myotherfile, comp, ',');
            comp_.push_back(stoi(comp));
            std::getline(myotherfile, chem, '\n');
            chem_.push_back(stoi(chem));
        }

        myotherfile.close();
        for (int j = 0; j < 9; j++)
        {
            cout << code_[j] << "\t" << math_[j] << "\t" << draw_[j] << "\t" << phy_[j] << "\t" << comp_[j] << "\t" << chem_[j] << endl;
        }
    }
    void Create_File()
    {
        ofstream myfilee;
        myfilee.open("read_me.csv");
        for (unsigned i = 0; i < 1; i++) {
            myfilee << "code" << "," << "name" << "," << "math" << "," << "draw" << "," << "physics" << "," << "computer" << "," << "chemistry" << endl;
        }
        for (unsigned i = 0; i < 9; i++) {
            myfilee << code_[i] << "," << name_[i] << "," << math_g[i] << "," << draw_g[i] << "," << phy_g[i] << "," << comp_g[i] << "," << chem_g[i] << endl;
        }
    }

    void inf_data(string std_id)

    {

        for (int i = 0; i < 9; i++)
        {
            if (std_id == code_[i])
            {
                cout << "Student's Information: \n";
                cout << "Student's code:   " << code_[i] << endl;
                cout << "Student's Name:   " << name_[i] << endl;
                cout << "Student's Age:    " << age_[i] << endl;
                cout << "Student's Gender:  " << gender_[i] << endl;
                cout << "Student's Grades : \n\n";
                cout << "Math      : " << math_[i] << "  (" << math_g[i] << ")" << endl;
                cout << "Physics   : " << phy_[i] << "  (" << phy_g[i] << ")" << endl;
                cout << "Drawing   : " << draw_[i] << "  (" << draw_g[i] << ")" << endl;
                cout << "Computer  : " << comp_[i] << "  (" << comp_g[i] << ")" << endl;
                cout << "Chemistry : " << chem_[i] << "  (" << chem_g[i] << ")\n" << endl;
            }
        }
    }


    void inf_grades(string std_id)

    {

        for (int i = 0; i < 9; i++)
        {
            if (std_id == code_[i])
            {
                cout << "Student's code:   " << code_[i] << endl;
                cout << "Student's Name:   " << name_[i] << endl;
                cout << "Student's Grades : \n\n";
                cout << "Math      : " << math_[i] << "  (" << math_g[i] << ")" << endl;
                cout << "Physics   : " << phy_[i] << "  (" << phy_g[i] << ")" << endl;
                cout << "Drawing   : " << draw_[i] << "  (" << draw_g[i] << ")" << endl;
                cout << "Computer  : " << comp_[i] << "  (" << comp_g[i] << ")" << endl;
                cout << "Chemistry : " << chem_[i] << "  (" << chem_g[i] << ")\n" << endl;
            }
        }
    }
};

void statistics_chem()
{
    float counter_chemistry_A = 0;
    float counter_chemistry_B_plus = 0;
    float counter_chemistry_B = 0;
    float counter_chemistry_C_plus = 0;
    float counter_chemistry_C = 0;
    float counter_chemistry_D_plus = 0;
    float counter_chemistry_D = 0;
    float counter_chemistry_F = 0;

    for (int i = 0; i < 9; i++)
    {
        if (chem_[i] >= 90) { counter_chemistry_A += 1; }
        else if (chem_[i] > 90 && chem_[i] >= 85) { counter_chemistry_B_plus += 1; }
        else if (chem_[i] < 85 && chem_[i] >= 80) { counter_chemistry_B += 1; }
        else if (chem_[i] > 80 && chem_[i] >= 75) { counter_chemistry_C_plus += 1; }
        else if (chem_[i] > 75 && chem_[i] >= 70) { counter_chemistry_C += 1; }
        else if (chem_[i] > 70 && chem_[i] >= 65) { counter_chemistry_D_plus += 1; }
        else if (chem_[i] > 65 && chem_[i] >= 60) { counter_chemistry_D += 1; }
        else { counter_chemistry_F += 1; }
    }
    cout << " Percentage of Students who got A in Chemistry = " << (counter_chemistry_A / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got B+ in Chemistry = " << (counter_chemistry_B_plus / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got B in Chemistry = " << (counter_chemistry_B / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got C+ in Chemistry = " << (counter_chemistry_C_plus / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got C in Chemistry = " << (counter_chemistry_C / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got D+ in Chemistry = " << (counter_chemistry_D_plus / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got D in Chemistry = " << (counter_chemistry_D / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got F in Chemistry = " << (counter_chemistry_F / 9) * 100 << "%" << endl;

}

void statistics_draw()
{
    float counter_drawing_A = 0;
    float counter_drawing_B_plus = 0;
    float counter_drawing_B = 0;
    float counter_drawing_C_plus = 0;
    float counter_drawing_C = 0;
    float counter_drawing_D_plus = 0;
    float counter_drawing_D = 0;
    float counter_drawing_F = 0;

    for (int i = 0; i < 9; i++)
    {
        if (draw_[i] >= 90) { counter_drawing_A += 1; }
        else if (draw_[i] > 90 && draw_[i] >= 85) { counter_drawing_B_plus += 1; }
        else if (draw_[i] < 85 && draw_[i] >= 80) { counter_drawing_B += 1; }
        else if (draw_[i] > 80 && draw_[i] >= 75) { counter_drawing_C_plus += 1; }
        else if (draw_[i] > 75 && draw_[i] >= 70) { counter_drawing_C += 1; }
        else if (draw_[i] > 70 && draw_[i] >= 65) { counter_drawing_D_plus += 1; }
        else if (draw_[i] > 65 && draw_[i] >= 60) { counter_drawing_D += 1; }
        else { counter_drawing_F += 1; }
    }
    cout << " Percentage of Students who got A in Drawing = " << (counter_drawing_A / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got B+ in Drawing = " << (counter_drawing_B_plus / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got B in Drawing = " << (counter_drawing_B / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got C+ in Drawing = " << (counter_drawing_C_plus / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got C in Drawing = " << (counter_drawing_C / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got D+ in Drawing = " << (counter_drawing_D_plus / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got D in Drawing = " << (counter_drawing_D / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got F in Drawing = " << (counter_drawing_F / 9) * 100 << "%" << endl;
    cout << "\n\n";
}

void statistics_phy()
{
    float counter_physics_A = 0;
    float counter_physics_B_plus = 0;
    float counter_physics_B = 0;
    float counter_physics_C_plus = 0;
    float counter_physics_C = 0;
    float counter_physics_D_plus = 0;
    float counter_physics_D = 0;
    float counter_physics_F = 0;


    for (int i = 0; i < 9; i++)
    {
        if (phy_[i] >= 90) { counter_physics_A += 1; }
        else if (phy_[i] > 90 && phy_[i] >= 85) { counter_physics_B_plus += 1; }
        else if (phy_[i] < 85 && phy_[i] >= 80) { counter_physics_B += 1; }
        else if (phy_[i] > 80 && phy_[i] >= 75) { counter_physics_C_plus += 1; }
        else if (phy_[i] > 75 && phy_[i] >= 70) { counter_physics_C += 1; }
        else if (phy_[i] > 70 && phy_[i] >= 65) { counter_physics_D_plus += 1; }
        else if (phy_[i] > 65 && phy_[i] >= 60) { counter_physics_D += 1; }
        else { counter_physics_F += 1; }

    }

    cout << " Percentage of Students who got A in Physics = " << (counter_physics_A / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got B+ in Physics = " << (counter_physics_B_plus / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got B in Physics = " << (counter_physics_B / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got C+ in Physics = " << (counter_physics_C_plus / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got C in Physics = " << (counter_physics_C / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got D+ in Physics = " << (counter_physics_D_plus / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got D in Physics = " << (counter_physics_D / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got F in Physics = " << (counter_physics_F / 9) * 100 << "%" << endl;
    cout << "\n\n";
}

void statistics_comp()

{
    float counter_computer_A = 0;
    float counter_computer_B_plus = 0;
    float counter_computer_B = 0;
    float counter_computer_C_plus = 0;
    float counter_computer_C = 0;
    float counter_computer_D_plus = 0;
    float counter_computer_D = 0;
    float counter_computer_F = 0;

    for (int i = 0; i < 9; i++)
    {
        if (comp_[i] >= 90) { counter_computer_A += 1; }
        else if (comp_[i] > 90 && comp_[i] >= 85) { counter_computer_B_plus += 1; }
        else if (comp_[i] < 85 && comp_[i] >= 80) { counter_computer_B += 1; }
        else if (comp_[i] > 80 && comp_[i] >= 75) { counter_computer_C_plus += 1; }
        else if (comp_[i] > 75 && comp_[i] >= 70) { counter_computer_C += 1; }
        else if (comp_[i] > 70 && comp_[i] >= 65) { counter_computer_D_plus += 1; }
        else if (comp_[i] > 65 && comp_[i] >= 60) { counter_computer_D += 1; }
        else { counter_computer_F += 1; }
    }

    cout << " Percentage of Students who got A in Computer = " << (counter_computer_A / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got B+ in Computer = " << (counter_computer_B_plus / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got B in Computer = " << (counter_computer_B / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got C+ in Computer = " << (counter_computer_C_plus / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got C in Computer = " << (counter_computer_C / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got D+ in Computer = " << (counter_computer_D_plus / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got D in Computer = " << (counter_computer_D / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got F in Computer = " << (counter_computer_F / 9) * 100 << "%" << endl;
    cout << "\n\n";

}

void statistics_math()
{
    float counter_math_A = 0;
    float counter_math_B_plus = 0;
    float counter_math_B = 0;
    float counter_math_C_plus = 0;
    float counter_math_C = 0;
    float counter_math_D_plus = 0;
    float counter_math_D = 0;
    float counter_math_F = 0;

    for (int i = 0; i < 9; i++)
    {
        if (math_[i] >= 90) { counter_math_A += 1; }
        else if (math_[i] > 90 && math_[i] >= 85) { counter_math_B_plus += 1; }
        else if (math_[i] < 85 && math_[i] >= 80) { counter_math_B += 1; }
        else if (math_[i] > 80 && math_[i] >= 75) { counter_math_C_plus += 1; }
        else if (math_[i] > 75 && math_[i] >= 70) { counter_math_C += 1; }
        else if (math_[i] > 70 && math_[i] >= 65) { counter_math_D_plus += 1; }
        else if (math_[i] > 65 && math_[i] >= 60) { counter_math_D += 1; }
        else { counter_math_F += 1; }
    }

    cout << " Percentage of Students who got A in Maths = " << (counter_math_A / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got B+ in Maths = " << (counter_math_B_plus / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got B in Maths = " << (counter_math_B / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got C+ in Maths = " << (counter_math_C_plus / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got C in Maths = " << (counter_math_C / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got D+ in Maths = " << (counter_math_D_plus / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got D in Maths = " << (counter_math_D / 9) * 100 << "%" << endl;
    cout << " Percentage of Students who got F in Maths = " << (counter_math_F / 9) * 100 << "%" << endl;
    cout << "\n\n";
}


void normalizing_student(vector <double> course_, int z)
{

    double y = 0, SD = 0, mean = 0, sum = 0, o[10]{};
    vector <double> normalize;
    for (int i = 0; i < 9; i++)
    {
        sum = course_[i] + sum;

    }

    mean = sum / 9;

    for (int i = 0; i < 9; i++)
    {
        y = pow((course_[i] - mean), 2) + y;
    }
    SD = pow((y / 9), 0.5);

    for (int i = 0; i < 9; i++)
    {
        o[i] = (course_[i] - mean) / SD;
        //cout << o[i] << "    ";
    }    cout << o[z] << endl;
}


void normalizing(vector <double> course_)
{

    double y = 0, SD = 0, mean = 0, sum = 0, o[10]{};
    vector <double> normalize;
    for (int i = 0; i < 9; i++)
    {
        sum = course_[i] + sum;

    }

    mean = sum / 9;

    for (int i = 0; i < 9; i++)
    {
        y = pow((course_[i] - mean), 2) + y;
    }
    SD = pow((y / 9), 0.5);

    for (int i = 0; i < 9; i++)
    {
        o[i] = (course_[i] - mean) / SD;
        cout << o[i] << "    ";
    }

}

void calculate_grades(vector<double> mark, string  p[])
{
    for (unsigned i = 0; i < 9; i++)
    {
        if (mark[i] >= 90)
        {
            p[i] = "A";
        }
        else if (85 < mark[i] && mark[i] <= 90)
        {
            p[i] = "B+";
        }
        else if (80 < mark[i] && mark[i] <= 85)
        {
            p[i] = "B";
        }
        else if (75 < mark[i] && mark[i] <= 80)
            p[i] = "C+ ";
        else if (70 < mark[i] && mark[i] <= 75)
            p[i] = "C";
        else if (65 < mark[i] && mark[i] <= 70)
            p[i] = "D+";
        else if (60 < mark[i] && mark[i] <= 65) {
            p[i] = "D";
        }
        else if (mark[i] <= 60) {
            p[i] = "F";
        }
        else p[i] = "eror";

    }

}

void print_normalized_data(vector<double> course_, string s)
{
    cout << "Normalized data for " << s << " : " << endl;
    normalizing(course_);
    cout << endl;
}

int main()
{
    student students;
    int choice1 = 0, choice3 = 0, choice2 = 0;
    string ID;
    students.Open_File();
    students.Open_Grades();
    calculate_grades(math_, math_g);
    calculate_grades(chem_, chem_g);
    calculate_grades(phy_, phy_g);
    calculate_grades(comp_, comp_g);
    calculate_grades(draw_, draw_g);
    do
    {
    cout << "\n\n welcome to our program, type a number to start program : \n 1-student 2-instructor\n" << endl;
    cin >> choice1;



    if (choice1 == 1) {

        cout << "type your personal ID in capital letters" << endl;
        cin >> ID;
        students.inf_grades(ID);
    }


    else if (choice1 == 2) {

        do {

            cout << "\n\ndo you want to?\n\n 1- import students' personal information\n 2-import students' GPA grades\n 3-import normalized grades\n 4-import a course statistics\n 5-create a csv file of all your student's data\n or type (0) to exit\n or type(00) to restart the program" << endl;
            cin >> choice2;

            if (choice2 == 1) {
                cout << "type the student personal ID in capital letters" << endl;
                cin >> ID;
                students.inf_data(ID);
            }

            else if (choice2 == 2) {

                cout << "choose a course to import its information\n 1-Math 2-Chemistry 3-physics 4-Drawing 5- computer\n or type (0) to exit\n or type(00) to restart the program" << endl;
                cin >> choice3;

                if (choice3 == 1)
                {
                    calculate_grades(math_, math_g);

                    for (unsigned i = 0; i < 9; i++)
                    {
                        cout << math_g[i] << "    ";
                    }


                }
                else if (choice3 == 2)
                {
                    calculate_grades(chem_, chem_g);

                    for (unsigned i = 0; i < 9; i++)
                    {
                        cout << chem_g[i] << "    ";

                    }
                }
                else if (choice3 == 3)
                {
                    calculate_grades(phy_, phy_g);

                    for (unsigned i = 0; i < 9; i++)
                    {
                        cout << phy_g[i] << "    ";

                    }
                }
                else if (choice3 == 5)
                {
                    calculate_grades(comp_, comp_g);

                    for (unsigned i = 0; i < 9; i++)
                    {
                        cout << comp_g[i] << "    ";

                    }
                }
                else if (choice3 == 4)
                {
                    calculate_grades(draw_, draw_g);

                    for (unsigned i = 0; i < 9; i++)
                    {
                        cout << draw_g[i] << "    ";

                    }
                }

                else if (choice3 == 0) {} // to exit

            }

            else if (choice2 == 3)
            {

                cout << "choose a course to import its normalized information\n 1-Math 2-Chemistry 3-physics 4-Drawing 5-computer\n or type (0) to exit \n or type(00) to restart the program\t" << endl;
                cin >> choice3;

                if (choice3 == 1)
                {
                    print_normalized_data(math_, "math");

                }
                else if (choice3 == 2)
                {
                    print_normalized_data(chem_, "chemistry");
                }
                else if (choice3 == 3)
                {
                    print_normalized_data(phy_, "physics");
                }
                else if (choice3 == 4)
                {
                    print_normalized_data(draw_, "drawing");
                }
                else if (choice3 == 5)
                {
                    print_normalized_data(comp_, "computer");
                }
                else if (choice3 == 0) {} // to exit

            }


            else if (choice2 == 4)

            {
                cout << "choose a course to import its statistics\n 1-Math 2-Chemistry 3-physics 4-Drawing 5-computer\n or type (0) to exit\n or type(00) to restart the program\t" << endl;
                cin >> choice3;

                if (choice3 == 1)
                {
                    statistics_math();
                }
                else if (choice3 == 2)
                {
                    statistics_chem();
                }
                else if (choice3 == 3)
                {
                    statistics_phy();
                }
                else if (choice3 == 4)
                {
                    statistics_draw();
                }
                else if (choice3 == 5)
                {
                    statistics_comp();
                }
                else if (choice3 == 0) {} // to exit
            }

            else if (choice2 == 5) {
                cout << "a csv file called (read me) has been created successfully! " << endl;
                students.Create_File();

            }
        } while (choice2 != 0);
    }
    } while (choice1 != 00 || choice2 != 00 || choice3 != 00);

    return 0;
}
