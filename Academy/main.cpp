#include<iostream>
#include<fstream>
using namespace std;
#define delimiter "\n__________________________________________________________________\n"

class Human
{
	static const int LAST_NAME_WIDTH = 12;
	static const int FIRST_NAME_WIDTH = 12;
	static const int AGE_WIDTH = 5;
	static int count; // ���������� ����������� ����������

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
		count++;
		cout << "HConstructor;\t" << this << endl;
	}
	virtual ~Human()
	{
		count--;
		cout << "HDestructor;\t" << this << endl;
	}

	virtual std::ostream& print(std::ostream& os)const
	{
		return os << "Last name: " << last_name << "\t" << "First name: " << first_name << "\t" << "Age: " << age << "years old";
	}
	virtual std::ofstream& print(std::ofstream& ofs)const
	{
		ofs.width(LAST_NAME_WIDTH);
		ofs << std::left;
		ofs << last_name;
		ofs.width(FIRST_NAME_WIDTH);
		ofs << std::left;
		ofs << first_name;
		ofs.width(AGE_WIDTH);
		ofs << age;
		return ofs;
	}
};

int Human::count = 0; // ����������� (����������) ����������� ����������

/*std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age() << endl;
}*/
std::ostream& operator<<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	obj.print(ofs);
	return ofs;
}

class Student :public Human
{
	static const int SPECIALITY_WIDTH = 22;
	static const int GROUP_WIDTH = 7;
	static const int RATING_WIDTH = 8;
	static const int ATTENDANCE_WIDTH = 8;
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
	std::ostream& print(std::ostream& os)const
	{
		Human::print(os);
		return os << "Speciality: " << speciality << "\t" << "Group: " << group << "\t" << "Rating: " << rating << "\t" << "Attendance: " << attendance;
	}
	std::ofstream& print(std::ofstream& ofs) const
	{
		Human::print(ofs);
		ofs.width(SPECIALITY_WIDTH);
		ofs << speciality;
		ofs.width(GROUP_WIDTH);
		ofs << group;
		ofs.width(RATING_WIDTH);
		ofs << rating;
		ofs.width(ATTENDANCE_WIDTH);
		ofs << attendance;
		return ofs;
	}
};
//std::ostream& operator<<(std::ostream& os, const Student& obj)
//{
//	return os << obj.get_speciality() << " " << obj.get_group() << " " << obj.get_rating() << " " << obj.get_attendance() << endl;
//}

class Teacher :public Human
{
	static const int SPECIALITY_WIDTH = 22;
	static const int EXPERIENCE_WIDTH = 5;
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
	std::ostream& print(std::ostream& os)const
	{
		Human::print(os);
		return os << speciality << " " << experience;
	}
	std::ofstream& print(std::ofstream ofs)const
	{
		Human::print(ofs);
		ofs.width(SPECIALITY_WIDTH);
		ofs << speciality;
		ofs.width(EXPERIENCE_WIDTH);
		ofs << experience;
		return ofs;
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
	std::ostream& print(std::ostream& os)const
	{
		Student::print(os);
		return os << subject;
	}
};

void print(Human** group, const int n)
{
	cout << "\n---------------------------------------------\n" << endl;
	for (int i = 0; i < n; i++)
	{
		/*cout << typeid(*group[i]).name() << ":\n";
		group[i]->print();*/
		//cout << *group[i] << endl;
		cout << *group[i] << endl;
		cout << "\n---------------------------------------------\n" << endl;
	}
}

void save(Human** group, const int size, const char filename[])
{
	std::ofstream fout(filename);
	for (int i = 0; i < size; i++)fout << *group[i] << endl;
	fout.close();
	std::string command = "start notepad ";
	command += filename;
	system(command.c_str());
}

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

	//cout << "\n---------------------------------------------\n" << endl;
	//for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	//{
	//	/*cout << typeid(*group[i]).name() << ":\n";
	//	group[i]->print();*/
	//	//cout << *group[i] << endl;
	//	cout << *group[i] << endl;
	//	cout << "\n---------------------------------------------\n" << endl;
	//}
	//for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	//{
	//	delete group[i];
	//}
	print(group, sizeof(group) / sizeof(group[0]));
	save(group, sizeof(group) / sizeof(group[0]), "group.txt");

}