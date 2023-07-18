#include<iostream>
using namespace std;
#define delimiter "\n__________________________________________________________________\n"

class Human
{
protected:
	string last_name;
	string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	Human(const std::string& last_name, const std::string& first_name, int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor;\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor;\t" << this << endl;
	}

	void print()const
	{
		cout << "Last name: " << last_name << "\t" << "First name: " << first_name << "\t" << "Age: " << age << "years old" << endl;
	}
};

class Student :public Human
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}

	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//	Constructor:
	Student
	(
		const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciality, const std::string& group, double rating, double attendance
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}
	void print()const
	{
		Human::print();
		cout << "Speciality: " << speciality << "\t" << "Group: " << group << "\t" << "Rating: " << rating << "\t" << "Attendance: " << attendance << endl;
	}

};

class Teacher :Human
{
	std::string speciality;
	std::string degree;
	std::string loyalty;
	double experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string get_degree()const
	{
		return degree;
	}
	const std::string get_loyalty()const
	{
		return loyalty;
	}
	double get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_degree(const std::string& degree)
	{
		this->degree = degree;
	}
	void set_loyalty(const std::string& loyalty)
	{
		this->loyalty = loyalty;
	}
	void set_experience(double experience)
	{
		this->experience = experience;
	}
	//		Constructor:
	Teacher
	(
		const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciality, const std::string& degree, const std::string& loyalty, double experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_degree(degree);
		set_loyalty(loyalty);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void print()
	{
		Human::print();
		cout << "speciality: " << speciality << "\t" << "degree: " << degree << "\t" << "loyalty: " << loyalty << "\t" << "experience: " << experience << " years" << endl;
	}
};

class Graduate :public Human, public Student
{
	std::string graduate_work;
	double average_rating;
public:
	const std::string& get_graduate_work()const
	{
		return graduate_work;
	}
	double get_average_rating()const
	{
		return average_rating;
	}
	void set_graduate_work(const std::string& graduate_work)
	{
		this->graduate_work = graduate_work;
	}
	void set_average_rating(double average_rating)
	{
		this->average_rating = average_rating;
	}
	//		Constructor:
	Graduate
	(
		const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciality, const std::string& group, double rating, double attendance,
		const std::string& graduate_work, double average_rating
	) : Human(last_name, first_name,age), Student(last_name, first_name, age, speciality,group,rating,attendance) //Student(speciality, group, rating, attendance)
	{
		set_graduate_work(graduate_work);
		set_average_rating(average_rating);
		cout << "GDestructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	void print()const
	{
		//Human::print();
		Student::print();
		cout << "Graduate work: " << graduate_work << "\t" << "Average rating: " << average_rating << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Human human("Montana", "Antonio", 30);
	human.print();
	cout << delimiter << endl;
	Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 95, 98);
	stud.print();
	cout << delimiter << endl;
	Teacher teacher("Jones", "John", 48, "Physicist", "PhD", "strict", 20);
	teacher.print();
	cout << delimiter << endl;
	Graduate graduate("Clinton", "Bill", 26, "Biology", "DP_223", 85, 70, "Life in ocean", 3.5);
	graduate.print();
	cout << delimiter << endl;
}