/** Requirements:
        Class for a student and his grades per course.
        Grade max is 100 (e.g. 76.5/100)
        Printing functionality or retrieve per course
        Track how many times printing is called.
    Figure out:
        2 coding bugs
        Several OOP violation or design issues.
        Something if we need to change, cause changes in several places
        Naming inconsistency
        2 better variables naming in functions
    Suggest better definition for:
        pair<string, double> GetCourseGradeInfo(int pos)

//Note: the original code is at the end.
**/

#include <bits/stdc++.h>
using namespace std;

class StudentGradesInfo {
private:
	string student_id;
	vector<double> grades;
	vector<string> courses_names;
	const int MAX_GRADE_PER_COURSE = 100.0;

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

int main() {
	StudentGradesInfo st1("S000123");
	st1.AddGrade(70, "Math");
	st1.AddGrade(70, "programming 1");
	st1.AddGrade(85, "programming 2");

	st1.PrintAllCourses();

	pair<double, double> p = st1.GetTotalGradesSum();
	cout << p.first << "/" << p.second << "\n";

	cout << "Bye\n";

	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

int statistics_total_prints = 0;

class StudentGradesInfo {
private:
	string student_id;
	vector<double> grades;
	vector<string> courses_names;
public:

	StudentGradesInfo() {
		assert(false);
	}

	StudentGradesInfo(string name_, string student_id_) {
		student_id = student_id_;
	}

	int AdjustGrade(int grade) {
		if (grade < 0)
			return grade;
		if (grade > 100)
			return 100;
		return grade;
	}
	bool AddGrade(double grade, string course_name) {
		grade = AdjustGrade(grade);
		grades.push_back(grade);

		for (int i = 0; i < (int) courses_names.size(); ++i)
			if(course_name == courses_names[i])
				return false;	// already added
		courses_names.push_back(course_name);
		return true;
	}
	void PrintAllCourses() {
		++statistics_total_prints;

		cout << "Grades for student: " << student_id << "\n";
		for (int i = 0; i < (int) grades.size(); ++i)
			cout << "\t" << courses_names[i] << " = " << grades[i] << "\n";
	}
	pair<string, double> GetCourseGradeInfo(int pos) {
		if (pos < 0 || pos >= (int) grades.size())
			return make_pair("", -1);
		return make_pair(courses_names[pos], grades[pos]);
	}
	string GetStudentId() {
		return student_id;
	}
	int GetTotalCoursesCount() {
		return grades.size();
	}
	// Use GetTotalCoursesCount for naming consistency
	pair<double, double> get_total_gradesSum() {
		double sum = 0, total = 0;
		for (int i = 0; i < (int) grades.size(); ++i)
			sum += grades[i], total += 100;
		return make_pair(sum, total);
	}
};

int main() {
	StudentGradesInfo st1("Mostafa", "S000123");
	st1.AddGrade(70, "Math");
	st1.AddGrade(70, "programming 1");
	st1.AddGrade(85, "programming 2");

	st1.PrintAllCourses();

	pair<double, double> p = st1.get_total_gradesSum();
	cout<<p.first<<"/"<<p.second<<"\n";

	cout<<"Bye\n";

	return 0;
}
*/
