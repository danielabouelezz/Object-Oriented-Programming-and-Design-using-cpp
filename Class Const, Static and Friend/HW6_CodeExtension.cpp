/*** Sadly current print has 2 issues
        Print to console / Print all content!
     For some reasons, we can't change the code
        Another idea is to extend its functionality!
     Your team lead asked to develop a class that satisfy the following main
        Mainly a new class that works on an object from StudentGradesInfo
        It satisfies 2 critical methods for iterating on the StudentGradesInfo courses:
            HasNext: that tell us if there is more to retrieve
            GetNext: Return actual element in trun to retrieve
        Also Reset method in case we wanna iterate from scratch again
     Develop a class that satisfies this main
***/

#include <bits/stdc++.h>
using namespace std;

class StudentGradesInfo {
private:
	string student_id;
	vector<double> grades;
	vector<string> courses_names;
	const int MAX_GRADE_PER_COURSE = 100.0;
    friend class StudentGradesInfoWhiteBoxTester;
	// It seems developer wants to keep track of how many times this function is called
	// Proper way to maintain a static counter inside the class

	// Side note: in real life, we applications keep track of what users do and analyze it
	// This allows discovering what users do/don't so that we improve their experience
	static int statistics_total_prints;

	// Several issues in this function
	// 1- It is public, although for internal usage! Move to private
	// 2- It doesn't change class variables! Make it const. Another way is just to change it to void AdjustGrade(double & grade)
	// 3- It uses a magic number:
	// A magic number is a numeric literal (for example, 8080 , 2048 ) that is used in the middle of a block of code without explanation.
	// It is considered good practice to avoid magic numbers by assigning the numbers to named constants and using the named constants instead
	// 4- Also: if requirement changed 100 to say 50, we will do a lot of code changes!
	// 5: bug, it should be double not int (in parameter and return)
	// 6: bug in if (grade < 0) => should return 0
	double AdjustGrade(double grade) const {
		if (grade < 0)
			return 0;
		if (grade > MAX_GRADE_PER_COURSE)
			return MAX_GRADE_PER_COURSE;
		return grade;
	}
public:

	// It seems developer wants to prevent users from using empty constructor
	// Just asserting will break the program
	// Removing this constructor will disallow the default constructor!
	//StudentGradesInfo() {
	//	assert(false);
	//}

	// Seems string name_ is not used! Don't add what is not useful!
	// Use initializer list as possible!
	StudentGradesInfo(string student_id) :
			student_id(student_id) {
	}

	bool AddGrade(double grade, const string &course_name) {
		grade = AdjustGrade(grade);

		// Very big bug. A lot of run time errors will happen!
		// needed to move to end of function
		//grades.push_back(grade);

		for (int i = 0; i < (int) courses_names.size(); ++i)
			if (course_name == courses_names[i])
				return false;	// already added

		grades.push_back(grade);
		courses_names.push_back(course_name);

		return true;
	}

	// Make const!
	// Use variables names that are understandable!
	// Good function and variable names are key in clear code
	void PrintAllCourses() const {
		++statistics_total_prints;

		// If there is a getter/setter for a data member, use it
		cout << "Grades for student: " << GetStudentId() << "\n";
		for (int course_idx = 0; course_idx < (int) courses_names.size(); ++course_idx)
			cout << "\t" << courses_names[course_idx] << " = " << grades[course_idx] << "\n";
	}

	// const!
	bool GetCourseGradeInfo(int pos, pair<string, double> &result) const{
		if (pos < 0 || pos >= (int) grades.size()) {
			result = make_pair("", -1);
			return false;
		}
		result = make_pair(courses_names[pos], grades[pos]);
		return true;
	}

	// const!
	string GetStudentId() const {
		return student_id;
	}

	// const!
	int GetTotalCoursesCount() const {
		return grades.size();
	}

	// const!
	pair<double, double> GetTotalGradesSum() const {
		double sum = 0, total = 0;
		for (int grade_idx = 0; grade_idx < (int) grades.size(); ++grade_idx)
			sum += grades[grade_idx], total += MAX_GRADE_PER_COURSE;
		return make_pair(sum, total);
	}
};

int StudentGradesInfo::statistics_total_prints = 0;

class StudentGradesInfoPrinter{
private:
    const StudentGradesInfo &st;
    int printer_Iterator;
public:
    StudentGradesInfoPrinter(const StudentGradesInfo &st):
        st(st), printer_Iterator(-1){}

    bool HasNext() const
    {
        return (printer_Iterator + 1) < st.GetTotalCoursesCount();
    }

    pair<string, double> GetNext()
    {
        ++printer_Iterator;

        pair<string, double> result;
        st.GetCourseGradeInfo(printer_Iterator, result);

        return result;
    }

    void ResetIterator()
    {
        printer_Iterator = -1;
    }
};


int main()
{
    StudentGradesInfo st1("123");
    StudentGradesInfoPrinter printer(st1);

    st1.AddGrade(50, "Math");
    st1.AddGrade(60, "Programming1");

    int limit = 3;
    cout<<"Printing top " <<limit<<" Grades, if available\n";
    while(limit-- && printer.HasNext())
    {
        pair<string, double> result = printer.GetNext();
        cout<<"\t" << result.first << " = " <<result.second <<"\n";
    }

    st1.AddGrade(70, "Algorithms");
    st1.AddGrade(67, "Programming2");

    printer.ResetIterator();
    limit = 3;
    cout<<"\nPrinting top " << limit << " Grades, if available\n";
    while(limit-- && printer.HasNext())
    {
        pair<string, double> result = printer.GetNext();
        cout<<"\t" << result.first << " = " <<result.second <<"\n";
    }

    return 0;
}
