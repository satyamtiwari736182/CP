from abc import ABC,abstractmethod
from dataclasses import dataclass,field
import heapq as heap

class AbstractSample(ABC):
    @abstractmethod
    def abstractMethodSample(self):
        pass

class Sample(AbstractSample):
    __address = "Jaigaon" #! private variable in true sense
    _protected_var = "Protected Variable"   #! protected variable by convention

    name="Class Name Sample"  #! public class variable

    def __init__(self, name): # Constructor
        self.__name = name

    def greet(self):
        return f"Hello, {self.name}!, Address: {self.__address}"
    
    def get_address(self):
        return self.__address
    
    @classmethod
    def classMethod(cls):
        return f"This is a class method {cls.name}"
    
    def instanceMethod(self):
        return f"This is an instance method {self.name}"
    
    @staticmethod
    def staticMethod(): #! Utility methods. No access to self or cls .
        return "This is a static method"

    # @abstractmethod
    # def abstractMethod(self):
    #     print("This is a normal method, not abstract")
    
    def abstractMethodSample(self):
        print("This is an abstract method implementation in subclass")

@dataclass
class Student:
    name:str
    age:int
    roll:int
    def show(self)->int:
        print("I am Student")
        return 19
    def __lt__(self,other): # overriding less than operator
        return self.roll>other.roll


if __name__ == "__main__":
    obj = Sample("Satyam")
    # print(obj.__address)  # This will raise an AttributeError

    obj.__name = "New Name"  # This will create a new attribute in obj2, not modify the private __name
    print(obj.__name)  # Outputs: New Name

    print(obj.greet())
    print(Sample.classMethod())
    obj.abstractMethodSample()

    obj2 : AbstractSample = Sample("Rahul")
    print(obj2.greet())
    # obj2 = AbstractSample()  # This will raise a TypeError because we cannot instantiate an abstract class

    print("2. ----------------------------\n")
    student = [ Student('satyam',23,120),Student('atyam',23,100),Student('Asatyam',32,130) ]
    heap.heapify(student)
    top=heap.heappop(student);
    print(top)
    print((student[0]<student[1]))

    print('\n3. ---------------------------\n')
    student.sort(key=lambda x : x.roll,reverse=True)
    print(student)
    for s in student:
        print(s.name)
