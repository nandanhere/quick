public class Student {

  String name, usn, address, category;
  int age;
  //float sgpa1,sgpa2,sgpa3,sgpa4,sgpa5,sgpa6,sgpa7,sgpa8;
  float cgpa;

  public Student(
    String name,
    String usn,
    String address,
    String cat,
    int age,
    float cgpa
  ) {
    this.name = name;
    this.usn = usn;
    this.address = address;
    this.category = cat;
    this.age = age;
    this.cgpa = cgpa;
  }

  public String toString() {
    String stud =
      name +
      " " +
      usn +
      " residing in " +
      address +
      "belonging to category" +
      category +
      " of age " +
      age;
    stud += "has cgpa " + cgpa;
    return stud;
  }
}
