/*** In black box testing, we test the public functionality fo a class:
        Focus on what not how
        No-care of internals
     Develop a class that test our previous class
        Try the old code
        Then the fixed code
***/

#include <bits/stdc++.h>

using namespace std;

class StudentGradesInfo {
private:
	string student_id;
	vector<double> grades;
	vector<string> courses_names;
	const int MAX_GRADE_PER_COURSE = 100.0;
	static int statistics_total_prints;


	double AdjustGrade(double grade) const{
		if (grade < 0)
			return 0;
		if (grade > MAX_GRADE_PER_COURSE)
			return MAX_GRADE_PER_COURSE;
		return grade;
	}

public:
	StudentGradesInfo(string student_id_):
		student_id(student_id_){}


	bool AddGrade(double grade, const string &course_name) {
		grade = AdjustGrade(grade);

		for (int i = 0; i < (int) courses_names.size(); ++i)
			if(course_name == courses_names[i])
				return false;	// already added
        grades.push_back(grade);
		courses_names.push_back(course_name);
		return true;
	}
	void PrintAllCourses() const{
		++statistics_total_prints;

		cout << "Grades for student: " << GetStudentId() << "\n";
		for (int i = 0; i < (int) grades.size(); ++i)
			cout << "\t" << courses_names[i] << " = " << grades[i] << "\n";
	}
	bool GetCourseGradeInfo(int pos, pair<string, double> &result) const{
		if (pos < 0 || pos >= (int) grades.size())
        {
            result = make_pair("", -1);
			return false;
        }
        result = make_pair(courses_names[pos], grades[pos]);
		return true;
	}
	string GetStudentId() const{
		return student_id;
	}
	int GetTotalCoursesCount() const{
		return grades.size();
	}
	// Use GetTotalCoursesCount for naming consistency
	pair<double, double> GetTotalGradesSum() const{
		double sum = 0, total = 0;
		for (int i = 0; i < (int) grades.size(); ++i)
			sum += grades[i], total += MAX_GRADE_PER_COURSE;
		return make_pair(sum, total);
	}
};

int StudentGradesInfo::statistics_total_prints = 0;

class StudentGradesInfoBlackBoxTester{
private:
    const int MAX_GRADE_PER_COURSE = 100.0;
public:
    void Test_TotalCoursesCount()
    {
        cout<<__func__<<"\n";


        StudentGradesInfo st1("123");
        assert(st1.GetStudentId() == "123");
        StudentGradesInfo st2("225");
        assert(st2.GetStudentId() == "225");
        StudentGradesInfo st3("222");
        assert(st3.GetStudentId() == "222");

        st1.AddGrade(24.5, "Programming 1");
        assert(st1.GetTotalCoursesCount() == 1);
        st1.AddGrade(99, "Programming 2");
        assert(st1.GetTotalCoursesCount() == 2);
        st1.AddGrade(45.22, "Calculus 3");
        assert(st1.GetTotalCoursesCount() == 3);

        st2.AddGrade(66, "Programming 1");
        assert(st2.GetTotalCoursesCount() == 1);
        st2.AddGrade(88.23, "Programming 2");


    }

    void Test_TotalGradesSum() {
		cout << __func__ << "\n";
		pair<double, double> p;

		StudentGradesInfo st1("S000123");
		p = st1.GetTotalGradesSum();
		assert(p.first == 0);
		assert(p.second == 0);

		st1.AddGrade(200, "Math");
		p = st1.GetTotalGradesSum();
		assert(p.first == MAX_GRADE_PER_COURSE);
		assert(p.second == MAX_GRADE_PER_COURSE);

		st1.AddGrade(70, "programming 1");
		p = st1.GetTotalGradesSum();
		assert(p.first == 70 + MAX_GRADE_PER_COURSE);
		assert(p.second == 2 * MAX_GRADE_PER_COURSE);

		// If readded, make sure not updated
		st1.AddGrade(60, "programming 1");	// try lower
		p = st1.GetTotalGradesSum();
		assert(p.first == 70 + MAX_GRADE_PER_COURSE);
		assert(p.second == 2 * MAX_GRADE_PER_COURSE);

		// If readded, make sure not updated
		st1.AddGrade(80, "programming 1");	// try bigger
		p = st1.GetTotalGradesSum();
		assert(p.first == 70 + MAX_GRADE_PER_COURSE);
		assert(p.second == 2 * MAX_GRADE_PER_COURSE);

		st1.AddGrade(85, "programming 2");
		p = st1.GetTotalGradesSum();
		assert(p.first == 85 + 70 + MAX_GRADE_PER_COURSE);
		assert(p.second == 3 * MAX_GRADE_PER_COURSE);

		if (false) {
			// This will fail. We should handle the code to not be case sensetive!
			st1.AddGrade(85, "PROGramming 2");
			p = st1.GetTotalGradesSum();
			assert(p.first == 85 + 70 + MAX_GRADE_PER_COURSE);
			assert(p.second == 3 * MAX_GRADE_PER_COURSE);
		}

	}

    void Test_GetCourseGradeInfo() {
		cout << __func__ << "\n";
		StudentGradesInfo st1("S000123");
		assert(st1.GetTotalCoursesCount() == 0);
		st1.AddGrade(200, "Math");
		st1.AddGrade(70, "programming 1");

		pair<string, double> result;
		assert(st1.GetCourseGradeInfo(st1.GetTotalCoursesCount(), result) == false);
		assert(st1.GetCourseGradeInfo(-5, result) == false);

		st1.GetCourseGradeInfo(0, result);
		assert(result.first == "Math");
		assert(result.second == MAX_GRADE_PER_COURSE);

		st1.GetCourseGradeInfo(1, result);
		assert(result.first == "programming 1");
		assert(result.second == 70);
	}

	void Test_PrintAllCourses() {
		cout << __func__ << "\n";
		/// This function is writing to console! How to test?
		/// 1) use Freopen to direct output to file
		/// 2) read file content
		/// 3) compare to what you expect!
	}

    void TestAll()
    {
        Test_TotalCoursesCount();
        Test_TotalGradesSum();
        Test_GetCourseGradeInfo();
        Test_PrintAllCourses();
    }
};

int main()
{
    StudentGradesInfoBlackBoxTester().TestAll();

    return 0;
}
