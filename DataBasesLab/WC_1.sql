
-- 													Assignment 1
										
-- 													  SET - 1

create database testDB;
use testDB;
DROP table CLIENT_MASTER_1157;
create table CLIENT_MASTER_1157(
	CLIENTNO varchar(6) primary key,
    NAME varchar(20),
    ADDRESS1 varchar(30),
    ADDRESS2 varchar(30),
    CITY varchar(15),
    PINCODE varchar(8),
    STATE varchar(15),
    BALDUE numeric(10,2)
);

describe CLIENT_MASTER_1157;
truncate table client_master_1157;

insert into CLIENT_MASTER_1157(CLIENTNO,NAME,CITY,PINCODE,STATE,BALDUE) values 
('C00001','Anil','Madras','780001','Tamil Naidu',15000),
('C00002','Sachin','Mumbai','400054','Maharastra',0),
('C00003','Dravid','Mumbai','400057','Maharastra',5000),
('C00004','Ganguly','Banglore','560001','Karnataka',0),
('C00005','Sehwag','Manglore','560050','Karnataka',2000),
('C00006','Harbhajan','Jalandhar','144401','Punjab',0);


select *from CLIENT_MASTER_1157;

# 1
select CLIENTNO,NAME from CLIENT_MASTER_1157;

# 2
update CLIENT_MASTER_1157 set CITY='Banglore' where CLIENTNO='C00005';

# 3
update CLIENT_MASTER_1157 set baldue=1000 where clientno='C00001';

# 4
SET SQL_SAFE_UPDATES = 0;

delete from CLIENT_MASTER_1157 where state='Tamil Naidu';

/*0	32	12:39:36	delete from CLIENT_MASTER_1157 where state='Tamil Naidu'	Error Code: 1175. You are using safe update mode and you tried to update a table without a WHERE that uses a KEY column. 
 To disable safe mode, toggle the option in Preferences -> SQL Editor and reconnect.	0.047 sec*/
 
 # 5
 alter table CLIENT_MASTER_1157
 add TELEPHONE numeric(10);
 
 # 6
 alter table CLIENT_MASTER_1157
 rename column CLIENTNO to CLIENT_ID;
 
 # 7
 select name from client_master_1157 where name like '_a%';
 
 # 8
 select client_id,name from client_master_1157 where city like 'M%';
 
 # 9
 select *from client_master_1157 where state='Maharastra' or state='Karnataka';
 
 # 10
 select *from client_master_1157 where client_id in ('C00001','C00002','C00003') order by name asc;
 
 # 11
 select client_id, name from client_master_1157 where baldue between 5000 and 15000;

# 12
drop table client_master_1157;

show tables;

		
        
-- 																	SET - 2

create table DEPT_1157(
DEPTNO numeric(3) primary key not null,
DNAME varchar(14),
LOC numeric(2)
);

create table EMP_1157(
EMPNO varchar(6) not null,
ENAME varchar(10),
JOB varchar(9),
HIREDATE date,
SAL numeric(7,2),
DEPTNO numeric(3)
);

drop table emp_1157;
drop table dept_1157;
show tables;
describe dept_1157;
describe emp_1157;

# 1
alter table emp_1157
	modify empno varchar(6) primary key check (empno like ('CS%','ME%','EE','CI%'));
select *from emp_1157;
insert into emp_1157(empno,deptno) value('456',456);
    
    
# 2
alter table emp_1157 
	add MGR varchar(6) ,
		add constraint foreign key(MGR) references emp_1157(empno);

# 3
alter table dept_1157
	drop column loc;
    
alter table dept_1157
    modify DNAME varchar(10);

# 4
alter table dept_1157
	alter DNAME set default 'CS';

# 5
alter table emp_1157
	add constraint foreign key(deptno) references dept_1157(deptno);
--




























