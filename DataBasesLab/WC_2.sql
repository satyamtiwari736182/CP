use testdb;

create table if not exists STUDIES_1157(
	SPLACE varchar(10),
    COURSE varchar(20),
    CCOST varchar(10)
);

create table if not exists SOFTWARE_1157(
	S_ID varchar(6),
    TITLE varchar(20),
    DEVIN varchar(10),
    SCOST numeric(10),
    DCOST numeric(10),
    SOLD numeric(10)
);

create table if not exists PROGRAMMER_1157(
	PNAME varchar(10),
    DOB date,
    DOJ date,
    SEX char(1),
    PROF1 varchar(6),
    PROF2 varchar(6),
    SAL numeric(10,2)
);


# 1
alter table programmer_1157
	add column P_ID varchar(6) primary key check(P_ID like 'C%'or p_id like 'O%'),
    add column MGR varchar(6);
    
# 2
alter table software_1157
	add column P_ID varchar(6) ,
    add constraint foreign key(P_ID) references programmer_1157(P_ID);

# 3
alter table studies_1157
		alter splace set default 'CU';
        
alter table studies_1157
        add constraint check(ccost>0);
        
alter table studies_1157
	add column P_ID varchar(6) ,
    add constraint foreign key(P_ID) references programmer_1157(P_ID);

describe studies_1157;

-- 


insert into programmer_1157(p_id,pname,dob,doj,sex,prof1,prof2,sal) values
		('C1','Harsh',str_to_date('17-DEC-1989','%d-%b-%Y'),str_to_date('23-JUL-2012','%d-%b-%Y'),'M','C','C++',50000);
        
insert into programmer_1157(p_id,pname,dob,doj,sex,prof1,prof2,sal,mgr) value
		('O2','Chirag',str_to_date('21-MAR-1990','%d-%b-%Y'),str_to_date('21-JUL-2012','%d-%b-%Y'),'M','C','Java',55000,'O2');
        
insert into programmer_1157(p_id,pname,dob,doj,sex,prof1,prof2,sal) values
		('O3','Anu',str_to_date('23-MAR-1987','%d-%b-%Y'),str_to_date('21-JUL-2012','%d-%b-%Y'),'F','C','Java',55000);

insert into programmer_1157(p_id,pname,dob,doj,sex,prof1,prof2,sal,mgr) value
		('C4','Ravinder',str_to_date('25-JAN-1987','%d-%b-%Y'),str_to_date('23-JUL-2012','%d-%b-%Y'),'M','C','VB',40000,'C1');
        

insert into studies_1157(course,ccost,p_id) values
		('Oracle',5000,'C1'),
        ('Java',5000,'O2'),
        ('Advanced Java',5000,'O3');
        

insert into software_1157 values
		('S1','CProject','C',5000,2000,5,'C4'),
        ('S2','VBProject','VB',5000,5000,4,'C4'),
        ('S3','JavaProject','Java',5000,10000,2,'O2'),
        ('S4','JavaProject2','Java',5000,15000,1,'O3'),
        ('S5','VBProject2','VB',7000,45000,3,'C4');
        


select *from PROGRAMMER_1157;
select *from software_1157;
select *from studies_1157;

describe studies_1157;
describe software_1157;
describe table PROGRAMMER_1157;




-- 1. List the id and name of the programmers who have proficiency in C and Java and order
-- them by their name in the descending order.

select p_id,pname from programmer_1157 
			where prof1='C' and prof2='Java'
					order by pname desc;

-- 2. Calculate the total number of employees who developed project in ‘C’, ‘VB’ and JAVA
-- and display the projects in descending order.
select *from software_1157;

select count(pname) from programmer_1157
			where programmer_1157.p_id in 
            (select software_1157.p_id from software_1157
					where software_1157.devin in('C','VB','Java')
            );
            -- and software_1157(devin) in('C','VB','Java');
select *from programmer_1157;
-- 3. Find out the selling cost average for packages developed in JAVA and VB.
-- 4. What is the price of the costliest software developed in VB and JAVA?
-- 5. Create a table Programmer_Details having columns P_Id, PNAME, SAL from the
-- Programmer and P_ID, S_ID, TITLE from the Software table.
-- 6. Delete the values from the Programmer_Details table and insert into the table by taking
-- the values from the source table.
























