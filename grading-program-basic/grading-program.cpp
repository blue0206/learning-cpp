#include <iostream>
#include <cstdlib>

using namespace std;

class Grade
{
    public:
        Grade();
        void input();
        void output();
    private:
        double quiz1;
        double quiz2;
        double midterm;
        double final_exam;
        double quiz_weight;
        double midterm_weight;
        double final_exam_weight;
        double grade_score;
        char grade;
        void input_check();
        void total();
        void grade_assign();
};

int main()
{
    while (true)
    {
        Grade blue;
        blue.output();
        blue.input();
        blue.output();

        char prompt {};
        cout << "Run again? (Y/N): ";
        cin >> prompt;
        if (prompt == 'n' || prompt == 'N')
        {
            break;
        }
    }

    return 0;
}

Grade::Grade()
{
    quiz1 = 0;
    quiz2 = 0;
    midterm = 0;
    final_exam = 0;
}

void Grade::input()
{
    cout << "Enter Quiz 1 Score (Out of 10):\n";
    cin >> quiz1;
    cout << "Enter Quiz 2 Score (Out of 10):\n";
    cin >> quiz2;
    cout << "Enter Midterm Score (Out of 100):\n";
    cin >> midterm;
    cout << "Enter Final Exam Score (Out of 100):\n";
    cin >> final_exam;
    input_check();
}

void Grade::input_check()
{
    if (quiz1 < 0 || quiz2 < 0 || midterm < 0 || final_exam < 0 ||
        quiz1 > 10 || quiz2 > 10 || midterm > 100 || final_exam > 100)
    {
        cout << "Illegal score input. Aborting program.\n";
        exit (1);
    }
}

void Grade::total()
{
    quiz_weight = ((quiz1 + quiz2) * 25.0) / 100.0;
    midterm_weight = (midterm * 25.0) / 100.0;
    final_exam_weight = (final_exam * 50.0) / 100.0;
    grade_score = quiz_weight + midterm_weight + final_exam_weight;
}

void Grade::grade_assign()
{
    if (grade_score >= 90)
    {
        grade = 'A';
    }
    else if (grade_score >= 80)
    {
        grade = 'B';
    }
    else if (grade_score >= 70)
    {
        grade = 'C';
    }
    else if (grade_score >= 60)
    {
        grade = 'D';
    }
    else
    {
        grade = 'F';
    }
}

void Grade::output()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "The student grades are as follows:\n"
        << "\tQuiz 1: " << quiz1 << '\n'
        << "\tQuiz 2: " << quiz2 << '\n'
        << "\tMidterm: " << midterm << '\n'
        << "\tFinal Exam: " << final_exam << '\n';
    
    cout << "The final result is as follows:\n";
    total();
    grade_assign();

    cout << "\tTotal Weighted Score: " << grade_score << '\n'
        << "\tGrade: " << grade << '\n';
    if (grade == 'F')
    {
        cout << "\nThe student is FAIL.\n";
    }
    else
    {
        cout << "\nThe student is PASS.\n";
    }
}
