# SQL

```md
# leetcode - 196
Table: Person
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+

id is the primary key (column with unique values) for this table.
Each row of this table contains an email. The emails will not contain uppercase letters.
Write a solution to delete all duplicate emails, keeping only one unique email with the smallest id.
```
```sql
delete a from person a,person b where a.email=b.email and a.id>b.id;
```
---
<br>

```md
# leetcode - 175

Table: Person
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| personId    | int     |
| lastName    | varchar |
| firstName   | varchar |
+-------------+---------+

Table: Address
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| addressId   | int     |
| personId    | int     |
| city        | varchar |
| state       | varchar |
+-------------+---------+

Write a solution to report the first name, last name, city, and state of each person in the Person table. If the address of a personId is not present in the Address table, report null instead.
```
```sql
select firstName, lastName, city, state from person p left join address a on p.personId=a.personId;
```
---
<br>

```md
# leetcode - 176

Table: Employee
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+

Write a solution to find the second highest salary from the Employee table. If there is no second highest salary, return null 
```
```sql
select (select distinct salary from employee e order by salary desc limit 1 OFFSET 1) as SecondHighestSalary;
```
---
<br>

```md
# leetcode - 177
Table: Employee
+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| salary      | int  |
+-------------+------+
Write a solution to find the nth highest salary from the Employee table. If there is no nth highest salary, return null.
```
```sql
create function getNthHighestSalary(N int) returns int
begin
set n=N-1;
  return (
    select distinct salary from employee e order by salary desc limit 1 offset n
  );
end
```
---
<br>

```md
# leetcode - 178

Table: Scores
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| score       | decimal |
+-------------+---------+

Write a solution to find the rank of the scores. The ranking should be calculated according to the following rules:
    - The scores should be ranked from the highest to the lowest.
    - If there is a tie between two scores, both should have the same ranking.
    After a tie, the next ranking number should be the next consecutive integer value. In other words, there should be no holes between ranks.

Return the result table ordered by score in descending order.
```
```sql
select score, (select count(distinct score) from scores where score>=s.score) as "rank" from scores s order by score desc;
```
---
## Window function
<img src="./Screenshot 2024-07-22 at 5.13.38 PM.png" height="500">

```sql
select concat(firstName, " ", lastName) as fullName, salary, deptId, avg(salary) over(partition by deptId) as dept_avg_salary from employees;
```
<br>
<img src="./Screenshot 2024-07-22 at 5.29.00 PM.png" height="500">
<br>
<img src="./Screenshot 2024-07-22 at 6.09.54 PM.png" height="500">

---
<br><br>
<img src="./Screenshot 2024-07-24 at 10.51.01 AM.png" height="170">
<img src="./Screenshot 2024-07-24 at 10.49.46 AM.png" height="170">

---
<br><br>
<img src="./Screenshot 2024-07-24 at 8.54.20 PM.png" height="200">
<br><br>
<img src="./Screenshot 2024-07-24 at 8.56.11 PM.png" height="190">
<img src="./Screenshot 2024-07-24 at 8.57.10 PM.png" height="190">

---
<br>

```md
# leetcode - 180
Table: Logs
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| num         | varchar |
+-------------+---------+
Find all numbers that appear at least three times consecutively.
```
```sql
select distinct num as consecutivenums
from (
    select 
        num,
        lead(num, 1) over () as num1,
        lead(num, 2) over () as num2
    from logs
) as subquery
where num = num1 and num = num2;
```

#### Alternate way to write
```sql
with cte as (
    select num,
    lead(num,1) over() num1,
    lead(num,2) over()  num2
    from logs
)

select distinct num ConsecutiveNums from cte where (num=num1) and (num=num2)
```
---
<br>

```md
# LeetCode - 181
Table: Employee
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| salary      | int     |
| managerId   | int     |
+-------------+---------+
Write a solution to find the employees who earn more than their managers.
```
```sql
select a.name as "Employee" from Employee a,Employee b
where a.managerId=b.id and a.salary>b.salary
```
---
<br>

```md
# LeetCode - 184
Table: Employee
+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| id           | int     |
| name         | varchar |
| salary       | int     |
| departmentId | int     |
+--------------+---------+

Table: Department
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+

Write a solution to find employees who have the highest salary in each of the departments.
```
```sql
select s.Department,s.Employee,s.Salary from(
    select d.name Department, e.name Employee, e.salary
    ,rank() over(partition by e.departmentId order by e.salary desc) rnk
    from employee e 
    inner join department d 
    on e.departmentId=d.id
) s where rnk=1
```
---
<br>

```md
# LeetCode - 197
Table: Weather
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| recordDate    | date    |
| temperature   | int     |
+---------------+---------+

Write a solution to find all dates' Id with higher temperatures compared to its previous dates (yesterday).
```
```sql
select a.id from weather a
inner join weather b
on a.temperature>b.temperature and datediff(a.recordDate,b.recordDate)=1
```
#### Alternate ways
```sql
select Id from
    (select *, lag(temperature,1) over(order by recordDate) as prevTemp
    ,lag(recordDate,1) over(order by recordDate) as prevDate from weather) as s
where temperature>prevTemp and datediff(recordDate,prevDate)=1
```
---
<br>

#### Attention needed
```md
# LeetCode - 262

Table: Trips
+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| id          | int      |
| client_id   | int      |
| driver_id   | int      |
| city_id     | int      |
| status      | enum     |
| request_at  | varchar  |     
+-------------+----------+
id is the primary key (column with unique values) for this table.
The table holds all taxi trips. Each trip has a unique id, while client_id and driver_id are foreign keys to the users_id at the Users table.
Status is an ENUM (category) type of ('completed', 'cancelled_by_driver', 'cancelled_by_client').
 

Table: Users

+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| users_id    | int      |
| banned      | enum     |
| role        | enum     |
+-------------+----------+
users_id is the primary key (column with unique values) for this table.
The table holds all users. Each user has a unique users_id, and role is an ENUM type of ('client', 'driver', 'partner').
banned is an ENUM (category) type of ('Yes', 'No').
 

The cancellation rate is computed by dividing the number of canceled (by client or driver) requests with unbanned users by the total number of requests with unbanned users on that day.

Write a solution to find the cancellation rate of requests with unbanned users (both client and driver must not be banned) each day between "2013-10-01" and "2013-10-03". Round Cancellation Rate to two decimal points.
```
#### Approach - 1 : failed
```sql
select a.request_at as "Day",ROUND(COALESCE(b.totalCanceled, 0)/NULLIF(COALESCE(a.totalReq, 0),0),2) "Cancellation Rate" 

from

(select t.request_at,count(distinct t.id) as totalReq
from trips t
inner join users u
on u.users_id in (t.client_id,t.driver_id)
where u.banned='No'
group by request_at) a

left join

(select t.request_at,count(distinct t.id) as totalCanceled
from trips t
inner join users u
on u.users_id in (t.client_id,t.driver_id)
where u.banned='No'
and t.status <> 'completed'
group by request_at) b

on a.request_at=b.request_at
```
#### Approach - 2 : Accepted
```sql
with stats as(
    select t.request_at, t.status <> 'completed' as IsCancelled
    from trips t
    join users u1 on (t.client_id=u1.users_id and u1.banned='No')
    join users u2 on (t.driver_id=u2.users_id and u2.banned='No')
    where t.request_at between '2013-10-01' and '2013-10-03'
)
select request_at as 'Day', round(cast(sum(IsCancelled) as real)/cast(count(*) as real),2) as 'Cancellation Rate'
from stats
group by request_at
```
## View

<img src="./Screenshot 2024-07-24 at 9.57.26 PM.png" height="300">

<br>

**1. create or replace view viewName ->** We can't change columnName or it's dataType if the same view previouly existed. As view store the structure of the view table and execute the same query and retaining structure each time whenever view is reffered.

**2. Normally view are not modifiable i-e modification in view won't affect the original table but,**

**3. modification capabilities to view can be achived by ensuring that during cration of view no keyword like distinct, where, join, or involving multiple table has been used.**