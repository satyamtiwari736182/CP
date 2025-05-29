import heapq as hq
print("\nhello world!\n\n")

num= {1,2,3} #set
num.add(49), num.add(9)

temp=True
print((1 and 2)==True)
if not temp:
    print("true value")
else:
    print("false value")
print('---------------------------')

size=10
arr2=[None]*size  #list
arr3=[1]*size

arr4=arr2+arr3

arr2[2]=189
arr2[0]=True

arr2.clear
print(arr2)
print('---------------------------')

a=input("num1: ")
b=input("num2: ")
print(type(a))
print(a+b)

print('Summation: ',(int(a)+int(b)))
print('Summation: ',(float(a)+float(b)))

print('---------------------------')

c = 3.7
from math import *
print(round(c),floor(c),ceil(c))  

print('---------------------------')
name='satyam'
address='jaigaon'
amt=897.6745
year=2025
print()
print(f"{1.:<20}hello{name} from {address:<20} with reward of Rs. {amt:^20.2f} {'':^20} year {year}")
print()
print('---------------------------')

from typing import Final
num:Final=120
num=900
print(num)


str1="satyam"
# str1[0]='Q' # string immutable
print(str1.title())
print(str1)

str2=list(str1)
str2[0]='Q'
str3=str(str2)
print("".join(str2))
print(str3)
print('\n1.----------------\n')

lst=[1,22,3,23,43,56,12]
lst2 = [x**2 for x in lst] #  list comprehension 
print(lst,end='\n\n')
for x in lst2:
    print(x,end=", ")
print()
lst2 = [x**2 for x in lst if x % 2 == 0] 

pairs = [(x, y) for x in range(10)if x%2==0 for y in [3, 4]]
print(pairs)

n,l=4,3
arr1 = [[0 for _ in range(l)] for _ in range(n)]
print(arr1)

dp = [[0] * n for _ in range(n)]
print(dp)
print('\n2.----------------\n')
hq.heapify(lst)
print()
print(hq.heappop(lst),end='\n')
print(hq.heappop(lst))
lst.sort(reverse=True)
print(lst,end='\n')

# print('\n----------------\n')
# from dataclasses import dataclass,field
# @dataclass(order=True)
# class Student:
#     name:str=field(compare=False)
#     age:int=field(compare=False)
#     roll:int

# student = [ Student('satyam',23,-100),Student('atyam',23,-99),Student('Asatyam',32,-130) ]
# hq.heapify(student)
# top=hq.heappop(student);
# top.roll = -top.roll;
# print(top)

print('\n3.----------------\n')
from dataclasses import dataclass,field
@dataclass
class Student:
    name:str
    age:int
    roll:int
    def show(self)->int:
        print("I am Student")
        return 19
    def __lt__(self,other): # overriding less than operator
        return self.roll<other.roll

student = [ Student('satyam',23,-100),Student('atyam',23,-100),Student('Asatyam',32,-130) ]
hq.heapify(student)
top=hq.heappop(student);
top.roll = -top.roll;
print(top)
print((student[0]<student[1]))

print('\n4.----------------\n')
student.sort(key=lambda x : x.roll,reverse=True)
print(student)
for s in student:
    print(s.name)
print('\n5.----------------\n')


from collections import deque,UserList
que=deque()
que.appendleft(10)
que.append(20)
que.appendleft(30)

print(que)
print(que.pop())
print(que.popleft())
print('\n6.----------------\n')

arr=[]
arr.append([1,2,3])
arr.append([4,5,6])

print(arr)
print(arr[1][1],end='\n')
del arr[0][1]
arr[1].remove(5)
print(arr)
print('\n7.----------------\n')

lst3=UserList()
lst3.append(12)
lst4=[1,3]
print(len(lst3))
print('\n8.----------------\n')

def my_decorator(func):
    def wrapper():
        print("Before function execution")
        func()  # Call the original function
        print("After function execution")
    return wrapper  # Return the modified function

@my_decorator  # Applying decorator
def say_hello():
    print("Hello!")

say_hello()
print('\n9.----------------\n')

from abc import ABC,abstractmethod

class Bag(ABC):
    arr=[1,20]
    @staticmethod
    def show():
        print("I am static show func")
    def __init__(self):
        # self.arr=[]
        self.data = []
    # @abstractmethod
    def add(self, x):
        self.data.append(x)
    def addtwice(self, x):
        self.add(x)
        self.add(x)
bag=Bag()
bag2=Bag()
bag2.arr.append(34)
bag.add(12)
bag.addtwice(102)
print(bag.arr)
Bag.show()
print('\n10.----------------\n')

def display(name,*info,city='jaigaon',**score,):
    print(name)
    print(city)
    print(info)
    print(score)
score={'phy':20,'eng':50,'math':90}
display('satyam',107,'A','science',city='siliguri',phy=20,eng=50,math=90)
print('\n11.----------------\n')

sets={1,2,5,1,2,3,4,5}
sets.add(10)
sets.remove(2)
print(sets)
print('\n12.----------------\n')

mp={"name":"satyam","roll":101}
mp["name"]="rahul"
mp[1]=90
mp[10]=[1,3,4,5]
print(mp.__contains__(10))
if mp.__contains__(10):
    print(mp.get(10))
print('\n')
for k,v in mp.items():
    print(k,v,sep='->')
print('\n13.----------------\n')

