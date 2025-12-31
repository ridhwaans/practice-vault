class School(object):
    def __init__(self):
        self.students = {}

    def add_student(self, name, grade):
        self.students[name] = grade

    def roster(self):
        return [k for k, v in sorted(self.students.items(), key=lambda x: (x[1], x[0]))]

    def grade(self, grade_number):
        return sorted([k for k,v in self.students.items() if v == grade_number])