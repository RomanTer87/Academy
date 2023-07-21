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
	virtual ~Human()
	{
		cout << "HDestructor;\t" << this << endl;
	}

	virtual void print()const
	{
		cout << "Last name: " << last_name << "\t" << "First name: " << first_name << "\t" << "Age: " << age << "years old" << endl;
	}
};

 std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << endl;
}

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
std::ostream& operator<<(std::ostream& os, const Student& obj)
{
	return os << obj.get_speciality() << " " << obj.get_group() << " " << obj.get_rating() << " " << obj.get_attendance() << endl;
}

class Teacher :public Human
{
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}
	Teacher
	(
		const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciality, int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	void print()const
	{
		Human::print();
		cout << speciality << " " << experience << endl;
	}
};

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	Graduate
	(
		const std::string& last_name, const std::string& first_name, int age,
		const std::string& speciality, const std::string& group, double rating, double attendance,
		const std::string& subject
	) :Student(last_name, first_name, age, speciality, group, rating, attendance)
	{
		set_subject(subject);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDenstructor:\t" << this << endl;
	}
	void print()const
	{
		Student::print();
		cout << subject << endl;
	}
};

//#define INHERITANCE
void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE
	Human human("Montana", "Antonio", 30);
	human.print();
	cout << delimiter << endl;
	Student stud("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 95, 98);
	stud.print();
	cout << delimiter << endl;
	Teacher teacher("White", "Walter", 50, "Chemistry", 20);
	teacher.print();
	cout << delimiter << endl;
	Graduate grad("Schrader", "Hank", 40, "Criminalistic", "OBN", 50, 50, "How to catch Heisenberg");
	grad.print();
	cout << delimiter << endl;
#endif // inheritance


	Human* group[] =
	{
	new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 95, 98),
	new Teacher("White", "Walter", 50, "Chemistry", 20),
	new Graduate("Schrader", "Hank", 40, "Criminalistic", "OBN", 50, 50, "How to catch Heisenberg")
	};

	cout << "\n---------------------------------------------\n" << endl;
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		/*cout << typeid(*group[i]).name() << ":\n";
		group[i]->print();*/
		cout << *group[i] << endl;
		cout << "\n---------------------------------------------\n" << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
}