-- ------------------------------------------
BACKUP DATABASE testDB
TO DISK = 'D:\backups\testDB.bak';
-- ------------------------------------------
BACKUP DATABASE testDB
TO DISK = 'D:\backups\testDB.bak'
WITH DIFFERENTIAL;
-- ------------------------------------------


-- ------------------------------------------
CREATE TABLE TestTable AS
SELECT customername, contactname
FROM customers;
-- ------------------------------------------

CREATE INDEX idx_lastname
ON Persons (LastName);


ALTER TABLE table_name
DROP INDEX index_name;
-- ------------------------------------------


CREATE TABLE IF NOT EXISTS `tblsample` (
  `id` int(11) NOT NULL auto_increment,   
  `recid` int(11) NOT NULL default '0',       
  `cvfilename` varchar(250)  NOT NULL default '',     
  `cvpagenumber`  int(11) NULL,     
  `cilineno` int(11)  NULL,    
  `batchname`  varchar(100) NOT NULL default '',
  `type` varchar(20) NOT NULL default '',    
  `data` varchar(100) NOT NULL default '',
  PRIMARY KEY  (`id`)

);
-- ------------------------------------------

create table EMP( 
  EMPNO int NOT NULL,
  ENAME VARCHAR(10) ,
  JOB VARCHAR(9) ,
  MGR  INT ,
  HIREDATE DATE ,
  SAL float(7,2) ,
  COMM float(7,2) ,
  DEPTNO int ,
  AGE int ,
  ESAL int
);
insert into EMP values(1,'Rahul','SDE',7902,str_to_date('06-03-2000', '%m-%d-%Y'),5000.6456,550,10,25,250);
insert into EMP values(2,'Rajan','DBA',7566,str_to_date('06-03-2019', '%m-%d-%Y'),1500,559,20,35,2050);
insert into EMP values(3,'Satyam','Q/AS',7760,str_to_date('06-06-2002', '%m-%d-%Y'),3500,490,10,45,2000);
insert into EMP values(4,'Rajiv','tech',7902,str_to_date('04-03-2020', '%m-%d-%Y'),1500,909,10,22,500);
insert into EMP values(5,'Santosh','network',7789,str_to_date('06-03-2000', '%m-%d-%Y'),2500.6678,449,20,32,600);
insert into EMP values(6,'Vickey','SDE',7902,str_to_date('07-05-2008', '%m-%d-%Y'),1000,459,10,28,700);
insert into EMP values(7,'Vivek','SDE',7789,str_to_date('09-03-2000', '%m-%d-%Y'),1200,549,20,26,400);
insert into EMP values(8,'Munna','Product',7760,str_to_date('03-03-2010', '%m-%d-%Y'),3500,455,30,29,450);
desc EMP;
select *from emp;
select ename as EMPLOYEE,sal as SALARY from emp where sal>=1500 and sal<=3500;

select ename as EMPLOYEE,mgr as MANAGER from emp where mgr in(7902 , 7566 , 7789);
select ename as EMPLOYEE,DEPTNO from EMP where emp.deptno=10 or emp.deptno=20;


-- ------------------------------------------
use practice;
drop database practice456;
select ename as EMPLOYEE from EMP where mgr is not null;
select distinct(deptno) from emp;
select ename as EMPLOYEE from EMP where comm is null;
select ename as EMPLOYEE,DEPTNO from EMP where deptno=20;
show databases;
show tables;
select *from sample;
desc table sample;
select distinct count(*) from countrylanguage;
-- /////////////////////////////////////////////////////////////////////////////////////////////////////////////



-- Consider the database for a banking enterprise. Write the queries for the below questions.

--  Insert at least 5 tuples in each table



CREATE TABLE branch( 
  branch_code VARCHAR(15),
  branch_city VARCHAR(15),
  assets float(10,2),
  State varchar(20),
  PRIMARY KEY(branch_code)
);

CREATE TABLE account( 
  accno INTEGER(8),
  branch_code VARCHAR(15),
  balance float(10,2),
  PRIMARY KEY(accno),
  FOREIGN KEY(branch_code) REFERENCES branch(branch_code)ON DELETE CASCADE
);

CREATE TABLE customer( 
  customer_name VARCHAR(15),
  customer_street VARCHAR(15),
  customer_city VARCHAR(15),
  accno integer(8),
  PRIMARY KEY(accno)
);

insert into branch (branch_code,branch_city,assets,state) values
          ("ALLAHJN","KOLKATA",10000,'WB'),
          ("ICCICIMH","MUMBAI",20000,'MAH'),
          ("SBIKOL","KOLKATA",30000,'WB'),
          ("INDJN","MUMBAI",40000,'MAH'),
          ("HDFCSIL","SIKKIM",50000,'SKM');

select *from account;

insert into account values  (12345,'ALLAHJN',25600),
                            (45678,'HDFCSIL',36500),
                            (45612,'SBIKOL',457895),
                            (55647,'INDJN',7568920),
                            (75463,'ICCICIMH',45678);

select *from account;
insert into CUSTOMER values ('satyam','VP road','KOLKATA',1234),
                            ('Rahul','MG road','MUMBAI',4567),
                            ('rajan','Link road','CHENNAI',4562),
                            ('Ranjit','NS road','KOLKATA',5547),
                            ('Deepak','GT road','MUMBAI',7543);

truncate table customer;

-- a. Display the branch details

-- b. List the customers of ‘Mumbai’ city

-- c. List the male customers of ‘Kolkata’ city

-- d. List the state having more than one branch.

-- e. List the deposit schemes provided by the bank to the customers
select *from customer where customer_city='MUMBAI';
select *from account;
select *from customer;
select *from branch;
select * from customer right join account on customer.accno = account.accno;
select count(*)  from branch;


use practice;
show databases;
show tables;
select *from emp;
-- 123456
-- satyam

create table chktab as
select  *from emp where job="sde";


select *from chk;
select *from chktab where hiredate="20080705";
insert into EMP values(810,'LuRARIA','SDE',7760,str_to_date('03-03-2010', '%m-%d-%Y'),3500,455,30,29,450);
select *from emp where hiredate< date_add(sysdate(),interval -16 year);

select dayname(day(hiredate)) as "month" from emp;



